/*****************************************************************************
File name: 5_intersect 
Description: 用顺序表表示集合，设计算法实现集合的求交集运算 
*****************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define LIST_INIT_SIZE 100 //初始表空间大小
#define LISTINCREMENT 10 //表长增量

typedef int Status; 
typedef int ElemType; 

/**顺序表的定义**/
typedef struct{
	ElemType *elem; /**储存空间基地址**/
	int length;     /**当前长度**/
	int listsize;   /**当前分配的储存容量**/
}SeqList;
 
SeqList La, Lb, Lc, Ld; /**定义全局变量**/
 

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
 
/**构造一个空的线性表L**/
Status InitList_Sq(SeqList &L){
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if(!L.elem) exit(OVERFLOW); /**储存分配失败**/
	L.length = 0; /**空表长度为0**/
	L.listsize = LIST_INIT_SIZE; /**初始储存容量**/
	return OK;
} 

Status compare(ElemType a, ElemType b){
	if(a==b)return TRUE;
	else return FALSE;
} 
 
 
Status LocalElem(SeqList *L, ElemType e){
	ElemType *p;
	p = L->elem;
	int n;
	n = L->length;
	int i=1;
	while(i <= n && !compare(*p++, e)) ++i;
	if(i <= n)return i;
	else return 0;
}


Status InsertElem(SeqList *L, ElemType elem){
	int n = L->length;
	L->elem[L->length] = elem;
	printf("Insert successful...\n");
	L->length++; 
	return OK;
}
 
 
void intersect(SeqList *L1, SeqList *L2, SeqList *L3){
	ElemType elem;
	L3->length = 0;
	for(int i=0; i < L1->length; i++){
		elem = L1->elem[i];
		printf("L1:%d\n",elem);
		if(LocalElem(L2, elem)){
			printf("Find the elem %d in Lb...\n", elem);
			InsertElem(L3, elem);
		}
	}
}
 
/**打印顺序表函数**/
void Print_Seq(SeqList *L){
	int i;
	printf("The result is: ");
	for(i = 0; i < L->length; i++)
		printf("%d ",L->elem[i]);
	if(L->length == 0) printf("It's an empty set."); 
	printf("\nthe number of the set is %d\n",L->length);
}



int main() {
    ElemType *p; //表示p是一个指针变量，它的值是某个整型变量的地址
 	printf("******请输入你的第一个集合：******\n");
    if(ListCreate_Sq(La)!= OK) {
        printf("ListCreate_Sq: Fail to create a list, please try again...\n");
        return -1;
    }
    printf("******请输入你的第二个集合：******\n");
    if(ListCreate_Sq(Lb)!= OK) {
        printf("ListCreate_Sq: Fail to create a list, please try again...\n");
        return -1;
    }
    
    InitList_Sq(Lc);
    
    printf("Initialization of Lc successful...\n");
    
    intersect(&La, &Lb, &Lc);
    
    Print_Seq(&Lc);
 
    return 0;
}
