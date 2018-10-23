/*****************************************************************************
File name: 2_LeverOrder 
Description: ��������洢�������Ĳ�������㷨�� 
	�����룺ABD##E##C#F##
	�������Print LeverOrder:
				A B C D E F
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define MAXSIZE 100

using namespace std;

typedef struct BiNode
{
    char data;
    struct BiNode *L_tree;
    struct BiNode *R_tree;
}BiNode, *BiTree;


struct BiNode *creat_tree()//����������
{
    char ch;
    ch = getchar();
    struct BiNode *Tree;
    Tree = (struct BiNode *)malloc(sizeof(struct BiNode));
    if(ch == '#')
        Tree = NULL;
    else
    {
        Tree->data   = ch;//���뱾�ڵ���Ϣ
        Tree->L_tree = creat_tree();//��������
        Tree->R_tree = creat_tree();
    }
    return Tree;
}


void LeverOrder(BiNode * root) 
{
	BiNode* Q[MAXSIZE];
	Q[0] = root;
	int front = 0;
    int rear = 1;
    while(front < rear)
    {
		printf("%c\t", Q[front]->data);
		if (Q[front]->L_tree) Q[rear++] = Q[front]->L_tree ;
		if (Q[front]->R_tree) Q[rear++] = Q[front]->R_tree ;
		++ front;
    }
	printf(" ");
}


int main()
{
	struct BiNode *root;
	root = creat_tree();
	
	printf("Initial seccessful...\n");
	printf("Print LeverOrder: \n");	
	LeverOrder(root);
	
	return 0 ;
}
