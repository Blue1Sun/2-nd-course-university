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

//������� �� "������ ����"
void MainWindow::on_startGame_clicked()
{
    add = new game; //�������� ������ ����
    add->show();

    ofstream file;
    file.open("records.txt", std::ios_base::app); //�������� � ����

    string msg;
    if (ui->playerName->text() == "") //���� ������������ ����� ������� ���
        msg = main_shifer("NO_NAME\nlying\n");
    else
        msg = main_shifer(ui->playerName->text().toStdString()+"\nlying\n"); //��� ������+������� ����� - ���������
    file << msg;

    file.close();

}

//������� �� "�������"
void MainWindow::on_Records_clicked()
{
    add2 = new records; //�������� ������ ����
    add2->show();
}

//��������
string MainWindow::main_shifer(string str)
{
    for (int n = 0; n < str.length(); n++)
        str[n] = str[n] ^ 1001; //XOR
    return str;
}
