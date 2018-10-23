/*****************************************************************************
File name: 7_store_chain
Description: 在某商店的仓库中，对电视机按照其价格从低到高建立单链表，
	完成一批次电脑的入库。
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	float price; 
	int num;
	struct Node  *next;
}Node,*LinkList;
 
LinkList getNewList(){
	Node *head = NULL;  /*定义了一个Node类型的结构体指针head，并将指针head初始化为空*/
	head = (Node *)calloc(1, sizeof(Node));  /*将head这个指针指向一块通过calloc函数分配的内存的地址*/ 
	if(head == NULL)
		return NULL;
	head->price = 0;
	head->num = 0;
	head->next = NULL;	
	return head;
}

LinkList Creat(LinkList head, float a[], int b[], int n){
	Node *p = head;
	for(int i = 0; i < n; i++){
		Node *q = NULL; 
		p->next = (Node *)calloc(1, sizeof(Node));
		if(p->next == NULL){
			printf("Memory allocation failed...");
			return NULL;
		}
		p->price = a[i];
		p->num = b[i];
		p = p->next;
	}
	p = NULL;
	return head;
}
 
void list_display(Node *head)
{
    Node *p = head;
    printf("list:\n");
    while(p->next != NULL){
        printf("%f\n", p->price);
        printf("%d\n", p->num);
        p = p->next;
    }
    printf("\n");
}

void Store(Node *head, float n, int m){
	Node *p = head;
	while(p->next != NULL && n > p->next->price) p = p->next;
	if( p->next==NULL || n < p->next->price){
		if(n <= p->price){
			if(n == p->price) p->num += m;
			else{
				Node *q = NULL; 
				q = (struct Node *)malloc(sizeof(Node));
				q->price = n;
				q->num = m;
				q->next = p;
				p = q;	
			}
		}
		else{
			Node *q = NULL; 
			q = (struct Node *)malloc(sizeof(Node));
			q->price = n;
			q->num = m;
			q->next = p->next;
			p->next = q;	
			printf("successful...")	;	
		}
	}
	else p->next->num += m; 
}
 
 
int main(int argc, char *argv[])
{
	int n;
	float LA[10];
	int LB[10];
	printf("Please input the number of television types: ");
	scanf("%d",&n);
	printf("Please input the price of each type which is increasing progressively: ");
	for(int i = 0; i < n; i++){
		scanf("%f",&LA[i]);
	}
	printf("Please input the number of each type: ");
	for(int i = 0; i < n; i++){
		scanf("%d",&LB[i]);
	}
		
	Node *head = getNewList(); 
	head = Creat(head,LA,LB,n);

 	list_display(head);
 	
 	float price_new;
 	int num_new;
 	
 	printf("Please input the price of the new television type: ");
 	scanf("%f", &price_new);
 	printf("Please input the number of the new television type: ");
 	scanf("%d", &num_new);
 	printf("So, you want to store %d television, whose price is %f.\n", num_new, price_new);
 	
    Store(head, price_new, num_new);
    list_display(head);
    
	return 0;
}
