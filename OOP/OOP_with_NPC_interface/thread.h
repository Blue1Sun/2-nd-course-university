#ifndef THREAD_H
#define THREAD_H
#include <QThread>
#include "myclasses.h"

//добавление НПЦ
class myThread1 : public QThread
{
    Q_OBJECT
public:
    myThread1();
    void run();

public slots:
    void addNPC(listNPC<NPC> *,int, int, float, float, string, int);

signals:
    void finished();
};

//добавление монстра
class myThread2 : public QThread
{
    Q_OBJECT
public:
    myThread2();
    void run();

public slots:
    void addNPC(listNPC<NPC> *,int, int, float, float, int, string, int);

signals:
    void finished();
};

//удаление
class myThread3 : public QThread
{
    Q_OBJECT
public:
    myThread3();
    void run();

public slots:
    void delNPC(listNPC<NPC> *);

signals:
    void finished();
};

#endif // THREAD_H
