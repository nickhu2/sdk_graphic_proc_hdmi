#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QDir>
#include <QTimer>
#include <QThread>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0, QString abs_path = "", int rate = 20);
    ~MainWindow();
    int argc_num;
    QString abs_src_path;
    int frame_rate;
private slots:
    void on_pathBt_clicked(); //打开目录

    void on_photoList_clicked(const QModelIndex &index);//单击播放图片

    void on_autoPhoto_clicked(bool checked);//自动播放选择
    void autoPhoto(); //自动播放函数
    void showDinamicPhoto(QString path);//动态图播放（格式为gif）

private:
    Ui::MainWindow *ui;
    QFile *file;
    QString Dir;//打开文件的路径
    QString tempDir; //照片的绝地路径
    QVector<QString> photoPath;//存放照片相对路径的容器
    QTimer *mtime; //定时器
    QString delayTime; //延时间隔
    bool autoFlag; //判断是否进入的自动播放格式

    int num; //照片张数
};

#endif // MAINWINDOW_H
