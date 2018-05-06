#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "fdengine.h"
#include "frengine.h"
#include "ftengine.h"
#include "ageestimationengine.h"
#include "ImageLabel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    /* 获取图片 */
    void getImage();

    /* 设置ImageLabel的位置 */
    void setLabelLocation();

private slots:
    void on_btnOpenImage_clicked();

    void on_btnFaceDetect_clicked();

    void on_btnAgeEstimation_clicked();

    void on_btnGenderEstimation_clicked();



private:
    Ui::MainWindow *ui;

    QString m_imageSrcFilePath;    // 获取图片文件的绝对路径

    QString m_bmpPath;          // BMP文件的路径

    QImage *m_image;            // 图片对象

    FDEngine *m_fdEngine;       // 人脸检测引擎

    FREngine *m_frEngine;       // 人脸识别引擎

    FTEngine *m_ftEngine;       // 人脸追踪引擎

    AgeEstimationEngine *m_ageEstimationEngine; // 年龄估计引擎 

};

#endif // MAINWINDOW_H
