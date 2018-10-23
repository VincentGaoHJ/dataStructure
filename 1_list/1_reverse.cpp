/*****************************************************************************
File name: 1_reverse 
Description: 试着以顺序表为存储结构，实现线性表的就地逆置 
*****************************************************************************/
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
 
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE -1
#define OVERFLOW   -2
 
typedef int Status;
 
#define LIST_INIT_SIZE  100
#define LISTINCREMENT   10

typedef int ElemType;  

typedef struct{
    ElemType *elem; 
    int length;
    int listsize; 
}SqList;
 
Status ListCreate_Sq(SqList &L)
 {
	int n;
	printf("Please input the length of the list: ") ;
	scanf("%d",&n);
	
	// 将L.elem这个指针指向一块通过malloc函数分配的内存的地址
	// 这个内存的大小为Elemtype这个结构体的size*LIST_INIT_SIZE的乘积这么大
	L.elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	
	// 分配失败,L.elem将为null,(!)取非就是非null,也就是条件为真,则执行下面的语句
	// 直接退出进程,返回错误代码OVERFLOW 给操作系统
	if(!L.elem) exit(OVERFLOW);
	L.listsize=LIST_INIT_SIZE;
	L.length=0;
	
	printf("Please input the list, using space to distinguish: ");
	for(int i = 0; i < n; i ++)	{
		scanf("%d", &L.elem[i]);
		L.length++;
	}
	return OK;
 }

void ListReverse_Sq(SqList *L)
 {
     int temp;
     int n = L->length;
     for(int i = 0; i < n/2; i ++)
    {
        temp = L->elem[i];
        L->elem[i] = L->elem[n-1-i];
        L->elem[n-1-i] = temp;
    }
 }
 
int main() {
    SqList L;
    ElemType *p; //表示p是一个指针变量，它的值是某个整型变量的地址
 
    if(ListCreate_Sq(L)!= OK) {
        printf("ListCreate_Sq: Fail to create a list, please try again...\n");
        return -1;
    }
 
    ListReverse_Sq(&L);
 
    if(L.length){
    	printf("The result is: ");
		for(p=L.elem ; p<L.elem+L.length-1 ; ++p){
		    printf("%d ",*p);
		}
		printf("%d",*p); 
    }
    return 0;
}
