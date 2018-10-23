/*****************************************************************************
File name: 3_reverse_chain 
Description: 设计算法实现单链表的就地逆置 
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>



typedef struct _list_node
{
	int        key;
	struct _list_node  *next;
}list_node;
 

void list_insert(list_node *head, int key)  
{
	list_node *p = head;
	while(p->next != NULL)
		p = p->next;
	list_node *node = NULL;	
	node = (list_node *)calloc(1, sizeof(list_node));
	node->key = key;
	node->next = NULL;
	p->next = node;
}
 
void list_display(list_node *head)
{
    list_node *p = head->next;
    printf("list:");
    while(p != NULL)
    {
        printf(" %d", p->key);
        p = p->next;
    }
    printf("\n");
}
 
/*
** 头插法
*/
list_node list_reverse(list_node *head)
{
    list_node *p = head->next;
    list_node *q = NULL;
    head->next = NULL;
    while(p != NULL)
    {
        q = p->next;          /*保存下一个节点*/
        p->next = head->next; /*把节点插入到头结点后面*/
        head->next = p;       /*头结点一直指向最新插入的节点*/
        p = q;                /*调整指针，指向下一个节点*/
    }
}
 
int main(int argc, char *argv[])
{
	list_node *head = NULL;  /*定义了一个list_node类型的结构体指针head，并将指针head初始化为空*/
	head = (list_node*)calloc(1, sizeof(list_node));  /*将head这个指针指向一块通过calloc函数分配的内存的地址*/ 
	head->key = 0;  
	head->next = NULL;
 
	list_insert(head, 1);
	list_insert(head, 2);
	list_insert(head, 3);
	list_insert(head, 4);
	list_insert(head, 5);
 
    list_display(head);
    list_reverse(head);
    list_display(head);
	return 0;
}
