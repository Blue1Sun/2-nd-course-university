#ifndef MYCLASS_H
#define MYCLASS_H

#include <iostream>
#include <string>
#include <cmath>
#include <QMutex>

#include <sstream>

using namespace std;

//��������� ���������

class NPC //����� ��������� ����������
{
private:
    mutable int HealthPoints, ManaPoints; //���������� ��������, ����
    float damage, armor; //��������� ����, ��������� �����
    string name, specialization; //���, �������������
public:
    NPC(); //����������� �� ���������
    NPC(int, int, float, float, string, int); //����������� �������������
    NPC(const NPC &); //����������� �����������
    ~NPC(); //����������

    //������������:
    void setHP(int) const;
    void setMP(int) const;
    void setDamage(float);
    void setArmor(float);
    void setName(string);
    void setSpec(int);

    //���������:
    int getHP() const;
    int getMP() const;
    float getDamage() const;
    float getArmor() const;
    string getName() const;
    string getSpec() const;

    //���������� ����������:
    //�������������� ���������, ���������� � ����� ��������� ������
    NPC operator +(NPC &);
    NPC operator -(NPC &);

    //�������������� ���������, ���������� � ����� �������� ������ � ������
    friend NPC operator +(NPC&, int);
    friend NPC operator -(NPC&, int);

    //����������:
    NPC& operator ++(); //����������
    NPC operator ++(int); //�����������

    //����������:
    NPC& operator --(); //����������
    NPC operator --(int); //�����������

    //���������� ��������� � ��������� ���������:
    bool operator < (const NPC&); //������
    bool operator > (const NPC&); //������
    bool operator == (const NPC&); //�����
    bool operator != (const NPC&); //�� �����

    NPC operator()(int, int, int, int); //�������� ()

    //��������� ����� � ������ << � >>
    friend ofstream& operator<<(ofstream&, const NPC&); //������ � ����
    friend ifstream& operator>>(ifstream&, NPC*); //�������� �� �����

    NPC& operator =(int); //�������� ������������

    operator bool() const; //�������� ���������� �����

    //��������� ���������:
    NPC operator >>(int); //����� ������
    NPC operator <<(int); //����� �����

    virtual string show(); //������� ������ ���
    virtual string fshow();
};

//�������

class monster: public NPC //������������
{
private:
    int agression;
public:
    monster(); //����������� �� ���������
    monster(int, int, float, float, int, string, int); //����������� �������������
    monster(const monster &); //����������� �����������
    ~monster(); //����������

    //������������:
    void setAgression(int);

    //���������:
    int getAgression() const;

    string show(); //������� ������ �������
    string fshow();
};

//��������������� ������

template <typename T> struct node //�����
{
    T *info; //���� ��������
    node *next, *prev; //��������� �� ���������� � ��������� ��������
};

template <typename T> class listNPC //����� ������
{
private:
    node<T> *head, *tail; //��������� �� ������ � ����� ������
    QMutex mutex; //������������� mutex
public:
    listNPC(); //����������� �� ���������
    listNPC(T *); //����������� �������������
    listNPC(const listNPC<T> &); //����������� �����������
    ~listNPC(); //����������

    node<T> *getHead(); //��������
    node<T> *getTail(); //��������

    void addElement(T *); //���������� ��������
    void deleteElement(int); //�������� ��������
    int numberOfElement(); //���������� ���������

    //���������� ��������� ����������
    node<T> *operator[](int);
};

template <typename T1, typename T2> T1 plussing(T1 &first, T2 &second) //������ ������������
{
    return first + second;
}

template <class T> string to_string(T param)
{
    stringstream ss;
    ss<<param;
    return ss.str();
}

//������ ������ ���������������� ������

template <typename T> listNPC<T>::listNPC() //����������� �� ���������
{
    head = tail = NULL;
}

template <typename T> listNPC<T>::listNPC(T *x) //����������� �������������, ������ ������
{
    head = new node<NPC>;

    head->info = *x;
    head->next = NULL;
    head->prev = NULL;

    tail = head;
}

template <typename T> listNPC<T>::listNPC(const listNPC<T> &obj) //����������� �����������
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

template <typename T> listNPC<T>::~listNPC() //����������
{
    node<NPC> *curr = new node<NPC>;
    while (head) //���� ���� ��� ������� - �������
    {
        curr = head->next;
        delete head;
        head = curr;
    }
}

template <typename T> node<T>* listNPC<T>::getHead() //�������� ��������� �� ������ ������
{
    return head;
}

template <typename T> node<T>* listNPC<T>::getTail() //�������� ��������� �� ����� ������
{
    return tail;
}

template <typename T> void listNPC<T>::addElement(T *x) //���������� �������
{
    mutex.lock();//������������� mutex

    node<NPC> *curr = new node<NPC>;
    curr->next = NULL;
    curr->info = x;
    if (head!=NULL) //���� ������ ������ ����
    {
        curr->prev = tail;
        tail->next = curr;
        tail = curr;
    }
    else //���� ������ ������ ���
    {
        curr->prev = NULL;
        head = tail = curr;
    }

    mutex.unlock();//������������� mutex
}

template <typename T> void listNPC<T>::deleteElement(int num) //�������� num-��� ��������
{
    mutex.lock();//������������� mutex

    node<NPC> *curr = new node<NPC>;
    curr = head; //������ �������
    for (int i = 1; i < num; i++)
    {
        curr = curr->next; //����� �������� ��� ��������
    }
    if (curr == head) //���� ��������� ������
    {
        head = head->next;
        if(head)
            head->prev = NULL;
        else
            tail = NULL;
    }
    else if (curr == tail) //���� ��������� �����
    {
        tail = tail->prev;
        if(tail)
            tail->next = NULL;
        else
            head = NULL;
    }
    else //���� ��������� �� ��������
    {
        curr->prev->next=curr->next;
        curr->next->prev=curr->prev;
    }
    delete curr;

    mutex.unlock();//������������� mutex
}
template <typename T> int listNPC<T>::numberOfElement() //��������� ��������� ��������� � ������
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

template <typename T> node<T>* listNPC<T>::operator [](int x) //���������� ��������� [] ����������
{
    node<NPC> *curr = head; //��������� �� ������
    int i = 1;

    while (i < x)
    {
        i++;
        curr = curr->next; //���� ������ �������
    }
    return curr;
}


#endif // MYCLASS_H
