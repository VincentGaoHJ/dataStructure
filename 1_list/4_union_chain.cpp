/*****************************************************************************
File name: 4_union_chain
Description: 有两个有序递增的单链表la和lb，设计算法将这两个链表合并成一个有序链表 
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef int elemtype; 

typedef struct Node
{
	int key;
	struct Node  *next;
}Node,*LinkList;
 
LinkList getNewList(){
	Node *head = NULL;  /*定义了一个Node类型的结构体指针head，并将指针head初始化为空*/
	head = (Node *)calloc(1, sizeof(Node));  /*将head这个指针指向一块通过calloc函数分配的内存的地址*/ 
	if(head == NULL)
		return NULL;
	head->key = 0;
	head->next = NULL;	
	return head;
}

LinkList Creat(LinkList head, int a[], int n){
	Node *p = head;
	head->key = n;
	for(int i = 0; i < n; ++i){
		p->next = (Node *)calloc(1, sizeof(Node));
		if(p->next == NULL){
			printf("Memory allocation failed...");
			return NULL;
		}
		p->next->key = a[i];
		p = p->next;
	}
	p->next = NULL;
	return head;
}
 
void list_display(Node *head)
{
    Node *p = head->next;
    printf("list:");
    while(p != NULL)
    {
        printf(" %d", p->key);
        p = p->next;
    }
    printf("\n");
}
 
LinkList Union(LinkList la,LinkList lb){
	Node *a, *b, *c, *head;
	a = la;
	b = lb;
	c = head = getNewList();
	head->key = la->key + lb->key;
	while(a->next || b->next){
		c->next = (Node *)calloc(1, sizeof(Node));
		if(c->next == NULL){
			printf("Memory allocate failed...");
			return NULL;
		}
		if(a->next && b->next){
			if(a->next->key <= b->next->key){
				c->next->key = a->next->key;
				a = a->next;
			}
			else if(b->next->key < a->next->key){
				c->next->key = b->next->key;
				b = b->next;
			}
			c = c->next;
		}
		else if(a->next){
			c->next->key = a->next->key;
	        a = a->next;
	        c = c->next;
		}
		else if(b->next){
			c->next->key = b->next->key;
	        b = b->next;
	        c = c->next;
		}	
	}
	c->next = NULL;
	return head;
}
 
int main(int argc, char *argv[])
{
	int n,m;
	elemtype LA[10],LB[10];
	printf("Please input the length of LA: ");
	scanf("%d",&n);
	printf("Please input the LA which is increase progressively: ");
	for(int i = 0; i < n; i++)
		scanf("%d",&LA[i]);
	printf("Please input the length of LB: ");
	scanf("%d",&m);
	printf("Please input the LB which is increase progressively: ");
	for(int i = 0; i < m; i++){
		scanf("%d",&LB[i]);
	}
		
	Node *la = getNewList(); 
	Node *lb = getNewList(); 
	la = Creat(la,LA,n);
	lb = Creat(lb,LB,m);
	printf("la: ");
 	list_display(la);
 	printf("lb: ");
 	list_display(lb);
 	
 	Node *lc = Union(la, lb);
 	printf("lc: ");
 	list_display(lc);
    
	return 0;
}
