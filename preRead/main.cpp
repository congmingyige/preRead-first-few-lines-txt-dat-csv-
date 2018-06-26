#include <iostream>
#include <cstdio>
#include <cstring>
#include <io.h>
#include <windows.h>
using namespace std;

char addr[200],s[10000],str[100000];

int main()
{
    printf("preRead!\n");
    printf("Please input (directory+)filename:\t");
    ///data.dat
    ///test.txt
    ///1.csv
    ///1.xlsx wrong!
    ///1.doc wrong!
    gets(addr);
    if (_access(addr,0)!=-1)
    {
        int i,limitLine;

        FILE *in_line=fopen("limitLine.txt","r");
        fscanf(in_line,"%d",&limitLine);
        fclose(in_line);

        FILE *in=fopen(addr,"r");
        ///若不清楚格式，按行读取
        i=1;
        strcpy(str,"");
        while (fgets(s,1000,in)!=NULL)
        {
            strcat(str,s);
            if (i==limitLine)
                break;
            i++;
        }
        printf("%s",str);
        fclose(in);
    }
    else
        printf("File not exists\n");
    system("pause");
    return 0;
}
