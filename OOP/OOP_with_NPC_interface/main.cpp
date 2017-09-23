/*
Жалкова Наталия Евгеньевна. БИВ151. Задания 12а, 4.
Хранение NPC(неигровых персонажей) в двунаправленном списке.
Перегрузки различных операторов.
Версия программы: Ver. 6.
1. Прежде всего, мною были добавлены новые элементы интерфейса: кнопка для работы с потоком,
вызывающая удаление элемента в начале списка, а так же ProgressBar, отображающий наполненность
списка.
2. Затем был написан новый класс потоков, реализованный в отдельном файле от других классов.
Всего было создано 3 потока - два добавления, для каждого класса, и одно удаление. То есть потоки
потребителей и производителей.
3. После этого мною были связаны сигналы из главного окна и слоты у потоков, а так же проведена работа
с ProgressBar. Реализовано удаление с помощью потоков, а так же добавление элементов. Добавлены mutex.
4. Работа в потоках вызывает различные сообщения, выводимые в progressbar
*/

#include <QtGui/QApplication>
#include "dialog.h"

//оператор ввода в файл <<
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

//оператор вывода из файла >>
ifstream& operator >> (ifstream& file, NPC* npc)
{
    string name, sspec, x;
    int hp, mp, spec;
    float damage, armor;

    getline(file,name); //считывание строки с именем

    getline(file,sspec); //считывание строки со специализацией и дальшейшая ее конвертация в int
    if (sspec == "Warrior")
        spec = 1;
    if (sspec == "Mage")
        spec = 2;
    if (sspec == "Rogue")
        spec = 3;

    getline(file,x); //считывание строки с HP
    hp = atoi(x.c_str()); //перевод string в int

    getline(file,x); //считывание строки с MP
    mp = atoi(x.c_str()); //перевод string в int

    getline(file,x); //считывание строки с уроном
    damage = atof(x.c_str()); //перевод string в float

    getline(file,x); //считывание строки с защитой
    armor = atof(x.c_str()); //перевод string в float

    //запись в объект:
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

    myThread1 thread1; //поток, отвечающий за добавление нпц
    myThread2 thread2; //поток, отвечающий за добавление монстров
    myThread3 thread3; //поток, отвечающий за удаление


    //сигналы из главного окна связываются со слотами потоков
    QObject::connect(&w, SIGNAL(sendList(listNPC<NPC>*,int, int, float, float, string, int)),
                     &thread1, SLOT(addNPC(listNPC<NPC>*,int, int, float, float, string, int)));

    QObject::connect(&w, SIGNAL(sendList(listNPC<NPC>*,int, int, float, float, int, string, int)),
                     &thread2, SLOT(addNPC(listNPC<NPC>*,int, int, float, float, int, string, int)));

    QObject::connect(&w, SIGNAL(sendListtoDel(listNPC<NPC>*)),&thread3, SLOT(delNPC(listNPC<NPC>*)));


    //начало работы
    thread1.start();
    thread2.start();
    thread3.start();


    w.show();

    return a.exec();
}

/*
  Итог: мною были использованы преимущества многопоточности, использовались потоки, qdebug,
  механизм событий-слотов. Во время выполнения всех лабораторных работ, программа была много раз
  усовершенствована. Было добавлено множество функций, которые во многом улучшили работу программы,
  заметно отличающейся от той, что была создана мною в самом начале работы. Мною были изучены:
  1. Классы, конструкторы, селекторы и модификаторы.
  2. Интерфейс, подстраивающийся под изменение размера, QMessageBox.
  3. Наследование и перегрузка методов, работа с файлами.
  4. Перегрузка множества операторов, использование их там, где раньше приходилось писать целые функции.
  5. Использование шаблонов, полная переработка списка.
  6. Многопоточность, использование mutex.
  Таким образом, программа была значительно преобразована и улучшена.

*/
