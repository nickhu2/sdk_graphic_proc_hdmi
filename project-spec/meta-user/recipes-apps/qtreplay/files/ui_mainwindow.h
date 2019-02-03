/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QTextBrowser *photoPath;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pathBt;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QLineEdit *delayEdit;
    QCheckBox *autoPhoto;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_4;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_4;
    QListWidget *photoList;
    QLabel *photoShow;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(702, 800);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 456, 57));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, -1, 0);
        photoPath = new QTextBrowser(layoutWidget);
        photoPath->setObjectName(QString::fromUtf8("photoPath"));
        photoPath->setMaximumSize(QSize(150, 20));

        verticalLayout->addWidget(photoPath);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pathBt = new QPushButton(layoutWidget);
        pathBt->setObjectName(QString::fromUtf8("pathBt"));

        horizontalLayout_2->addWidget(pathBt);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_5->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        delayEdit = new QLineEdit(layoutWidget);
        delayEdit->setObjectName(QString::fromUtf8("delayEdit"));
        delayEdit->setMaximumSize(QSize(95, 16777215));

        horizontalLayout->addWidget(delayEdit);

        autoPhoto = new QCheckBox(layoutWidget);
        autoPhoto->setObjectName(QString::fromUtf8("autoPhoto"));

        horizontalLayout->addWidget(autoPhoto);


        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        horizontalLayout_5->addLayout(horizontalLayout_3);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(12, 62, 1024, 506));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        photoList = new QListWidget(layoutWidget1);
        photoList->setObjectName(QString::fromUtf8("photoList"));
        photoList->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(photoList->sizePolicy().hasHeightForWidth());
        photoList->setSizePolicy(sizePolicy);
        photoList->setMinimumSize(QSize(120, 0));
        photoList->setMaximumSize(QSize(120, 400));
        photoList->setSizeIncrement(QSize(0, 0));
        photoList->setBaseSize(QSize(2, 0));

        horizontalLayout_4->addWidget(photoList);

        photoShow = new QLabel(layoutWidget1);
        photoShow->setObjectName(QString::fromUtf8("photoShow"));
        photoShow->setMinimumSize(QSize(300, 200));
        photoShow->setMaximumSize(QSize(16777215, 800));

        horizontalLayout_4->addWidget(photoShow);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pathBt->setText(QApplication::translate("MainWindow", "\346\265\217\350\247\210", nullptr));
        delayEdit->setPlaceholderText(QApplication::translate("MainWindow", "\351\227\264\351\232\224\346\227\266\351\227\264\357\274\210\347\247\222\357\274\211", nullptr));
        autoPhoto->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\346\222\255\346\224\276", nullptr));
        photoShow->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
