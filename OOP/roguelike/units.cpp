#include "units.h"

//конструктор по умолчанию
enemy::enemy()
{
    PositionX = rand() %27 + 0; //рандомно выбираются координаты X и Y
    PositionY = rand() %59 + 0;
    Symbol = '$'; //символ для врага
}

//конструктор инициализации
enemy::enemy(int x, int y, char c)
{
    PositionX = x;
    PositionY = y;
    Symbol = c;
}

//установка позиции X
void enemy::setPositionX(int x)
{
    PositionX = x;
}

//установка позиции Y
void enemy::setPositionY(int y)
{
    PositionY = y;
}

//установка символа
void enemy::setSymbol(char s)
{
    Symbol = s;
}

//получение позиции X
int enemy::getPositionX() const
{
    return PositionX;
}

//получение позиции Y
int enemy::getPositionY() const
{
    return PositionY;
}

//получение символа
char enemy::getSymbol() const
{
    return Symbol;
}

//движение врага относительно игрока
void enemy::moving(player victim)
{
    if (rand() %10 + 1 > 5) //рандомно выбирается способ движения
    {
        //вначале изменяется позиция X, если она не равна
        if (getPositionX() != victim.getPositionX())
        {
            if (this->getPositionX() < victim.getPositionX()) //если X врага меньше X игрока
                setPositionX(this->getPositionX()+1); //X увеличивается

            else
                if (this->getPositionX() > victim.getPositionX()) //если X врага больше X игрока
                setPositionX(this->getPositionX()-1); //X уменьшается
        }
        else
            //возможен один шаг только в одном направлении (или изменение X, или изменение Y)
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
        //вначале изменяется позиция Y, если она не равна. Аналогично
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

//конструктор по умолчанию
player::player() : enemy (rand() %27 + 0, rand() %59 + 0, '@')
{
    PickedItemsCount = 0;
}

//конструктор инициализации
player::player(int x, int y, char c) : enemy (x, y, c)
{

}

//установка полученного символа
void player::setPickedItems(char c)
{
    PickedItems[PickedItemsCount] = c;
}

//установка кол-ва полученных символов
void player::setPickedItemsCount(int x)
{
    PickedItemsCount = x;
}

//получение полученного символа
char player::getPickedItems(int x) const
{
    return PickedItems[x];
}

//получение полученного символа
int player::getPickedItemsCount() const
{
    return PickedItemsCount;
}

//измененение позиции игрока
void player::moving(int x, int y)
{
    setPositionX(this->getPositionX() + x);
    setPositionY(this->getPositionY() + y);
}
