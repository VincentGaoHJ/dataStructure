#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
#define TOTALNUM 200

void HeapAdjust(int array[],int i,int nLength)
{
    int nChild;
    int nTemp;
    for(;2*i+1<nLength;i=nChild)
    {
        nChild=2*i+1;
        if(nChild<nLength-1&&array[nChild+1]<array[nChild])
			++nChild;
        if(array[i]>array[nChild])
        {
            nTemp=array[i];
            array[i]=array[nChild];
            array[nChild]=nTemp; 
        }
        else break;
    }
}


void DotHeap(int Heap[], int n, char *slabel,int input=-1, int drop=-1)
{
	FILE *fpTree=fopen("heapT.gv","w+");
	fprintf(fpTree,"digraph heapT {\n");
	fprintf(fpTree,"fontname = \"Microsoft YaHei\"; labelloc = t; labeljust = l; rankdir = TB;\n");
	fprintf(fpTree,"label = \"%s\";\n",slabel);
	fprintf(fpTree,"node [fontname = \"Microsoft YaHei\", color=darkgreen, shape=circle, height=.1];\n");
	fprintf(fpTree,"edge [fontname = \"Microsoft YaHei\", color=darkgreen, style=solid, arrowsize=0.7];\n");	
	
	if(input!=-1 && drop!=-1)
		fprintf(fpTree,"in%d[label=\"%d\",shape=Mcircle,fontcolor=blue,color=blue];\n",input,input);

	for(int i=0; i<n; i++)
		fprintf(fpTree,"node%d[label=\"%d\"];\n",i,Heap[i]);
	
	if(input!=-1 && drop!=-1 && input!=drop)
		fprintf(fpTree,"%d[label=\"%d\",shape=circle,fontcolor=blue,color=blue];\n",input,input);
	
	if(input!=-1 && drop!=-1)
		if(input==drop)
			fprintf(fpTree,"%d[label=\"%d\",shape=doublecircle,fontcolor=darkgreen,color=darkgreen];\n",Heap[0],Heap[0]);
	
	if(input!=-1 && drop!=-1)
		if(input!=drop)
			fprintf(fpTree,"dp%d[label=\"%d\",shape=doublecircle,fontcolor=red,color=red];\n",drop,drop);
		else
			fprintf(fpTree,"dp%d[label=\"%d\",shape=Mcircle,fontcolor=red,color=red];\n",drop,drop);
	
	if(input!=-1 && drop!=-1)
	{
		fprintf(fpTree,"{rank = same; in%d; %d; dp%d;};\n",input,Heap[0],drop);
		fprintf(fpTree,"in%d -> %d[color=blue];\n",input,Heap[0]);
		fprintf(fpTree,"%d -> dp%d[color=red];\n",Heap[0],drop);
	}

	for(int i=0; i<n; i++)
	{
		if(2*(i+1)-1<n)
			fprintf(fpTree,"node%d:sw -> node%d;\n",i,i*2+1);
		if(2*(i+1)<n)
			fprintf(fpTree,"node%d:se -> node%d;\n",i,i*2+2);
	}

///////////////////////////////////////////////////////////	
	fprintf(fpTree,"node [fontname = \"Microsoft YaHei\", color=darkgreen, shape=record, height=.1];\n");
	fprintf(fpTree,"edge [fontname = \"Microsoft YaHei\", color=darkgreen, style=solid];\n");
	fprintf(fpTree,"struct [ label = \"{value|address} |");
	fprintf(fpTree,"{|%d} ",0);
	for(int i=0; i<n; i++)
		fprintf(fpTree,"| {%d|%d} ",Heap[i],i+1);
	fprintf(fpTree,"\"]; \n");
	fprintf(fpTree,"struct:s -> node0 [color=white]; \n");
//////////////////////////////////////////////////////////
	
	fprintf(fpTree,"}\n\n");
	fclose(fpTree);
	
}

int main(int argc, char *argv[])
{
	if(argc<3)
		printf("Order is Heap.exe [N][K]\n");
	
	char figlabel[128];
	char orderstr[128];
	
	int Nnum = atoi(argv[1]);
	int Heapsize = atoi(argv[2]);
	int Heap[Heapsize]; 
	memset(Heap,'\0',sizeof(Heap));


	srand((unsigned)time(0));  
	for(int i = 0; i<Heapsize; i++)
		Heap[i] = (unsigned int)rand(); 
	sprintf(figlabel, "Initial Heap");
	DotHeap(Heap,Heapsize,figlabel);
	sprintf(orderstr, "dot.exe -Tpng heapT.gv -o IniT.png");
	system(orderstr);
	
	for(int i=Heapsize/2; i>=0; --i)
		HeapAdjust(Heap,i,Heapsize);
	sprintf(figlabel, "Adjust Heap");
	DotHeap(Heap,Heapsize,figlabel);
	sprintf(orderstr, "dot.exe -Tpng heapT.gv -o AdjT.png");
	system(orderstr);
	
	
	for(int i=Heapsize; i<RAND_MAX;i++){
		int temp = rand();
		if (temp>Heap[0]){
			Heap[0] = temp;
			HeapAdjust(Heap,0,Heapsize);
		}
	}
	
	sprintf(figlabel, "FinaT Heap");
	DotHeap(Heap,Heapsize,figlabel);
	sprintf(orderstr, "dot.exe -Tpng heapT.gv -o FinaT.png");
	system(orderstr);
		
	return 0;	
////////////////////////////////////////////

}
