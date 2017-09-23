/*
������� ������� ����������. ���151. ������� 12�, 4.
�������� NPC(��������� ����������) � ��������������� ������.
���������� ��������� ����������.
������ ���������: Ver. 6.
1. ������ �����, ���� ���� ��������� ����� �������� ����������: ������ ��� ������ � �������,
���������� �������� �������� � ������ ������, � ��� �� ProgressBar, ������������ �������������
������.
2. ����� ��� ������� ����� ����� �������, ������������� � ��������� ����� �� ������ �������.
����� ���� ������� 3 ������ - ��� ����������, ��� ������� ������, � ���� ��������. �� ���� ������
������������ � ��������������.
3. ����� ����� ���� ���� ������� ������� �� �������� ���� � ����� � �������, � ��� �� ��������� ������
� ProgressBar. ����������� �������� � ������� �������, � ��� �� ���������� ���������. ��������� mutex.
4. ������ � ������� �������� ��������� ���������, ��������� � progressbar
*/

#include <QtGui/QApplication>
#include "dialog.h"

//�������� ����� � ���� <<
ofstream& operator << (ofstream& file, const NPC& npc)
{
    file << npc.name << "\n";
    file << npc.specialization << "\n";
    file << npc.HealthPoints << "\n";
    file << npc.ManaPoints << "\n";
    file << npc.damage << "\n";
    file << npc.armor << "\n";

    return file;
}

//�������� ������ �� ����� >>
ifstream& operator >> (ifstream& file, NPC* npc)
{
    string name, sspec, x;
    int hp, mp, spec;
    float damage, armor;

    getline(file,name); //���������� ������ � ������

    getline(file,sspec); //���������� ������ �� �������������� � ���������� �� ����������� � int
    if (sspec == "Warrior")
        spec = 1;
    if (sspec == "Mage")
        spec = 2;
    if (sspec == "Rogue")
        spec = 3;

    getline(file,x); //���������� ������ � HP
    hp = atoi(x.c_str()); //������� string � int

    getline(file,x); //���������� ������ � MP
    mp = atoi(x.c_str()); //������� string � int

    getline(file,x); //���������� ������ � ������
    damage = atof(x.c_str()); //������� string � float

    getline(file,x); //���������� ������ � �������
    armor = atof(x.c_str()); //������� string � float

    //������ � ������:
    npc->setName(name);
    npc->setSpec(spec);
    npc->setHP(hp);
    npc->setMP(mp);
    npc->setDamage(damage);
    npc->setArmor(armor);

    return file;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;

    myThread1 thread1; //�����, ���������� �� ���������� ���
    myThread2 thread2; //�����, ���������� �� ���������� ��������
    myThread3 thread3; //�����, ���������� �� ��������


    //������� �� �������� ���� ����������� �� ������� �������
    QObject::connect(&w, SIGNAL(sendList(listNPC<NPC>*,int, int, float, float, string, int)),
                     &thread1, SLOT(addNPC(listNPC<NPC>*,int, int, float, float, string, int)));

    QObject::connect(&w, SIGNAL(sendList(listNPC<NPC>*,int, int, float, float, int, string, int)),
                     &thread2, SLOT(addNPC(listNPC<NPC>*,int, int, float, float, int, string, int)));

    QObject::connect(&w, SIGNAL(sendListtoDel(listNPC<NPC>*)),&thread3, SLOT(delNPC(listNPC<NPC>*)));


    //������ ������
    thread1.start();
    thread2.start();
    thread3.start();


    w.show();

    return a.exec();
}

/*
  ����: ���� ���� ������������ ������������ ���������������, �������������� ������, qdebug,
  �������� �������-������. �� ����� ���������� ���� ������������ �����, ��������� ���� ����� ���
  �����������������. ���� ��������� ��������� �������, ������� �� ������ �������� ������ ���������,
  ������� ������������ �� ���, ��� ���� ������� ���� � ����� ������ ������. ���� ���� �������:
  1. ������, ������������, ��������� � ������������.
  2. ���������, ���������������� ��� ��������� �������, QMessageBox.
  3. ������������ � ���������� �������, ������ � �������.
  4. ���������� ��������� ����������, ������������� �� ���, ��� ������ ����������� ������ ����� �������.
  5. ������������� ��������, ������ ����������� ������.
  6. ���������������, ������������� mutex.
  ����� �������, ��������� ���� ����������� ������������� � ��������.

*/
