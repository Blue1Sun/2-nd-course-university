#ifndef UNITS_H
#define UNITS_H

#include <string>

#include <stdlib.h>
class player;

//����� �����, ��������
class enemy
{
private:
    int PositionX, PositionY; //�������
    char Symbol; //������ ���������

public:
    enemy(); //����������� �� ���������
    enemy(int, int, char); //����������� �������������

    void setPositionX(int); //��������� �������
    void setPositionY(int); //��������� �������
    void setSymbol(char); //��������� �������


    int getPositionX() const; //��������� �������
    int getPositionY() const; //��������� �������
    char getSymbol() const; //��������� �������

    void moving(player); //�������� �����, ������������ ������
};

//����� ������, ���������
class player : public enemy
{
private:
    char PickedItems[50]; //����������� ������� ��������
    int PickedItemsCount;
public:
    player(); //����������� �� ���������
    player(int, int, char); //����������� �������������

    void setPickedItems(char); //��������� ����������� �������
    void setPickedItemsCount(int); //��������� ���-�� ���������� ��������

    char getPickedItems(int x) const; //��������� ����������� �������
    int getPickedItemsCount() const; //��������� ���-�� ���������� ��������

    void moving(int, int); //�������� ������, � ���������� �����������
};

#endif // UNITS_H
