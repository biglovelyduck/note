#include<stdio.h>
#include<conio.h>
#define VERTEX_MAX 26  //ͼ����󶥵���
#define MAXVALUE 32767//���ֵ������Ϊһ�����������
typedef struct{

	char Vertex[VERTEX_MAX];//���涥����Ϣ����Ż���ĸ��
	int Edges[VERTEX_MAX][VERTEX_MAX];//����ߵ�Ȩ
	int isTrav[VERTEX_MAX];//������־
    int VertexNum;//��������
	int EdgeNum;//������
	int GraphType;//ͼ�����ͣ�0������ͼ��1������ͼ��
}MatrixGraph;//�����ڽӾ���ͼ�ṹ

/*void CreateMatrixGraph(MatrixGraph *G);//�����ڽӾ���ͼ
void OutMatrix(MatrixGraph *g);//����ڽӾ���
*/
void CreateMatrixGraph(MatrixGraph *G){

    int i,j,k,weight;
	char start,end;//�ߵ���ʼ����
	printf("�����������Ϣ��\n");
	for(i=0;i<G->VertexNum;i++){//���붥��
	
		printf("��%d������:",i+1);
		scanf("%c\n",&(G->Vertex[i]));//���浽����������Ԫ����
	}
	printf("���빹�ɸ��ߵ��������㼰Ȩֵ���ö��ŷ��룩:\n");

	//����
	for(int m=0;m<G->VertexNum;m++){
	
		printf("%c\t",G->Vertex[m]);
	}

	for(k=0;k<G->EdgeNum;k++){//����ߵ���Ϣ
	
		fflush(stdin);//������뻺����
       //getchar();//��ͣ����
	   printf("��%d����:",k+1);
	   scanf("%c,%c,%d",&start,&end,&weight);
	   for(i=0;start!=G->Vertex[i];i++);//�����ж����в�����ʼ���
       for(j=0;end!=G->Vertex[j];j++);//�����н���в��ҽ������
	   G->Edges[i][j]=weight;//��Ӧλ�ñ���Ȩֵ����ʾ��һ����

       if(G->GraphType==0)  G->Edges[j][i]=weight;//��������ͼ���ڶԽ�λ�ñ���Ȩֵ
	}
}
void OutMatrix(MatrixGraph *G){//����ڽӾ���

	int i,j;
	for(j=0;j<G->VertexNum;j++)
	    printf("\t%c",G->Vertex[j]);//�ڵ�һ�����������Ϣ

		printf("\n");
		for(i=0;i<G->VertexNum;i++){
		
			printf("%c",G->Vertex[i]);
			for(j=0;j<G->VertexNum;j++){
			
                if(G->Edges[i][j]==MAXVALUE) printf("\t-��");//��ȨֵΪ���ֵ�������������
				else printf("\t-",G->Edges[i][j]);//��������ߵ�Ȩֵ

			}
			printf("\n");
		}
}
int main(){

	MatrixGraph G;//���屣���ڽӾ����ͼ
	int i,j;
	printf("��������ͼ������:(0:����ͼ,1:����ͼ):");
	scanf("%d",&G.GraphType);
	printf("����ͼ�Ķ��������ͱ�����:");
	scanf("%d,%d",&G.VertexNum,&G.EdgeNum);
	for(i=0;i<G.VertexNum;i++){
	
		for(j=0;j<G.VertexNum;j++){
		
			G.Edges[i][j]=MAXVALUE;
		}
	}
	CreateMatrixGraph(&G);//�����ڽӱ����ͼ
	printf("�ڽӱ����������:");
	OutMatrix(&G);
	getch();
	return 0;
}