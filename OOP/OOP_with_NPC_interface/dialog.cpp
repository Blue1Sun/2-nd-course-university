#include "dialog.h"
#include "ui_dialog.h"

using namespace std;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)

{
    connect(this, SIGNAL(fullness(int)), this, SLOT(progressing(int))); //����������� ������ � ����(������ � �������� �����)
    connect(this, SIGNAL(fullness(int)), this, SLOT(filework())); //����������� ������ � ����(������������� � ������)
    ui->setupUi(this);
    QSound::play("C:/Qt/qtcreator-2.4.1/Interface_NPC/Strength2.wav"); //������
}

Dialog::~Dialog()
{
    delete ui;
}

//���������� ���������� ��� ��������� ������
void Dialog::updateUI()
{
    ui->label_num_element->setText(qTranslate(OneList.numberOfElement()));

    ui->spinBoxElement->setMaximum(OneList.numberOfElement());
    ui->spinBoxEditElement->setMaximum(OneList.numberOfElement());
    ui->spinBox->setMaximum(OneList.numberOfElement());

    ui->spinBoxElement->setValue(1);
    ui->spinBoxEditElement->setValue(1);
    ui->spinBox->setValue(1);

    emit fullness(OneList.numberOfElement()); //������������� ������ => ��������� �������� ����
}

//�������� �������� �������� �� ��������� ����
void Dialog::HPnot0(NPC &npc)
{
    if (npc.getHP() == 0)
    {
        QMessageBox msg;
        msg.setText("Your NPC is dead cuz\n it's HP became 0 :C");
        msg.setIcon(QMessageBox::Critical);
        msg.exec();
    }
    else
    {
        OneList.addElement(&npc);

        updateUI();
    }
}

//������� ���������� � QString
QS Dialog::qTranslate(string x)
{
    QS result = QS::fromStdString(x);
    return result;
}

QS Dialog::qTranslate(int x)
{
    QS result = QS::number(x);
    return result;
}

QS Dialog::qTranslate(float x)
{
    QS result = QS::number(x);
    return result;
}

QS Dialog::qTranslate(char x[])
{
    QS result = QS::fromStdString(x);
    return result;
}

//������� ������ ������ � QString
QS Dialog::showList(listNPC<NPC> *obj)
{
    QS result;
    node<NPC> *curr;

    //���� �� ������
    curr = obj->getHead();

    while (curr)
    {
        result.append(qTranslate(curr->info->show())); //��������� QString � ������ �������(��������)
        result.append("\n");
        curr = curr ->next;
    }

    return result;
}

void Dialog::progressing(int v) //��������� ������������
{
    ui->progressBar->setValue(v);
}

void Dialog::filework()//���������� � ����
{
    ofstream file("list_of_mobs.txt");

    node<NPC> *curr;
    curr = OneList.getHead();

    while (curr)
    {
        file << curr->info->fshow();
        curr = curr->next;
    }

    file.close();
}

//�����:

//������� �� ������ "��� �� ���������"
void Dialog::on_commonButton_clicked()
{
    NPC *Usual = new NPC; //����������� �� ���������

    OneList.addElement(Usual); //���������� � ������

    QMessageBox msg;
    msg.setText("Boring NPC was added!");
    msg.exec();

    updateUI();

}

//������� �� ������ "�������� ������"
void Dialog::on_updateButton_clicked()
{
    ui->textBrowser->setText(showList(&OneList)); //����� ���������� � textBrowser
}

//������� �� ������ "������� �������"
void Dialog::on_deleteButton_clicked()
{
    if (OneList.getHead() != NULL) //���� ������ �� ����
    {
            OneList.deleteElement(ui->spinBoxElement->value()); //������� ������� �� ������ �������

            updateUI();
    }
    else //���� ������ ���� - ������
    {
        QMessageBox msg;
        msg.setText("List is EMPTY!");
        msg.setIcon(QMessageBox::Critical);
        msg.exec();
    }

}

