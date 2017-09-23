#include <stdio.h>
#include <string.h>
#include <ctype.h> //��� isdigit

using namespace std;
#define FCLR while (getc(fin)!='\n')
//������� ������� ������

//��������� ��������� (1)
struct model
{
int seriya,number;
};

//��������� ��������� (2)
struct date
{
int year, month;
};

struct car
{model mod; //��������� ��������� (1)
date dat; //��������� ��������� (2)
char firm[20], color[20];
int price, engine;
};

//������ � ������ ������� '\n' �� '\0'
void deln(char *s)
{ for (; *s && *s!='\n'; s++);
    *s='\0';
}


//����
void read(int *kol, car cat[], char *filename)
{FILE *fin;
car *ucar;
*kol=0;
if (!(fin=fopen(filename, "r")))
        printf("File %s does not exist\n",filename);
    else
    {
        //�� ������� ����� ��� ������ ����� � ������ ����� �������� ����� ������
        for (ucar=cat; !feof(fin); (*kol)++, ucar++)
            if(fgets(ucar->firm,20,fin))
            {
                deln(ucar->firm);
                fscanf(fin,"%d", &(ucar->mod.seriya));
                fscanf(fin,"%d", &(ucar->mod.number));
                fscanf(fin,"%d", &(ucar->price));
                fscanf(fin,"%d", &(ucar->dat.year));
                fscanf(fin,"%d", &(ucar->dat.month));
                if (!feof(fin)) FCLR;
                fgets(ucar->color, 20, fin);
                deln(ucar->color);
                fscanf(fin,"%d", &(ucar->engine));
                //������� �������� ������
                if (!feof(fin)) FCLR;
            }
        fclose(fin);
    }
}


//������, � ������� ������� ������������ ���������� ��������� ������� ���������.
void search(car cat[], int kol, int mod[], int *n1)
{car *iukaz,*jukaz;
    int i,c,diff=0,max=0;
    *n1=-1;//���������� ��� �������
    if (kol==1)
    {*n1=0;
     mod[*n1]=0;
    }
    else
    {for(iukaz=cat;iukaz<cat+kol-1;iukaz++)//����������� �������� ������ �������
        {diff=0;
        for (jukaz=cat;jukaz<cat+kol;jukaz++)
            {if (iukaz->mod.seriya==jukaz->mod.seriya&&iukaz->mod.number==jukaz->mod.number)//���� ���� ������
                if (iukaz->engine!=jukaz->engine)//���� � ��� ������ ���������
                    diff++;//��������� ��� ��������
            }
        if (diff>max) max=diff; //��������� ��������
        }
    for(iukaz=cat,i=0;iukaz<cat+kol;iukaz++,i++) //������� ����� ������ ����� ���� ��������
        {diff=0;
        for (jukaz=iukaz;jukaz<cat+kol;jukaz++)
            {if (iukaz->mod.seriya==jukaz->mod.seriya&&iukaz->mod.number==jukaz->mod.number)
                if (iukaz->engine!=jukaz->engine)
                    diff++;
            }
        if (diff==max)//���� ����� ������, ���������� ��
            {*n1=*n1+1;
             mod[*n1]=i;}
        }
    }
}

void print(int n1, int mod[], car cat[], char *filename)
{int c,i;
FILE *fout;
fout=fopen(filename, "w");
fprintf(fout,"Models with max amount of different engine capacity:\r\n");
    for(i=0;i<n1+1;i++)
        {c=mod[i];
        if (cat[c].mod.seriya!=cat[c-1].mod.seriya||i==0)
        {
        fprintf(fout,"Model...Series.....%d\r\n",cat[c].mod.seriya);
        fprintf(fout,"Model...Number.....%d\r\n\r\n",cat[c].mod.number);
        }
        }
    fclose(fout);
}

int main (){
    int kol,n1;
    car catalog[200];
    int models[20];
    FILE *fout;

    read(&kol,catalog,"input.txt");
    search(catalog, kol, models, &n1);
    if(n1!=-1)
        print(n1, models,catalog,"output.txt");
    else
        {fout=fopen("output.txt", "w");
        fprintf(fout,"No needed cars were found");
        }
    return 0;
}
