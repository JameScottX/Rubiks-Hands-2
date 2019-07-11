/********************************************************************************
** Form generated from reading UI file 'magic.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_H
#define UI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Magic
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_15;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_f;
    QLabel *label_b;
    QSpacerItem *horizontalSpacer;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *comboBox_port;
    QPushButton *pushButton_connect;
    QTextBrowser *textBrowser_info;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton_clear;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_14;
    QVBoxLayout *verticalLayout_10;
    QCheckBox *checkBox;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label;
    QLineEdit *lE_F;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_2;
    QLineEdit *lE_R;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_3;
    QLineEdit *lE_B;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_4;
    QLineEdit *lE_L;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_7;
    QLineEdit *lE_U;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_8;
    QLineEdit *lE_D;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_13;
    QVBoxLayout *verticalLayout_12;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_18;
    QSpinBox *camera_f;
    QSpacerItem *horizontalSpacer_7;
    QSpinBox *camera_b;
    QHBoxLayout *horizontalLayout_19;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButton_4;
    QCheckBox *checkBox_2;
    QHBoxLayout *horizontalLayout_9;
    QGridLayout *gridLayout;
    QLabel *label_B;
    QLabel *label_R;
    QLabel *label_D;
    QLabel *label_U;
    QLabel *label_L;
    QLabel *label_F;
    QVBoxLayout *verticalLayout_6;
    QLCDNumber *lcdNumber;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_10;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_7;
    QLineEdit *lineEdit_get;
    QLineEdit *lineEdit_answer;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *Motor_Correction;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Magic)
    {
        if (Magic->objectName().isEmpty())
            Magic->setObjectName(QString::fromUtf8("Magic"));
        Magic->resize(1279, 908);
        centralWidget = new QWidget(Magic);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_15 = new QVBoxLayout(centralWidget);
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setContentsMargins(11, 11, 11, 11);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font;
        font.setFamily(QString::fromUtf8("BankGothic Lt BT"));
        font.setPointSize(9);
        font.setItalic(false);
        label_5->setFont(font);

        horizontalLayout_3->addWidget(label_5);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        horizontalLayout_3->addWidget(label_6);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_f = new QLabel(centralWidget);
        label_f->setObjectName(QString::fromUtf8("label_f"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_f->sizePolicy().hasHeightForWidth());
        label_f->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label_f);

        label_b = new QLabel(centralWidget);
        label_b->setObjectName(QString::fromUtf8("label_b"));
        sizePolicy.setHeightForWidth(label_b->sizePolicy().hasHeightForWidth());
        label_b->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label_b);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(18, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_5 = new QVBoxLayout(tab);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        comboBox_port = new QComboBox(tab);
        comboBox_port->setObjectName(QString::fromUtf8("comboBox_port"));

        horizontalLayout_5->addWidget(comboBox_port);

        pushButton_connect = new QPushButton(tab);
        pushButton_connect->setObjectName(QString::fromUtf8("pushButton_connect"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ebrima"));
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton_connect->setFont(font1);

        horizontalLayout_5->addWidget(pushButton_connect);


        verticalLayout_2->addLayout(horizontalLayout_5);

        textBrowser_info = new QTextBrowser(tab);
        textBrowser_info->setObjectName(QString::fromUtf8("textBrowser_info"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(textBrowser_info->sizePolicy().hasHeightForWidth());
        textBrowser_info->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(textBrowser_info);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_6 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_6);

        pushButton_clear = new QPushButton(tab);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton_clear->sizePolicy().hasHeightForWidth());
        pushButton_clear->setSizePolicy(sizePolicy3);
        QFont font2;
        font2.setBold(true);
        font2.setWeight(75);
        pushButton_clear->setFont(font2);

        horizontalLayout_8->addWidget(pushButton_clear);


        verticalLayout_2->addLayout(horizontalLayout_8);


        verticalLayout_5->addLayout(verticalLayout_2);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_14 = new QVBoxLayout(tab_2);
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setContentsMargins(11, 11, 11, 11);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        checkBox = new QCheckBox(tab_2);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        verticalLayout_10->addWidget(checkBox);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label = new QLabel(tab_2);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font3;
        font3.setPointSize(17);
        label->setFont(font3);

        horizontalLayout_12->addWidget(label);

        lE_F = new QLineEdit(tab_2);
        lE_F->setObjectName(QString::fromUtf8("lE_F"));
        lE_F->setFont(font3);

        horizontalLayout_12->addWidget(lE_F);


        verticalLayout_9->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font3);

        horizontalLayout_13->addWidget(label_2);

        lE_R = new QLineEdit(tab_2);
        lE_R->setObjectName(QString::fromUtf8("lE_R"));
        lE_R->setFont(font3);

        horizontalLayout_13->addWidget(lE_R);


        verticalLayout_9->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font3);

        horizontalLayout_14->addWidget(label_3);

        lE_B = new QLineEdit(tab_2);
        lE_B->setObjectName(QString::fromUtf8("lE_B"));
        lE_B->setFont(font3);

        horizontalLayout_14->addWidget(lE_B);


        verticalLayout_9->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font3);

        horizontalLayout_15->addWidget(label_4);

        lE_L = new QLineEdit(tab_2);
        lE_L->setObjectName(QString::fromUtf8("lE_L"));
        lE_L->setFont(font3);

        horizontalLayout_15->addWidget(lE_L);


        verticalLayout_9->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font3);

        horizontalLayout_16->addWidget(label_7);

        lE_U = new QLineEdit(tab_2);
        lE_U->setObjectName(QString::fromUtf8("lE_U"));
        lE_U->setFont(font3);

        horizontalLayout_16->addWidget(lE_U);


        verticalLayout_9->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font3);

        horizontalLayout_17->addWidget(label_8);

        lE_D = new QLineEdit(tab_2);
        lE_D->setObjectName(QString::fromUtf8("lE_D"));
        lE_D->setFont(font3);

        horizontalLayout_17->addWidget(lE_D);


        verticalLayout_9->addLayout(horizontalLayout_17);


        verticalLayout_10->addLayout(verticalLayout_9);


        verticalLayout_14->addLayout(verticalLayout_10);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_13 = new QVBoxLayout(tab_3);
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        camera_f = new QSpinBox(tab_3);
        camera_f->setObjectName(QString::fromUtf8("camera_f"));
        camera_f->setMaximum(2);
        camera_f->setValue(1);

        horizontalLayout_18->addWidget(camera_f);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_7);

        camera_b = new QSpinBox(tab_3);
        camera_b->setObjectName(QString::fromUtf8("camera_b"));
        camera_b->setMaximum(2);
        camera_b->setValue(2);

        horizontalLayout_18->addWidget(camera_b);


        verticalLayout_11->addLayout(horizontalLayout_18);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_8);

        pushButton_4 = new QPushButton(tab_3);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout_19->addWidget(pushButton_4);


        verticalLayout_11->addLayout(horizontalLayout_19);


        verticalLayout_12->addLayout(verticalLayout_11);

        checkBox_2 = new QCheckBox(tab_3);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(checkBox_2->sizePolicy().hasHeightForWidth());
        checkBox_2->setSizePolicy(sizePolicy4);
        checkBox_2->setChecked(true);

        verticalLayout_12->addWidget(checkBox_2);


        verticalLayout_13->addLayout(verticalLayout_12);

        tabWidget->addTab(tab_3, QString());

        horizontalLayout_2->addWidget(tabWidget);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_B = new QLabel(centralWidget);
        label_B->setObjectName(QString::fromUtf8("label_B"));
        label_B->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(label_B, 1, 3, 1, 1);

        label_R = new QLabel(centralWidget);
        label_R->setObjectName(QString::fromUtf8("label_R"));
        label_R->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(label_R, 2, 1, 1, 1);

        label_D = new QLabel(centralWidget);
        label_D->setObjectName(QString::fromUtf8("label_D"));
        sizePolicy1.setHeightForWidth(label_D->sizePolicy().hasHeightForWidth());
        label_D->setSizePolicy(sizePolicy1);
        label_D->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(label_D, 1, 0, 1, 1);

        label_U = new QLabel(centralWidget);
        label_U->setObjectName(QString::fromUtf8("label_U"));
        label_U->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(label_U, 1, 2, 1, 1);

        label_L = new QLabel(centralWidget);
        label_L->setObjectName(QString::fromUtf8("label_L"));
        label_L->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(label_L, 0, 1, 1, 1);

        label_F = new QLabel(centralWidget);
        label_F->setObjectName(QString::fromUtf8("label_F"));
        label_F->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(label_F, 1, 1, 1, 1);


        horizontalLayout_9->addLayout(gridLayout);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        sizePolicy.setHeightForWidth(lcdNumber->sizePolicy().hasHeightForWidth());
        lcdNumber->setSizePolicy(sizePolicy);

        verticalLayout_6->addWidget(lcdNumber);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));

        verticalLayout_8->addLayout(horizontalLayout_10);


        verticalLayout_6->addLayout(verticalLayout_8);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        lineEdit_get = new QLineEdit(centralWidget);
        lineEdit_get->setObjectName(QString::fromUtf8("lineEdit_get"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(lineEdit_get->sizePolicy().hasHeightForWidth());
        lineEdit_get->setSizePolicy(sizePolicy5);
        lineEdit_get->setMinimumSize(QSize(300, 0));
        lineEdit_get->setMaximumSize(QSize(16777215, 16777215));
        lineEdit_get->setReadOnly(true);

        verticalLayout_7->addWidget(lineEdit_get);

        lineEdit_answer = new QLineEdit(centralWidget);
        lineEdit_answer->setObjectName(QString::fromUtf8("lineEdit_answer"));
        QSizePolicy sizePolicy6(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(lineEdit_answer->sizePolicy().hasHeightForWidth());
        lineEdit_answer->setSizePolicy(sizePolicy6);
        lineEdit_answer->setMaximumSize(QSize(222222, 16777215));
        lineEdit_answer->setReadOnly(true);

        verticalLayout_7->addWidget(lineEdit_answer);


        horizontalLayout_11->addLayout(verticalLayout_7);


        verticalLayout_6->addLayout(horizontalLayout_11);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));

        verticalLayout_6->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);

        Motor_Correction = new QPushButton(centralWidget);
        Motor_Correction->setObjectName(QString::fromUtf8("Motor_Correction"));

        horizontalLayout_6->addWidget(Motor_Correction);

        horizontalSpacer_9 = new QSpacerItem(50, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_9);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(170, 0));

        horizontalLayout_6->addWidget(pushButton);

        horizontalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);


        verticalLayout_6->addLayout(horizontalLayout_6);


        horizontalLayout_9->addLayout(verticalLayout_6);


        verticalLayout_4->addLayout(horizontalLayout_9);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));

        horizontalLayout_7->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout_7);


        verticalLayout_15->addLayout(verticalLayout_4);

        Magic->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Magic);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1279, 26));
        Magic->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Magic);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Magic->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Magic);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Magic->setStatusBar(statusBar);

        retranslateUi(Magic);
        QObject::connect(pushButton_connect, SIGNAL(pressed()), Magic, SLOT(serial_connect()));
        QObject::connect(pushButton_clear, SIGNAL(released()), Magic, SLOT(info_clear()));
        QObject::connect(checkBox, SIGNAL(stateChanged(int)), Magic, SLOT(useHandIn()));
        QObject::connect(checkBox_2, SIGNAL(stateChanged(int)), Magic, SLOT(showParams()));
        QObject::connect(pushButton_4, SIGNAL(released()), Magic, SLOT(OpenCamera()));
        QObject::connect(Motor_Correction, SIGNAL(pressed()), Magic, SLOT(Motor_PosCorrection()));
        QObject::connect(pushButton, SIGNAL(released()), Magic, SLOT(start_func_all()));

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Magic);
    } // setupUi

    void retranslateUi(QMainWindow *Magic)
    {
        Magic->setWindowTitle(QApplication::translate("Magic", "Magic", nullptr));
        label_5->setText(QApplication::translate("Magic", "Camera one", nullptr));
        label_6->setText(QApplication::translate("Magic", "Camera two", nullptr));
        label_f->setText(QString());
        label_b->setText(QString());
        pushButton_connect->setText(QApplication::translate("Magic", "Connect", nullptr));
        pushButton_clear->setText(QApplication::translate("Magic", "Clear", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Magic", "Serial", nullptr));
        checkBox->setText(QApplication::translate("Magic", "HandIN", nullptr));
        label->setText(QApplication::translate("Magic", "F", nullptr));
        label_2->setText(QApplication::translate("Magic", "R", nullptr));
        label_3->setText(QApplication::translate("Magic", "B", nullptr));
        label_4->setText(QApplication::translate("Magic", "L", nullptr));
        label_7->setText(QApplication::translate("Magic", "U", nullptr));
        label_8->setText(QApplication::translate("Magic", "D", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Magic", "ColorIn", nullptr));
        pushButton_4->setText(QApplication::translate("Magic", "OpenCamera", nullptr));
        checkBox_2->setText(QApplication::translate("Magic", "ShowParams", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Magic", "Set", nullptr));
        label_B->setText(QString());
        label_R->setText(QString());
        label_D->setText(QString());
        label_U->setText(QString());
        label_L->setText(QString());
        label_F->setText(QString());
        Motor_Correction->setText(QApplication::translate("Magic", "Motor_Correction", nullptr));
        pushButton->setText(QApplication::translate("Magic", "Start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Magic: public Ui_Magic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_H
