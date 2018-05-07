#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_AttendanceClient.h"

#include <QCamera>
#include <QImage>
#include <QCameraViewFInder>
#include <QCameraImageCapture>

class AttendanceClient : public QMainWindow
{
	Q_OBJECT

public:
	AttendanceClient(QWidget *parent = Q_NULLPTR);


private slots:

	void captureImage();
	void displayImage(int, QImage);
	void saveImage();

private:
	Ui::AttendanceClientClass ui;

	QCamera *m_pCamera;
	QCameraViewfinder *m_pViewfinder;
	QCameraImageCapture *m_pImageCapture;
};
