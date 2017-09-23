/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created: Sun 11. Dec 19:09:56 2016
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_game
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QPushButton *up;
    QPushButton *down;
    QPushButton *right;
    QPushButton *left;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout;
    QLabel *textMap;
    QTextBrowser *MapUI;

    void setupUi(QDialog *game)
    {
        if (game->objectName().isEmpty())
            game->setObjectName(QString::fromUtf8("game"));
        game->resize(1000, 500);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(game->sizePolicy().hasHeightForWidth());
        game->setSizePolicy(sizePolicy);
        game->setMinimumSize(QSize(1000, 500));
        game->setMaximumSize(QSize(1000, 500));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(188, 188, 188, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        game->setPalette(palette);
        QIcon icon;
        icon.addFile(QString::fromUtf8("Liandry's_Torment_item.png"), QSize(), QIcon::Normal, QIcon::Off);
        game->setWindowIcon(icon);
        horizontalLayout = new QHBoxLayout(game);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        up = new QPushButton(game);
        up->setObjectName(QString::fromUtf8("up"));

        gridLayout->addWidget(up, 1, 1, 1, 1);

        down = new QPushButton(game);
        down->setObjectName(QString::fromUtf8("down"));

        gridLayout->addWidget(down, 3, 1, 1, 1);

        right = new QPushButton(game);
        right->setObjectName(QString::fromUtf8("right"));

        gridLayout->addWidget(right, 2, 2, 1, 1);

        left = new QPushButton(game);
        left->setObjectName(QString::fromUtf8("left"));

        gridLayout->addWidget(left, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textMap = new QLabel(game);
        textMap->setObjectName(QString::fromUtf8("textMap"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        textMap->setFont(font);
        textMap->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(textMap);

        MapUI = new QTextBrowser(game);
        MapUI->setObjectName(QString::fromUtf8("MapUI"));
        MapUI->setEnabled(true);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Terminal"));
        font1.setPointSize(12);
        font1.setItalic(false);
        MapUI->setFont(font1);

        verticalLayout->addWidget(MapUI);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(game);

        QMetaObject::connectSlotsByName(game);
    } // setupUi

    void retranslateUi(QDialog *game)
    {
        game->setWindowTitle(QApplication::translate("game", "Let's play", 0, QApplication::UnicodeUTF8));
        up->setText(QApplication::translate("game", "\320\262\320\262\320\265\321\200\321\205", 0, QApplication::UnicodeUTF8));
        down->setText(QApplication::translate("game", "\320\262\320\275\320\270\320\267", 0, QApplication::UnicodeUTF8));
        right->setText(QApplication::translate("game", "\320\262\320\277\321\200\320\260\320\262\320\276", 0, QApplication::UnicodeUTF8));
        left->setText(QApplication::translate("game", "\320\262\320\273\320\265\320\262\320\276", 0, QApplication::UnicodeUTF8));
        textMap->setText(QApplication::translate("game", "Items: 0", 0, QApplication::UnicodeUTF8));
        MapUI->setHtml(QApplication::translate("game", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Terminal'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8pt;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class game: public Ui_game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
