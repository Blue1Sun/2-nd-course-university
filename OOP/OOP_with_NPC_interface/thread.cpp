#include "thread.h"

#include <QDebug>
#include <QString>

myThread1::myThread1()
{

}

void myThread1::run()
{
    qDebug() << "Thread1 started running (adding NPC)";
}

void myThread1::addNPC(listNPC<NPC> *mylist, int HP, int MP, float DMG, float ARM, string n, int spec)
{
    NPC *newboy = new NPC(); //создание объекта типа  НПЦ

    newboy->setHP(HP);
    newboy->setMP(MP);
    newboy->setDamage(DMG);
    newboy->setArmor(ARM);
    newboy->setName(n);
    newboy->setSpec(spec);

    mylist->addElement(newboy); //добавление

    qDebug() << "NPC" << QString::fromStdString(n) << " was added";

    emit finished();
}

myThread2::myThread2()
{

}

void myThread2::run()
{
    qDebug() << "Thread2 started running (adding Monsters)";
}

void myThread2::addNPC(listNPC<NPC> *mylist, int HP, int MP, float DMG, float ARM, int agro, string n, int spec)
{
    monster *newbadass = new monster(); //создание объекта типа  монстр

    newbadass->setHP(HP);
    newbadass->setMP(MP);
    newbadass->setDamage(DMG);
    newbadass->setArmor(ARM);
    newbadass->setName(n);
    newbadass->setSpec(spec);
    newbadass->setAgression(agro);

    mylist->addElement(newbadass); //добавление

    qDebug() << "Monster" << QString::fromStdString(n) << " was added";

    emit finished();
}

myThread3::myThread3()
{

}

void myThread3::run()
{
    qDebug() << "Thread3 started running (deleting)";
}

void myThread3::delNPC(listNPC<NPC> *mylist)
{
    string n = mylist->getHead()->info->getName(); //запись имени(дальше используется)
    mylist->deleteElement(1); //удаление головы

    qDebug() << "Object[1]" << QString::fromStdString(n) << " was deleted";

    emit finished();
}
