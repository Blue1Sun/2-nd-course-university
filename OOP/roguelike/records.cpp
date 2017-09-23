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

//дешифратор
string records::unshifer(string str)
{
    for (int n = 0; n < str.length(); n++)
        str[n] = str[n] ^ 1001; //XOR
    return str;
}

//открытие и проверка файла
void records::openFile(char *fname)
{
    ifstream file(fname);
    if (!file) //если файл был удален
    {
        //отображение ошибки
        QMessageBox msg;
        msg.setText("No such file!");
        msg.setIcon(QMessageBox::Critical);
        msg.exec();
    }
    else //если файл существует
    {
        string result;

        while(file) //пока не дошли до конца
        {
            string str;
            getline(file, str); //считываются строки
            result.append(str); //запись в QString
        }

        string sresult = unshifer(result); //расшифровываем

        bool checking = true; //флаг проверки
        int count = 0; //количество переходов на новую строку
        string newresult; //строка для вывода

        for (int i = 0, j = 0; i < sresult.length() && checking == true; i++, j++)
        {
            char s = sresult[i]; //идем по символам расшифрованной строки

            if (s == '\n') //если встречен переход на новую строку
            {
                count ++; //увеличиваем их кол-во
                if ((count == 2 || count == 1) && sresult.substr(i+1, 5) != "lying") //если это первый \n, а после него не кодовое слово
                    checking = false; //флаг становится false

                else if (sresult.substr(i+1, 5) == "lying") //если кодовое слово есть
                    i = i + 6; //пропускаем его и следующий после него \n

                if (count == 3) //если \n второй
                    count = 0; //перешли к новому игроку => количество \n обнуляем
            }
            newresult = newresult + s; //записывается новая строка(с пропущенным кодовом словом)
        }
        if (checking) //если кодовое слово было каждый раз
        {
            ui->textBrowser->setText(QString::fromStdString(newresult)); //выводится строка без кодового слова
        }
        else //если файл был изменен
        {
            QMessageBox msg;
            msg.setText("File was edited!\nPlease, delete file records.txt");
            msg.setIcon(QMessageBox::Critical);
            msg.exec();
        }
    }
}
