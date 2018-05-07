/********************************************************************************
** Form generated from reading UI file 'AttendanceClient.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATTENDANCECLIENT_H
#define UI_ATTENDANCECLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AttendanceClientClass
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *ImageView;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *ImageCapture;
    QPushButton *btnCapture;
    QPushButton *btnSave;
    QPushButton *btnQuit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AttendanceClientClass)
    {
        if (AttendanceClientClass->objectName().isEmpty())
            AttendanceClientClass->setObjectName(QStringLiteral("AttendanceClientClass"));
        AttendanceClientClass->resize(502, 400);
        centralWidget = new QWidget(AttendanceClientClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 301, 341));
        ImageView = new QHBoxLayout(horizontalLayoutWidget);
        ImageView->setSpacing(6);
        ImageView->setContentsMargins(11, 11, 11, 11);
        ImageView->setObjectName(QStringLiteral("ImageView"));
        ImageView->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(300, 0, 201, 341));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        ImageCapture = new QLabel(verticalLayoutWidget);
        ImageCapture->setObjectName(QStringLiteral("ImageCapture"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        ImageCapture->setFont(font);

        verticalLayout->addWidget(ImageCapture);

        btnCapture = new QPushButton(verticalLayoutWidget);
        btnCapture->setObjectName(QStringLiteral("btnCapture"));

        verticalLayout->addWidget(btnCapture);

        btnSave = new QPushButton(verticalLayoutWidget);
        btnSave->setObjectName(QStringLiteral("btnSave"));

        verticalLayout->addWidget(btnSave);

        btnQuit = new QPushButton(verticalLayoutWidget);
        btnQuit->setObjectName(QStringLiteral("btnQuit"));

        verticalLayout->addWidget(btnQuit);

        AttendanceClientClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(AttendanceClientClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 502, 23));
        AttendanceClientClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(AttendanceClientClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        AttendanceClientClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(AttendanceClientClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        AttendanceClientClass->setStatusBar(statusBar);

        retranslateUi(AttendanceClientClass);

        QMetaObject::connectSlotsByName(AttendanceClientClass);
    } // setupUi

    void retranslateUi(QMainWindow *AttendanceClientClass)
    {
        AttendanceClientClass->setWindowTitle(QApplication::translate("AttendanceClientClass", "AttendanceClient", Q_NULLPTR));
        ImageCapture->setText(QApplication::translate("AttendanceClientClass", "no image to display... ...", Q_NULLPTR));
        btnCapture->setText(QApplication::translate("AttendanceClientClass", "Capture", Q_NULLPTR));
        btnSave->setText(QApplication::translate("AttendanceClientClass", "Save", Q_NULLPTR));
        btnQuit->setText(QApplication::translate("AttendanceClientClass", "Quit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AttendanceClientClass: public Ui_AttendanceClientClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATTENDANCECLIENT_H
