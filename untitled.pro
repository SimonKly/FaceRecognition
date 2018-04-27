#-------------------------------------------------
#
# Project created by QtCreator 2018-03-11T15:40:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    frengine.cpp \
    ftengine.cpp \
    fdengine.cpp \
    ageestimationengine.cpp \
    miscellaneous.cpp

HEADERS += \
        mainwindow.h \
    amcomdef.h \
    arcsoft_fsdk_age_estimation.h \
    arcsoft_fsdk_face_detection.h \
    arcsoft_fsdk_face_recognition.h \
    arcsoft_fsdk_face_tracking.h \
    arcsoft_fsdk_gender_estimation.h \
    asvloffscreen.h \
    merror.h \
    frengine.h \
    ftengine.h \
    fdengine.h \
    ageestimationengine.h \
    miscellaneous.h

FORMS += \
        mainwindow.ui


#年龄估计
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -llibarcsoft_fsdk_age_estimation
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -llibarcsoft_fsdk_age_estimationd
else:unix:!macx: LIBS += -L$$PWD/lib/ -llibarcsoft_fsdk_age_estimation

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.


#面部侦测
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -llibarcsoft_fsdk_face_detection
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -llibarcsoft_fsdk_face_detectiond
else:unix:!macx: LIBS += -L$$PWD/lib/ -llibarcsoft_fsdk_face_detection

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.


#面部追踪
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -llibarcsoft_fsdk_face_tracking
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -llibarcsoft_fsdk_face_trackingd
else:unix:!macx: LIBS += -L$$PWD/lib/ -llibarcsoft_fsdk_face_tracking

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

#面试识别
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -llibarcsoft_fsdk_face_recognition
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -llibarcsoft_fsdk_face_recognitiond
else:unix:!macx: LIBS += -L$$PWD/lib/ -llibarcsoft_fsdk_face_recognition

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

#性别判断
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -llibarcsoft_fsdk_gender_estimation
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -llibarcsoft_fsdk_gender_estimationd
else:unix:!macx: LIBS += -L$$PWD/lib/ -llibarcsoft_fsdk_gender_estimation

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.
