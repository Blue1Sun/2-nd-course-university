#include <iostream>
#include <string>
#include "myclasses.h"

using namespace std;

//������ ������ �������

NPC::NPC()//����������� �� ���������, ������� "����������" ���������
{
    HealthPoints = 100;
    ManaPoints = 50;
    damage = 10.5;
    armor = 2.5;
    name = "Basic Character";
    specialization = "Warrior";
}

NPC::NPC(int HP, int MP, float DMG, float ARM, string n, int spec) //����������� �������������
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

NPC::NPC(const NPC &obj) //����������� �����������. ��� ����������, �.�. ������ ���������� ����������
{

}

NPC::~NPC()//����������. ���������� ������������ �����������
{

}

void NPC::setHP(int HP) //���������������� ����������� ��� ��������
{
    if (HP<0)
        HP = HP * (-1);
    HealthPoints = HP;
}
void NPC::setMP(int MP) //���������������� ����������� ��� ����
{
    if (MP<0)
        MP = MP * (-1);
    ManaPoints = MP;
}
void NPC::setDamage(float DMG) //���������������� ����������� ��� �����
{
    if (DMG<0)
        DMG = DMG * (-1);
    damage = DMG;
}
void NPC::setArmor(float ARM) //���������������� ����������� ��� �����
{
    if (ARM<0)
        ARM = ARM * (-1);
    armor = ARM;
}
void NPC::setName(string n) //����������� ��� �����
{
    name = n;
}
void NPC::setSpec(int spec)//���������������� ����������� ��� �������������
{
    if (spec==1)
        specialization = "Warrior";
    if (spec==2)
        specialization = "Mage";
    if (spec==3)
        specialization = "Rogue";
}

int NPC::getHP() const //��������� ����� ��������
{
    return HealthPoints;
}
int NPC::getMP() const //��������� ����� ����
{
    return ManaPoints;
}
float NPC::getDamage() const //��������� ���������� �����
{
    return damage;
}
float NPC::getArmor() const //��������� �����
{
    return armor;
}
string NPC::getName() const //��������� �����
{
    return name;
}
string NPC::getSpec() const //��������� �������������
{
    return specialization;
}

//������ ������ ���������������� ������

list::list() //����������� �� ���������
{
    head = tail = NULL;
}

list::list(NPC *x)//����������� �������������, ������ ������
{
    head = new node;

    head->info = *x;
    head->next = NULL;
    head->prev = NULL;

    tail = head;
}

list::list(const list &obj)//����������� �����������
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

list::~list()//����������
{
    node *curr = new node;
    while (head)//���� ���� ��� ������� - �������
    {
        curr = head->next;
        delete head;
        head = curr;
    }
}

node* list::getHead()//�������� ��������� �� ������ ������
{
    return head;
}

node* list::getTail()//�������� ��������� �� ����� ������
{
    return tail;
}

void list::addElement(NPC *x)//���������� ��������
{
    node *curr = new node;
    curr->next = NULL;
    curr->info = *x;

    if (head!=NULL)//���� ������ ������ ����
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
}

void list::deleteElement(int num)//�������� num-��� ��������
{
    node *curr = new node;
    curr = head;//������ �������
    for (int i = 1; i < num; i++)
    {
        curr = curr->next;//����� �������� ��� ��������
    }
    if (curr == head)//���� ��������� ������
    {
        head = head->next;
        if(head)
            head->prev = NULL;
        else
            tail = NULL;
    }
    else if (curr == tail)//���� ��������� �����
    {
        tail = tail->prev;
        if(tail)
            tail->next = NULL;
        else
            head = NULL;
    }
    else//���� ��������� �� ��������
    {
        curr->prev->next=curr->next;
        curr->next->prev=curr->prev;
    }
    delete curr;
}
int list::numberOfElement()//��������� ��������� ��������� � ������
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


