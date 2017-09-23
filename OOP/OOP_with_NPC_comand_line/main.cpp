/*
������� ������� ����������. ���151. ������� 12�, 4.
�������� NPC(��������� ����������) � ��������������� ������.
����� �������, ��������� ����������� ��� ������: NPC � ��������������� ������.
1. ����� NPC:
�������� - ���������� ��������, ����, ��������� ����, �����, ���, ������������� -
����� �������, ��� ����������� ���������� ��� �������� �������.
����������, ����� ����, ����� ����������� ��������� ��� ��������� "������",
��� � ������, � ��������� ����������������(������������). ��� �� ���������� �����
����������� �������� ���������� � ������ �� ����� ������(���������) ��� ��
�������� ��� ��������(������������).
2. ����� ���������������� ������:
�������� - ��������� �� ������ � ����� ������, ������ ��������� �������, � ���� �������,
����� ��������� �� ���������� � ��������� �������, � ���� ��������.
����� ���������� ��� ��������� ������, ��� � � �������� �������. ����� ����,
����� ������� �� ���������� ������, � ������� �� �����������. � ����� � ������������
���������� ������, ������ �������� � ������������ �����������.
������ - ���������� ��������(�������������� ����������� �������� � ����� ������),
�������� ��������(�������������� ��������� �������� ��������� ������), ���������
����� ������.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "myclasses.h"

using namespace std;

void showNPC(NPC &obj)//������� ������ ���
{
    cout << obj.getName() << " the " << obj.getSpec() << " - " << obj.getHP() << " HP, " << obj.getMP() << " MP, " << obj.getDamage() << " DMG, " << obj.getArmor() << " ARM" << endl;

}

void showList(list *obj) //������� ������ ������
{
    node *curr;
    curr = obj->getHead();
    while (curr)
    {
        showNPC(curr->info);
        curr = curr ->next;
    }
}

int main(int argc, char const *argv[])
{
    int number, HPinput, MPinput, specializationInput;
    float damageInput, armorInput;
    string nameInput;

    cout << setw(55) <<"Welcome to Laboratory Work 1!" << endl;

    cout << setw(52) <<"Let's create some NPCs" << endl;
    NPC Noob; //����������� �� ���������
    NPC Leo(200, 507, 50, 0, "Leo", 2);//����������� �������������
    NPC Mia(600, 12, 65.4, 234.5, "Mia", 1);
    NPC Rick(423, 239, 75.3, 34.3, "Rick", 3);

    Rick.setMP(-329);//�������� ����������������� ������������

    cout << setw(49) <<"Here they are:" << endl;
    showNPC(Noob);
    showNPC(Leo);
    showNPC(Mia);
    showNPC(Rick);

    cout << endl << setw(52) <<"Now we can create list..." << endl;
    list *listOfNPC1 = new list();

    cout << setw(50) <<"And add NPCs to it..." << endl;
    listOfNPC1->addElement(&Noob);
    listOfNPC1->addElement(&Leo);
    listOfNPC1->addElement(&Mia);
    listOfNPC1->addElement(&Rick);

    cout << setw(48) <<"Let's check it:" << endl;
    showList(listOfNPC1);

    cout << endl << setw(58) <<"Or we can just create list with head:" << endl;
    list *listWithBegining = new list(&Leo);
    showList(listWithBegining);

    delete listWithBegining;

    cout << setw(50) <<"Okay, let's copy previous list to new, and delete old one" << endl;
    list *listOfNPC = new list(*listOfNPC1);
    delete listOfNPC1;

    showList(listOfNPC);

    cout << endl << setw(47) <<"Now let's play! :D" << endl;
    cout << setw(54) <<"What element you want to delete?" << endl;

    cin >> number;
    while(number <= 0 || number > listOfNPC->numberOfElement())
    {
        cout << "Please , enter 0 < element < " << listOfNPC->numberOfElement() << endl;
        cin >> number;
    }
    listOfNPC->deleteElement(number);

    cout << setw(47) <<"That's the result:" << endl;
    showList(listOfNPC);

    cout << endl << setw(65) <<"Now, let's create new NPC and add it to the list" << endl;
    cout << "Name? "; cin >> nameInput;
    cout << "Specialization? 1 = warrior, 2 = mage, 3 = rogue "; cin >> specializationInput;
    while (specializationInput != 1 && specializationInput != 2 && specializationInput != 3)
    {
        cout <<"Enter correctly, please" << endl;
        cin >> specializationInput;
    }
    cout << "HealthPoints? "; cin >> HPinput;
    while (HPinput <= 0)
    {
        cout <<"Enter correctly, please" << endl;
        cin >> HPinput;
    }
    cout << "ManaPoints? "; cin >> MPinput;
    while (MPinput <= 0)
    {
        cout <<"Enter correctly, please" << endl;
        cin >> MPinput;
    }
    cout << "Damage? "; cin >> damageInput;
    while (damageInput <= 0)
    {
        cout <<"Enter correctly, please" << endl;
        cin >> damageInput;
    }
    cout << "Armor? "; cin >> armorInput;
    while (armorInput <= 0)
    {
        cout <<"Enter correctly, please" << endl;
        cin >> armorInput;
    }

    cout << setw(50) << "Thanks! It's creating..." << endl;
    NPC OwnNPC(HPinput, MPinput, damageInput, armorInput, nameInput, specializationInput);
    listOfNPC->addElement(&OwnNPC);

    cout << endl << setw(40) << "Here!" << endl;
    showList(listOfNPC);

    cout << endl << setw(48) << "Goodbye and good luck!" << endl;
    return 0;
}

/*
  ����: ��� ����� ���� ������������� �������� � ������ �����������, ��������������, ����� ���� ���������
  ������� � main, ��� ����� ������� ������.
  �������, ���� � ��, ��� � � �������, ����������, ���������. � ����� ��������� ����� ��������� �������
  �������� ����� ������������� ������ ������, ������� ��������� ������������� ���������� ������������� ����
  � ������, ����� ������������� ������ ��� ������.
  �������� ����� � ������ ����������� ������� ���������� ��������� ���� � �����������, ���������� ������,
  ���� ����� ������� ������ �������, �� ���������� � ������ ��: ����������, ������� ���������, ������������
  � �.�.
  */
