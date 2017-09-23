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

    QChar myMap[28][60]; //карта местности

    player You; //объект класса игрок

    enemy CoolGuy; //объект класса противник
    enemy CoolGuyFriend; //объект2 класса противник

    QChar stopingSymbols[10]; //массив типа символов, через которые пройти нельзя
    QChar pickingSymbols[10]; //массив типа символов, которые можно подобрать

    void GenerateMap(); //генерация карты
    void showMap(); //вывод карты

    bool CheckMoving(int, int); //проверка, можно ли сдвинуться
    void IsEnding(enemy, player); //проверка на конец игры

    void UnitsMoving(int, int); //движение единиц

    string game_shifer (string); //шифровка
    
private slots:
    void on_up_clicked(); //кнопка "Вверх" нажата

    void on_down_clicked(); //кнопка "Вниз" нажата

    void on_left_clicked(); //кнопка "Влево" нажата

    void on_right_clicked(); //кнопка "Вправо" нажата

private:
    Ui::game *ui;
};

//шаблонная функция перевода переменной в string
template <typename T>
  string to_string ( T myvar )
  {
     ostringstream ss; //поток
     ss << myvar;
     return ss.str();
  }

#endif // GAME_H
