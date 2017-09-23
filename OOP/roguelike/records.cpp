#include "records.h"
#include "ui_records.h"


records::records(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::records)
{
    ui->setupUi(this);

    openFile("records.txt");
}

records::~records()
{
    delete ui;
}

//����������
string records::unshifer(string str)
{
    for (int n = 0; n < str.length(); n++)
        str[n] = str[n] ^ 1001; //XOR
    return str;
}

//�������� � �������� �����
void records::openFile(char *fname)
{
    ifstream file(fname);
    if (!file) //���� ���� ��� ������
    {
        //����������� ������
        QMessageBox msg;
        msg.setText("No such file!");
        msg.setIcon(QMessageBox::Critical);
        msg.exec();
    }
    else //���� ���� ����������
    {
        string result;

        while(file) //���� �� ����� �� �����
        {
            string str;
            getline(file, str); //����������� ������
            result.append(str); //������ � QString
        }

        string sresult = unshifer(result); //��������������

        bool checking = true; //���� ��������
        int count = 0; //���������� ��������� �� ����� ������
        string newresult; //������ ��� ������

        for (int i = 0, j = 0; i < sresult.length() && checking == true; i++, j++)
        {
            char s = sresult[i]; //���� �� �������� �������������� ������

            if (s == '\n') //���� �������� ������� �� ����� ������
            {
                count ++; //����������� �� ���-��
                if ((count == 2 || count == 1) && sresult.substr(i+1, 5) != "lying") //���� ��� ������ \n, � ����� ���� �� ������� �����
                    checking = false; //���� ���������� false

                else if (sresult.substr(i+1, 5) == "lying") //���� ������� ����� ����
                    i = i + 6; //���������� ��� � ��������� ����� ���� \n

                if (count == 3) //���� \n ������
                    count = 0; //������� � ������ ������ => ���������� \n ��������
            }
            newresult = newresult + s; //������������ ����� ������(� ����������� ������� ������)
        }
        if (checking) //���� ������� ����� ���� ������ ���
        {
            ui->textBrowser->setText(QString::fromStdString(newresult)); //��������� ������ ��� �������� �����
        }
        else //���� ���� ��� �������
        {
            QMessageBox msg;
            msg.setText("File was edited!\nPlease, delete file records.txt");
            msg.setIcon(QMessageBox::Critical);
            msg.exec();
        }
    }
}
