#include "dialog.h"
#include "ui_dialog.h"

using namespace std;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)

{
    connect(this, SIGNAL(fullness(int)), this, SLOT(progressing(int))); //связывается сигнал и слот(работа с прогресс баром)
    connect(this, SIGNAL(fullness(int)), this, SLOT(filework())); //связывается сигнал и слот(синхронизация с файлом)
    ui->setupUi(this);
    QSound::play("C:/Qt/qtcreator-2.4.1/Interface_NPC/Strength2.wav"); //музыка
}

Dialog::~Dialog()
{
    delete ui;
}

//обновление интерфейса при изменении списка
void Dialog::updateUI()
{
    ui->label_num_element->setText(qTranslate(OneList.numberOfElement()));

    ui->spinBoxElement->setMaximum(OneList.numberOfElement());
    ui->spinBoxEditElement->setMaximum(OneList.numberOfElement());
    ui->spinBox->setMaximum(OneList.numberOfElement());

    ui->spinBoxElement->setValue(1);
    ui->spinBoxEditElement->setValue(1);
    ui->spinBox->setValue(1);

    emit fullness(OneList.numberOfElement()); //заполненность списка => изменение прогресс бара
}

//проверка значения здоровья на равенство нулю
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

//перевод переменных в QString
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

//функция вывода списка в QString
QS Dialog::showList(listNPC<NPC> *obj)
{
    QS result;
    node<NPC> *curr;

    //идем по списку
    curr = obj->getHead();

    while (curr)
    {
        result.append(qTranslate(curr->info->show())); //получение QString о данном монстре(элементе)
        result.append("\n");
        curr = curr ->next;
    }

    return result;
}

void Dialog::progressing(int v) //изменение прогрессБара
{
    ui->progressBar->setValue(v);
}

void Dialog::filework()//сохранение в файл
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

//СЛОТЫ:

//нажатие на кнопку "НПЦ по умолчанию"
void Dialog::on_commonButton_clicked()
{
    NPC *Usual = new NPC; //конструктор по умолчанию

    OneList.addElement(Usual); //добавление в список

    QMessageBox msg;
    msg.setText("Boring NPC was added!");
    msg.exec();

    updateUI();

}

//нажатие на кнопку "Обновить список"
void Dialog::on_updateButton_clicked()
{
    ui->textBrowser->setText(showList(&OneList)); //вывод информации в textBrowser
}

//нажатие на кнопку "Удалить элемент"
void Dialog::on_deleteButton_clicked()
{
    if (OneList.getHead() != NULL) //если список не пуст
    {
            OneList.deleteElement(ui->spinBoxElement->value()); //удаляем элемент на нужной позиции

            updateUI();
    }
    else //если список пуст - ошибка
    {
        QMessageBox msg;
        msg.setText("List is EMPTY!");
        msg.setIcon(QMessageBox::Critical);
        msg.exec();
    }

}

//нажатие на кнопку "Добавить НПЦ"
void Dialog::on_addButton_clicked()
{
    //запись в переменные, чтобы избежать нагромождения при вызове конструктора
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

    //NPC *UserNPC = new NPC(HP, MP, DMG, ARM, name, spec); //вызов конструктора
    //OneList.addElement(UserNPC); //добавление в список
    emit sendList(&OneList, HP, MP, DMG, ARM, name, spec);

    updateUI();

    //пасхалка №1
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

//нажатие на кнопку "Монстр по умолчанию"
void Dialog::on_commonButton_2_clicked()
{
    monster *Usual = new monster; //конструктор по умолчанию

    OneList.addElement(Usual); //добавление в список

    QMessageBox msg;
    msg.setText("Bunny was added!");
    msg.exec();

    updateUI();;
}

// нажатие на кнопку "Добавить Монстрa"
void Dialog::on_addButton_2_clicked()
{
    //запись в переменные, чтобы избежать нагромождения при вызове конструктора
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

    //monster *UserMonster = new monster(HP, MP, DMG, ARM, agro, name, spec); //вызов конструктора
    //OneList.addElement(UserMonster); //добавление в список
    emit sendList(&OneList, HP, MP, DMG, ARM, agro, name, spec);

    updateUI();

    //пасхалка №2
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

//нажатие на кнопку "сохранить"
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

//нажатие на кнопку "загрузить"
void Dialog::on_loadButton_clicked()
{
    ifstream file("list_of_mobs.txt");

    int i = 1;
    //очищение списка
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
                if (x[0] == '\0') //если конец - НПЦ
                {
                    NPC *UserNPC = new NPC(hp, mp, damage, armor, name, spec); //вызов конструктора
                    OneList.addElement(UserNPC); //добавление в список
                }
                else //монстр
                {
                    agro = atoi(x.c_str());
                    monster *UserMonster = new monster(hp, mp, damage, armor, agro, name, spec); //вызов конструктора
                    OneList.addElement(UserMonster); //добавление в список
                    getline(file,x); //лишняя строка
                }
             }
    }
    file.close();

    updateUI();
}

//нажатие на кнопку "имя"
void Dialog::on_editName_clicked()
{
    node<NPC> *curr;

    curr = OneList[ui->spinBoxEditElement->value()]; //применение индексации

    QS qname = ui->lineEdit->text();
    string name = qname.toStdString();

    if (OneList.getHead() != NULL) // если список не пуст
    {
        curr->info->setName(name);
    }
    else //если список пуст - ошибка
    {
        QMessageBox msg;
        msg.setText("List is EMPTY!");
        msg.setIcon(QMessageBox::Critical);
        msg.exec();
    }
}

