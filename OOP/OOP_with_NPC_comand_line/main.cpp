/*
Жалкова Наталия Евгеньевна. БИВ151. Задания 12а, 4.
Хранение NPC(неигровых персонажей) в двунаправленном списке.
Таким образом, требуется разработать двя класса: NPC и двунаправленный список.
1. Класс NPC:
Свойства - количество здоровья, маны, наносимый урон, броня, имя, специализация -
иными словами, вся необходимая информация для описания объекта.
Необходимо, кроме того, иметь возможность создавать как некоторую "основу",
так и объект, с заданными характеристиками(конструкторы). Так же необходимо иметь
возможность получить информацию о каждом из полей класса(селекторы) или же
изменить его значение(модификаторы).
2. Класс двунаправленного списка:
Свойства - указатели на начало и конец списка, каждый отдельный элемент, в свою очередь,
имеет указатель на предыдущий и следующий элемент, и поле значения.
Класс необходимо как создавать пустым, так и с заданным началом. Кроме того,
нужно следить за выделением памяти, е забывая ее освобождать. В связи с динамическим
выделением памяти, нельзя забывать о конструкторе копирования.
Методы - добавление элемента(осуществляется добавлением элемента к конец списка),
удаление элемента(осуществляется удалением элемента заданного номера), получение
длины списка.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "myclasses.h"

using namespace std;

void showNPC(NPC &obj)//функция вывода НПЦ
{
    cout << obj.getName() << " the " << obj.getSpec() << " - " << obj.getHP() << " HP, " << obj.getMP() << " MP, " << obj.getDamage() << " DMG, " << obj.getArmor() << " ARM" << endl;

}

void showList(list *obj) //функция вывода списка
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
    NPC Noob; //конструктор по умолчанию
    NPC Leo(200, 507, 50, 0, "Leo", 2);//конструктор инициализации
    NPC Mia(600, 12, 65.4, 234.5, "Mia", 1);
    NPC Rick(423, 239, 75.3, 34.3, "Rick", 3);

    Rick.setMP(-329);//проверка интеллектуального модификатора

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
  Итог: все ранее мною перечисленные свойства и методы реализованы, протестированы, кроме того добавлены
  функции в main, для более удобной работы.
  Впрочем, есть и то, что я в будущем, несомненно, доработаю. К этому относятся самые различные функции
  проверки ввода пользователем верных данных, перевод введенных пользователем переменных неправильного вида
  в верный, более разнообразные методы для класса.
  Конечной целью я ставлю превращение данного небольшого фрагмента кода в полноценный, интересный проект,
  куда будут входить другие понятия, не затронутые в данной ЛР: перегрузка, внешний интерфейс, наследование
  и т.д.
  */
