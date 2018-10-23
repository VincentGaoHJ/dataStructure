/*****************************************************************************
File name: 5_intersect 
Description: ��˳����ʾ���ϣ�����㷨ʵ�ּ��ϵ��󽻼����� 
*****************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define LIST_INIT_SIZE 100 //��ʼ��ռ��С
#define LISTINCREMENT 10 //������

typedef int Status; 
typedef int ElemType; 

/**˳���Ķ���**/
typedef struct{
	ElemType *elem; /**����ռ����ַ**/
	int length;     /**��ǰ����**/
	int listsize;   /**��ǰ����Ĵ�������**/
}SeqList;
 
SeqList La, Lb, Lc, Ld; /**����ȫ�ֱ���**/
 

Status ListCreate_Sq(SeqList &L)
 {
	int n;
	printf("Please input the length of the list: ") ;
	scanf("%d",&n);
	
	// ��L.elem���ָ��ָ��һ��ͨ��malloc����������ڴ�ĵ�ַ
	// ����ڴ�Ĵ�СΪElemtype����ṹ���size*LIST_INIT_SIZE�ĳ˻���ô��
	L.elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	
	// ����ʧ��,L.elem��Ϊnull,(!)ȡ�Ǿ��Ƿ�null,Ҳ��������Ϊ��,��ִ����������
	// ֱ���˳�����,���ش������OVERFLOW ������ϵͳ
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
 
/**����һ���յ����Ա�L**/
Status InitList_Sq(SeqList &L){
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if(!L.elem) exit(OVERFLOW); /**�������ʧ��**/
	L.length = 0; /**�ձ���Ϊ0**/
	L.listsize = LIST_INIT_SIZE; /**��ʼ��������**/
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
 
/**��ӡ˳�����**/
void Print_Seq(SeqList *L){
	int i;
	printf("The result is: ");
	for(i = 0; i < L->length; i++)
		printf("%d ",L->elem[i]);
	if(L->length == 0) printf("It's an empty set."); 
	printf("\nthe number of the set is %d\n",L->length);
}



int main() {
    ElemType *p; //��ʾp��һ��ָ�����������ֵ��ĳ�����ͱ����ĵ�ַ
 	printf("******��������ĵ�һ�����ϣ�******\n");
    if(ListCreate_Sq(La)!= OK) {
        printf("ListCreate_Sq: Fail to create a list, please try again...\n");
        return -1;
    }
    printf("******��������ĵڶ������ϣ�******\n");
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
