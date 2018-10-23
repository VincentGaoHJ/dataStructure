/*****************************************************************************
File name: 4_Exchange 
Description: 二叉链表存储二叉排序树，写出交换左右子树的算法（递归）。 
	例输入：ABD##E##C#F##
	例输出：Before Exchange...
				A   B   D   E   C   F
			After Exchange...
				A   C   F   B   E   D
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


void Exchange(BiNode * root) 
{
	if(root != NULL)
	{
		Exchange(root->L_tree);
		Exchange(root->R_tree);
		BiNode *temp = root->L_tree;
		root->L_tree = root->R_tree;
		root->R_tree = temp;
	} 
}


void PreOrder(BiNode * root) 
{
	if(root != NULL)
	{
		printf("%c\t",root->data);
		PreOrder(root->L_tree);
		PreOrder(root->R_tree);
	}
}

int main()
{
	struct BiNode *root;
	root = creat_tree();
	printf("Initial seccessful...\n");
	printf("Before Exchange...\n");
	PreOrder(root);
	Exchange(root);
	printf("\nAfter Exchange...\n");
	PreOrder(root);
	return 0 ;
}
