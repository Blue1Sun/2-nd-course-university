#include "game.h"
#include "ui_game.h"


game::game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Window
        | Qt::WindowMinimizeButtonHint
        | Qt::CustomizeWindowHint); //������ ������� � ������ ���������� �� ���� �����

    QSound::play("music.wav"); //������

    GenerateMap(); //��������� �����
    showMap(); //�����������

}

game::~game()
{
    delete ui;
}

//��������� �����
void game::GenerateMap()
{
    for (int x = 0; x < 28; x++)
        for (int y = 0; y < 60; y++)
        {
            if (x == 0 || y == 0 || y == 59 || x == 27)
                myMap[x][y] = '#'; //������� ����
            else
                myMap[x][y] = ' '; //������ �����
        }

    stopingSymbols[0] = '#'; //���������� � ������ ��������������� �������� �����

    pickingSymbols[0] = 'A'; //���������� � ������ ����������� �������� A � T
    pickingSymbols[1] = 'T';

    //������ ������ �����
    for (int x = 1; x < 27; x++)
        for (int y = 1; y < 59; y++)
        {
            if (((rand()%90 + 10) > 80) && ((x != You.getPositionX() && y != You.getPositionY())
                                         && (x != CoolGuy.getPositionX() && y != CoolGuy.getPositionY())&& (x != CoolGuyFriend.getPositionX() && y != CoolGuyFriend.getPositionY())))
                //�������� ������������ ����� � �������� ����������
                myMap[x][y] = '#';
            else
                myMap[x][y] = ' ';
            //����������� ����������� �������, ���� ��� �����
            if (myMap[x][y] != '#' && (rand()%900 + 0) > 868)
            {
                if ((rand()%2 + 1) == 1)
                    myMap[x][y] = 'A';
                else
                    myMap[x][y] = 'T';
            }
        }
}

//����������� �����
void game::showMap()
{
    QString qresult = "";

    for (int i = 0; i < 28; i++)
    {
        for (int j = 0; j < 60; j++)
        {
            if (i == You.getPositionX() && j == You.getPositionY()) //��������� ������� ������
                qresult.append(You.getSymbol());
            else if (i == CoolGuy.getPositionX() && j == CoolGuy.getPositionY()) //��������� ������� �����1
                qresult.append(CoolGuy.getSymbol());
            else if (i == CoolGuyFriend.getPositionX() && j == CoolGuyFriend.getPositionY()) //��������� ������� �����2
                qresult.append(CoolGuyFriend.getSymbol());
            else //���� ��� ������/����� - �������� ������ � �����
                qresult.append(myMap[i][j]);
        }
        if (i != 27) //������� �� ����� ������
            qresult.append("\n");
    }
    ui->MapUI->setText(qresult); //����� � �����
}

//��������, ����� �� ����������
bool game::CheckMoving(int x, int y)
{
    bool canMove = true; //���������� �����
    QChar targetSymbol = myMap[x][y]; //������, ���� ����� ��������

    if (targetSymbol == stopingSymbols[0]) //���� ������ �����������
        canMove = false; //������ ���� ������
    if (targetSymbol == pickingSymbols[0] || targetSymbol == pickingSymbols[1]) //���� ������ �����������
    {
        You.setPickedItems(targetSymbol.toAscii()); //����������� � ������ �����������
        You.setPickedItemsCount(You.getPickedItemsCount()+1); //������������� ���������� �����������
        ui->textMap->setText("Items: "+ QString::number(You.getPickedItemsCount())); //����� ��� ������
        myMap[x][y] = ' '; //����� ���������� ������
    }
    return canMove;
}

//�������� �� ����� ����
void game:: IsEnding(enemy slayer, player victim)
{
    if ((slayer.getPositionX() == victim.getPositionX()) &&(slayer.getPositionY() == victim.getPositionY()))
        //���� ���������� ������ � ����� �����
    {
        //���������� �� ������ � ��� ����������� ������������ � ��������������� � ����
        ofstream file;
        file.open("records.txt", std::ios_base::app);

        string msg = to_string(You.getPickedItemsCount())+" Items : ";

        for (int i = 0; i < You.getPickedItemsCount(); i++)
            msg = msg + to_string(You.getPickedItems(i));

        msg = game_shifer(msg+"\nlying\n");
        file << msg;

        file.close();

        //����� ����� ��������� ���������
        int res = QMessageBox::information(this,"END!!!", "THAT'S YOUR END\nAre you crying?",QMessageBox::Yes );

        switch(res)
        {
            case QMessageBox::Yes:
                game::close();
            break;
        }
    }
}

void game::UnitsMoving(int x, int y)
{
    //���� ����� ����� ��������� - ����������
    if (CheckMoving(You.getPositionX() + x,You.getPositionY() + y))
        You.moving(x,y);

    int enemyX = CoolGuy.getPositionX(); //�� ���������
    int enemyY = CoolGuy.getPositionY();
    int enemyX2 = CoolGuyFriend.getPositionX(); //�� ���������
    int enemyY2 = CoolGuyFriend.getPositionY();

    CoolGuy.moving(You); //�������� �����1
    CoolGuyFriend.moving(You); //�������� �����2

    //���� ����1 �� ����� ���������� ����, ���� ����� - ���������� ������������
    if (myMap[CoolGuy.getPositionX()][CoolGuy.getPositionY()] == '#')
    {
        CoolGuy.setPositionX(enemyX);
        CoolGuy.setPositionY(enemyY);
    }
    //���������� ��� ����2
    if (myMap[CoolGuyFriend.getPositionX()][CoolGuyFriend.getPositionY()] == '#')
    {
        CoolGuyFriend.setPositionX(enemyX2);
        CoolGuyFriend.setPositionY(enemyY2);
    }
}

//������� �� "�����"
void game::on_up_clicked()
{
    //����� ������� �������� ������
    UnitsMoving(-1, 0);

    //��������� �����
    showMap();

    //�������� �� ����� ����
    IsEnding(CoolGuy, You);
    IsEnding(CoolGuyFriend, You);

}

//������� �� "����". ���������� "�����"
void game::on_down_clicked()
{
    UnitsMoving(1, 0);

    showMap();

    IsEnding(CoolGuy, You);
    IsEnding(CoolGuyFriend, You);

}

//������� �� "�����". ���������� "�����"
void game::on_left_clicked()
{
    UnitsMoving(0, -1);

    showMap();

    IsEnding(CoolGuy, You);
    IsEnding(CoolGuyFriend, You);

}

//������� �� "������". ���������� "�����"
void game::on_right_clicked()
{
    UnitsMoving(0, 1);

    showMap();

    IsEnding(CoolGuy, You);
    IsEnding(CoolGuyFriend, You);
}

//��������
string game::game_shifer(string str)
{
    for (int n = 0; n < str.length(); n++)
        str[n] = str[n] ^ 1001; //XOR
    return str;
}
