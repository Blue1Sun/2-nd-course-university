/********************************************************************************
** Form generated from reading UI file 'aboutwindow.ui'
**
** Created: Mon 8. May 00:45:38 2017
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTWINDOW_H
#define UI_ABOUTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AboutWindow
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *title;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *AboutWindow)
    {
        if (AboutWindow->objectName().isEmpty())
            AboutWindow->setObjectName(QString::fromUtf8("AboutWindow"));
        AboutWindow->resize(400, 300);
        AboutWindow->setMinimumSize(QSize(400, 300));
        AboutWindow->setMaximumSize(QSize(400, 300));
        QIcon icon;
        icon.addFile(QString::fromUtf8("Images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        AboutWindow->setWindowIcon(icon);
        label = new QLabel(AboutWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(9, 54, 382, 231));
        label->setWordWrap(true);
        layoutWidget = new QWidget(AboutWindow);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 9, 370, 31));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        title = new QLabel(layoutWidget);
        title->setObjectName(QString::fromUtf8("title"));
        QFont font;
        font.setPointSize(18);
        title->setFont(font);

        horizontalLayout->addWidget(title);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        retranslateUi(AboutWindow);

        QMetaObject::connectSlotsByName(AboutWindow);
    } // setupUi

    void retranslateUi(QDialog *AboutWindow)
    {
        AboutWindow->setWindowTitle(QApplication::translate("AboutWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265 \"Pascal - C++ converter\"", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AboutWindow", "\320\257\320\267\321\213\320\272 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217: C++, HTML. \n"
"\320\244\321\200\320\265\320\271\320\274\320\262\320\276\321\200\320\272: Qt Creator 2.4.1. \n"
"OC: Windows. \n"
"\320\222\320\265\321\200\321\201\320\270\321\217:1.0.\n"
"\302\251 \320\226\320\260\320\273\320\272\320\276\320\262\320\260 \320\235\320\260\321\202\320\260\320\273\320\270\321\217, 2017. \320\222\321\201\320\265 \320\277\321\200\320\260\320\262\320\260 \320\267\320\260\321\211\320\270\321\211\320\265\320\275\321\213.\n"
"\n"
"\320\224\320\260\320\275\320\275\320\276\320\265 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\275\320\276\320\265 \320\276\320\261\320\265\321\201\320\277\320\265\321\207\320\265\320\275\320\270\320\265 \320\277\320\265\321\200\320\265\320\262\320\276\320\264\320\270\321\202 \320\262\320\262\320\265\320\264\320\265\320\275\320\275\321\213\320\271 \320\277\320\276\320\273\321\214"
                        "\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\265\320\274 \321\204\321\200\320\260\320\263\320\274\320\265\320\275\321\202 \320\272\320\276\320\264\320\260, \320\275\320\260\320\277\320\270\321\201\320\260\320\275\320\275\320\276\320\263\320\276 \320\275\320\260 \321\217\320\267\321\213\320\272\320\265 Pascal, \320\262 \320\272\320\276\320\264, \320\275\320\260\320\277\320\270\321\201\320\260\320\275\320\275\321\213\320\271 \320\275\320\260 \321\217\320\267\321\213\320\272\320\265 C, \321\201\320\276\321\205\321\200\320\260\320\275\321\217\321\217 \321\204\321\203\320\275\320\272\321\206\320\270\320\276\320\275\320\260\320\273 \320\270\321\201\321\205\320\276\320\264\320\275\320\270\320\272\320\260. \n"
"\320\230\320\274\320\265\320\265\321\202\321\201\321\217 \320\262\320\276\320\267\320\274\320\276\320\266\320\275\320\276\321\201\321\202\321\214 \320\267\320\260\320\263\321\200\321\203\320\267\320\272\320\270 \320\272\320\276\320\264\320\260 \320\270\320\267 \321\204\320\260\320\271\320\273\320"
                        "\260 \321\204\320\276\321\200\320\274\320\260\321\202\320\260 .pas \320\270 \321\201\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\270\321\217 \320\277\320\276\320\273\321\203\321\207\320\270\320\262\321\210\320\265\320\263\320\276\321\201\321\217 \321\200\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\320\260 \320\277\320\265\321\200\320\265\320\262\320\276\320\264\320\260 \320\262 \321\204\320\260\320\271\320\273 \321\204\320\276\321\200\320\274\320\260\321\202\320\260 .cpp. \320\222 \320\264\320\276\320\277\320\276\320\273\320\275\320\265\320\275\320\270\320\265 \320\272 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\275\320\276\320\274\321\203 \320\276\320\261\320\265\321\201\320\277\320\265\321\207\320\265\320\275\320\270\321\216 \320\270\320\264\320\265\321\202 \321\201\320\277\321\200\320\260\320\262\320\272\320\260.\n"
" \n"
" Developer/Support e-mail: nezhalkova@edu.hse.ru", 0, QApplication::UnicodeUTF8));
        title->setText(QApplication::translate("AboutWindow", "Pascal - C++ CONVERTER", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AboutWindow: public Ui_AboutWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTWINDOW_H
