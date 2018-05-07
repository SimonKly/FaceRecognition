#include "AttendanceClient.h"
#include <QPushButton>
#include <QPixmap>
#include <QFileDialog>

AttendanceClient::AttendanceClient(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	this->m_pCamera = new QCamera(this);
	this->m_pViewfinder = new QCameraViewfinder(this);
	this->m_pImageCapture = new QCameraImageCapture(m_pCamera);

	ui.ImageView->addWidget(m_pViewfinder);
	ui.ImageCapture->setScaledContents(true);

	m_pCamera->setViewfinder(m_pViewfinder);
	m_pCamera->start();

	connect(m_pImageCapture, &QCameraImageCapture::imageCaptured, this, &AttendanceClient::displayImage);
	connect(ui.btnCapture, &QPushButton::clicked, this, &AttendanceClient::captureImage);
	connect(ui.btnSave, &QPushButton::clicked, this, &AttendanceClient::saveImage);
	connect(ui.btnQuit, &QPushButton::clicked, qApp, &QApplication::quit);
}

void AttendanceClient::captureImage()
{
	ui.statusBar->showMessage(tr("capture..."), 1000);
	m_pImageCapture->capture();
}

//************************************
// Method:    displayImage
// FullName:  AttendanceClient::displayImage
// Access:    private 
// Returns:   void
// Qualifier:
// Parameter: int
// Parameter: QImage
//************************************
void AttendanceClient::displayImage(int id, QImage image)
{
	ui.ImageCapture->setPixmap(QPixmap::fromImage(image));
	ui.statusBar->showMessage(tr("capture ok"));
}

//************************************
// Method:    saveImage
// FullName:  AttendanceClient::saveImage
// Access:    private 
// Returns:   void
// Qualifier:
//************************************
void AttendanceClient::saveImage()
{
	QString fileName = QFileDialog::getSaveFileName(this, tr("save file"), ".", tr("jpg file(*.jpg)"));

	if (fileName.isEmpty())
	{
		ui.statusBar->showMessage(tr("save failed!"));
		return;
	}
	qDebug() << fileName;
	const QPixmap *pixmap = ui.ImageCapture->pixmap();
	if (pixmap)
	{
		pixmap->save(fileName);
		ui.statusBar->showMessage(tr("save ok!"));
	}

}