//������� �� ������ "�������� ���"
void Dialog::on_addButton_clicked()
{
    //������ � ����������, ����� �������� ������������� ��� ������ ������������
    int HP = ui->spinBoxHP->value();
    int MP = ui->spinBoxMP->value();

    float DMG = ui->doubleSpinBoxDMG->value();
    float ARM = ui->doubleSpinBoxARM->value();

    QS qname = ui->lineEditName->text();
    string name = qname.toStdString();

    int spec;
    if (ui->warriorButton->isChecked())
        spec = 1;
    if (ui->mageButton->isChecked())
        spec = 2;
    if (ui->rogueButton->isChecked())
        spec = 3;

    //NPC *UserNPC = new NPC(HP, MP, DMG, ARM, name, spec); //����� ������������
    //OneList.addElement(UserNPC); //���������� � ������
    emit sendList(&OneList, HP, MP, DMG, ARM, name, spec);

    updateUI();

    //�������� �1
    if (HP == ui->spinBoxHP->maximum() || MP == ui->spinBoxMP->maximum()
            || DMG == ui->doubleSpinBoxDMG->maximum() || ARM == ui->doubleSpinBoxARM->maximum())
    {
        QMessageBox msg;
        msg.setText("Why so GODLIKE???");
        msg.setInformativeText("Anyway, I added it...");
        msg.addButton(tr("Okay :C"), QMessageBox::AcceptRole);
        msg.setIcon(QMessageBox::Question);
        msg.exec();
    }
}

//������� �� ������ "������ �� ���������"
void Dialog::on_commonButton_2_clicked()
{
    monster *Usual = new monster; //����������� �� ���������

    OneList.addElement(Usual); //���������� � ������

    QMessageBox msg;
    msg.setText("Bunny was added!");
    msg.exec();

    updateUI();;
}

// ������� �� ������ "�������� ������a"
void Dialog::on_addButton_2_clicked()
{
    //������ � ����������, ����� �������� ������������� ��� ������ ������������
    int HP = ui->spinBoxHP_3->value();
    int MP = ui->spinBoxMP_3->value();

    float DMG = ui->doubleSpinBoxDMG_3->value();
    float ARM = ui->doubleSpinBoxARM_3->value();

    int agro = ui->spinBoxAGRO->value();

    QS qname = ui->lineEditName_2->text();
    string name = qname.toStdString();

    int spec;
    if (ui->warriorButton_2->isChecked())
        spec = 1;
    if (ui->mageButton_2->isChecked())
        spec = 2;
    if (ui->rogueButton_2->isChecked())
        spec = 3;

    //monster *UserMonster = new monster(HP, MP, DMG, ARM, agro, name, spec); //����� ������������
    //OneList.addElement(UserMonster); //���������� � ������
    emit sendList(&OneList, HP, MP, DMG, ARM, agro, name, spec);

    updateUI();

    //�������� �2
    if (HP == ui->spinBoxHP_3->maximum() || MP == ui->spinBoxMP_3->maximum()
            || DMG == ui->doubleSpinBoxDMG_3->maximum() || ARM == ui->doubleSpinBoxARM_3->maximum())
    {
        QMessageBox msg;
        msg.setText("Why so OVERPOWERED???");
        msg.setInformativeText("Anyway, I added it...");
        msg.addButton(tr("Okay :C"), QMessageBox::AcceptRole);
        msg.setIcon(QMessageBox::Question);
        msg.exec();
    }
}

//������� �� ������ "���������"
void Dialog::on_saveButton_clicked()
{
    ofstream file("list_of_mobs.txt");

    node<NPC> *curr;
    curr = OneList.getHead();

    while (curr)
    {
        file << curr->info->fshow();
        curr = curr->next;
    }

    file.close();
}

//������� �� ������ "���������"
void Dialog::on_loadButton_clicked()
{
    ifstream file("list_of_mobs.txt");

    int i = 1;
    //�������� ������
    while (OneList.getHead() != NULL)
    {
        OneList.deleteElement(1);
        i++;
    }

    string name, sspec, x;
    int hp, mp, agro;
    float damage, armor;

    while(!file.eof())
    {
        if(!file.eof())
            getline(file,name);
        if(!file.eof())
            getline(file,sspec);
        int spec;
        if (sspec == "Warrior")
            spec = 1;
        if (sspec == "Mage")
            spec = 2;
        if (sspec == "Rogue")
            spec = 3;
        if(!file.eof())
            getline(file,x);
        hp = atoi(x.c_str());
        if(!file.eof())
            getline(file,x);
        mp = atoi(x.c_str());
        if(!file.eof())
            getline(file,x);
        damage = atof(x.c_str());
        if(!file.eof())
            getline(file,x);
        armor = atof(x.c_str());
        if (!file.eof())
            {
                getline(file,x);
                if (x[0] == '\0') //���� ����� - ���
                {
                    NPC *UserNPC = new NPC(hp, mp, damage, armor, name, spec); //����� ������������
                    OneList.addElement(UserNPC); //���������� � ������
                }
                else //������
                {
                    agro = atoi(x.c_str());
                    monster *UserMonster = new monster(hp, mp, damage, armor, agro, name, spec); //����� ������������
                    OneList.addElement(UserMonster); //���������� � ������
                    getline(file,x); //������ ������
                }
             }
    }
    file.close();

    updateUI();
}

