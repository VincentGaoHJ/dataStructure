/*****************************************************************************
File name: 8_jonsephus
Description: Լɪ������ 
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Jonse
{
	int code;
	struct Jonse  *next;
}Jonse;


Jonse* Create(int n){
	Jonse *head = NULL;  /*������һ��Jonse���͵Ľṹ��ָ��head������ָ��head��ʼ��Ϊ��*/
	head = (Jonse *)calloc(1, sizeof(Jonse));  /*��head���ָ��ָ��һ��ͨ��calloc����������ڴ�ĵ�ַ*/ 
	if(head == NULL){
		printf("Fail to create...");
		return NULL;		
	}
	head->code = n; 
	
	Jonse *rear, *p;
	rear = head;

	for(int i = 0; i < n; i++){
		p = (Jonse *)calloc(1, sizeof(Jonse));
		if(p == NULL){
			printf("Memory allocation failed...");
			return NULL;
		}
		p->code = i;
		rear->next = p;
		rear = p;
	}
	rear->next=head->next;
	return head;
}


void ShowList(Jonse *head){
    Jonse *p = head->next;
    printf("list:\n");
    printf("%d ", p->code);
	p = p->next;
    while(p != head->next)  //ѭ���������ֹ����:��p != ͷָ�룩
	{
		printf("%d ", p->code);
		p = p->next;
	}
	printf("\n");
    printf("\n");	
}

Jonse* JonseOut(Jonse *head, int m){
	Jonse *p = head->next, *q;
	while(p != p->next){
		for(int i=1; i<m; i++){
			q = p;
			p = p->next;
		} 
		printf("%d\t", p->code);
		q->next = p->next;
		free(p);
	 	p=NULL;
	 	p = q->next;
	}
	printf("\nThe winner is %d\n",p->code);
	return head;
}

int main(int argc, char *argv[])
{
	int n,m;
	printf("Please input the number of Jonsephus: ");
	scanf("%d",&n);
	
	Jonse *head = Create(n); 
 	ShowList(head);
 	
	printf("Please input the number of killing: ");
	scanf("%d", &m);
	
 	JonseOut(head, m);

	return 0;
}