//нажатие на кнопку "HP"
void Dialog::on_editHP_clicked()
{
    node<NPC> *curr;

    curr = OneList[ui->spinBoxEditElement->value()]; //применение индексации

    int HP = ui->spinBox_2->value();

    if (OneList.getHead() != NULL) // если список не пуст
    {
        curr->info->setHP(HP);
    }
    else //если список пуст - ошибка
    {
        QMessageBox msg;
        msg.setText("List is EMPTY!");
        msg.setIcon(QMessageBox::Critical);
        msg.exec();
    }
}

//нажатие на кнопку "EXIT"
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

//нажатие на первую кнопку "OK"
//операции над двумя объектами
void Dialog::on_pushButton_clicked()
{
    node<NPC> *curr; //указатель на первый элемент
    node<NPC> *ccurr; //указатель на второй элемент

    //применение индексации:
    curr = OneList[ui->spinBoxEditElement->value()];
    ccurr = OneList[ui->spinBox->value()];

    NPC *newNPC = new NPC;

    if (OneList.getHead() != NULL) //если список не пуст
    {
        if (ui->type1ofedit->currentIndex() == 0) //сложение двух объектов
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

        if (ui->type1ofedit->currentIndex() == 1) //вычитание  двух объектов
        {
            *newNPC = curr->info - ccurr->info;
            HPnot0(*newNPC); //проверка здоровья
        }

        if (ui->type1ofedit->currentIndex() == 2) // оператор сравнения >
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

        if (ui->type1ofedit->currentIndex() == 3) // оператор сравнения <
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

        if (ui->type1ofedit->currentIndex() == 4) // логический оператор ==
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

        if (ui->type1ofedit->currentIndex() == 5) // логический оператор !=
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
    else //если список пуст - ошибка
    {
        QMessageBox msg;
        msg.setText("List is EMPTY!");
        msg.setIcon(QMessageBox::Critical);
        msg.exec();
    }
}

//при определенных выбранных функциях доступ к изменению spinbox закрывается
void Dialog::on_type2ofedit_currentIndexChanged(int index)
{
    if (index > 2)
        ui->spinBox2->setDisabled(true); //spinbox не активен
    else
        ui->spinBox2->setDisabled(false); //spinbox активен
}

//нажатие на первую кнопку "OK"
//операции над одним объектом
void Dialog::on_pushButton_2_clicked()
{
    node<NPC> *curr; //указатель на элемент

    curr = OneList[ui->spinBoxEditElement->value()]; //применение индексации

    NPC *newNPC = new NPC;

    if (ui->type2ofedit->currentIndex() == 8) // оператор >> загрузка из файла, может происходить и при пустом списке
    {
        NPC newbie;
        FILE *f;

        f = fopen("1new.txt","r"); //открываем файл на чтение

        if (!f) //если файл не найден - ошибка
        {
            QMessageBox msg;
            msg.setText("No such file!");
            msg.setIcon(QMessageBox::Critical);
            msg.exec();
        }
        else //если файл найден - считывается объект и добавляется в список
        {
            ifstream fin ("1new.txt");
            fin >> &newbie;

            OneList.addElement(&newbie);
            updateUI();
        }
        fclose(f);
    }

    if (OneList.getHead() != NULL) //если список не пустой
        {
            if (ui->type2ofedit->currentIndex() == 0) //оператор +
            {
                *newNPC = (*curr->info) + ui->spinBox2->value();
                OneList.addElement(newNPC);

                updateUI();
            }

            if (ui->type2ofedit->currentIndex() == 1) //оператор -
            {
                *newNPC = (*curr->info) - ui->spinBox2->value();
                HPnot0(*newNPC); //проверка здоровья
            }

            if (ui->type2ofedit->currentIndex() == 2) //оператор =
            {
                (*curr->info) = ui->spinBox2->value();
            }

            if (ui->type2ofedit->currentIndex() == 3) //постфикс ++
            {
                (*curr->info)++;
            }

            if (ui->type2ofedit->currentIndex() == 4) //постфикс --
            {
                (*curr->info)--;
            }

            if (ui->type2ofedit->currentIndex() == 5) //++ префикс
            {
                ++(*curr->info);
            }

            if (ui->type2ofedit->currentIndex() == 6) //-- префикс
            {
                --(*curr->info);
            }

            if (ui->type2ofedit->currentIndex() == 7) // оператор << запись
            {
                FILE *f;

                f = fopen("1new.txt","w"); //открытие файла на запись
                ofstream fout ("1new.txt");

                fout << curr->info; //запись объекта

                fclose(f);
            }

            if (ui->type2ofedit->currentIndex() == 9) // оператор () функтор
            {
                NPC newbie = newbie(46, 56, 12, 1);
                OneList.addElement(&newbie);

                updateUI();
            }

            if (ui->type2ofedit->currentIndex() == 10) // оператор побитовый >> сдвиг вправо
            {
                *newNPC = (*curr->info) >> 1;
                HPnot0(*newNPC); //проверка здоровья
            }

            if (ui->type2ofedit->currentIndex() == 11) // оператор побитовый << сдвиг влево
            {
                *newNPC = (*curr->info) << 1;
            }

            if (ui->type2ofedit->currentIndex() == 12) // приведение типа (булевая переменная)
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
        else //если список пуст - ошибка
        {
            QMessageBox msg;
            msg.setText("List is EMPTY!");
            msg.setIcon(QMessageBox::Critical);
            msg.exec();
        }
}

void Dialog::on_pushButton_3_clicked() //удаление головы
{

    if (OneList.getHead() != NULL) //если список не пуст
    {
            emit sendListtoDel(&OneList);//поток

            updateUI();
    }
    else //если список пуст - ошибка
    {
        QMessageBox msg;
        msg.setText("List is EMPTY!");
        msg.setIcon(QMessageBox::Critical);
        msg.exec();
    }

}
