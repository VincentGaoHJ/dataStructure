/*****************************************************************************
File name: 5_InsertBST 
Description: 二叉链表存储二叉排序树，写出排序树的插入算法。
	设集合记录存放在数组r[n]中，编写算法构造二叉排序树。 
	例输出：Before Insert...
			3   1   2   6   5   8   7   9
			After Insert...
			3   1   2   6   5   4   8   7   9
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAXSIZE 100

using namespace std;

typedef struct BiNode
{
    int data; 
    struct BiNode *L_tree;
    struct BiNode *R_tree;
}BiNode, *BiTree;

void PreOrder(BiNode * root) 
{
	if(root != NULL)
	{
		printf("%d\t",root->data);
		PreOrder(root->L_tree);
		PreOrder(root->R_tree);
	}
}

void Insert_BST(BiNode **root, BiNode *s)
{
    //空树时，直接作为根节点
    if (*root == NULL){
    	*root = s;
    }
	else{
		if(s->data < (*root)->data) Insert_BST(&((*root)->L_tree), s);
		else Insert_BST(&((*root)->R_tree), s);
	}
}

void CreateBST(BiNode **T, int a[], int n)
{
	printf("%d",n);
    for (int i = 0; i < n; i++){
    	BiNode *p = (BiNode *)malloc(sizeof(struct BiNode));
	    if (!p){
	    	printf("return");
	    	return;
		}
    	p->data = a[i];
    	printf("\na[i]:%d", a[i]);
    	p->L_tree = p->R_tree = NULL;
        Insert_BST(&*T, p);
    }
}


int main()
{
	struct BiNode *root = NULL;
	int a[MAXSIZE] = {3,1,2,6,5,8,9,7};
	int n = 8;
	CreateBST(&root, a, n);
	printf("Initial seccessful...\n");
	printf("Before Insert...\n");
	PreOrder(root);
	BiNode *p = (BiNode *)malloc(sizeof(struct BiNode));
	p->data = 4;
	p->L_tree = p->R_tree = NULL;
	Insert_BST(&root, p);
	printf("\nAfter Insert...\n");
	PreOrder(root);
	return 0 ;
}
