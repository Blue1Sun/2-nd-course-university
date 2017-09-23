#include <iostream>
#include <string>
#include "myclasses.h"

using namespace std;

//Методы класса матрицы

NPC::NPC()//конструктор по умолчанию, создает "шаблонного" персонажа
{
    HealthPoints = 100;
    ManaPoints = 50;
    damage = 10.5;
    armor = 2.5;
    name = "Basic Character";
    specialization = "Warrior";
}

NPC::NPC(int HP, int MP, float DMG, float ARM, string n, int spec) //конструктор инициализации
{
    HealthPoints = HP;
    ManaPoints = MP;
    damage = DMG;
    armor = ARM;
    name = n;
    if (spec==1)
        specialization = "Warrior";
    if (spec==2)
        specialization = "Mage";
    if (spec==3)
        specialization = "Rogue";
}

NPC::NPC(const NPC &obj) //конструктор копирования. нет применения, т.к. память выделяется статически
{

}

NPC::~NPC()//деструктор. аналогично конструктору копирования
{

}

void NPC::setHP(int HP) //интеллектуальный модификатор для здоровья
{
    if (HP<0)
        HP = HP * (-1);
    HealthPoints = HP;
}
void NPC::setMP(int MP) //интеллектуальный модификатор для маны
{
    if (MP<0)
        MP = MP * (-1);
    ManaPoints = MP;
}
void NPC::setDamage(float DMG) //интеллектуальный модификатор для урона
{
    if (DMG<0)
        DMG = DMG * (-1);
    damage = DMG;
}
void NPC::setArmor(float ARM) //интеллектуальный модификатор для брони
{
    if (ARM<0)
        ARM = ARM * (-1);
    armor = ARM;
}
void NPC::setName(string n) //модификатор для имени
{
    name = n;
}
void NPC::setSpec(int spec)//интеллектуальный модификатор для специальности
{
    if (spec==1)
        specialization = "Warrior";
    if (spec==2)
        specialization = "Mage";
    if (spec==3)
        specialization = "Rogue";
}

int NPC::getHP() const //получение очков здоровья
{
    return HealthPoints;
}
int NPC::getMP() const //получение очков маны
{
    return ManaPoints;
}
float NPC::getDamage() const //получение наносимого урона
{
    return damage;
}
float NPC::getArmor() const //получение брони
{
    return armor;
}
string NPC::getName() const //получение имени
{
    return name;
}
string NPC::getSpec() const //получение специализации
{
    return specialization;
}

//Методы класса двунаправленного списка

list::list() //конструктор по умолчанию
{
    head = tail = NULL;
}

list::list(NPC *x)//конструктор инициализации, задаем начало
{
    head = new node;

    head->info = *x;
    head->next = NULL;
    head->prev = NULL;

    tail = head;
}

list::list(const list &obj)//конструктор копирования
{
   head = tail = NULL;

   node *curr = obj.head;

   while (curr != NULL)
   {
       node *currNew = new node;
       currNew->next = NULL;
       currNew->info = curr->info;
       currNew->prev = tail;

       if (tail != NULL)
           tail->next = currNew;
       if (numberOfElement()==0)
           head = tail = currNew;
       else
           tail = currNew;
       curr = curr->next;
   }
}

list::~list()//деструктор
{
    node *curr = new node;
    while (head)//пока есть что удалять - удаляем
    {
        curr = head->next;
        delete head;
        head = curr;
    }
}

node* list::getHead()//получить указатель на начало списка
{
    return head;
}

node* list::getTail()//получить указатель на конец списка
{
    return tail;
}

void list::addElement(NPC *x)//добавление элемента
{
    node *curr = new node;
    curr->next = NULL;
    curr->info = *x;

    if (head!=NULL)//если начало списка есть
    {
        curr->prev = tail;
        tail->next = curr;
        tail = curr;
    }
    else //если начала списка нет
    {
        curr->prev = NULL;
        head = tail = curr;
    }
}

void list::deleteElement(int num)//удаление num-ого элемента
{
    node *curr = new node;
    curr = head;//первый элемент
    for (int i = 1; i < num; i++)
    {
        curr = curr->next;//поиск элемента для удаления
    }
    if (curr == head)//если удаляется начало
    {
        head = head->next;
        if(head)
            head->prev = NULL;
        else
            tail = NULL;
    }
    else if (curr == tail)//если удаляется конец
    {
        tail = tail->prev;
        if(tail)
            tail->next = NULL;
        else
            head = NULL;
    }
    else//если удаляется из середины
    {
        curr->prev->next=curr->next;
        curr->next->prev=curr->prev;
    }
    delete curr;
}
int list::numberOfElement()//получение количеста элементов в списке
{
    int count;
    node *curr = new node;
    curr = head;
    for (count = 0; curr; count++)
    {
        curr = curr->next;
    }
    return count;
}


