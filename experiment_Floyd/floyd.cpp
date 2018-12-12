#include <stdio.h>
#include <stdlib.h>

#define MAXN 10 
#define INF = 1000

typedef struct struct_graph{
    char vexs[MAXN];
    int vexnum;//������ 
    int edgnum;//���� 
    int matirx[MAXN][MAXN];//�ڽӾ��� 
} Graph;

int pathmatirx[MAXN][MAXN];//��¼��Ӧ�����С·����ǰ���㣬����p(1,3) = 2 ˵������1������3����С·��Ҫ����2 
int shortPath[MAXN][MAXN];//��¼��������С·��ֵ

void short_path_floyd(Graph G, int P[MAXN][MAXN], int D[MAXN][MAXN]){
    int v, w, k;
    FILE *fp2,*fp3;
    //��ʼ��floyd�㷨���������� 
    for(v = 0; v < G.vexnum; v++){
        for(w = 0; w < G.vexnum; w++){
            D[v][w] = G.matirx[v][w];
            P[v][w] = w;
        }
    }

    //�����Ǹ��������㷨�ĺ��Ĳ��� 
    //kΪ�м�� 
    for(k = 0; k < G.vexnum; k++){
        //vΪ��� 
        for(v = 0 ; v < G.vexnum; v++){
            //wΪ�յ� 
            for(w =0; w < G.vexnum; w++){
                if(D[v][w] > (D[v][k] + D[k][w])){
                    D[v][w] = D[v][k] + D[k][w];//������С·�� 
                    P[v][w] = P[v][k];//������С·���м䶥�� 
                }
            }
        }
    }

    printf("\n��ʼ����D����\n");
    fp2 = fopen("F:\\Distance5.txt","a");
    for(v = 0; v < G.vexnum; v++){
        for(w = 0; w < G.vexnum; w++){
            printf("%d ", D[v][w]);
            fprintf(fp2,"%d ",D[v][w]);
        }
        fprintf(fp2,"\n");
        printf("\n");
    }
    fclose(fp2);

    printf("\n��ʼ����P����\n");
    fp3 = fopen("F:\\Path5.txt","a");
    for(v = 0; v < G.vexnum; v++){
        for(w = 0; w < G.vexnum; w++){
            printf("%d ", P[v][w]);
            fprintf(fp3,"%d ",P[v][w]);
        }
        fprintf(fp3,"\n");
        printf("\n");
    }
    fclose(fp3);

    v = 0;
    w = 3;
    //�� 0 �� 3����С·��
    printf("\n%d -> %d ����С·��Ϊ��%d\n", v, w, D[v][w]);
    k = P[v][w];
    printf("path: %d", v);//��ӡ���
    while(k != w){
        printf("-> %d", k);//��ӡ�м��
        k = P[k][w]; 
    }
    printf("-> %d\n", w);
}

int main()
{
    int v, w;
    Graph G;
    FILE *fp1,*fp2,*fp3;
    fp1 = fopen("F:\\TEST5.txt","a");
    printf("�����붥����:\n");
    scanf("%d", &G.vexnum);
    printf("�������ʼ����ֵ��\n");
    for(v = 0; v < G.vexnum; v++){
        for(w = 0; w < G.vexnum; w++){
            scanf("%d", &G.matirx[v][w]);
        }
    }
    printf("\n����ľ���ֵ��\n");
    for(v = 0; v < G.vexnum; v++){
        for(w = 0; w < G.vexnum; w++){
            printf("%d ", G.matirx[v][w]);
            fprintf(fp1,"%d ",G.matirx[v][w]);
        }
        fprintf(fp1,"\n");
        printf("\n");
    }
    fclose(fp1);
    short_path_floyd(G, pathmatirx, shortPath);
}