//������� �� ������ "���"
void Dialog::on_editName_clicked()
{
    node<NPC> *curr;

    curr = OneList[ui->spinBoxEditElement->value()]; //���������� ����������

    QS qname = ui->lineEdit->text();
    string name = qname.toStdString();

    if (OneList.getHead() != NULL) // ���� ������ �� ����
    {
        curr->info->setName(name);
    }
    else //���� ������ ���� - ������
    {
        QMessageBox msg;
        msg.setText("List is EMPTY!");
        msg.setIcon(QMessageBox::Critical);
        msg.exec();
    }
}

//������� �� ������ "HP"
void Dialog::on_editHP_clicked()
{
    node<NPC> *curr;

    curr = OneList[ui->spinBoxEditElement->value()]; //���������� ����������

    int HP = ui->spinBox_2->value();

    if (OneList.getHead() != NULL) // ���� ������ �� ����
    {
        curr->info->setHP(HP);
    }
    else //���� ������ ���� - ������
    {
        QMessageBox msg;
        msg.setText("List is EMPTY!");
        msg.setIcon(QMessageBox::Critical);
        msg.exec();
    }
}

//������� �� ������ "EXIT"
void Dialog::on_exitButton_clicked()
{
    int res = QMessageBox::information(this,"EXIT", "Are you sure?",QMessageBox::Yes | QMessageBox::No );

    switch(res)
    {
        case QMessageBox::Yes:
            Dialog::close();
        break;

        case QMessageBox::No:

        break;
    }
}

//������� �� ������ ������ "OK"
//�������� ��� ����� ���������
void Dialog::on_pushButton_clicked()
{
    node<NPC> *curr; //��������� �� ������ �������
    node<NPC> *ccurr; //��������� �� ������ �������

    //���������� ����������:
    curr = OneList[ui->spinBoxEditElement->value()];
    ccurr = OneList[ui->spinBox->value()];

    NPC *newNPC = new NPC;

    if (OneList.getHead() != NULL) //���� ������ �� ����
    {
        if (ui->type1ofedit->currentIndex() == 0) //�������� ���� ��������
        {
            *newNPC = (*curr->info) + (*ccurr->info);

            NPC *newNPC2 = new NPC;

            *newNPC2 = plussing(*curr->info, *ccurr->info);

            OneList.addElement(newNPC);
            OneList.addElement(newNPC2);

            if (*newNPC == *newNPC2)
            {
                QMessageBox msg;
                msg.setText("FUNCTION WORK!");
                msg.exec();
            }


            updateUI();
        }

        if (ui->type1ofedit->currentIndex() == 1) //���������  ���� ��������
        {
            *newNPC = curr->info - ccurr->info;
            HPnot0(*newNPC); //�������� ��������
        }

        if (ui->type1ofedit->currentIndex() == 2) // �������� ��������� >
        {
            if (curr->info > ccurr->info)
            {
                QMessageBox msg;
                msg.setText("True!");
                msg.exec();
            }
            else
            {
                QMessageBox msg;
                msg.setText("False!");
                msg.exec();
            }
        }

        if (ui->type1ofedit->currentIndex() == 3) // �������� ��������� <
        {
            if (curr->info < ccurr->info)
            {
                QMessageBox msg;
                msg.setText("True!");
                msg.exec();
            }
            else
            {
                QMessageBox msg;
                msg.setText("False!");
                msg.exec();
            }
        }

        if (ui->type1ofedit->currentIndex() == 4) // ���������� �������� ==
        {
            if (curr->info == ccurr->info)
            {
                QMessageBox msg;
                msg.setText("They are the same!");
                msg.exec();
            }
            else
            {
                QMessageBox msg;
                msg.setText("They are NOT the same!");
                msg.exec();
            }
        }

        if (ui->type1ofedit->currentIndex() == 5) // ���������� �������� !=
        {
            if (curr->info != ccurr->info)
            {
                QMessageBox msg;
                msg.setText("They are NOT the same!");
                msg.exec();
            }
            else
            {
                QMessageBox msg;
                msg.setText("They are the same!");
                msg.exec();
            }
        }
    }
    else //���� ������ ���� - ������
    {
        QMessageBox msg;
        msg.setText("List is EMPTY!");
        msg.setIcon(QMessageBox::Critical);
        msg.exec();
    }
}

