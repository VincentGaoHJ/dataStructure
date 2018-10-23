/*****************************************************************************
File name: 2_LeverOrder 
Description: 二叉链表存储二叉树的层序遍历算法。 
	例输入：ABD##E##C#F##
	例输出：Print LeverOrder:
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


struct BiNode *creat_tree()//建立二叉树
{
    char ch;
    ch = getchar();
    struct BiNode *Tree;
    Tree = (struct BiNode *)malloc(sizeof(struct BiNode));
    if(ch == '#')
        Tree = NULL;
    else
    {
        Tree->data   = ch;//输入本节点信息
        Tree->L_tree = creat_tree();//建左子树
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
