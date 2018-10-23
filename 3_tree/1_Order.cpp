/*****************************************************************************
File name: 1_Order 
Description: ��������洢����������������ͺ��������㷨�� 
	�����룺ABD##E##C#F##
	�������Print PreOrder:
				A B D E C F
			Print InOrder:
				D B E A C F
			Print PostOrder:
				D E B F C A
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct BiNode
{
    char data;
    struct BiNode *L_tree;
    struct BiNode *R_tree;
};

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


void PreOrder(BiNode * root) 
{
	if(root != NULL)
	{
		printf("%c\n",root->data);
		PreOrder(root->L_tree);
		PreOrder(root->R_tree);
	}
}

void InOrder(BiNode * root) 
{
	if(root != NULL)
	{
		InOrder(root->L_tree);
		printf("%c\n",root->data);
		InOrder(root->R_tree);
	}
}

void PostOrder(BiNode * root) 
{
	if(root != NULL)
	{
		PostOrder(root->L_tree);
		PostOrder(root->R_tree);
		printf("%c\n",root->data);
	}
}

int main()
{
	struct BiNode *root;
	root = creat_tree();
	
	printf("Initial seccessful...\n");
	printf("Print PreOrder: \n");	
	PreOrder(root);
	printf("Print InOrder: \n");	
	InOrder(root);
	printf("Print PostOrder: \n");	
	PostOrder(root);
	
	return 0 ;
}
