/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "imagelabel.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *line;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    ImageLabel *imageLabel;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btnOpenImage;
    QPushButton *btnFaceDetect;
    QPushButton *btnAgeEstimation;
    QPushButton *btnGenderEstimation;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(471, 372);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(270, 0, 71, 341));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 20, 251, 291));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        imageLabel = new ImageLabel(verticalLayoutWidget);
        imageLabel->setObjectName(QStringLiteral("imageLabel"));

        verticalLayout->addWidget(imageLabel);

        verticalLayoutWidget_2 = new QWidget(centralWidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(340, 20, 81, 291));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        btnOpenImage = new QPushButton(verticalLayoutWidget_2);
        btnOpenImage->setObjectName(QStringLiteral("btnOpenImage"));

        verticalLayout_2->addWidget(btnOpenImage);

        btnFaceDetect = new QPushButton(verticalLayoutWidget_2);
        btnFaceDetect->setObjectName(QStringLiteral("btnFaceDetect"));

        verticalLayout_2->addWidget(btnFaceDetect);

        btnAgeEstimation = new QPushButton(verticalLayoutWidget_2);
        btnAgeEstimation->setObjectName(QStringLiteral("btnAgeEstimation"));

        verticalLayout_2->addWidget(btnAgeEstimation);

        btnGenderEstimation = new QPushButton(verticalLayoutWidget_2);
        btnGenderEstimation->setObjectName(QStringLiteral("btnGenderEstimation"));

        verticalLayout_2->addWidget(btnGenderEstimation);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 471, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        imageLabel->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        btnOpenImage->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\345\233\276\347\211\207", Q_NULLPTR));
        btnFaceDetect->setText(QApplication::translate("MainWindow", "\344\276\246\346\265\213\344\272\272\350\204\270", Q_NULLPTR));
        btnAgeEstimation->setText(QApplication::translate("MainWindow", "\351\242\204\344\274\260\345\271\264\351\276\204", Q_NULLPTR));
        btnGenderEstimation->setText(QApplication::translate("MainWindow", "\351\242\204\344\274\260\346\200\247\345\210\253", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
