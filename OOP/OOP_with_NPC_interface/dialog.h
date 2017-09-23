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

    listNPC<NPC> OneList; //����� ������

    void updateUI(); //���������� ���������� ��� ��������� ������

    void HPnot0(NPC &); //�������� �������� �������� �� ��������� ����

    //������� �������� ���������� � Qstring
    QS qTranslate(string);
    QS qTranslate(int);
    QS qTranslate(float);
    QS qTranslate(char[]);

    //������� �������
    QS showList(listNPC<NPC> *); //������� ������ ������
    
private slots:

    void on_commonButton_clicked(); //������� ��� �� ���������

    void on_updateButton_clicked(); //�������� ������ ������

    void on_deleteButton_clicked(); //�������� ��������

    void on_addButton_clicked(); //�������� ��������� ���

    void on_commonButton_2_clicked(); //������� ������� �� ���������

    void on_addButton_2_clicked(); //�������� ��������� �������

    void on_saveButton_clicked(); //��������� � ����

    void on_loadButton_clicked(); //��������� �� �����

    void on_editName_clicked(); //��������� ����� ��������

    void on_editHP_clicked(); //��������� HP ��������

    void on_exitButton_clicked(); //����� �� ���������

    void on_pushButton_clicked(); //������ � ����� ����������

    void on_type2ofedit_currentIndexChanged(int index); //��� ������������ ��������� �������� ������ � ��������� spinbox �����������

    void on_pushButton_2_clicked(); //������ � ����� ���������(������ � ��� ��� ��� � ��������� ������)

    void on_pushButton_3_clicked(); //�������� ������

    void progressing(int); //��������� ������������

    void filework(); //�������������� ������������� ��������� � ������ �������� ������

private:
    Ui::Dialog *ui;

signals:
    void sendList(listNPC<NPC>*, int, int, float, float, int, string, int); //������ � ����������� ������
    void sendList(listNPC<NPC>*, int, int, float, float, string, int); //������ � ����������� �����

    void sendListtoDel(listNPC<NPC>*); //������ � ���������

    void fullness(int); //������������� ������

};



#endif // DIALOG_H
