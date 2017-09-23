/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created: Thu 15. Dec 18:50:43 2016
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>
#include <QtGui/QSplitter>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QHBoxLayout *horizontalLayout_18;
    QVBoxLayout *verticalLayout_2;
    QPushButton *commonButton;
    QHBoxLayout *horizontalLayout_3;
    QLabel *HP_label;
    QSpinBox *spinBoxHP;
    QHBoxLayout *horizontalLayout_4;
    QLabel *MP_label;
    QSpinBox *spinBoxMP;
    QHBoxLayout *horizontalLayout_5;
    QLabel *DMG_label;
    QDoubleSpinBox *doubleSpinBoxDMG;
    QHBoxLayout *horizontalLayout_6;
    QLabel *ARM_label;
    QDoubleSpinBox *doubleSpinBoxARM;
    QLabel *name_label;
    QLineEdit *lineEditName;
    QSplitter *splitter;
    QLabel *spec_label;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *warriorButton;
    QRadioButton *mageButton;
    QRadioButton *rogueButton;
    QPushButton *addButton;
    QVBoxLayout *verticalLayout_4;
    QPushButton *commonButton_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *HP_label_3;
    QSpinBox *spinBoxHP_3;
    QHBoxLayout *horizontalLayout_8;
    QLabel *MP_label_3;
    QSpinBox *spinBoxMP_3;
    QHBoxLayout *horizontalLayout_9;
    QLabel *DMG_label_3;
    QDoubleSpinBox *doubleSpinBoxDMG_3;
    QHBoxLayout *horizontalLayout_10;
    QLabel *ARM_label_3;
    QDoubleSpinBox *doubleSpinBoxARM_3;
    QHBoxLayout *horizontalLayout_11;
    QLabel *AGRO_label;
    QSpinBox *spinBoxAGRO;
    QLabel *name_label_2;
    QLineEdit *lineEditName_2;
    QSplitter *splitter_2;
    QLabel *spec_label_2;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_5;
    QRadioButton *warriorButton_2;
    QRadioButton *mageButton_2;
    QRadioButton *rogueButton_2;
    QPushButton *addButton_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label;
    QSpinBox *spinBoxEditElement;
    QHBoxLayout *horizontalLayout_13;
    QLineEdit *lineEdit;
    QPushButton *editName;
    QSpinBox *spinBox_2;
    QPushButton *editHP;
    QHBoxLayout *horizontalLayout_14;
    QHBoxLayout *horizontalLayout_16;
    QComboBox *type1ofedit;
    QSpinBox *spinBox;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_17;
    QComboBox *type2ofedit;
    QSpinBox *spinBox2;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_2;
    QLabel *label_num_element;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *updateButton;
    QPushButton *saveButton;
    QPushButton *loadButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *deleteButton;
    QSpinBox *spinBoxElement;
    QPushButton *pushButton_3;
    QPushButton *exitButton;
    QProgressBar *progressBar;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(717, 487);
        Dialog->setMaximumSize(QSize(1600, 1200));
        QPalette palette;
        QBrush brush(QColor(48, 51, 88, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(188, 191, 223, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(215, 218, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(164, 166, 194, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(46, 49, 85, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush2);
        QBrush brush5(QColor(47, 50, 86, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette.setBrush(QPalette::Active, QPalette::Base, brush2);
        QBrush brush6(QColor(172, 174, 204, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush6);
        QBrush brush7(QColor(139, 145, 255, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush7);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush2);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Active, QPalette::NoRole, brush2);
        QBrush brush8(QColor(40, 43, 74, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::NoRole, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush8);
        QBrush brush9(QColor(120, 120, 120, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush9);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush9);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush9);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        QBrush brush10(QColor(51, 153, 255, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush10);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::NoRole, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush8);
        Dialog->setPalette(palette);
        QIcon icon;
        icon.addFile(QString::fromUtf8("img/Liandry's_Torment_item.png"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog->setWindowIcon(icon);
        Dialog->setAutoFillBackground(true);
        Dialog->setSizeGripEnabled(true);
        horizontalLayout_18 = new QHBoxLayout(Dialog);
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        commonButton = new QPushButton(Dialog);
        commonButton->setObjectName(QString::fromUtf8("commonButton"));

        verticalLayout_2->addWidget(commonButton);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        HP_label = new QLabel(Dialog);
        HP_label->setObjectName(QString::fromUtf8("HP_label"));
        QFont font;
        font.setPointSize(8);
        font.setBold(true);
        font.setUnderline(false);
        font.setWeight(75);
        HP_label->setFont(font);

        horizontalLayout_3->addWidget(HP_label);

        spinBoxHP = new QSpinBox(Dialog);
        spinBoxHP->setObjectName(QString::fromUtf8("spinBoxHP"));
        spinBoxHP->setMinimum(1);
        spinBoxHP->setMaximum(1000000);
        spinBoxHP->setSingleStep(100);

        horizontalLayout_3->addWidget(spinBoxHP);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        MP_label = new QLabel(Dialog);
        MP_label->setObjectName(QString::fromUtf8("MP_label"));
        MP_label->setFont(font);

        horizontalLayout_4->addWidget(MP_label);

        spinBoxMP = new QSpinBox(Dialog);
        spinBoxMP->setObjectName(QString::fromUtf8("spinBoxMP"));
        spinBoxMP->setMaximum(1000000);
        spinBoxMP->setSingleStep(100);

        horizontalLayout_4->addWidget(spinBoxMP);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        DMG_label = new QLabel(Dialog);
        DMG_label->setObjectName(QString::fromUtf8("DMG_label"));
        DMG_label->setFont(font);

        horizontalLayout_5->addWidget(DMG_label);

        doubleSpinBoxDMG = new QDoubleSpinBox(Dialog);
        doubleSpinBoxDMG->setObjectName(QString::fromUtf8("doubleSpinBoxDMG"));
        doubleSpinBoxDMG->setMaximum(500000);
        doubleSpinBoxDMG->setSingleStep(100);

        horizontalLayout_5->addWidget(doubleSpinBoxDMG);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        ARM_label = new QLabel(Dialog);
        ARM_label->setObjectName(QString::fromUtf8("ARM_label"));
        ARM_label->setFont(font);

        horizontalLayout_6->addWidget(ARM_label);

        doubleSpinBoxARM = new QDoubleSpinBox(Dialog);
        doubleSpinBoxARM->setObjectName(QString::fromUtf8("doubleSpinBoxARM"));
        doubleSpinBoxARM->setMaximum(500000);
        doubleSpinBoxARM->setSingleStep(100);

        horizontalLayout_6->addWidget(doubleSpinBoxARM);


        verticalLayout_2->addLayout(horizontalLayout_6);

        name_label = new QLabel(Dialog);
        name_label->setObjectName(QString::fromUtf8("name_label"));
        name_label->setFont(font);

        verticalLayout_2->addWidget(name_label);

        lineEditName = new QLineEdit(Dialog);
        lineEditName->setObjectName(QString::fromUtf8("lineEditName"));

        verticalLayout_2->addWidget(lineEditName);

        splitter = new QSplitter(Dialog);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        spec_label = new QLabel(splitter);
        spec_label->setObjectName(QString::fromUtf8("spec_label"));
        spec_label->setFont(font);
        splitter->addWidget(spec_label);
        groupBox = new QGroupBox(splitter);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        warriorButton = new QRadioButton(groupBox);
        warriorButton->setObjectName(QString::fromUtf8("warriorButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("img/warrior.png"), QSize(), QIcon::Normal, QIcon::Off);
        warriorButton->setIcon(icon1);
        warriorButton->setIconSize(QSize(24, 24));
        warriorButton->setChecked(true);

        verticalLayout->addWidget(warriorButton);

        mageButton = new QRadioButton(groupBox);
        mageButton->setObjectName(QString::fromUtf8("mageButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("img/mage.png"), QSize(), QIcon::Normal, QIcon::Off);
        mageButton->setIcon(icon2);
        mageButton->setIconSize(QSize(24, 24));
        mageButton->setChecked(false);

        verticalLayout->addWidget(mageButton);

        rogueButton = new QRadioButton(groupBox);
        rogueButton->setObjectName(QString::fromUtf8("rogueButton"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("img/rogue.png"), QSize(), QIcon::Normal, QIcon::Off);
        rogueButton->setIcon(icon3);
        rogueButton->setIconSize(QSize(24, 24));

        verticalLayout->addWidget(rogueButton);

        splitter->addWidget(groupBox);

        verticalLayout_2->addWidget(splitter);

        addButton = new QPushButton(Dialog);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        verticalLayout_2->addWidget(addButton);


        horizontalLayout_18->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        commonButton_2 = new QPushButton(Dialog);
        commonButton_2->setObjectName(QString::fromUtf8("commonButton_2"));

        verticalLayout_4->addWidget(commonButton_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        HP_label_3 = new QLabel(Dialog);
        HP_label_3->setObjectName(QString::fromUtf8("HP_label_3"));
        HP_label_3->setFont(font);

        horizontalLayout_7->addWidget(HP_label_3);

        spinBoxHP_3 = new QSpinBox(Dialog);
        spinBoxHP_3->setObjectName(QString::fromUtf8("spinBoxHP_3"));
        spinBoxHP_3->setMinimum(1);
        spinBoxHP_3->setMaximum(1000000);
        spinBoxHP_3->setSingleStep(100);

        horizontalLayout_7->addWidget(spinBoxHP_3);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        MP_label_3 = new QLabel(Dialog);
        MP_label_3->setObjectName(QString::fromUtf8("MP_label_3"));
        MP_label_3->setFont(font);

        horizontalLayout_8->addWidget(MP_label_3);

        spinBoxMP_3 = new QSpinBox(Dialog);
        spinBoxMP_3->setObjectName(QString::fromUtf8("spinBoxMP_3"));
        spinBoxMP_3->setMaximum(1000000);
        spinBoxMP_3->setSingleStep(100);

        horizontalLayout_8->addWidget(spinBoxMP_3);


        verticalLayout_4->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        DMG_label_3 = new QLabel(Dialog);
        DMG_label_3->setObjectName(QString::fromUtf8("DMG_label_3"));
        DMG_label_3->setFont(font);

        horizontalLayout_9->addWidget(DMG_label_3);

        doubleSpinBoxDMG_3 = new QDoubleSpinBox(Dialog);
        doubleSpinBoxDMG_3->setObjectName(QString::fromUtf8("doubleSpinBoxDMG_3"));
        doubleSpinBoxDMG_3->setMaximum(500000);
        doubleSpinBoxDMG_3->setSingleStep(100);

        horizontalLayout_9->addWidget(doubleSpinBoxDMG_3);


        verticalLayout_4->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        ARM_label_3 = new QLabel(Dialog);
        ARM_label_3->setObjectName(QString::fromUtf8("ARM_label_3"));
        ARM_label_3->setFont(font);

        horizontalLayout_10->addWidget(ARM_label_3);

        doubleSpinBoxARM_3 = new QDoubleSpinBox(Dialog);
        doubleSpinBoxARM_3->setObjectName(QString::fromUtf8("doubleSpinBoxARM_3"));
        doubleSpinBoxARM_3->setMaximum(500000);
        doubleSpinBoxARM_3->setSingleStep(100);

        horizontalLayout_10->addWidget(doubleSpinBoxARM_3);


        verticalLayout_4->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        AGRO_label = new QLabel(Dialog);
        AGRO_label->setObjectName(QString::fromUtf8("AGRO_label"));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        AGRO_label->setFont(font1);

        horizontalLayout_11->addWidget(AGRO_label);

        spinBoxAGRO = new QSpinBox(Dialog);
        spinBoxAGRO->setObjectName(QString::fromUtf8("spinBoxAGRO"));
        spinBoxAGRO->setMaximum(5);

        horizontalLayout_11->addWidget(spinBoxAGRO);


        verticalLayout_4->addLayout(horizontalLayout_11);

        name_label_2 = new QLabel(Dialog);
        name_label_2->setObjectName(QString::fromUtf8("name_label_2"));
        name_label_2->setFont(font);

        verticalLayout_4->addWidget(name_label_2);

        lineEditName_2 = new QLineEdit(Dialog);
        lineEditName_2->setObjectName(QString::fromUtf8("lineEditName_2"));

        verticalLayout_4->addWidget(lineEditName_2);

        splitter_2 = new QSplitter(Dialog);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        spec_label_2 = new QLabel(splitter_2);
        spec_label_2->setObjectName(QString::fromUtf8("spec_label_2"));
        spec_label_2->setFont(font);
        splitter_2->addWidget(spec_label_2);
        groupBox_2 = new QGroupBox(splitter_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setFlat(false);
        groupBox_2->setCheckable(false);
        verticalLayout_5 = new QVBoxLayout(groupBox_2);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        warriorButton_2 = new QRadioButton(groupBox_2);
        warriorButton_2->setObjectName(QString::fromUtf8("warriorButton_2"));
        warriorButton_2->setIcon(icon1);
        warriorButton_2->setIconSize(QSize(24, 24));
        warriorButton_2->setChecked(true);

        verticalLayout_5->addWidget(warriorButton_2);

        mageButton_2 = new QRadioButton(groupBox_2);
        mageButton_2->setObjectName(QString::fromUtf8("mageButton_2"));
        mageButton_2->setIcon(icon2);
        mageButton_2->setIconSize(QSize(24, 24));
        mageButton_2->setChecked(false);

        verticalLayout_5->addWidget(mageButton_2);

        rogueButton_2 = new QRadioButton(groupBox_2);
        rogueButton_2->setObjectName(QString::fromUtf8("rogueButton_2"));
        rogueButton_2->setIcon(icon3);
        rogueButton_2->setIconSize(QSize(24, 24));

        verticalLayout_5->addWidget(rogueButton_2);

        splitter_2->addWidget(groupBox_2);

        verticalLayout_4->addWidget(splitter_2);

        addButton_2 = new QPushButton(Dialog);
        addButton_2->setObjectName(QString::fromUtf8("addButton_2"));

        verticalLayout_4->addWidget(addButton_2);


        horizontalLayout_18->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);
        label->setFrameShape(QFrame::NoFrame);
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_12->addWidget(label);

        spinBoxEditElement = new QSpinBox(Dialog);
        spinBoxEditElement->setObjectName(QString::fromUtf8("spinBoxEditElement"));
        spinBoxEditElement->setMinimum(1);
        spinBoxEditElement->setMaximum(1);

        horizontalLayout_12->addWidget(spinBoxEditElement);


        verticalLayout_3->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        lineEdit = new QLineEdit(Dialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setAlignment(Qt::AlignCenter);

        horizontalLayout_13->addWidget(lineEdit);

        editName = new QPushButton(Dialog);
        editName->setObjectName(QString::fromUtf8("editName"));

        horizontalLayout_13->addWidget(editName);

        spinBox_2 = new QSpinBox(Dialog);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setAlignment(Qt::AlignCenter);
        spinBox_2->setMinimum(1);
        spinBox_2->setMaximum(1000000);
        spinBox_2->setSingleStep(100);
        spinBox_2->setValue(1);

        horizontalLayout_13->addWidget(spinBox_2);

        editHP = new QPushButton(Dialog);
        editHP->setObjectName(QString::fromUtf8("editHP"));

        horizontalLayout_13->addWidget(editHP);


        verticalLayout_3->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));

        verticalLayout_3->addLayout(horizontalLayout_14);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        type1ofedit = new QComboBox(Dialog);
        type1ofedit->setObjectName(QString::fromUtf8("type1ofedit"));

        horizontalLayout_16->addWidget(type1ofedit);

        spinBox = new QSpinBox(Dialog);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setAlignment(Qt::AlignCenter);
        spinBox->setMinimum(1);
        spinBox->setMaximum(1);
        spinBox->setSingleStep(1);

        horizontalLayout_16->addWidget(spinBox);

        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_16->addWidget(pushButton);


        verticalLayout_3->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        type2ofedit = new QComboBox(Dialog);
        type2ofedit->setObjectName(QString::fromUtf8("type2ofedit"));

        horizontalLayout_17->addWidget(type2ofedit);

        spinBox2 = new QSpinBox(Dialog);
        spinBox2->setObjectName(QString::fromUtf8("spinBox2"));
        spinBox2->setAlignment(Qt::AlignCenter);
        spinBox2->setMinimum(1);
        spinBox2->setMaximum(500000);
        spinBox2->setSingleStep(100);

        horizontalLayout_17->addWidget(spinBox2);

        pushButton_2 = new QPushButton(Dialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_17->addWidget(pushButton_2);


        verticalLayout_3->addLayout(horizontalLayout_17);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_15->addWidget(label_2);

        label_num_element = new QLabel(Dialog);
        label_num_element->setObjectName(QString::fromUtf8("label_num_element"));
        label_num_element->setFont(font1);
        label_num_element->setAlignment(Qt::AlignCenter);

        horizontalLayout_15->addWidget(label_num_element);


        verticalLayout_3->addLayout(horizontalLayout_15);

        textBrowser = new QTextBrowser(Dialog);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setMinimumSize(QSize(200, 0));

        verticalLayout_3->addWidget(textBrowser);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        updateButton = new QPushButton(Dialog);
        updateButton->setObjectName(QString::fromUtf8("updateButton"));
        QFont font2;
        font2.setItalic(false);
        font2.setUnderline(true);
        updateButton->setFont(font2);

        horizontalLayout_2->addWidget(updateButton);

        saveButton = new QPushButton(Dialog);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        QFont font3;
        font3.setUnderline(true);
        saveButton->setFont(font3);

        horizontalLayout_2->addWidget(saveButton);

        loadButton = new QPushButton(Dialog);
        loadButton->setObjectName(QString::fromUtf8("loadButton"));
        loadButton->setFont(font3);

        horizontalLayout_2->addWidget(loadButton);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        deleteButton = new QPushButton(Dialog);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        horizontalLayout->addWidget(deleteButton);

        spinBoxElement = new QSpinBox(Dialog);
        spinBoxElement->setObjectName(QString::fromUtf8("spinBoxElement"));
        spinBoxElement->setMinimum(1);
        spinBoxElement->setMaximum(1);

        horizontalLayout->addWidget(spinBoxElement);

        pushButton_3 = new QPushButton(Dialog);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);


        verticalLayout_3->addLayout(horizontalLayout);

        exitButton = new QPushButton(Dialog);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        QFont font4;
        font4.setBold(true);
        font4.setUnderline(false);
        font4.setWeight(75);
        exitButton->setFont(font4);

        verticalLayout_3->addWidget(exitButton);

        progressBar = new QProgressBar(Dialog);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setMaximum(100);
        progressBar->setValue(0);

        verticalLayout_3->addWidget(progressBar);


        horizontalLayout_18->addLayout(verticalLayout_3);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "List of GREAT NPC", 0, QApplication::UnicodeUTF8));
        commonButton->setText(QApplication::translate("Dialog", "Default NPC", 0, QApplication::UnicodeUTF8));
        HP_label->setText(QApplication::translate("Dialog", "HP:", 0, QApplication::UnicodeUTF8));
        MP_label->setText(QApplication::translate("Dialog", "MP:", 0, QApplication::UnicodeUTF8));
        DMG_label->setText(QApplication::translate("Dialog", "Damage:", 0, QApplication::UnicodeUTF8));
        ARM_label->setText(QApplication::translate("Dialog", "Armor:", 0, QApplication::UnicodeUTF8));
        name_label->setText(QApplication::translate("Dialog", "Name:", 0, QApplication::UnicodeUTF8));
        lineEditName->setText(QApplication::translate("Dialog", "Name of your NPC", 0, QApplication::UnicodeUTF8));
        spec_label->setText(QApplication::translate("Dialog", "Specialization:", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        warriorButton->setText(QApplication::translate("Dialog", "Warrior", 0, QApplication::UnicodeUTF8));
        mageButton->setText(QApplication::translate("Dialog", "Mage", 0, QApplication::UnicodeUTF8));
        rogueButton->setText(QApplication::translate("Dialog", "Rogue", 0, QApplication::UnicodeUTF8));
        addButton->setText(QApplication::translate("Dialog", "Add NPC", 0, QApplication::UnicodeUTF8));
        commonButton_2->setText(QApplication::translate("Dialog", "Default monster", 0, QApplication::UnicodeUTF8));
        HP_label_3->setText(QApplication::translate("Dialog", "HP:", 0, QApplication::UnicodeUTF8));
        MP_label_3->setText(QApplication::translate("Dialog", "MP:", 0, QApplication::UnicodeUTF8));
        DMG_label_3->setText(QApplication::translate("Dialog", "Damage:", 0, QApplication::UnicodeUTF8));
        ARM_label_3->setText(QApplication::translate("Dialog", "Armor:", 0, QApplication::UnicodeUTF8));
        AGRO_label->setText(QApplication::translate("Dialog", "Agression", 0, QApplication::UnicodeUTF8));
        name_label_2->setText(QApplication::translate("Dialog", "Name:", 0, QApplication::UnicodeUTF8));
        lineEditName_2->setText(QApplication::translate("Dialog", "Name of your monster", 0, QApplication::UnicodeUTF8));
        spec_label_2->setText(QApplication::translate("Dialog", "Specialization:", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QString());
        warriorButton_2->setText(QApplication::translate("Dialog", "Warrior", 0, QApplication::UnicodeUTF8));
        mageButton_2->setText(QApplication::translate("Dialog", "Mage", 0, QApplication::UnicodeUTF8));
        rogueButton_2->setText(QApplication::translate("Dialog", "Rogue", 0, QApplication::UnicodeUTF8));
        addButton_2->setText(QApplication::translate("Dialog", "Add Monster", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog", "Edit element #", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("Dialog", "New Name", 0, QApplication::UnicodeUTF8));
        editName->setText(QApplication::translate("Dialog", "Name", 0, QApplication::UnicodeUTF8));
        editHP->setText(QApplication::translate("Dialog", "HP", 0, QApplication::UnicodeUTF8));
        type1ofedit->clear();
        type1ofedit->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "+element #", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "- element #", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "> element #", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "< element #", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "== element #", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "!= element #", 0, QApplication::UnicodeUTF8)
        );
        pushButton->setText(QApplication::translate("Dialog", "OK", 0, QApplication::UnicodeUTF8));
        type2ofedit->clear();
        type2ofedit->insertItems(0, QStringList()
         << QApplication::translate("Dialog", "+", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "-", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "=", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "postfix ++", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "postfix --", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "++ prefix", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "-- prefix", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "save <<", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "load >>", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "(46, 56, 12, 1)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "bit >>", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "bit <<", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Dialog", "bool?", 0, QApplication::UnicodeUTF8)
        );
        pushButton_2->setText(QApplication::translate("Dialog", "OK", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Dialog", "Number of elements:", 0, QApplication::UnicodeUTF8));
        label_num_element->setText(QApplication::translate("Dialog", "0", 0, QApplication::UnicodeUTF8));
        textBrowser->setHtml(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">.</span></p>\n"
"<"
                        "p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">.</span></p>\n"
"<p sty"
                        "le=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">There will be the list. Press the button &quot;Refresh&quot;</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><"
                        "span style=\" font-size:8pt;\">.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span "
                        "style=\" font-size:8pt;\">.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        updateButton->setText(QApplication::translate("Dialog", "Refresh", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("Dialog", "Save", 0, QApplication::UnicodeUTF8));
        loadButton->setText(QApplication::translate("Dialog", "Load", 0, QApplication::UnicodeUTF8));
        deleteButton->setText(QApplication::translate("Dialog", "Delete element \342\204\226", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("Dialog", "Delete head(QThread)", 0, QApplication::UnicodeUTF8));
        exitButton->setText(QApplication::translate("Dialog", "EXIT", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
