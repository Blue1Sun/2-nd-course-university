#ifndef GAME_H
#define GAME_H

#include <QDialog>
#include "units.h"
#include <string>

#include <QSound>

#include <fstream>

#include <QMessageBox>

#include <sstream>

using namespace std;

namespace Ui {
class game;
}

class game : public QDialog
{
    Q_OBJECT
    
public:
    explicit game(QWidget *parent = 0);
    ~game();

    QChar myMap[28][60]; //����� ���������

    player You; //������ ������ �����

    enemy CoolGuy; //������ ������ ���������
    enemy CoolGuyFriend; //������2 ������ ���������

    QChar stopingSymbols[10]; //������ ���� ��������, ����� ������� ������ ������
    QChar pickingSymbols[10]; //������ ���� ��������, ������� ����� ���������

    void GenerateMap(); //��������� �����
    void showMap(); //����� �����

    bool CheckMoving(int, int); //��������, ����� �� ����������
    void IsEnding(enemy, player); //�������� �� ����� ����

    void UnitsMoving(int, int); //�������� ������

    string game_shifer (string); //��������
    
private slots:
    void on_up_clicked(); //������ "�����" ������

    void on_down_clicked(); //������ "����" ������

    void on_left_clicked(); //������ "�����" ������

    void on_right_clicked(); //������ "������" ������

private:
    Ui::game *ui;
};

//��������� ������� �������� ���������� � string
template <typename T>
  string to_string ( T myvar )
  {
     ostringstream ss; //�����
     ss << myvar;
     return ss.str();
  }

#endif // GAME_H
