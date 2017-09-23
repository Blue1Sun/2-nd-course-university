#ifndef MYCLASS_H
#define MYCLASS_H

#include <iostream>
#include <string>
#include <cmath>
#include <QMutex>

#include <sstream>

using namespace std;

//Неигровые персонажи

class NPC //класс неигровых персонажей
{
private:
    mutable int HealthPoints, ManaPoints; //количество Здоровья, Маны
    float damage, armor; //наносимый Урон, имеющаяся Броня
    string name, specialization; //Имя, Специализация
public:
    NPC(); //конструктор по умолчанию
    NPC(int, int, float, float, string, int); //конструктор инициализации
    NPC(const NPC &); //конструктор копирования
    ~NPC(); //деструктор

    //модификаторы:
    void setHP(int) const;
    void setMP(int) const;
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

    //перегрузки операторов:
    //арифметические операторы, работающие с двумя объектами класса
    NPC operator +(NPC &);
    NPC operator -(NPC &);

    //арифметические операторы, работающие с одним объектом класса и числом
    friend NPC operator +(NPC&, int);
    friend NPC operator -(NPC&, int);

    //инкременты:
    NPC& operator ++(); //префиксный
    NPC operator ++(int); //постфиксный

    //декременты:
    NPC& operator --(); //префиксный
    NPC operator --(int); //постфиксный

    //логические операторы и операторы сравнения:
    bool operator < (const NPC&); //меньше
    bool operator > (const NPC&); //больше
    bool operator == (const NPC&); //равно
    bool operator != (const NPC&); //не равно

    NPC operator()(int, int, int, int); //оператор ()

    //операторы ввода и вывода << и >>
    friend ofstream& operator<<(ofstream&, const NPC&); //запись в файл
    friend ifstream& operator>>(ifstream&, NPC*); //загрузка из файла

    NPC& operator =(int); //оператор присваивания

    operator bool() const; //оператор приведения типов

    //побитовые операторы:
    NPC operator >>(int); //сдвиг вправо
    NPC operator <<(int); //сдвиг влево

    virtual string show(); //функция вывода НПЦ
    virtual string fshow();
};

//Монстры

class monster: public NPC //наследование
{
private:
    int agression;
public:
    monster(); //конструктор по умолчанию
    monster(int, int, float, float, int, string, int); //конструктор инициализации
    monster(const monster &); //конструктор копирования
    ~monster(); //деструктор

    //модификаторы:
    void setAgression(int);

    //селекторы:
    int getAgression() const;

    string show(); //функция вывода монстра
    string fshow();
};

//Двунаправленный список

template <typename T> struct node //звено
{
    T *info; //поле значения
    node *next, *prev; //указатели на предыдущий и следующий элементы
};

template <typename T> class listNPC //класс списка
{
private:
    node<T> *head, *tail; //указатели на начало и конец списка
    QMutex mutex; //использование mutex
public:
    listNPC(); //конструктор по умолчанию
    listNPC(T *); //конструктор инициализации
    listNPC(const listNPC<T> &); //конструктор копирования
    ~listNPC(); //деструктор

    node<T> *getHead(); //селектор
    node<T> *getTail(); //селектор

    void addElement(T *); //добавление элемента
    void deleteElement(int); //удаление элемента
    int numberOfElement(); //количество элементов

    //перегрузка оператора индексации
    node<T> *operator[](int);
};

template <typename T1, typename T2> T1 plussing(T1 &first, T2 &second) //ШАБЛОН СУММИРОВАНИЯ
{
    return first + second;
}

template <class T> string to_string(T param)
{
    stringstream ss;
    ss<<param;
    return ss.str();
}

//Методы класса двунаправленного списка

template <typename T> listNPC<T>::listNPC() //конструктор по умолчанию
{
    head = tail = NULL;
}

template <typename T> listNPC<T>::listNPC(T *x) //конструктор инициализации, задаем начало
{
    head = new node<NPC>;

    head->info = *x;
    head->next = NULL;
    head->prev = NULL;

    tail = head;
}

template <typename T> listNPC<T>::listNPC(const listNPC<T> &obj) //конструктор копирования
{
   head = tail = NULL;

   node<NPC> *curr = obj.head;

   while (curr != NULL)
   {
       node<NPC> *currNew = new node<NPC>;
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

template <typename T> listNPC<T>::~listNPC() //деструктор
{
    node<NPC> *curr = new node<NPC>;
    while (head) //пока есть что удалять - удаляем
    {
        curr = head->next;
        delete head;
        head = curr;
    }
}

template <typename T> node<T>* listNPC<T>::getHead() //получить указатель на начало списка
{
    return head;
}

template <typename T> node<T>* listNPC<T>::getTail() //получить указатель на конец списка
{
    return tail;
}

template <typename T> void listNPC<T>::addElement(T *x) //добавление элемент
{
    mutex.lock();//использование mutex

    node<NPC> *curr = new node<NPC>;
    curr->next = NULL;
    curr->info = x;
    if (head!=NULL) //если начало списка есть
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

    mutex.unlock();//использование mutex
}

template <typename T> void listNPC<T>::deleteElement(int num) //удаление num-ого элемента
{
    mutex.lock();//использование mutex

    node<NPC> *curr = new node<NPC>;
    curr = head; //первый элемент
    for (int i = 1; i < num; i++)
    {
        curr = curr->next; //поиск элемента для удаления
    }
    if (curr == head) //если удаляется начало
    {
        head = head->next;
        if(head)
            head->prev = NULL;
        else
            tail = NULL;
    }
    else if (curr == tail) //если удаляется конец
    {
        tail = tail->prev;
        if(tail)
            tail->next = NULL;
        else
            head = NULL;
    }
    else //если удаляется из середины
    {
        curr->prev->next=curr->next;
        curr->next->prev=curr->prev;
    }
    delete curr;

    mutex.unlock();//использование mutex
}
template <typename T> int listNPC<T>::numberOfElement() //получение количеста элементов в списке
{
    int count;
    node<NPC> *curr = new node<NPC>;
    curr = head;
    for (count = 0; curr; count++)
    {
        curr = curr->next;
    }
    return count;
}

template <typename T> node<T>* listNPC<T>::operator [](int x) //перегрузка оператора [] индексации
{
    node<NPC> *curr = head; //указатель на голову
    int i = 1;

    while (i < x)
    {
        i++;
        curr = curr->next; //ищем нужный элемент
    }
    return curr;
}


#endif // MYCLASS_H
