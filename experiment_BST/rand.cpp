#include <stdlib.h>
#include <stdio.h>
#include <time.h>
 
//生成随机数列
int write()
{
    int i,j;
    FILE *pf = NULL;
    int arr[60];
    srand((unsigned)time(NULL));//随机种子
    pf = fopen("Num_2.txt","a");
    //生成数列
    for(i=0; i<60; i++)
    {
        arr[i] = rand()%1000;
    }
    //格式化输出到文件中
    for(i=0; i<20; i++)
    {
        for(j=0; j<3; j++)
        {
            fprintf(pf,"%-5d",arr[i*3+j]);
        }
    }
    fclose(pf);
    return 0;
}
 
//读取生成数列
int read()
{
    int i,j;
    FILE *pf;
    int arr[60];
    if((pf = fopen("Num_2.txt","r"))==NULL)
    {
        printf("Error\n");
        system("PAUSE");
        exit(1);
    }
    //读取文件内容到数列
    for(i=0; i<20; i++)
    {
        for(j=0; j<3; j++)
        {
            fscanf(pf,"%d",&arr[i*3+j]);
        }
    }
    fclose(pf);
    //将数列输出到屏幕
    for(i=0; i<20; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("%-5d",arr[i*3+j]);
        }
    }
 
    return 0;
}
 
int main()
{
    write();
    read();
    return 0;
}
