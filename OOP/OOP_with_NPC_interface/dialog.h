#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QSound>

#include <string>

#include <fstream>
#include <iostream>

#include "myclasses.h"
#include "thread.h"

using namespace std;

typedef QString QS;

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:

    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    listNPC<NPC> OneList; //общий список

    void updateUI(); //обновление интерфейса при изменении списка

    void HPnot0(NPC &); //проверка значения здоровья на равенство нулю

    //функции перевода переменных в Qstring
    QS qTranslate(string);
    QS qTranslate(int);
    QS qTranslate(float);
    QS qTranslate(char[]);

    //функции выводов
    QS showList(listNPC<NPC> *); //функция вывода списка
    
private slots:

    void on_commonButton_clicked(); //создать НПЦ по умолчанию

    void on_updateButton_clicked(); //обновить окошко вывода

    void on_deleteButton_clicked(); //удаление элемента

    void on_addButton_clicked(); //добавить заданного НПЦ

    void on_commonButton_2_clicked(); //создать монстра по умолчанию

    void on_addButton_2_clicked(); //добавить заданного монстра

    void on_saveButton_clicked(); //сохранить в файл

    void on_loadButton_clicked(); //загрузить из файла

    void on_editName_clicked(); //изменение имени элемента

    void on_editHP_clicked(); //изменение HP элемента

    void on_exitButton_clicked(); //выход из программы

    void on_pushButton_clicked(); //работа с двумя элементами

    void on_type2ofedit_currentIndexChanged(int index); //при определенных выбранных функциях доступ к изменению spinbox закрывается

    void on_pushButton_2_clicked(); //работа с одним элементом(только с ним или еще с введенным числом)

    void on_pushButton_3_clicked(); //удаление головы

    void progressing(int); //изменение прогрессБара

    void filework(); //Автоматическая синхронизация хранилища с файлом хранения данных

private:
    Ui::Dialog *ui;

signals:
    void sendList(listNPC<NPC>*, int, int, float, float, int, string, int); //работа с добавлением монстр
    void sendList(listNPC<NPC>*, int, int, float, float, string, int); //работа с добавлением НПЦра

    void sendListtoDel(listNPC<NPC>*); //работа с удалением

    void fullness(int); //заполненность списка

};



#endif // DIALOG_H
