#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QVector>
#include <QRect>
#include <QDir>
#include <QRegularExpression>
#include "miscellaneous.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), m_imageSrcFilePath()
{
    ui->setupUi(this);

    this->m_image = nullptr;
	this->ui->imageLabel->setText("");
    this->m_fdEngine = new FDEngine(); // 实例化FD引擎
    qDebug() << "fd init " << this->m_fdEngine->init(); // 初始化引擎

}

MainWindow::~MainWindow()
{
    delete ui;

    delete m_fdEngine;

    if (this->m_image != nullptr)
        delete m_image;
}

void MainWindow::getImage()
{
    m_image = new QImage(this->m_imageSrcFilePath);    // 先构建原图QImage对象

    QRegularExpression regEx("([^/]+)\\..+");
    QRegularExpressionMatch matchStr =  regEx.match(this->m_imageSrcFilePath);

    QString tmpFilePath("./tmp");   // 构建将原图转换为BMP格式路径  ./tmp/imagefile.tmp
    QDir *dir = new QDir();
    dir->mkdir(tmpFilePath);
    tmpFilePath = tmpFilePath + "/" + matchStr.captured(0) + ".tmp";   // 临时BMP图片路径
    m_image->save(tmpFilePath, "BMP");  // 将原图转换为bmp
    m_image->load(tmpFilePath, "BMP");  // image对象再次load

    m_bmpPath = tmpFilePath;          //
    //dir->remove(tmpFilePath);       // 删除临时bmp图片
    delete dir;
    dir = nullptr;
}

void MainWindow::setLabelLocation()
{
    this->ui->imageLabel->setPixmap(QPixmap::fromImage(*(this->m_image)));
    this->ui->imageLabel->resize(m_image->width(), m_image->height());
    this->show();
}

/* 打开图片文件 */
void MainWindow::on_btnOpenImage_clicked()
{
    QFileDialog *fileDialog = new QFileDialog(this);

    fileDialog->setWindowTitle(tr("打开图片文件"));
    fileDialog->setDirectory("");
    fileDialog->setFilter(QDir::Files);
    fileDialog->setNameFilter(("图片(*.jpg *.bmp *.png)"));

    if (fileDialog->exec() == QDialog::Accepted)
    {
        m_imageSrcFilePath = fileDialog->selectedFiles()[0]; // 获取图片文件的绝对路径
        this->getImage();
        this->setLabelLocation();
    }
}

/* 侦测人脸并画出人脸位置 */
void MainWindow::on_btnFaceDetect_clicked()
{
    if (m_imageSrcFilePath.isEmpty())  // 未打开文件先点击button
    {
        QMessageBox::information(this, "warnning", "请选择一张图片");
    }
    else
    {
        ASVLOFFSCREEN offInput = {0};
        offInput.u32PixelArrayFormat = ASVL_PAF_RGB24_B8G8R8;
        offInput.ppu8Plane[0] = nullptr;
        MISCELLANEOUS::readBmp(this->m_bmpPath, (unsigned char **)&offInput.ppu8Plane[0],
                &offInput.i32Width, &offInput.i32Height);
        offInput.pi32Pitch[0] = offInput.i32Width * 3;

        LPAFD_FSDK_FACERES pFaceRes = nullptr;
        qDebug() << "fd detect " << this->m_fdEngine->faceDetection(&offInput, &pFaceRes);


        if (pFaceRes == nullptr)
        {
            qDebug() << "failed";
            free(offInput.ppu8Plane[0]);
            offInput.ppu8Plane[0] = nullptr;

            return ;
        }
        else if (pFaceRes->nFace == 0)
        {
            QMessageBox::information(this, "侦测结果", "没有侦测到人脸");
            free(offInput.ppu8Plane[0]);
            offInput.ppu8Plane[0] = nullptr;

            return ;
        }

		// 获取人脸位置信息
        QVector<QRect> rectangles;
        for (int i = 0; i < pFaceRes->nFace; ++i)
        {
            rectangles.insert(rectangles.end(), QRect(pFaceRes->rcFace[i].left, pFaceRes->rcFace[i].top,
                                                      pFaceRes->rcFace[i].bottom - pFaceRes->rcFace[i].top,
                                                      pFaceRes->rcFace[i].right - pFaceRes->rcFace[i].left));
        }

        this->ui->imageLabel->setRectangles(rectangles);
        this->ui->imageLabel->repaint();

        free(offInput.ppu8Plane[0]);
        offInput.ppu8Plane[0] = nullptr;

    }
}

/* 估计年龄并画出 */
void MainWindow::on_btnAgeEstimation_clicked()
{
    if (m_imageSrcFilePath.isEmpty())  // 未打开文件先点击button
    {
        QMessageBox::information(this, "warnning", "请选择一张图片");
    }
    else
    {

    }
}

/* 估计性别并画出 */
void MainWindow::on_btnGenderEstimation_clicked()
{
    if (m_imageSrcFilePath.isEmpty())  // 未打开文件先点击button
    {
        QMessageBox::information(this, "warnning", "请选择一张图片");
    }
    else
    {

    }
}
