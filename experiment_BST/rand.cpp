#include <stdlib.h>
#include <stdio.h>
#include <time.h>
 
//�����������
int write()
{
    int i,j;
    FILE *pf = NULL;
    int arr[60];
    srand((unsigned)time(NULL));//�������
    pf = fopen("Num_2.txt","a");
    //��������
    for(i=0; i<60; i++)
    {
        arr[i] = rand()%1000;
    }
    //��ʽ��������ļ���
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
 
//��ȡ��������
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
    //��ȡ�ļ����ݵ�����
    for(i=0; i<20; i++)
    {
        for(j=0; j<3; j++)
        {
            fscanf(pf,"%d",&arr[i*3+j]);
        }
    }
    fclose(pf);
    //�������������Ļ
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
