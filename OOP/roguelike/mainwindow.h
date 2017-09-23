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

    string main_shifer (string); //��������

private slots:
    void on_startGame_clicked(); //������� �� ������ "������ ����"

    void on_Records_clicked(); //������� �� ������ "�������"

private:
    Ui::MainWindow *ui;

    game *add; //���� � �����
    records *add2; //���� � ���������
};

#endif // MAINWINDOW_H
