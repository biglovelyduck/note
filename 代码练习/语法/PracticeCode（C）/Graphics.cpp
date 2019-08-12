#include<stdio.h>
#include<conio.h>
#define VERTEX_MAX 26  //图的最大顶点数
#define MAXVALUE 32767//最大值（可设为一个最大整数）
typedef struct{

	char Vertex[VERTEX_MAX];//保存顶点信息（序号或字母）
	int Edges[VERTEX_MAX][VERTEX_MAX];//保存边的权
	int isTrav[VERTEX_MAX];//遍历标志
    int VertexNum;//顶点数量
	int EdgeNum;//边数量
	int GraphType;//图的类型（0：无向图，1：有向图）
}MatrixGraph;//定义邻接矩阵图结构

/*void CreateMatrixGraph(MatrixGraph *G);//创建邻接矩阵图
void OutMatrix(MatrixGraph *g);//输出邻接矩阵
*/
void CreateMatrixGraph(MatrixGraph *G){

    int i,j,k,weight;
	char start,end;//边的起始顶点
	printf("输入各顶点信息：\n");
	for(i=0;i<G->VertexNum;i++){//输入顶点
	
		printf("第%d个顶点:",i+1);
		scanf("%c\n",&(G->Vertex[i]));//保存到各顶点数组元素中
	}
	printf("输入构成各边的两个顶点及权值（用逗号分离）:\n");

	//测试
	for(int m=0;m<G->VertexNum;m++){
	
		printf("%c\t",G->Vertex[m]);
	}

	for(k=0;k<G->EdgeNum;k++){//输入边的信息
	
		fflush(stdin);//清空输入缓冲区
       //getchar();//暂停输入
	   printf("第%d条边:",k+1);
	   scanf("%c,%c,%d",&start,&end,&weight);
	   for(i=0;start!=G->Vertex[i];i++);//在已有顶点中查找起始结点
       for(j=0;end!=G->Vertex[j];j++);//在已有结点中查找结束结点
	   G->Edges[i][j]=weight;//对应位置保存权值，表示有一条边

       if(G->GraphType==0)  G->Edges[j][i]=weight;//若是无向图，在对角位置保存权值
	}
}
void OutMatrix(MatrixGraph *G){//输出邻接矩阵

	int i,j;
	for(j=0;j<G->VertexNum;j++)
	    printf("\t%c",G->Vertex[j]);//在第一行输出顶点信息

		printf("\n");
		for(i=0;i<G->VertexNum;i++){
		
			printf("%c",G->Vertex[i]);
			for(j=0;j<G->VertexNum;j++){
			
                if(G->Edges[i][j]==MAXVALUE) printf("\t-∞");//若权值为最大值，输出无穷大符号
				else printf("\t-",G->Edges[i][j]);//否则输出边的权值

			}
			printf("\n");
		}
}
int main(){

	MatrixGraph G;//定义保存邻接矩阵的图
	int i,j;
	printf("输入生成图的类型:(0:无向图,1:有向图):");
	scanf("%d",&G.GraphType);
	printf("输入图的顶点数量和边数量:");
	scanf("%d,%d",&G.VertexNum,&G.EdgeNum);
	for(i=0;i<G.VertexNum;i++){
	
		for(j=0;j<G.VertexNum;j++){
		
			G.Edges[i][j]=MAXVALUE;
		}
	}
	CreateMatrixGraph(&G);//创建邻接表保存的图
	printf("邻接表的数据如下:");
	OutMatrix(&G);
	getch();
	return 0;
}