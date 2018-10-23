/*****************************************************************************
File name: 3_decimaltor 
Description: 设计算法把 
*****************************************************************************/

#include <stack> 
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void DEcimaltor(int num, int r){
	stack<int>s;
	if(num==0)printf("The result is zero...");
	else{
		while(num){
			int t = num % r;
			s.push(t);
			num/=r;
		}
		while(!s.empty()){
			printf("%d",s.top());
			s.pop();
		}
	}
	
}

int main(){
	int num, r;
	cout<<"请输入要转换的数字："<<endl;
	scanf("%d",&num);
	cout<<"请输入要转换的进制数："<<endl;
	scanf("%d",&r);
	DEcimaltor(num, r);
	return 0;
}


