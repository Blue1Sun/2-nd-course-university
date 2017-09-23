#include "units.h"

//����������� �� ���������
enemy::enemy()
{
    PositionX = rand() %27 + 0; //�������� ���������� ���������� X � Y
    PositionY = rand() %59 + 0;
    Symbol = '$'; //������ ��� �����
}

//����������� �������������
enemy::enemy(int x, int y, char c)
{
    PositionX = x;
    PositionY = y;
    Symbol = c;
}

//��������� ������� X
void enemy::setPositionX(int x)
{
    PositionX = x;
}

//��������� ������� Y
void enemy::setPositionY(int y)
{
    PositionY = y;
}

//��������� �������
void enemy::setSymbol(char s)
{
    Symbol = s;
}

//��������� ������� X
int enemy::getPositionX() const
{
    return PositionX;
}

//��������� ������� Y
int enemy::getPositionY() const
{
    return PositionY;
}

//��������� �������
char enemy::getSymbol() const
{
    return Symbol;
}

//�������� ����� ������������ ������
void enemy::moving(player victim)
{
    if (rand() %10 + 1 > 5) //�������� ���������� ������ ��������
    {
        //������� ���������� ������� X, ���� ��� �� �����
        if (getPositionX() != victim.getPositionX())
        {
            if (this->getPositionX() < victim.getPositionX()) //���� X ����� ������ X ������
                setPositionX(this->getPositionX()+1); //X �������������

            else
                if (this->getPositionX() > victim.getPositionX()) //���� X ����� ������ X ������
                setPositionX(this->getPositionX()-1); //X �����������
        }
        else
            //�������� ���� ��� ������ � ����� ����������� (��� ��������� X, ��� ��������� Y)
            if (this->getPositionY() != victim.getPositionY())
        {
            if (this->getPositionY() > victim.getPositionY())
                setPositionY(this->getPositionY()-1);

            else
                if (this->getPositionY() < victim.getPositionY())
                setPositionY(this->getPositionY()+1);
        }
    }
    else
    {
        //������� ���������� ������� Y, ���� ��� �� �����. ����������
        if (this->getPositionY() != victim.getPositionY())
        {
            if (this->getPositionY() > victim.getPositionY())
                setPositionY(this->getPositionY()-1);

            else
                if (this->getPositionY() < victim.getPositionY())
                setPositionY(this->getPositionY()+1);
        }
        else
            if (getPositionX() != victim.getPositionX())
        {
            if (this->getPositionX() < victim.getPositionX())
                setPositionX(this->getPositionX()+1);

            else
                if (this->getPositionX() > victim.getPositionX())
                setPositionX(this->getPositionX()-1);
        }
    }
}

//����������� �� ���������
player::player() : enemy (rand() %27 + 0, rand() %59 + 0, '@')
{
    PickedItemsCount = 0;
}

//����������� �������������
player::player(int x, int y, char c) : enemy (x, y, c)
{

}

//��������� ����������� �������
void player::setPickedItems(char c)
{
    PickedItems[PickedItemsCount] = c;
}

//��������� ���-�� ���������� ��������
void player::setPickedItemsCount(int x)
{
    PickedItemsCount = x;
}

//��������� ����������� �������
char player::getPickedItems(int x) const
{
    return PickedItems[x];
}

//��������� ����������� �������
int player::getPickedItemsCount() const
{
    return PickedItemsCount;
}

//����������� ������� ������
void player::moving(int x, int y)
{
    setPositionX(this->getPositionX() + x);
    setPositionY(this->getPositionY() + y);
}
