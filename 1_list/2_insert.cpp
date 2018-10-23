/*****************************************************************************
File name: 2_insert
Description: 已知顺序表L中的元素为递增有序排列，设计一个算法实现将元素x插入表中
	后依然保持递增
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
}SeqList;
 
Status ListCreate_Sq(SeqList &L)
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
	
	printf("Please input the list which is increase progressively: ");
	for(int i = 0; i < n; i ++)	{
		scanf("%d", &L.elem[i]);
		L.length++;
	}
	return OK;
 }

void Insert(SeqList *L, int x)
 {
 	int n = L->length;
 	int i = 0;
 	while(i <= n && x > L ->elem[i])
 		i++;
	for(int k = n ; k >= i ; k--)
		L->elem[k+1] = L->elem[k];
	L->elem[i] = x;
	L->length++;
	printf("aaaaa");
 }
 
int main() {
    SeqList L;
    ElemType *p; //表示p是一个指针变量，它的值是某个整型变量的地址
 
    if(ListCreate_Sq(L)!= OK) {
        printf("ListCreate_Sq: Fail to create a list, please try again...\n");
        return -1;
    }
    
    printf("Please input the number you want you insert:");
    int g;
    scanf("%d", &g);

    Insert(&L, g);

 
    if(L.length){
    	printf("The result is: ");
		for(p=L.elem ; p<L.elem+L.length-1 ; ++p){
		    printf("%d ",*p);
		}
		printf("%d",*p); 
    }
    return 0;
}
