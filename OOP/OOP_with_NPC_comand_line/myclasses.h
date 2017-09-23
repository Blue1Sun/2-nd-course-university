#ifndef MYCLASS_H
#define MYCLASS_H

#include <string>

using namespace std;

//Неигровые персонажи

class NPC //класс неигровых персонажей
{
private:
    int HealthPoints, ManaPoints;//количество Здоровья, Маны
    float damage, armor;//наносимый Урон, имеющаяся Броня
    string name, specialization;//Имя, Специализация
public:
    NPC();//конструктор по умолчанию
    NPC(int, int, float, float, string, int);//конструктор инициализации
    NPC(const NPC &);//конструктор копирования
    ~NPC();//деструктор

    //модификаторы:
    void setHP(int);
    void setMP(int);
    void setDamage(float);
    void setArmor(float);
    void setName(string);
    void setSpec(int);

    //селекторы:
    int getHP() const;
    int getMP() const;
    float getDamage() const;
    float getArmor() const;
    string getName() const;
    string getSpec() const;

};

//Двунаправленный список

struct node //звено
{
    NPC info;//поле значения
    node *next, *prev;//указатели на предыдущий и следующий элементы
};

class list //класс списка
{
private:
    node *head, *tail;//указатели на начало и конец списка
public:
    list();//конструктор по умолчанию
    list(NPC *);//конструктор инициализации
    list(const list &);//конструктор копирования
    ~list();//деструктор

    node *getHead();//селектор
    node *getTail();//селектор

    void addElement(NPC *);//добавление элемента
    void deleteElement(int);//удаление элемента
    int numberOfElement();//количество элементов
};

#endif // MYCLASS_H