//��� ������������ ��������� �������� ������ � ��������� spinbox �����������
void Dialog::on_type2ofedit_currentIndexChanged(int index)
{
    if (index > 2)
        ui->spinBox2->setDisabled(true); //spinbox �� �������
    else
        ui->spinBox2->setDisabled(false); //spinbox �������
}

//������� �� ������ ������ "OK"
//�������� ��� ����� ��������
void Dialog::on_pushButton_2_clicked()
{
    node<NPC> *curr; //��������� �� �������

    curr = OneList[ui->spinBoxEditElement->value()]; //���������� ����������

    NPC *newNPC = new NPC;

    if (ui->type2ofedit->currentIndex() == 8) // �������� >> �������� �� �����, ����� ����������� � ��� ������ ������
    {
        NPC newbie;
        FILE *f;

        f = fopen("1new.txt","r"); //��������� ���� �� ������

        if (!f) //���� ���� �� ������ - ������
        {
            QMessageBox msg;
            msg.setText("No such file!");
            msg.setIcon(QMessageBox::Critical);
            msg.exec();
        }
        else //���� ���� ������ - ����������� ������ � ����������� � ������
        {
            ifstream fin ("1new.txt");
            fin >> &newbie;

            OneList.addElement(&newbie);
            updateUI();
        }
        fclose(f);
    }

    if (OneList.getHead() != NULL) //���� ������ �� ������
        {
            if (ui->type2ofedit->currentIndex() == 0) //�������� +
            {
                *newNPC = (*curr->info) + ui->spinBox2->value();
                OneList.addElement(newNPC);

                updateUI();
            }

            if (ui->type2ofedit->currentIndex() == 1) //�������� -
            {
                *newNPC = (*curr->info) - ui->spinBox2->value();
                HPnot0(*newNPC); //�������� ��������
            }

            if (ui->type2ofedit->currentIndex() == 2) //�������� =
            {
                (*curr->info) = ui->spinBox2->value();
            }

            if (ui->type2ofedit->currentIndex() == 3) //�������� ++
            {
                (*curr->info)++;
            }

            if (ui->type2ofedit->currentIndex() == 4) //�������� --
            {
                (*curr->info)--;
            }

            if (ui->type2ofedit->currentIndex() == 5) //++ �������
            {
                ++(*curr->info);
            }

            if (ui->type2ofedit->currentIndex() == 6) //-- �������
            {
                --(*curr->info);
            }

            if (ui->type2ofedit->currentIndex() == 7) // �������� << ������
            {
                FILE *f;

                f = fopen("1new.txt","w"); //�������� ����� �� ������
                ofstream fout ("1new.txt");

                fout << curr->info; //������ �������

                fclose(f);
            }

            if (ui->type2ofedit->currentIndex() == 9) // �������� () �������
            {
                NPC newbie = newbie(46, 56, 12, 1);
                OneList.addElement(&newbie);

                updateUI();
            }

            if (ui->type2ofedit->currentIndex() == 10) // �������� ��������� >> ����� ������
            {
                *newNPC = (*curr->info) >> 1;
                HPnot0(*newNPC); //�������� ��������
            }

            if (ui->type2ofedit->currentIndex() == 11) // �������� ��������� << ����� �����
            {
                *newNPC = (*curr->info) << 1;
            }

            if (ui->type2ofedit->currentIndex() == 12) // ���������� ���� (������� ����������)
            {
                if (curr->info)
                {
                    QMessageBox msg;
                    msg.setText("True!");
                    msg.exec();
                }
                else
                {
                    QMessageBox msg;
                    msg.setText("False!");
                    msg.exec();
                }
            }
        }
        else //���� ������ ���� - ������
        {
            QMessageBox msg;
            msg.setText("List is EMPTY!");
            msg.setIcon(QMessageBox::Critical);
            msg.exec();
        }
}

void Dialog::on_pushButton_3_clicked() //�������� ������
{

    if (OneList.getHead() != NULL) //���� ������ �� ����
    {
            emit sendListtoDel(&OneList);//�����

            updateUI();
    }
    else //���� ������ ���� - ������
    {
        QMessageBox msg;
        msg.setText("List is EMPTY!");
        msg.setIcon(QMessageBox::Critical);
        msg.exec();
    }

}
