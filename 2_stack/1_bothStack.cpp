/*****************************************************************************
File name: 1_bothStack
Description: 两栈共享空间的存储结构 
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 10
#define OK 1
#define ERROR 0
#define True 1
#define FALSE 0

typedef int ElemType;
typedef int Status;

typedef struct BothStack{
	int data[STACKSIZE];
	int top1;   /*栈顶指针1*/
	int top2;   /*栈顶指针2*/
} BothStack;


/*初始化的过程*/
void InitBothStack(BothStack *S){
	S->top1 = -1;
	S->top2 = STACKSIZE;
}

void PushBothStack(BothStack *S, int i, int intnumber){
	if (S->top1 + 1 == S->top2)
		printf("The stack is overflow...");
	/*表示栈1有元素进栈*/
	else{
		switch(i){
			case 1 : S->data[++S->top1] = intnumber; break;
			case 2 : S->data[--S->top2] = intnumber; break;
		}		
	}
}

int PopBothStack(BothStack *S, int i){
	switch(i){
		case 1 : {
			if (-1 == S->top1) return ERROR;
			return S->data[S->top1--];
		}; break;
		case 2 : {
			if (STACKSIZE == S->top2) return ERROR;
			return S->data[S->top2++];
		}; break;		
	}
}

/*输出栈中所有元素*/
Status DispStack(BothStack* S, int stackNumber){
	int i;
	if (1 == stackNumber)
	{
		if (-1 == S->top1)
			return ERROR;
 
		printf("\n栈1中的元素为：");
		for (i=0; i<=S->top1; ++i)
			printf("%d ", S->data[i]);
	}
	else if (2 == stackNumber)
	{
		if (STACKSIZE == S->top2)
			return ERROR;
		printf("\n栈2中的元素为：");
		for (i=STACKSIZE-1; i>=S->top2; --i)	
			printf("%d ", S->data[i]);
	}
}


int main(void){
	BothStack S;
	ElemType e;
	InitBothStack(&S);
	
	PushBothStack(&S, 1, 1);
	PushBothStack(&S, 1, 2);
	PushBothStack(&S, 1, 3);
	PushBothStack(&S, 1, 4);
	PushBothStack(&S, 1, 5);
	PushBothStack(&S, 1, 6);
	PopBothStack(&S, 1);
	
	PushBothStack(&S, 2, 10);
	PushBothStack(&S, 2, 9);
	PushBothStack(&S, 2, 8);
	PushBothStack(&S, 2, 7);
	
	DispStack(&S, 1);
	DispStack(&S, 2);
	return 0;
} 
