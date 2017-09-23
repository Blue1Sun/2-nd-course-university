#ifndef MYCLASS_H
#define MYCLASS_H

#include <string>

using namespace std;

//��������� ���������

class NPC //����� ��������� ����������
{
private:
    int HealthPoints, ManaPoints;//���������� ��������, ����
    float damage, armor;//��������� ����, ��������� �����
    string name, specialization;//���, �������������
public:
    NPC();//����������� �� ���������
    NPC(int, int, float, float, string, int);//����������� �������������
    NPC(const NPC &);//����������� �����������
    ~NPC();//����������

    //������������:
    void setHP(int);
    void setMP(int);
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

};

//��������������� ������

struct node //�����
{
    NPC info;//���� ��������
    node *next, *prev;//��������� �� ���������� � ��������� ��������
};

class list //����� ������
{
private:
    node *head, *tail;//��������� �� ������ � ����� ������
public:
    list();//����������� �� ���������
    list(NPC *);//����������� �������������
    list(const list &);//����������� �����������
    ~list();//����������

    node *getHead();//��������
    node *getTail();//��������

    void addElement(NPC *);//���������� ��������
    void deleteElement(int);//�������� ��������
    int numberOfElement();//���������� ���������
};

#endif // MYCLASS_H
