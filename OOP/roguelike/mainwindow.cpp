#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//нажатие на "Начать игру"
void MainWindow::on_startGame_clicked()
{
    add = new game; //открытие нового окна
    add->show();

    ofstream file;
    file.open("records.txt", std::ios_base::app); //дозапись в файл

    string msg;
    if (ui->playerName->text() == "") //если пользователь забыл вписать имя
        msg = main_shifer("NO_NAME\nlying\n");
    else
        msg = main_shifer(ui->playerName->text().toStdString()+"\nlying\n"); //имя игрока+кодовое слово - шифруется
    file << msg;

    file.close();

}

//нажатие на "Рекорды"
void MainWindow::on_Records_clicked()
{
    add2 = new records; //открытие нового окна
    add2->show();
}

//шифратор
string MainWindow::main_shifer(string str)
{
    for (int n = 0; n < str.length(); n++)
        str[n] = str[n] ^ 1001; //XOR
    return str;
}
