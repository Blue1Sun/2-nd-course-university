#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "helpwindow.h"
#include "aboutwindow.h"

#include <QMainWindow>
#include <QMessageBox>
#include <QDir>
#include <QFileDialog>
#include <QDebug>

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QString qTranslate(string);
    QString qTranslate(int);
    QString qTranslate(float);
    QString qTranslate(char[]);

    void convertation(QString, QString *);
    
private slots:
    void on_convertButton_clicked();
    void savetofile();
    void loadfromfile();
    void newhelpwindow();
    void newaboutwindow();
    void closewindow();

private:
    Ui::MainWindow *ui;

    bool flag_var, flag_const, flag_type, programBegin, functionBegin, procedureBegin, funorproc;
    int numBegin, numEnd, numfun;
    QString currfun, functions[100], vars[100];

    bool begin_end(QString);
    QString arg_tran(QString);
    QString type_tran(QString, int, QString);
    QString matrix_tran(QString);
};

#endif // MAINWINDOW_H
