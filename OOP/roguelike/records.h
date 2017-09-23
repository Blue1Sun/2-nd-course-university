#ifndef RECORDS_H
#define RECORDS_H

#include <QDialog>
#include <QMessageBox>

#include <fstream>
#include <string>

using namespace std;


namespace Ui {
class records;
}

class records : public QDialog
{
    Q_OBJECT
    
public:
    explicit records(QWidget *parent = 0);
    ~records();

    string unshifer (string); //дешифровщик
    void openFile(char*); //открытие и проверка файла
    
private:
    Ui::records *ui;
};

#endif // RECORDS_H
