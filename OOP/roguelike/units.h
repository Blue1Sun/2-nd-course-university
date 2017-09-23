#ifndef UNITS_H
#define UNITS_H

#include <string>

#include <stdlib.h>
class player;

//класс врага, родитель
class enemy
{
private:
    int PositionX, PositionY; //позиция
    char Symbol; //символ отрисовки

public:
    enemy(); //конструктор по умолчанию
    enemy(int, int, char); //конструктор инициализации

    void setPositionX(int); //установка позиции
    void setPositionY(int); //установка позиции
    void setSymbol(char); //установка символа


    int getPositionX() const; //получение позиции
    int getPositionY() const; //получение позиции
    char getSymbol() const; //получение символа

    void moving(player); //движение врага, относительно игрока
};

//класс игрока, наследник
class player : public enemy
{
private:
    char PickedItems[50]; //подобранные игроком предметы
    int PickedItemsCount;
public:
    player(); //конструктор по умолчанию
    player(int, int, char); //конструктор инициализации

    void setPickedItems(char); //установка полученного символа
    void setPickedItemsCount(int); //установка кол-ва полученных символов

    char getPickedItems(int x) const; //получение полученного символа
    int getPickedItemsCount() const; //получение кол-ва полученных символов

    void moving(int, int); //движение игрока, в переданном направлении
};

#endif // UNITS_H
