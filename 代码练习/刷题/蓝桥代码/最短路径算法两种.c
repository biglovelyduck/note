/*
 * ���·�����Ͻ�˹�����㷨�͸��������㷨�������ڽӾ���洢��
 *
 */ 
   
#include<stdio.h> 
   
#define MAX_VERTEX_NUM 20 
#define INFINITE 10000  //��������� 
//ͼ�Ķ��� 
typedef struct  
{ 
    int vertexNum; 
    char vertex[MAX_VERTEX_NUM]; 
    int arc[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; 
}Graph,*PGraph; //PGraph��ָ��Graph���͵�ָ����� 
   
//���������е�Ԫ�ض��� 
typedef struct 
{ 
    int distance; 
    int path[MAX_VERTEX_NUM]; 
}ArrayNode; 
   
   
//���������� 
void createdGraph(PGraph g) 
{ 
    int i,j; 
    g->vertexNum=6; 
    for(i=0;i<g->vertexNum;i++) 
        g->vertex[i]='A'+i; 
    for(i=0;i<g->vertexNum;i++) 
        for(j=0;j<g->vertexNum;j++) 
            g->arc[i][j]=0; 
    g->arc[0][2]=10; 
    g->arc[0][4]=30; 
    g->arc[0][5]=100; 
    g->arc[1][2]=5; 
    g->arc[2][3]=50; 
    g->arc[3][5]=10; 
    g->arc[4][3]=20; 
    g->arc[4][5]=60; 
} 
   
//�Ͻ�˹�����㷨 
void Dijkstra(PGraph g,int from,int to) 
{ 
    int i,j,index=-1; 
    int n=1;//��¼�Ѿ������������֮�����̾���ĸ��� 
    ArrayNode shortestPath[MAX_VERTEX_NUM]; 
    int flag[MAX_VERTEX_NUM]={0};//��ǣ�Ϊ1��ʾ������������̾�������� 
   
    //1.��from�����������ֱ�Ӿ��룬����ʼ��shortestPath���� 
    for(i=0;i<g->vertexNum;i++){ 
        if(from==i){ 
            shortestPath[i].distance=0; 
            shortestPath[i].path[0]=i; 
            flag[from]=1; 
        } 
        else if(g->arc[from][i]>0){ 
            shortestPath[i].path[0]=from; 
            shortestPath[i].path[1]=i; 
            shortestPath[i].distance=g->arc[from][i]; 
        }else 
            shortestPath[i].distance=INFINITE; 
    } 
    //2.ÿ����һ�����·�� 
    while(n<g->vertexNum){ 
        //ѡ��shortestPath�о�����С�ģ����from�������������·�� 
        index=-1; 
        for(i=0;i<g->vertexNum;i++){ 
            if(i==from) 
                continue; 
            if(flag[i]==0 && index==-1 && shortestPath[i].distance!=INFINITE) 
                index=i; 
            if(flag[i]==0 && index!=-1 && shortestPath[i].distance<shortestPath[index].distance) 
                index=i; 
        } 
        flag[index]=1; 
        //�޸ĵ�������������·�� 
        for(i=0;i<g->vertexNum;i++){ 
            if(i==from) 
                continue; 
            if(g->arc[index][i]>0 && g->arc[index][i]+shortestPath[index].distance<shortestPath[i].distance){ 
                shortestPath[i].distance=g->arc[index][i]+shortestPath[index].distance; 
                //�޸�·�� 
                j=0; 
                while(1){ 
                    shortestPath[i].path[j]=shortestPath[index].path[j]; 
                    if(shortestPath[index].path[j]==index) 
                        break; 
                    j++; 
                } 
                shortestPath[i].path[j+1]=i; 
            } 
        } 
        n++; 
    } 
    //���from��to�����·�������� 
    if(shortestPath[to].distance==INFINITE){ 
        printf("%c��%cû��·��\n",from+'A',to+'A'); 
        return; 
    } 
    printf("%c��%c�����·�������ǣ�%d\n",from+'A',to+'A',shortestPath[to].distance); 
    printf("�����Ķ��㣺  "); 
    i=0; 
    while(1){ 
        printf("%-3c",shortestPath[to].path[i]+'A'); 
        if(shortestPath[to].path[i]==to) 
            break; 
        i++; 
    } 
    printf("\n"); 
} 
   
//���������㷨 
void Floyd(PGraph g,int from,int to) 
{ 
    int i,j,k; 
    int shortestPath[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//�洢���·�������� 
    //��ʼ��shortestPath 
    for(i=0;i<g->vertexNum;i++) 
        for(j=0;j<g->vertexNum;j++){ 
            if(i==j){ 
                shortestPath[i][j]=0; 
                continue; 
            } 
            if(g->arc[i][j]>0) 
                shortestPath[i][j]=g->arc[i][j]; 
            else 
                shortestPath[i][j]=INFINITE; 
        } 
    //����������˳�μ��룬���޸����·�� 
    for(k=0;k<g->vertexNum;k++){ 
        //��i��j֮�����k 
        for(i=0;i<g->vertexNum;i++){ 
            for(j=0;j<g->vertexNum;j++){ 
                if(shortestPath[i][k]+shortestPath[k][j]<shortestPath[i][j]) 
                    shortestPath[i][j]=shortestPath[i][k]+shortestPath[k][j]; 
            } 
        } 
    } 
    //������·�� 
    if(shortestPath[from][to]==INFINITE){ 
        printf("%c��%cû��·��\n",from+'A',to+'A'); 
        return; 
    } 
    printf("%c��%c�����·�������ǣ�%d\n",from+'A',to+'A',shortestPath[from][to]); 
    printf("\n"); 
} 
   
void main() 
{ 
    Graph graph; 
    char from,to; 
    createdGraph(&graph); 
    printf("����������յ�(��AF���м䲻Ҫ�пո�)\n"); 
    scanf("%c%c",&from,&to); 
    printf("\n�Ͻ�˹�����㷨:\n"); 
    Dijkstra(&graph,from-'A',to-'A'); 
    printf("\n���������㷨:\n"); 
    Floyd(&graph,from-'A',to-'A'); 
} 
