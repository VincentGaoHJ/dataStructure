/*****************************************************************************
File name: 3_Count 
Description: 二叉链表存储二叉树，要求不使用全局变量，请写出叶子总数的递归算法，
	节点总数的递归算法，二叉树深度的递归算法。 
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


int CountLeaf(BiNode * root) 
{
	int i;
	if(root != NULL)
	{
		//printf("%c\n",root->data);
		i = (root->L_tree != NULL?CountLeaf(root->L_tree):0) + (root->R_tree != NULL?CountLeaf(root->R_tree):0) + (root->L_tree == NULL && root->R_tree == NULL);
		//printf("%d\n",i);
	}
	return i;
}

int CountBiNode(BiNode * root) 
{
	int i;
	if(root != NULL)
	{
		//printf("%c\n",root->data);
		i = (root->L_tree != NULL?CountBiNode(root->L_tree)+1:0) + (root->R_tree != NULL?CountBiNode(root->R_tree)+1:0);
		//printf("%d\n",i);
	}
	return i;
}

int Depth(BiNode * root) 
{
	int i;
	if(root != NULL)
	{
		//printf("%c\n",root->data);
		i = ((root->L_tree!=NULL?Depth(root->L_tree):0) >= (root->R_tree!=NULL?Depth(root->R_tree):0)) ? ((root->L_tree!=NULL?Depth(root->L_tree):0)+1):((root->R_tree!=NULL?Depth(root->R_tree):0)+1);
		//printf("%d\n",i);
	}
	return i;
}


int main()
{
	struct BiNode *root;
	root = creat_tree();
	printf("Initial seccessful...\n");
	printf("CountLeaf: %d\n",CountLeaf(root));	
	printf("CountBiNode: %d\n",(CountBiNode(root)+1));	
	printf("Depth: %d\n",Depth(root));	
	return 0 ;
}
