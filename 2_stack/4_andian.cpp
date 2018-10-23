/*****************************************************************************
File name: 4_andian 
Description: �����㷨��������С��������� 
*****************************************************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define M 4
#define N 4
#define FALSE 0
#define TRUE 1 

void Andian(int A[M][N]){
	int i,j;
	int minNum[M] = {0}, maxNum[N] = {0};
    bool have = FALSE;
    
    /*���ÿ����С��������minNum[0,,,M-1]��*/
    printf("ÿ����С����\n");
    for(i=0; i<M; i++){
    	minNum[i]=A[i][0];
    	for(j=1; j<N; j++){
	    	if(minNum[i]>A[i][j]) minNum[i]=A[i][j];
	    }
	    printf("%d\t",minNum[i]) ;
	    printf("\n") ;
    }
    
    /*���ÿ�������������maxNum[0,,,N-1]��*/
    printf("ÿ���������\n");
    for(j=0; j<N; j++){
    	maxNum[j]=A[0][j];
    	for(i=1; i<M; i++){
	    	if(maxNum[j]<A[i][j]) maxNum[j]=A[i][j];
	    }
	    printf("%d\t",maxNum[j]) ;
    }
    
    /*Ѱ������*/
    for(i=0; i<M; i++){
    	for(j=0; j<N; j++){
	    	if(minNum[i] == maxNum[j]){
	    		printf("\n\nMatrix[%d][%d] is an Andian, and it's value is = %d\n",i,j,A[i][j]);
                have = TRUE;
	    	}
	    }
    } 
    if(!have)
        printf("\n\nThere is no Andian in the matrix...\n\n");
} 

void start(int A[M][N]){
	printf("The matrix is: \n");
	for(int i=0; i<M; i++){
		for(int k=0; k<N; k++){
			printf("%d\t",A[i][k]);
		}
		printf("\n");
	}
	printf("Ѱ�Ҿ����е����㣺\n");
	Andian(A);
}

int main(){
	int A[M][N]= {{13,12,17,11},{10,16,14,15},{8,19,21,9},{18,14,20,16}};
	start(A);
	int B[M][N]= {{13,12,17,11},{10,16,14,15},{8,19,21,9},{18,24,20,26}};
	start(B);
	return 0;
}


