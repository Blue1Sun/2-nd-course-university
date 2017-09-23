/********************************************************************************
** Form generated from reading UI file 'records.ui'
**
** Created: Sun 11. Dec 19:09:56 2016
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORDS_H
#define UI_RECORDS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_records
{
public:
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *records)
    {
        if (records->objectName().isEmpty())
            records->setObjectName(QString::fromUtf8("records"));
        records->resize(400, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8("Liandry's_Torment_item.png"), QSize(), QIcon::Normal, QIcon::Off);
        records->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(records);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textBrowser = new QTextBrowser(records);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        verticalLayout->addWidget(textBrowser);


        retranslateUi(records);

        QMetaObject::connectSlotsByName(records);
    } // setupUi

    void retranslateUi(QDialog *records)
    {
        records->setWindowTitle(QApplication::translate("records", "Records", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class records: public Ui_records {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDS_H
