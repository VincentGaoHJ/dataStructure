#include<iostream>
#include<stack>
#include<fstream>
#include <stdlib.h>
#include <pthread.h>

using namespace std;

int read(int arr[], char fileName[],int n)
{
    int i,j;
    FILE *pf;

    char *name = (char *) malloc(strlen(fileName) + strlen(".txt"));
    strcpy(name, fileName);
    strcat(name, ".txt");
    if((pf = fopen(name,"r"))==NULL)
    {
        printf("Error\n");
        system("PAUSE");
        exit(1);
    }
    
    //读取文件内容到数列
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            fscanf(pf,"%d",&arr[i*n+j]);
        }
    }
    fclose(pf);
    
    //将数列输出到屏幕
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%-5d",arr[i*n+j]);
        }
        printf("\n");
    }
    free(name);
 
    return 0;
}


void DotHeap(int arr[], char fileName[], int n)
{
	char *name_gv = (char *) malloc((strlen(fileName) + strlen(".gv")));
	strcpy(name_gv, fileName);
    strcat(name_gv, ".gv");
	FILE *fpTree=fopen(name_gv,"w+");
	fprintf(fpTree,"graph heapT {\n");
	fprintf(fpTree,"node [shape = plaintext]\n");
	fprintf(fpTree,"edge[style=dashed]\n");
	
	int h = 0;
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=n+1;j++){
			fprintf(fpTree,"%d%d [label=\"",j,i);
			if(j==1||i==1){
				if(i+j >2) fprintf(fpTree,"V%d\",fontcolor=\"#8A2BE2\",fontsize=20]\n",i+j-3);
				else fprintf(fpTree,"\"]\n");
			}
			else if(arr[h] != 1000) {
				fprintf(fpTree,"%d\",fontsize=20]\n",arr[h]);
				h ++;
			}
			else{
				fprintf(fpTree,"MAX\",fontcolor=\"#787878\"]\n");
				h ++;
			} 
			
		}
	}
	
	
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=n+1;j++){
			fprintf(fpTree,"%d%d",i,j);
			if(j != n+1)fprintf(fpTree," -- ");
			else fprintf(fpTree," [color=white];\n");
		}
	}
	
	
	fprintf(fpTree,"}\n\n");
	fclose(fpTree);
	free(name_gv);
	
}

void DotInit(int arr[], char fileName[], int n)
{
	int i,j;
    FILE *pf;
	FILE *fpTree=fopen("init.gv","w+");
	fprintf(fpTree,"digraph heapT {\n");
	fprintf(fpTree,"edge[style=dashed]\n");
	
	int h = 0;
	for(int i=0;i<=n-1;i++){
		for(int j=0;j<=n-1;j++){
			if(arr[h] != 1000 && arr[h] != 0)fprintf(fpTree,"v%d->v%d[style=bold,label=%d];\n",i,j,arr[h]);	
			h ++;
		}
	}
	
	fprintf(fpTree,"}\n\n");
	fclose(fpTree);
}

int main(){
	
	// 节点个数 
	int n = 9;
	
	int arr[n*n],*p;
	p = arr;
	char fileName[] = "TEST", *q;
	q = fileName;
	read(p,q,n);
	
	// 生成联通初始图
	DotInit(p,q,n);
	system("sfdp.exe -Tpng init.gv -o init.png"); 
	

	// 生成初始邻接矩阵 
	DotHeap(p,q,n);
	system("dot.exe -Tpng TEST.gv -o TEST.png"); 
	
	// 生成某两点相接的前驱 
	q = "Path";
	read(p,q,n);
	DotHeap(p,q,n);
	system("dot.exe -Tpng Path.gv -o Path.png"); 
	
	// 生成经过算法调整过后的矩阵 
	q = "Distance";
	read(p,q,n);
	DotHeap(p,q,n);
	system("dot.exe -Tpng Distance.gv -o Distance.png"); 
	

	
	
	
	
	
}   
 

