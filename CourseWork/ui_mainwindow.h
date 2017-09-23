/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon 8. May 00:45:38 2017
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
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *loadfrom;
    QAction *saveto;
    QAction *help;
    QAction *aboutprogram;
    QAction *quit;
    QWidget *main_container;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *upper_line;
    QSpacerItem *horizontalSpacer;
    QLabel *title;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *input_output;
    QSpacerItem *verticalSpacer;
    QPlainTextEdit *convert_input;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QTextBrowser *convert_output;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *under_browsers_line;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *select_allButton;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *lower_line;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *convertButton;
    QSpacerItem *horizontalSpacer_4;
    QMenuBar *menuBar;
    QMenu *file;
    QMenu *reference;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(750, 500);
        MainWindow->setMinimumSize(QSize(750, 500));
        MainWindow->setMaximumSize(QSize(1620, 780));
        QIcon icon;
        icon.addFile(QString::fromUtf8("Images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        loadfrom = new QAction(MainWindow);
        loadfrom->setObjectName(QString::fromUtf8("loadfrom"));
        saveto = new QAction(MainWindow);
        saveto->setObjectName(QString::fromUtf8("saveto"));
        help = new QAction(MainWindow);
        help->setObjectName(QString::fromUtf8("help"));
        aboutprogram = new QAction(MainWindow);
        aboutprogram->setObjectName(QString::fromUtf8("aboutprogram"));
        quit = new QAction(MainWindow);
        quit->setObjectName(QString::fromUtf8("quit"));
        main_container = new QWidget(MainWindow);
        main_container->setObjectName(QString::fromUtf8("main_container"));
        verticalLayout = new QVBoxLayout(main_container);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        upper_line = new QHBoxLayout();
        upper_line->setSpacing(6);
        upper_line->setObjectName(QString::fromUtf8("upper_line"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        upper_line->addItem(horizontalSpacer);

        title = new QLabel(main_container);
        title->setObjectName(QString::fromUtf8("title"));
        QFont font;
        font.setPointSize(18);
        title->setFont(font);

        upper_line->addWidget(title);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        upper_line->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(upper_line);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_6);

        input_output = new QHBoxLayout();
        input_output->setSpacing(6);
        input_output->setObjectName(QString::fromUtf8("input_output"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        input_output->addItem(verticalSpacer);

        convert_input = new QPlainTextEdit(main_container);
        convert_input->setObjectName(QString::fromUtf8("convert_input"));

        input_output->addWidget(convert_input);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        input_output->addItem(verticalSpacer_3);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        input_output->addItem(verticalSpacer_4);

        convert_output = new QTextBrowser(main_container);
        convert_output->setObjectName(QString::fromUtf8("convert_output"));

        input_output->addWidget(convert_output);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        input_output->addItem(verticalSpacer_2);


        verticalLayout->addLayout(input_output);

        under_browsers_line = new QHBoxLayout();
        under_browsers_line->setSpacing(6);
        under_browsers_line->setObjectName(QString::fromUtf8("under_browsers_line"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        under_browsers_line->addItem(horizontalSpacer_7);

        pushButton = new QPushButton(main_container);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        under_browsers_line->addWidget(pushButton);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        under_browsers_line->addItem(horizontalSpacer_9);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        under_browsers_line->addItem(horizontalSpacer_11);

        select_allButton = new QPushButton(main_container);
        select_allButton->setObjectName(QString::fromUtf8("select_allButton"));

        under_browsers_line->addWidget(select_allButton);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        under_browsers_line->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(under_browsers_line);

        lower_line = new QHBoxLayout();
        lower_line->setSpacing(6);
        lower_line->setObjectName(QString::fromUtf8("lower_line"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        lower_line->addItem(horizontalSpacer_3);

        convertButton = new QPushButton(main_container);
        convertButton->setObjectName(QString::fromUtf8("convertButton"));

        lower_line->addWidget(convertButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        lower_line->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(lower_line);

        MainWindow->setCentralWidget(main_container);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 750, 21));
        file = new QMenu(menuBar);
        file->setObjectName(QString::fromUtf8("file"));
        reference = new QMenu(menuBar);
        reference->setObjectName(QString::fromUtf8("reference"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(file->menuAction());
        menuBar->addAction(reference->menuAction());
        file->addAction(loadfrom);
        file->addAction(saveto);
        file->addSeparator();
        file->addAction(quit);
        reference->addAction(help);
        reference->addSeparator();
        reference->addAction(aboutprogram);

        retranslateUi(MainWindow);
        QObject::connect(select_allButton, SIGNAL(clicked()), convert_output, SLOT(setFocus()));
        QObject::connect(select_allButton, SIGNAL(clicked()), convert_output, SLOT(selectAll()));
        QObject::connect(pushButton, SIGNAL(clicked()), convert_input, SLOT(setFocus()));
        QObject::connect(pushButton, SIGNAL(clicked()), convert_input, SLOT(selectAll()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Converter", 0, QApplication::UnicodeUTF8));
        loadfrom->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\270\320\267 \321\204\320\260\320\271\320\273\320\260", 0, QApplication::UnicodeUTF8));
        saveto->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\262 \321\204\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
        help->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \321\201\320\277\321\200\320\260\320\262\320\272\321\203", 0, QApplication::UnicodeUTF8));
        aboutprogram->setText(QApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", 0, QApplication::UnicodeUTF8));
        quit->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", 0, QApplication::UnicodeUTF8));
        title->setText(QApplication::translate("MainWindow", "Pascal - C++ CONVERTER", 0, QApplication::UnicodeUTF8));
        convert_input->setPlainText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\201\321\216\320\264\320\260 \320\272\320\276\320\264 \320\275\320\260 \321\217\320\267\321\213\320\272\320\265 Pascal", 0, QApplication::UnicodeUTF8));
        convert_output->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">\320\227\320\264\320\265\321\201\321\214 \320\261\321\203\320\264\320\265\321\202 \320\277\320\265\321\200\320\265\320\262\320\265\320\264\320\265\320\275\320\275\321\213\320\271 \320\272\320\276\320\264 \320\275\320\260 \321\217\320\267\321\213\320\272\320\265 \320\241++</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "  \320\222\321\213\320\264\320\265\320\273\320\270\321\202\321\214 \320\262\321\201\320\265  ", 0, QApplication::UnicodeUTF8));
        select_allButton->setText(QApplication::translate("MainWindow", "  \320\222\321\213\320\264\320\265\320\273\320\270\321\202\321\214 \320\262\321\201\320\265  ", 0, QApplication::UnicodeUTF8));
        convertButton->setText(QApplication::translate("MainWindow", "  \320\232\320\276\320\275\320\262\320\265\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214  ", 0, QApplication::UnicodeUTF8));
        file->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
        reference->setTitle(QApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
