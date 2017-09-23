#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "game.h"
#include "records.h"

#include <fstream>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    string main_shifer (string); //шифровка

private slots:
    void on_startGame_clicked(); //нажатие на кнопку "Начать игру"

    void on_Records_clicked(); //нажатие на кнопку "Рекорды"

private:
    Ui::MainWindow *ui;

    game *add; //окно с игрой
    records *add2; //окно с рекордами
};

#endif // MAINWINDOW_H
