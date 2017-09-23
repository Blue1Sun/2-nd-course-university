/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun 11. Dec 19:09:56 2016
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *Title;
    QLabel *Welcome;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QLabel *textYourName;
    QSpacerItem *horizontalSpacer;
    QLineEdit *playerName;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_4;
    QPushButton *startGame;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *Records;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *Exit;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(371, 308);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(185, 185, 185, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        MainWindow->setPalette(palette);
        QIcon icon;
        icon.addFile(QString::fromUtf8("Liandry's_Torment_item.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        Title = new QLabel(centralWidget);
        Title->setObjectName(QString::fromUtf8("Title"));
        QFont font;
        font.setFamily(QString::fromUtf8("System"));
        font.setPointSize(25);
        Title->setFont(font);
        Title->setLayoutDirection(Qt::LeftToRight);
        Title->setTextFormat(Qt::AutoText);
        Title->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(Title);

        Welcome = new QLabel(centralWidget);
        Welcome->setObjectName(QString::fromUtf8("Welcome"));
        Welcome->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(Welcome);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        textYourName = new QLabel(centralWidget);
        textYourName->setObjectName(QString::fromUtf8("textYourName"));

        horizontalLayout->addWidget(textYourName);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        playerName = new QLineEdit(centralWidget);
        playerName->setObjectName(QString::fromUtf8("playerName"));

        horizontalLayout->addWidget(playerName);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_2);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_3);


        verticalLayout_2->addLayout(verticalLayout_3);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        startGame = new QPushButton(centralWidget);
        startGame->setObjectName(QString::fromUtf8("startGame"));

        verticalLayout_2->addWidget(startGame);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        Records = new QPushButton(centralWidget);
        Records->setObjectName(QString::fromUtf8("Records"));

        horizontalLayout_2->addWidget(Records);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        Exit = new QPushButton(centralWidget);
        Exit->setObjectName(QString::fromUtf8("Exit"));

        horizontalLayout_2->addWidget(Exit);


        verticalLayout_2->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(Exit, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Roguelike", 0, QApplication::UnicodeUTF8));
        Title->setText(QApplication::translate("MainWindow", "ROGUELIKE", 0, QApplication::UnicodeUTF8));
        Welcome->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\321\200\320\276 \320\277\320\276\320\266\320\260\320\273\320\276\320\262\320\260\321\202\321\214!", 0, QApplication::UnicodeUTF8));
        textYourName->setText(QApplication::translate("MainWindow", "\320\222\320\260\321\210\320\265 \320\270\320\274\321\217:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "\320\222\320\260\321\210 \321\201\320\270\320\274\320\262\320\276\320\273 = @. \320\230\320\263\321\200\320\260 \320\277\320\276\321\210\320\260\320\263\320\276\320\262\320\260\321\217", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\261\320\270\321\200\320\260\320\271\321\202\320\265 \320\262\320\265\321\211\320\270(A, T), \321\203\320\261\320\265\320\263\320\260\320\271\321\202\320\265 \320\276\321\202 \320\262\321\200\320\260\320\263\320\276\320\262($), \320\276\320\261\321\205\320\276\320\264\320\270\321\202\320\265 \321\201\321\202\320\265\320\275\321\213(#)", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "\320\222\321\201\320\265 \320\267\320\260\320\272\320\276\320\275\321\207\320\270\321\202\321\201\321\217 \320\275\320\260 \321\201\320\274\320\265\321\200\321\202\320\270 \320\222\320\260\321\210\320\265\320\263\320\276 \320\277\320\265\321\200\321\201\320\276\320\275\320\260\320\266\320\260", 0, QApplication::UnicodeUTF8));
        startGame->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\321\202\321\214 \320\270\320\263\321\200\321\203!", 0, QApplication::UnicodeUTF8));
        Records->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\272\320\276\321\200\320\264\321\213", 0, QApplication::UnicodeUTF8));
        Exit->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
