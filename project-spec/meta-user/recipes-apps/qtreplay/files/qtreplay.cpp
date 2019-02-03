#include "mainwindow.h"
#include <QApplication>

#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QMovie>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if(argc < 3)
    {
        printf("must specify input directory and frame speed(ms)\r\n");
        return -1;
    }

    QString temp_path_str;
    temp_path_str.sprintf("%s",argv[1]);

    QString temp_rate_str;
    temp_rate_str.sprintf("%s",argv[2]);
    int rate = temp_rate_str.toInt();

    MainWindow w(NULL, temp_path_str, rate);
    w.show();


    return a.exec();
}


MainWindow::MainWindow(QWidget *parent, QString abs_path, int rate) :
    QMainWindow(parent),
    autoFlag(false),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->photoList->setHidden(1);
    num = 0;

    abs_src_path = abs_path;
    frame_rate = rate;

    delayTime.clear();
    mtime = new QTimer();

    //连接自动播放槽函数
    connect(mtime,SIGNAL(timeout()),this,SLOT(autoPhoto()));

    on_pathBt_clicked();
    on_autoPhoto_clicked(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pathBt_clicked()
{
    /*
    Dir = QFileDialog::getExistingDirectory(this);//获取文件所在的具体路径
    ui->photoPath->setText(Dir);//显示打开的文件的具体路径
    */
    Dir = abs_src_path;


    QDir dir(Dir);
    dir.setSorting(QDir::Name);
    QStringList file;
    QFileInfoList fileList = dir.entryInfoList(file,QDir::Files, QDir::Name); //


    //fileList.
    QString fileDir; //保存图片所在的路径

    //列出目录下的文件，并按名称排序
    QDir dirtmp;

    for(int i=0;i<fileList.count();i++)
    {
        QFileInfo info = fileList.at(i);

        fileDir.clear();
        fileDir.append(Dir + "/");
        QString filename = info.fileName();
        fileDir.append(filename);
        photoPath.append(filename);// 把图片的路径装到容器中

        if(info.fileName() == "." || info.fileName() == "..") //跳过这两个目录
        {
            continue;
        }
        QListWidgetItem *item = new QListWidgetItem(QIcon(fileDir),info.fileName());//建立文件缩小图标
        ui->photoList->addItem(item);//把图片相对路径显示到窗口中

      }
     // qDebug()<<ui->photoList->count();
}


//单击图片列表中的图片进行播放，如果当前
void MainWindow::on_photoList_clicked(const QModelIndex &index)
{

    //如果选中了自动播放的情况下，点击列表中的内容，则停止自动播放
    if(autoFlag) //选中自动播放的情况
    {
        mtime->stop();
        ui->autoPhoto->setCheckState(Qt::Unchecked);
        autoFlag = false;
    }

    num = ui->photoList->row(ui->photoList->currentItem()); //获取当前点击的内容的行号

    //在没有选中自动播放的情况下，判断当前是否点击了最后一张照片，如果是最后一张照片，在选中自动播放的情况下让它返回到第一张照片
    if(!autoFlag)
    {
        num == ui->photoList->count();
        num = 0;
    }
    tempDir.clear();
    tempDir.append(Dir+"/");
    QString path = ui->photoList->currentItem()->text();
    tempDir.append(path);

    //判断是否是动态图
    if(tempDir.endsWith(".gif") || tempDir.endsWith(".Gif"))
    {
        showDinamicPhoto(tempDir);
    }
    else
    {
        ui->photoShow->setScaledContents(true);//显示图片的全部
        ui->photoShow->setPixmap(QPixmap(tempDir));//显示图片
    }

}


//自动播放照片
void MainWindow::on_autoPhoto_clicked(bool checked)
{
    /*
    if(ui->delayEdit->text().isEmpty())
    {
       QMessageBox::warning(this,"提示","请输入需要间隔的播放时间（ms）");
       ui->autoPhoto->setCheckState(Qt::Unchecked);
       return;
    }

    else if(ui->photoList->count() == 0)
    {
        QMessageBox::warning(this,"警告","还没有可以播放的图片");
        ui->autoPhoto->setCheckState(Qt::Unchecked); //把按钮重新置于没有被选中的状态
        return;
    }
    else*/ if(1) //启动定时器
    {
       delayTime = ui->delayEdit->text();
       mtime->start(frame_rate);//启动定时器并设置播放时间间隔
       autoFlag = true;
       //ui->autoPhoto->setCheckState(Qt::Unchecked);
    }

    else if(!checked)//停止定时器
    {
        mtime->stop();//停止定时器
        delayTime.clear();
        autoFlag = false;
    }

}

void MainWindow::autoPhoto()
{
        //int tempCount=0;

        //tempCount =  photoPath.count();
        tempDir.clear();
        tempDir.append(Dir+"/");
        QString path =  photoPath.at(num); //从容器中找到要播放的照片的相对路径
        tempDir.append(path); //拼接照片的绝对路径

        if(tempDir.endsWith(".gif")  || tempDir.endsWith(".Gif"))
        {
            showDinamicPhoto(tempDir);
            num++;
        }

       else if(!(tempDir.endsWith(".gif")  || tempDir.endsWith(".Gif")))
        {
           ui->photoShow->setScaledContents(true);//显示图片的全部
           ui->photoShow->setPixmap(QPixmap(tempDir));//显示图片

           //判断自动播放的时候是否播放到了最后一张图片，如果是则停止自动播放
           if(num ==  (photoPath.count()-1))
           {
               qDebug()<<num;
               mtime->stop();
               num = 0;
               if(autoFlag)
               {
                   autoFlag = false;
               }
               qDebug()<<num;
               ui->autoPhoto->setCheckState(Qt::Unchecked);//把自动播放按钮置于没有选择的状态
           }
           if(autoFlag)
           {
               num++;
           }
        }
}


//播放动态图
void MainWindow::showDinamicPhoto(QString path)
{
    QMovie *movie = new QMovie(path);  // path图片路径
    movie->start(); //开始播放动态图
    ui->photoShow->setMovie(movie); //将图片设置为为动态
    ui->photoShow->setScaledContents(true); //尽可能完整的播放整张动图 ，此处要设置为true
}
