#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect( ui->aboutprogram, SIGNAL(triggered()), this, SLOT(newaboutwindow()));
    connect( ui->quit, SIGNAL(triggered()), this, SLOT(closewindow()));
    connect( ui->saveto, SIGNAL(triggered()), this, SLOT(savetofile()));
    connect( ui->loadfrom, SIGNAL(triggered()), this, SLOT(loadfromfile()));
    connect( ui->help, SIGNAL(triggered()), this, SLOT(newhelpwindow()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::qTranslate(string x)
{
    char tmp[1024];
    strcpy(tmp, x.c_str());

    return QString::fromLocal8Bit(tmp);
}

QString MainWindow::qTranslate(int x)
{
    return QString::number(x);
}

QString MainWindow::qTranslate(float x)
{
    return QString::number(x);
}

QString MainWindow::qTranslate(char x[])
{
    return QString::fromStdString(x);
}

// Saving code to file
void MainWindow::savetofile()
{
    QString path = QFileDialog::getSaveFileName(0,"Save as...",QDir::homePath(),"*.cpp");
    path.replace(":/", ":\\\\");

    char *filename = path.toLocal8Bit().data();
    ofstream file(filename);

    QString output = ui->convert_output->toPlainText();

    if (!file)
    {
        QMessageBox msg;
        msg.setIcon(QMessageBox::Critical);
        msg.setText("Can not save here!");
        msg.exec();
    }
    else
    {
        file << output.toLocal8Bit().data();
    }

    file.close();
}

// Loading code from file
void MainWindow::loadfromfile()
{
    QString path = QFileDialog::getOpenFileName(0, QObject::tr("Choose file"),
                                                "", QObject::tr("File PASCAL (*.pas);;All files (*.*)"));
    path.replace(":/", ":\\\\");

    char *filename = path.toLocal8Bit().data();
    ifstream file(filename);

    if (!file)
    {
        QMessageBox msg;
        msg.setIcon(QMessageBox::Critical);
        msg.setText("No such file!");
        msg.exec();
    }
    else
    {
        string temp;
        QString result;
        while (!file.eof())
        {
            getline(file, temp);
            result.append(qTranslate(temp));
            result.append("\n");
        }

        ui->convert_input->clear();
        ui->convert_input->appendPlainText(result);
    }

    file.close();
}

void MainWindow::convertation(QString in, QString *out)
{
    QString temp;
    int i = 0;
    bool flag_error = false, flag_ready = true;

    // deleting spaces and tabs
    while (in[i] == ' ' || in[i] == '\t')
        i++;
    in = in.mid(i);

    // ignoring comments
    if (in.startsWith("//") || in == "")
    {
        &out->append(in);
        &out->append("\n");
    }
    // procedure
    else if (in.toLower().startsWith("procedure"))
    {
        procedureBegin = true;
        QString pname;

        for (int i = 10; i < in.indexOf("("); i++)
            if (in[i] != ' ')
                pname[i-10] = in[i];

        numfun++;
        functions[numfun] = "";
        vars[numfun] = "";
        functions[numfun] = pname;

        in = in.replace("procedure", "void", Qt::CaseInsensitive);

        int ends;
        for (ends = in.length()-1; ends > 0 && in[ends] != ';' && (in[ends] == ' ' || in[ends] == '\t'); ends--); //finding ';' from end
        in = in.replace(ends, 1, "{");

        in = arg_tran(in); // arguments translation

        &out->append(in);
        &out->append("\n");
    }
    // function
    else if (in.toLower().startsWith("function"))
    {
        currfun = "";

        functionBegin = true;
        QString ftype;

        for (int i = 9; i < in.indexOf("("); i++)
            if (in[i] != ' ')
                currfun[i-9] = in[i];

        numfun++;
        functions[numfun] = "";
        vars[numfun] = "";
        functions[numfun] = "fun_"+currfun;

        int ends, starts;

        for (int i = in.length(); in[i]!=':'; i--) //finding ':' from end
        {
            if (in[i] == ';')
                ends = i;
            starts = i;
        }

        for (int i = starts, k = 0; i < ends; i++, k++)
            ftype[k] = in[i];

        in = in.replace(ends, 1, "{");
        in = in.remove(starts-1, ftype.length()+1);
        in = in.replace("function ", ftype+" fun_", Qt::CaseInsensitive);

        in = arg_tran(in); // arguments translation

        if (ftype == "integer")
            ftype = "int";
        if (ftype == "boolean")
            ftype = "bool";
        if (ftype == "real")
            ftype = "float";

        in.append("\n"+ftype+" "+currfun+";"); // creating variable for returning

        &out->append(in);
        &out->append("\n");
    }
    // beginning of main body if there is no functions
    else if (in.toLower().startsWith("program") && !funorproc)
    {
        programBegin = true;

        temp = "int main() {\nsetlocale(LC_ALL,\"\");\n";
        &out->append(temp);
    }
    // ignoring program name, if there will be functions then
    else if (in.toLower().startsWith("program"))
        {

        }
    // variables declaration (single "var")
    else if (in.toLower() == "var")
    {
        flag_var = true;
        flag_type = false;
        flag_const = false;
    }
    // variables declaration ("var" with variables)
    else if (in.toLower().contains("var"))
    {
        flag_var = true;
        flag_type = false;
        flag_const = false;
        in = in.mid(4);

        int starts = in.indexOf(":");
        int ends = in.indexOf(";");
        QString own_type;

        for (int i = starts+1; i<ends; i++)
            own_type[i-starts-1] = in[i];

        in = type_tran(in, 0, own_type);

        &out->append(in);
        &out->append("\n");
    }
    // type declaration (single "type")
    else if (in.toLower() == "type")
    {
        flag_var = false;
        flag_type = true;
        flag_const = false;

        temp = "typedef ";
        &out->append(temp);
    }
    // type declaration ("type" with declaration)
    else if (in.toLower().contains("type"))
    {
        flag_var = false;
        flag_type = true;
        flag_const = false;

        in = in.replace("type", "typedef", Qt::CaseInsensitive);
        in = in.replace("=", "");

        in = type_tran(in, 8, "");

        &out->append(in);
        &out->append("\n");
    }
    // const declaration (single "const")
    else if (in.toLower() == "const")
    {
        flag_var = false;
        flag_type = false;
        flag_const = true;

        temp = "const int ";
        &out->append(temp);
    }
    // const declaration ("const" with variable)
    else if (in.toLower().contains("const"))
    {
        flag_var = false;
        flag_type = false;
        flag_const = true;

        in = in.replace("const","const int", Qt::CaseInsensitive);

        &out->append(in);
        &out->append("\n");
    }
    // ignoring begin in start of function
    else if (in.toLower() == "begin" && (programBegin || procedureBegin || functionBegin) && numBegin == 0)
    {
        flag_var = false;
        flag_type = false;
        flag_const = false;
        numBegin++;
    }
    // begin of main body
    else if (in.toLower() == "begin" && !programBegin && !procedureBegin && !functionBegin)
    {
        flag_var = false;
        flag_type = false;
        flag_const = false;
        numBegin++;
        programBegin = true;

        temp = "int main() {\nsetlocale(LC_ALL,\"\");\n";
        &out->append(temp);
    }
    // const variables
    else if (flag_const && !flag_var && !flag_type)
    {
        &out->append(in);
        &out->append("\n");
    }
    // typedef variables
    else if (flag_type && !flag_var && !flag_const)
    {
        in = in.replace("=", "");

        in = type_tran(in, 0, "");

        &out->append(in);
        &out->append("\n");
    }
    // var variables
    else if(flag_var && !flag_const && !flag_type)
    {
        int starts = in.indexOf(":");
        int ends = in.indexOf(";");
        QString own_type;

        for (int i = starts+1; i<ends ;i++)
            own_type[i-starts-1] = in[i];

        in = type_tran(in, 0, own_type);

        &out->append(in);
        &out->append("\n");
    }
    // begin of cycle
    else if (in.toLower() == "begin")
    {
        numBegin++;

        temp = "{\n";
        &out->append(temp);
    }
    // end of cycle
    else if (in.toLower() == "end;" || in.toLower() == "end")
    {
        numEnd++;

        temp = "}\n";
        &out->append(temp);
    }
    // end of main body
    else if (in.toLower().contains("end."))
    {
        temp = "return 0;\n}\n";
        &out->append(temp);
    }
    // reading variable
    else if (in.startsWith("read(") || in.startsWith("readln("))
    {
        temp = "cin >> ";

        if (in.startsWith("readln("))
            temp.append(in.mid(7));
        else
            temp.append(in.mid(5));
        temp = temp.replace(");", ";\n");

        temp = matrix_tran(temp);

        temp = temp.replace(",", " >> ");

        &out->append(temp);
    }
    // printing new line
    else if (in == "writeln;")
    {
        &out->append("cout << endl;");
    }
    // printing
    else if (in.startsWith("write"))
    {
        bool flag_write = true;
        if (in.startsWith("writeln"))
            flag_write = false;

        temp = "cout << ";
        if (flag_write)
           in = in.mid(5);
        else
           in = in.mid(7);

        in = in.replace("('", "\"");
        in = in.replace("(", "");

        in = in.replace("' ,", "\" << ");
        in = in.replace("',", "\" << ");

        in = in.replace(",'", " << \"");
        in = in.replace(", '", " << \"");

        if (flag_write)
        {
            in = in.replace("');", "\";\n");
            in = in.replace("')", "\";\n");
            in = in.replace(");", ";\n");
        }
        else
        {
            in = in.replace("');", "\" << endl;\n");
            in = in.replace("')", "\" << endl;\n");
            in = in.replace(");", " << endl;\n");
        }

        int f = in.indexOf(":");
        int l = in.indexOf(" <<", f);

        if (f > l)
            l = in.indexOf(";", f);
        if ((in[f+1].isDigit() || in[f+1] == ':') && f > -1)
            in = in.remove(f, l-f);

        in = matrix_tran(in);

        temp.append(in);
        &out->append(temp);
    }
    // else structure
    else if (in.toLower().contains("else"))
    {
        flag_ready = false; // string will be changed more lately

        in = in.remove("else ");
        in = in.remove("else");

        temp = "else\n";
        &out->append(temp);
    }
    // for ... to / downto ... do
    else if (in.toLower().startsWith("for") && (in.contains("to")) && in.contains("do"))
    {
        QString value;
        temp = "for (";

        in = in.mid(4);

        int ends = in.indexOf(':');
        in = in.replace(":=", "=");

        for (int i = 0, j = 0; i<ends; i++, j++)
            value[j] = in[i];

        if (in.toLower().contains("downto"))
        {
            in = in.replace(" downto ", "; "+value+">=", Qt::CaseInsensitive);
            in = in.replace(" do", "; "+value+"--)", Qt::CaseInsensitive);
        }
        else
        {
            in = in.replace(" to ", "; "+value+"<=", Qt::CaseInsensitive);
            in = in.replace(" do", "; "+value+"++)", Qt::CaseInsensitive);
        }
        in.append("\n");

        temp.append(in);
        &out->append(temp);

    }
    // while structure
    else if (in.toLower().contains("while"))
    {
        flag_ready = false; // string will be changed more lately

        in = in.replace("while", "while (", Qt::CaseInsensitive);
        in = in.replace("do", ")", Qt::CaseInsensitive);
    }
    // if .... then
    else if (in.toLower().startsWith("if"))
    {
        flag_ready = false; // string will be changed more lately
    }
    // repeat structure
    else if (in.toLower().contains("repeat"))
    {
        in = in.replace("repeat", "do {", Qt::CaseInsensitive);
        &out->append(in);
        &out->append("\n");
    }
    // until structure
    else if (in.toLower().contains("until"))
    {
        flag_ready = false; // string will be changed more lately

        in = in.replace("until ", "} while (!(", Qt::CaseInsensitive);
        in.insert(in.indexOf(";"),"))");
    }
    // assignment
    else if (in.contains(":="))
    {
        flag_ready = false; // string will be changed more lately

        int ends = in.indexOf("//");
        if (ends == -1)
            ends = in.length();

        // checking ';' at end
        for (ends = ends-1; ends > 0 && in[ends] != ';' && (in[ends] == ' ' || in[ends] == '\t'); ends--);
        if (in[ends] != ';')
            in = in.insert(ends+1, ';');
    }
    // if it's not common structure
    else
    {
        bool ff = false;
        int num, starts = 0;

        for (num = 0; num<=numfun && !ff; num++)
            if(in.contains(functions[num]+"(") || in.contains(functions[num]+" ("))
                ff = true; // it was one of declared functions

        if (!ff) //unknown command
        {
            flag_error = true;

            QMessageBox msg;
            msg.setIcon(QMessageBox::Warning);
            msg.setText("<strong>Unknown command</strong>: <u>" + in);
            msg.setInformativeText("Check that line of code, and if it's right please contact the developer.");
            msg.exec();

            in = in.insert(0, "// ");

            &out->append(in);
            &out->append("\n");
        }
        else
        {
            for (int i = 0; i < vars[num-1].length(); i++) // correction "var" arguments
            {
                if (i == 0)
                    starts = in.indexOf("(", 1);
                else
                    starts = in.indexOf(",", starts);

                if (vars[num-1][i] == '1')
                    in = in.insert(starts+1, "&"), starts += 1;
                starts += 1;
            }
            &out->append(in);
            &out->append("\n");
        }

    }
    // function/procedure/main ends
    if (numBegin == numEnd && numBegin != 0)
    {
        if (functionBegin)
        {
            &out->insert(out->length()-2,"return "+currfun+";\n");
            functionBegin = false;
        }
        if (procedureBegin)
            procedureBegin = false;
        if (programBegin)
            programBegin = false;

        numBegin = 0;
        numEnd = 0;
    }
    // syntax correction
    if (!flag_error && !flag_ready)
    {
        int n = 0;
        // correction of operand "equal"
        while (in.contains("=") && n > -1 && n <= in.length())
        {
            n = in.indexOf("=", n) - 1;
            if (n >=1 && in[n] != ':' && in[n] != '<' && in[n] != '>' && in[n+2] != '-')
                in = in.insert(n+1, "=");
            if (n > -1)
                n += 4;
        }

        n = 0;
        int m = 0;
        // correction of matrix indexation a[i,j] => a[i][j]
        while (in.contains(",") && n > -1 && n <= in.length())
        {
            n = in.indexOf("[", n);
            m = in.indexOf(",", n);
            if (m >= 1)
                in = in.replace(m, 1, "][");
            if (n > -1)
                n += 3;
        }

        n = 0;
        // correction of matrix indexation a[1] => a[0]
        while (n > -1 && n <= in.length() && in.contains("[") && in.contains("]"))
        {
            n = in.indexOf("]", n);
            if (n >= 1)
                in = in.insert(n, "-1");
            if (n > -1)
                n += 4;
        }

        in = in.replace(":=", "=");
        in = in.replace("<>", "!=");

        in = in.replace(" mod ", " % ", Qt::CaseInsensitive);
        in = in.replace(" div ", " / ", Qt::CaseInsensitive);
        in = in.replace(" xor ", " ^ ", Qt::CaseInsensitive);

        n = 0;
        // correction of operand '||'
        while (n > -1)
        {
            n = in.indexOf("or", n, Qt::CaseInsensitive);
            if (n >= 1 && ((in[n-1] == ' ') || (in[n-1] == ')'))
                    && ((in[n+2] == ' ') || (in[n+2] == '(')))
                in = in.replace(n, 2, "||");

            if (n > -1)
                n += 3;
        }

        n = 0;
        // correction of operand '&&'
        while (n > -1)
        {
            n = in.indexOf("and", n, Qt::CaseInsensitive);
            if (n >= 1 && ((in[n-1] == ' ') || (in[n-1] == ')'))
                    && ((in[n+3] == ' ') || (in[n+3] == '(')))
                in = in.replace(n, 3, "&&");

            if (n > -1)
                n += 4;
        }

        n = 0;
        // correction of operand '!'
        while (n > -1)
        {
            n = in.indexOf("not", n, Qt::CaseInsensitive);
            if (n >= 0 && ((in[n+3] == ' ') || (in[n+3] == '(')))
                in = in.replace(n, 3, "!");

            if (n > -1)
                n += 4;
        }

        in = in.replace("dec ", "--", Qt::CaseInsensitive);
        in = in.replace("inc ", "++", Qt::CaseInsensitive);

        in = in.replace("abs(", "fabs(", Qt::CaseInsensitive);
        in = in.replace("Exp(", "exp(", Qt::CaseInsensitive);
        in = in.replace("ln(", "log(", Qt::CaseInsensitive);
        in = in.replace("arctan(", "atan(", Qt::CaseInsensitive);

        in = in.replace("if", "if (", Qt::CaseInsensitive);
        in = in.replace("then", ")", Qt::CaseInsensitive);
        in = in.replace("maxint", "INT_MAX", Qt::CaseInsensitive);

        int num, x = 0;
        // correction of function arguments (var) + it's names
        for (num = 0; num <= numfun; num++)
            if((in.contains(functions[num].replace("fun_", "") + "(") && !in[in.indexOf(functions[num].replace("fun_", "") + "(") - 1].isLetter()) ||
                    in.contains(functions[num].replace("fun_", "") + " (") && !in[in.indexOf(functions[num].replace("fun_", "") + " (") - 1].isLetter())
            {
                for (int i = 0; i < vars[num].length(); i++)
                {
                    if (i == 0)
                        x = in.indexOf("(", 1);
                    else
                        x = in.indexOf(",", x);

                    if (vars[num][i] == '1')
                        in = in.insert(x+1,"&"), x += 1;
                    x += 1;
                }
                in = in.insert((in.indexOf(functions[num].replace("fun_","") + " (")), "fun_");
                in = in.insert((in.indexOf(functions[num].replace("fun_","") + "(")), "fun_");
            }

        &out->append(in);
        &out->append("\n");
    }
}

void MainWindow::on_convertButton_clicked()
{
    QString input = ui->convert_input->toPlainText();
    QString temp, output;

    programBegin = functionBegin = procedureBegin = flag_var = flag_const = flag_type = funorproc = false;
    numBegin = numEnd = 0; // number of begins/ends in program
    numfun = -1; // number of functions and procedures in program

    if (input.toLower().contains("procedure ") || input.toLower().contains("function "))
        funorproc = true;

    if (!begin_end(input))
    {
        QMessageBox msg;
        msg.setIcon(QMessageBox::Critical);
        msg.setText("Number of \"begin\"s not equal number of \"end\"s!\nCheck your code, please!");
        msg.exec();

        ui->convert_output->setText("Error!");
    }
    else
    {
        output.append("#include <iostream>\n#include <stdio.h>\n#include <limits.h>\n#include <math.h>\n#include <string>\nusing namespace std;\n");

        for (int i = 0, j = 0; i < input.length(); i++, j++)
        {
            if (input[i] != '\n' && input[i] != '\0')
            {
                temp[j] = input[i];
            }
            else
            {
                j = -1;
                convertation(temp, &output); // convertation one string
                temp.clear();
            }
        }
        ui->convert_output->setText(output);
    }
}

void MainWindow::newhelpwindow()
{
    HelpWindow *ww = new HelpWindow;
    ww->show();
}

void MainWindow::newaboutwindow()
{
    AboutWindow *ww = new AboutWindow;
    ww->show();
}

void MainWindow::closewindow()
{
    this->close();
}

bool MainWindow::begin_end(QString in)
{
    bool flag = false;

    int begins = in.toLower().count("begin\n") + in.toLower().count("begin;");
    int ends = in.toLower().count("end;") + in.toLower().count("end.") + in.toLower().count("end ") + in.toLower().count("end\n");
    int cases = in.toLower().count("case ");

    ends -= cases;

    if (ends == begins)
        flag = true;

    return flag;
}

// arguments translation
QString MainWindow::arg_tran(QString in)
{
    QString temp = in;

    int ends = 0, starts = 0, l = 0, num = temp.count(";");
    QString type = "", arrsize = "", check = "";

    for (int i = 0; i <= num; i++)
    {
        ends = temp.indexOf(";", ends);
        if (i == num)
            ends = temp.indexOf(")");

        starts = temp.indexOf(":", starts) + 1;

        for (int j = starts; j < ends; j++)
            type[j-starts] = temp[j];
        temp = temp.remove(starts-1, ends-starts+1);

        if (type.contains("array"))
        {
            for (int j = type.indexOf("["), k = 0; j <= type.indexOf("]"); j++, k++)
                arrsize[k] = type[j];
            arrsize = arrsize.replace("1..", "");
            arrsize = arrsize.replace(",", "][");

            type = type.remove(0, type.indexOf(" of ")+4);
        }

        if (i == 0)
            l = temp.indexOf("(", l), temp = temp.insert(l+1, " ");
        else
            l = temp.indexOf(";", l);

        for (int j = l; j<starts; j++)
            check[j-l] = temp[j];

        if (check.contains("var"))
            vars[numfun] = vars[numfun].append("1");
        else
            vars[numfun] = vars[numfun].append("0");

        temp = temp.insert(l+1, type);

        if (arrsize != "")
        {
            int nn = temp.indexOf(";", ends);
            if (i == num)
                nn = temp.indexOf(")");
            temp = temp.insert(nn, arrsize);
        }

        ends += 3;
        starts += 3;
        l += 3;
        type = arrsize = check = "";
    }
    temp = temp.replace(";", ",");
    temp = temp.replace("var ", "*");

    temp = temp.replace("integer", "int");
    temp = temp.replace("boolean", "bool");
    temp = temp.replace("real", "float");

    return temp;
}

QString MainWindow::type_tran(QString input, int index, QString own_type)
{
    QString temp = input;

    if (temp.toLower().contains("integer"))
    {
        temp.insert(index, "int ");
        temp = temp.replace("integer", "", Qt::CaseInsensitive);
        temp = temp.replace(": ", "");
        temp = temp.replace(":", "");
    }
    else if (temp.toLower().contains("boolean"))
    {
        temp.insert(index, "bool ");
        temp = temp.replace("boolean", "", Qt::CaseInsensitive);
        temp = temp.replace(": ", "");
        temp = temp.replace(":", "");
    }
    else if (temp.toLower().contains("real"))
    {
        temp.insert(index, "float ");
        temp = temp.replace("real", "", Qt::CaseInsensitive);
        temp = temp.replace(": ", "");
        temp = temp.replace(":", "");
    }
    else if (own_type != "")
    {
        temp = temp.replace(own_type, "");
        temp.insert(index, own_type + " ");
        temp = temp.replace(": ", "");
        temp = temp.replace(":", "");
    }
    if (temp.toLower().contains("array"))
    {
        int n = temp.indexOf("array");
        temp = temp.replace("array", "", Qt::CaseInsensitive);
        for(int i = n; i < temp.length(); i++)
            if (temp[i] == ',')
            {
                temp = temp.remove(i,1);
                temp = temp.insert(i,"][");
            }
        temp = temp.replace(" of ","", Qt::CaseInsensitive);
        temp = temp.replace("1..","");
        temp = temp.replace(":", "");
    }

    return temp;
}

QString MainWindow::matrix_tran(QString input)
{
    QString temp = input;

    int middle = 0, starts = 0, ends = 0;
    bool flag = true;

    while (temp.contains(",") && starts > -1 && starts <= temp.length() && flag)
    {
    starts = temp.indexOf("[", starts);
        ends = temp.indexOf("]", starts);
        middle = temp.indexOf(",", starts);
        if ((ends >= 1) && (starts >= 1) && (middle > starts) && (middle < ends))
            temp = temp.replace(middle, 1, "][");
        else
            flag = false;
        if (starts > -1 && middle > -1)
            starts += middle - starts + 3;
        else if (starts > -1)
            starts ++;
    }
    starts = 0;
    while (starts > -1 && starts <= temp.length() && temp.contains("[") && temp.contains("]"))
    {
        starts = temp.indexOf("]", starts);
        if (starts >= 1)
            temp = temp.insert(starts, "-1");
        if (starts > -1)
            starts += 4;
    }

    return temp;
}
