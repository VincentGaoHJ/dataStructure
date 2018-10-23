/*****************************************************************************
File name: 2_enqueueDequeue
Description: ����ͷ����ѭ�������ʾ���У�����ֻ����һ��ָ��ָ���β��������
	ͷָ�롣�����Ӧ����Ӻͳ����㷨�� 
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 10
#define OK 1
#define ERROR 0
#define True 1
#define FALSE 0

typedef int ElemType;

typedef struct Node{
	ElemType data;
	struct  Node *next; 
} Node;

void initQueue(Node *&rear){
	rear = NULL;
	printf("Init successful...\n");
}

void Enqueue(Node *&rear, ElemType x){
	Node *s;
	s = (Node *)malloc(sizeof(Node));
	s->data = x;
	/*����Ϊ��*/
	if(rear == NULL){
		s->next = s;
		rear = s;
	}
	/*���в�Ϊ��*/
	else{
		s->next=rear->next;
        rear->next=s;
        rear=s;
	}
}

void Dequeue(Node *&rear){
	Node *q;
	if(rear == NULL) printf("The Stack is NULL...");
	else if(rear->next == rear){
		free(rear);
        rear = NULL;
	}
	else{
		q = rear->next;
		rear->next = rear->next->next;
		free(q);
		q = NULL;
	}
}

void DispQueueR(Node *rear){
    if(rear==NULL)
        return;
    Node *p=rear->next;
    do{
        printf("%d ",p->data);
        p=p->next;
    }while(p!=rear->next);

    printf("\n");
}


int main(){
	Node *p;
	initQueue(p);
	printf("Starting...");
	for(int i=1;i<10;i++){
		Enqueue(p,i*i-1);
	}
	printf("\nEnqueue...\n");
	DispQueueR(p);
	printf("\nEnqueue...\n");
	Dequeue(p);
	DispQueueR(p);
	return 0;
}
