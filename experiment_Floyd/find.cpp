#include<iostream>
#include<stack>
#include<fstream>

using namespace std;

int read(int arr[], char fileName[], int n)
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


void DotHeap_find(int arr[], char fileName[], int list[], int t_num, int n)
{
	char *name_gv = (char *) malloc(strlen(fileName) + strlen("_find.gv"));
	strcpy(name_gv, fileName);
    strcat(name_gv, "_find.gv");
	FILE *fpTree=fopen(name_gv,"w+");
	fprintf(fpTree,"graph heapT {\n");
	fprintf(fpTree,"node [shape = plaintext]\n");
	fprintf(fpTree,"edge[style=dashed]\n");
	
	int flag = 0;
	int h = 0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			fprintf(fpTree,"%d%d [label=\"",j,i);
			flag = 0;
			for(int num=0;num<t_num-1;num++){
				if(list[num]==(i-1) && list[t_num-1]==(j-1)){
						fprintf(fpTree,"%d\",fontcolor=\"#FF0000\",fontsize=20,shape=circle,style=filled,margin=0]\n",arr[h]);
						flag = 1;
						break;															
					}
			}
		 	if(flag==1){
		 		h ++;
		 		continue;
			 }
			if(j==0||i==0){
				if(i+j >0) fprintf(fpTree,"V%d\",fontcolor=\"#8A2BE2\",fontsize=20]\n",i+j-1);
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
	
	
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			fprintf(fpTree,"%d%d",i,j);
			if(j != n)fprintf(fpTree," -- ");
			else fprintf(fpTree," [color=white];\n");
		}
	}
	
	
	fprintf(fpTree,"}\n\n");
	fclose(fpTree);
	free(name_gv);
	
}

void DotMatrix_find(int arr[], char fileName[], int list[], int t_num, int n)
{
	char *name_gv = (char *) malloc(strlen(fileName) + strlen("_find.gv"));
	strcpy(name_gv, fileName);
    strcat(name_gv, "_find.gv");
	FILE *fpTree=fopen(name_gv,"w+");
	fprintf(fpTree,"graph heapT {\n");
	fprintf(fpTree,"node [shape = plaintext]\n");
	fprintf(fpTree,"edge[style=dashed]\n");
	
	int flag = 0;
	int h = 0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			fprintf(fpTree,"%d%d [label=\"",j,i);
			flag = 0;
			for(int num=0;num<t_num-1;num++){
				if(list[0]==(i-1) && list[t_num-1]==(j-1)){
					fprintf(fpTree,"%d\",fontcolor=\"#FF0000\",fontsize=20,shape=circle,fillcolor=\"#FFFF00\",style=filled]\n",arr[h]);
					flag = 1;
					break;															
				}
				else if(list[num]==(i-1) && list[num+1]==(j-1)){
					fprintf(fpTree,"%d\",fontcolor=\"#FF0000\",fontsize=20,shape=circle,style=filled,margin=0]\n",arr[h]);
					flag = 1;
					break;															
				}
			}
		 	if(flag==1){
		 		h ++;
		 		continue;
			 }
			if(j==0||i==0){
				if(i+j >0) fprintf(fpTree,"V%d\",fontcolor=\"#8A2BE2\",fontsize=20]\n",i+j-1);
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
	
	
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			fprintf(fpTree,"%d%d",i,j);
			if(j != n)fprintf(fpTree," -- ");
			else fprintf(fpTree," [color=white];\n");
		}
	}
	
	
	fprintf(fpTree,"}\n\n");
	fclose(fpTree);
	free(name_gv);
	
}


void initFind(int arr[], char fileName[], int list[], int t_num, int n)
{
	int i,j;
    FILE *pf;
	FILE *fpTree=fopen("init_find.gv","w+");
	fprintf(fpTree,"digraph heapT {\n");
	fprintf(fpTree,"edge[style=dashed]\n");
	
	int h = 0;
	int flag = 0;
	for(int i=0;i<=n-1;i++){
		for(int j=0;j<=n-1;j++){
			if(arr[h] != 1000 && arr[h] != 0){
				flag = 0;
				for(int num=0;num<t_num-1;num++){
					if(list[num]==(i) && list[num+1]==(j)){
						fprintf(fpTree,"v%d->v%d[style=bold,color=red,fontcolor=red,label=%d];\n",i,j,arr[h]);
						fprintf(fpTree,"v%d[color=red,fontcolor=red];\n",j);
						fprintf(fpTree,"v%d[color=red,fontcolor=red];\n",i);
						flag =1;
						break;															
					}
				}
				if(flag == 0) fprintf(fpTree,"v%d->v%d[style=bold,label=%d];\n",i,j,arr[h]);	
			}
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
	
	int *t;
	// int list[] = {0,1,2,3};
	// int list[] = {1,7,5};
	// int list[] = {2,3,4,5,6,7};
	int t_num = sizeof(list) / sizeof(int);
	t = list;
	
	
	// 生成带有查找路线的联通图
	q = fileName;
	read(p,q,n);
	initFind(p,q,t,t_num,n);
	system("sfdp.exe -Tpng init_find.gv -o init_find.png"); 
	
	

	// 生成带有查找路线的前驱图 
	q = "Path";
	read(p,q,n);
	DotHeap_find(p,q,t,t_num,n);
	system("dot.exe -Tpng Path_find.gv -o Path_find.png"); 
	
		
	// 生成带有查找路线的算法调整过后的矩阵 
	q = "Distance";
	read(p,q,n);
	DotMatrix_find(p,q,t,t_num,n);
	system("dot.exe -Tpng Distance_find.gv -o Distance_find.png"); 

}   
 

