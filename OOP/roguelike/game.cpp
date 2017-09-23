#include "game.h"
#include "ui_game.h"


game::game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Window
        | Qt::WindowMinimizeButtonHint
        | Qt::CustomizeWindowHint); //убираю крестик и кнопку развернуть на весь экран

    QSound::play("music.wav"); //музыка

    GenerateMap(); //генераци€ карты
    showMap(); //отображение

}

game::~game()
{
    delete ui;
}

//генераци€ карты
void game::GenerateMap()
{
    for (int x = 0; x < 28; x++)
        for (int y = 0; y < 60; y++)
        {
            if (x == 0 || y == 0 || y == 59 || x == 27)
                myMap[x][y] = '#'; //границы окна
            else
                myMap[x][y] = ' '; //внутри пусто
        }

    stopingSymbols[0] = '#'; //записываем в массив останавливающих символов стену

    pickingSymbols[0] = 'A'; //записываем в массив поднимаемых символов A и T
    pickingSymbols[1] = 'T';

    //внутри границ карты
    for (int x = 1; x < 27; x++)
        for (int y = 1; y < 59; y++)
        {
            if (((rand()%90 + 10) > 80) && ((x != You.getPositionX() && y != You.getPositionY())
                                         && (x != CoolGuy.getPositionX() && y != CoolGuy.getPositionY())&& (x != CoolGuyFriend.getPositionX() && y != CoolGuyFriend.getPositionY())))
                //рандомно выставл€ютс€ стены и открытые промежутки
                myMap[x][y] = '#';
            else
                myMap[x][y] = ' ';
            //добавл€ютс€ подбираемые символы, если нет стены
            if (myMap[x][y] != '#' && (rand()%900 + 0) > 868)
            {
                if ((rand()%2 + 1) == 1)
                    myMap[x][y] = 'A';
                else
                    myMap[x][y] = 'T';
            }
        }
}

//отображение карты
void game::showMap()
{
    QString qresult = "";

    for (int i = 0; i < 28; i++)
    {
        for (int j = 0; j < 60; j++)
        {
            if (i == You.getPositionX() && j == You.getPositionY()) //отрисовка символа игрока
                qresult.append(You.getSymbol());
            else if (i == CoolGuy.getPositionX() && j == CoolGuy.getPositionY()) //отрисовка символа врага1
                qresult.append(CoolGuy.getSymbol());
            else if (i == CoolGuyFriend.getPositionX() && j == CoolGuyFriend.getPositionY()) //отрисовка символа врага2
                qresult.append(CoolGuyFriend.getSymbol());
            else //если нет игрока/врага - рисуетс€ символ с карты
                qresult.append(myMap[i][j]);
        }
        if (i != 27) //переход на новую строку
            qresult.append("\n");
    }
    ui->MapUI->setText(qresult); //вывод в форму
}

//проверка, можно ли сдвинутьс€
bool game::CheckMoving(int x, int y)
{
    bool canMove = true; //изначально можно
    QChar targetSymbol = myMap[x][y]; //символ, куда будет движение

    if (targetSymbol == stopingSymbols[0]) //если символ блокирующий
        canMove = false; //нельз€ туда пройти
    if (targetSymbol == pickingSymbols[0] || targetSymbol == pickingSymbols[1]) //если символ подбираемый
    {
        You.setPickedItems(targetSymbol.toAscii()); //добавл€етс€ в массив подобранных
        You.setPickedItemsCount(You.getPickedItemsCount()+1); //увеличиваетс€ количество подобранных
        ui->textMap->setText("Items: "+ QString::number(You.getPickedItemsCount())); //вывод над картой
        myMap[x][y] = ' '; //место становитс€ пустым
    }
    return canMove;
}

//проверка на конец игры
void game:: IsEnding(enemy slayer, player victim)
{
    if ((slayer.getPositionX() == victim.getPositionX()) &&(slayer.getPositionY() == victim.getPositionY()))
        //если координаты игрока и врага равны
    {
        //информаци€ об игроке и его результатах дописываетс€ и зашифровываетс€ в файл
        ofstream file;
        file.open("records.txt", std::ios_base::app);

        string msg = to_string(You.getPickedItemsCount())+" Items : ";

        for (int i = 0; i < You.getPickedItemsCount(); i++)
            msg = msg + to_string(You.getPickedItems(i));

        msg = game_shifer(msg+"\nlying\n");
        file << msg;

        file.close();

        //вывод очень грустного сообщени€
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
    //если игрок может сдиватьс€ - сдвигаетс€
    if (CheckMoving(You.getPositionX() + x,You.getPositionY() + y))
        You.moving(x,y);

    int enemyX = CoolGuy.getPositionX(); //до изменени€
    int enemyY = CoolGuy.getPositionY();
    int enemyX2 = CoolGuyFriend.getPositionX(); //до изменени€
    int enemyY2 = CoolGuyFriend.getPositionY();

    CoolGuy.moving(You); //движение врага1
    CoolGuyFriend.moving(You); //движение врага2

    //если враг1 не может сдвинутьс€ туда, куда хотел - координаты возвращаютс€
    if (myMap[CoolGuy.getPositionX()][CoolGuy.getPositionY()] == '#')
    {
        CoolGuy.setPositionX(enemyX);
        CoolGuy.setPositionY(enemyY);
    }
    //аналогично дл€ враг2
    if (myMap[CoolGuyFriend.getPositionX()][CoolGuyFriend.getPositionY()] == '#')
    {
        CoolGuyFriend.setPositionX(enemyX2);
        CoolGuyFriend.setPositionY(enemyY2);
    }
}

//нажатие на "¬верх"
void game::on_up_clicked()
{
    //вызов функции движени€ единиц
    UnitsMoving(-1, 0);

    //отрисовка карты
    showMap();

    //проверка на конец игры
    IsEnding(CoolGuy, You);
    IsEnding(CoolGuyFriend, You);

}

//нажатие на "¬низ". јналогично "¬верх"
void game::on_down_clicked()
{
    UnitsMoving(1, 0);

    showMap();

    IsEnding(CoolGuy, You);
    IsEnding(CoolGuyFriend, You);

}

//нажатие на "¬лево". јналогично "¬верх"
void game::on_left_clicked()
{
    UnitsMoving(0, -1);

    showMap();

    IsEnding(CoolGuy, You);
    IsEnding(CoolGuyFriend, You);

}

//нажатие на "¬право". јналогично "¬верх"
void game::on_right_clicked()
{
    UnitsMoving(0, 1);

    showMap();

    IsEnding(CoolGuy, You);
    IsEnding(CoolGuyFriend, You);
}

//шифратор
string game::game_shifer(string str)
{
    for (int n = 0; n < str.length(); n++)
        str[n] = str[n] ^ 1001; //XOR
    return str;
}
