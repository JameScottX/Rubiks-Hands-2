/********************************************************************************
** Form generated from reading UI file 'cameraset.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERASET_H
#define UI_CAMERASET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CameraSet
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *label_6;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSlider *hS_exposure;
    QSpinBox *sB_exposure;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSlider *hS_brightness;
    QSpinBox *sB_brightness;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSlider *hS_contrast;
    QSpinBox *sB_contrast;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSlider *hS_saturation;
    QSpinBox *sB_saturation;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QSlider *hS_hue;
    QSpinBox *sB_hue;

    void setupUi(QWidget *CameraSet)
    {
        if (CameraSet->objectName().isEmpty())
            CameraSet->setObjectName(QString::fromUtf8("CameraSet"));
        CameraSet->resize(724, 382);
        QFont font;
        font.setFamily(QString::fromUtf8("BankGothic Lt BT"));
        CameraSet->setFont(font);
        verticalLayout_2 = new QVBoxLayout(CameraSet);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_6 = new QLabel(CameraSet);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_6);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(CameraSet);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        hS_exposure = new QSlider(CameraSet);
        hS_exposure->setObjectName(QString::fromUtf8("hS_exposure"));
        hS_exposure->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(hS_exposure);

        sB_exposure = new QSpinBox(CameraSet);
        sB_exposure->setObjectName(QString::fromUtf8("sB_exposure"));
        sB_exposure->setMinimum(-1000);
        sB_exposure->setMaximum(1000);
        sB_exposure->setValue(-10);

        horizontalLayout->addWidget(sB_exposure);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(CameraSet);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        hS_brightness = new QSlider(CameraSet);
        hS_brightness->setObjectName(QString::fromUtf8("hS_brightness"));
        hS_brightness->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(hS_brightness);

        sB_brightness = new QSpinBox(CameraSet);
        sB_brightness->setObjectName(QString::fromUtf8("sB_brightness"));
        sB_brightness->setMinimum(-1000);
        sB_brightness->setMaximum(1000);
        sB_brightness->setValue(-10);

        horizontalLayout_2->addWidget(sB_brightness);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(CameraSet);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        hS_contrast = new QSlider(CameraSet);
        hS_contrast->setObjectName(QString::fromUtf8("hS_contrast"));
        hS_contrast->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(hS_contrast);

        sB_contrast = new QSpinBox(CameraSet);
        sB_contrast->setObjectName(QString::fromUtf8("sB_contrast"));
        sB_contrast->setMinimum(-1000);
        sB_contrast->setMaximum(1000);
        sB_contrast->setValue(-10);

        horizontalLayout_3->addWidget(sB_contrast);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(CameraSet);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        hS_saturation = new QSlider(CameraSet);
        hS_saturation->setObjectName(QString::fromUtf8("hS_saturation"));
        hS_saturation->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(hS_saturation);

        sB_saturation = new QSpinBox(CameraSet);
        sB_saturation->setObjectName(QString::fromUtf8("sB_saturation"));
        sB_saturation->setMinimum(-1000);
        sB_saturation->setMaximum(1000);
        sB_saturation->setValue(-10);

        horizontalLayout_4->addWidget(sB_saturation);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(CameraSet);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_5->addWidget(label_5);

        hS_hue = new QSlider(CameraSet);
        hS_hue->setObjectName(QString::fromUtf8("hS_hue"));
        hS_hue->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(hS_hue);

        sB_hue = new QSpinBox(CameraSet);
        sB_hue->setObjectName(QString::fromUtf8("sB_hue"));
        sB_hue->setMinimum(-1000);
        sB_hue->setMaximum(1000);
        sB_hue->setValue(-10);

        horizontalLayout_5->addWidget(sB_hue);


        verticalLayout->addLayout(horizontalLayout_5);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(CameraSet);

        QMetaObject::connectSlotsByName(CameraSet);
    } // setupUi

    void retranslateUi(QWidget *CameraSet)
    {
        CameraSet->setWindowTitle(QApplication::translate("CameraSet", "Form", nullptr));
        label_6->setText(QApplication::translate("CameraSet", "Camera Params Setting", nullptr));
        label->setText(QApplication::translate("CameraSet", "EXPOSURE", nullptr));
        label_2->setText(QApplication::translate("CameraSet", "BRIGHTNESS", nullptr));
        label_3->setText(QApplication::translate("CameraSet", "CONTRAST", nullptr));
        label_4->setText(QApplication::translate("CameraSet", "SATURATION", nullptr));
        label_5->setText(QApplication::translate("CameraSet", "PROP_HUE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CameraSet: public Ui_CameraSet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERASET_H
