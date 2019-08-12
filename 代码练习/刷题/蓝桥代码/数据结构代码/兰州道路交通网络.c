#include "string.h"
#include "stdio.h"
typedef struct ArcCell{
int adj;
char *info;
}ArcCell; /*����ߵ�����*/



typedef struct VertexType{
int number;
char *place;
}VertexType; /*���嶥�������*/




typedef struct{
VertexType vex[26];//��������
ArcCell arcs[26][26];
int vexnum,arcnum;
}MGraph; /*����ͼ������*/



MGraph G; /*��ͼ����Ϊȫ�ֱ���*/
int P[26][26];
long int D[26];



void CreateUDN(v,a) /*��ͼ����,����������������*/
int v,a;
{ int i,j;
G.vexnum=v;
G.arcnum=a;
for(i=0;i<G.vexnum;++i)//i�ȼ�1����ȡֵ
   G.vex[i].number=i;//forѭ������,���㸳ֵ
G.vex[0].place="���ݽ�ͨ��ѧ";//�ַ�����ֵ��ָ����ǽ���ֵַ����ָ��
G.vex[1].place="��������ѧԺ";
G.vex[2].place="����ʦ����ѧ";
G.vex[3].place="ʦ����";
G.vex[4].place="��վ";
G.vex[5].place="������˾";
G.vex[6].place="С����";
G.vex[7].place="�������󱾲�";
G.vex[8].place="������԰";
G.vex[9].place="�Ļ���";
G.vex[10].place="����ʮ��";
G.vex[11].place="½����Ժ";
G.vex[12].place="ʯ�ʹ���";
G.vex[13].place="��ɽ��";
G.vex[14].place="���ݾ�Ժ";
G.vex[15].place="�Ϲ�ʮ��";
G.vex[16].place="��Ȫɽ";
G.vex[17].place="�㳡����";
G.vex[18].place="�㳡����";
G.vex[19].place="���ݴ�ѧ";
G.vex[20].place="��վ";
G.vex[21].place="������";
G.vex[22].place="��̲";
G.vex[23].place="�����";
G.vex[24].place="������";
G.vex[25].place="����������У��";

for(i=0;i<G.vexnum;++i)
   for(j=0;j<G.vexnum;++j)
      G.arcs[i][j].adj=23000;//forѭ������
G.arcs[0][1].adj=G.arcs[1][0].adj=500;
G.arcs[1][2].adj=G.arcs[2][1].adj=600;
G.arcs[2][3].adj=G.arcs[3][2].adj=960;
G.arcs[3][4].adj=G.arcs[4][3].adj=2320;
G.arcs[4][5].adj=G.arcs[5][4].adj=1200;
G.arcs[5][6].adj=G.arcs[6][5].adj=780;
G.arcs[6][7].adj=G.arcs[7][6].adj=1006;
G.arcs[6][8].adj=G.arcs[8][6].adj=574;
G.arcs[8][9].adj=G.arcs[9][8].adj=540;
G.arcs[9][10].adj=G.arcs[10][9].adj=670;
G.arcs[11][6].adj=G.arcs[6][11].adj=640;
G.arcs[6][12].adj=G.arcs[12][6].adj=802;
G.arcs[12][13].adj=G.arcs[13][12].adj=625;
G.arcs[13][14].adj=G.arcs[14][13].adj=487;
G.arcs[10][14].adj=G.arcs[14][10].adj=280;
G.arcs[14][15].adj=G.arcs[15][14].adj=511;
G.arcs[15][16].adj=G.arcs[16][15].adj=1389;
G.arcs[15][17].adj=G.arcs[17][15].adj=956;
G.arcs[17][18].adj=G.arcs[18][17].adj=479;
G.arcs[18][19].adj=G.arcs[19][18].adj=1876;
G.arcs[19][20].adj=G.arcs[20][19].adj=765;
G.arcs[20][21].adj=G.arcs[21][20].adj=5969;
G.arcs[13][21].adj=G.arcs[21][13].adj=895;
G.arcs[21][22].adj=G.arcs[22][21].adj=2067;
G.arcs[22][23].adj=G.arcs[23][22].adj=9625;
G.arcs[23][24].adj=G.arcs[31][23].adj=800;
G.arcs[24][25].adj=G.arcs[25][24].adj=329;

}




    void narrate() /*˵������*/
{
int i,k=0;
printf("\n*****************************��ӭʹ�øó���!*************************\n");

printf("\n������ѡ��:\n\n");
for(i=0;i<26;i++)
{
printf("(%d) %-10s",i,G.vex[i].place);
k=k+1;
if(k%4==0) printf("\n\n");
}
}




void introduce()
{
    int b;
    printf("�����ѯ�ĸ��ط�����ϸ��Ϣ?������ص���:");
    scanf("%d",&b);
    getchar();
    printf("\n");
    switch(b)
    {   case 0:
            printf("0:���ݽ�ͨ��ѧ\n\n����ǰ��������ѧԺ��\n\n");break;
        case 1: 
            printf("1:��������ѧԺ\n\n   ���ݵ�һ����Ҫ��ѧУ��\n\n");break;
        case 2: 
            printf("2:����ʦ����ѧ\n\n��������һ����Ҫ��ʦ����ѧУ��\n\n");break; 

        case 3:
            printf("3:ʦ����\n\n���������е�һ�ĸ���ѧУ��\n\n");break; 

        case 4:
            printf("4:������վ\n\n��������վ�湺���г��������˶ࡣ\n\n");break;
        case 5:
            printf("5:������˾\n\n�����������Ĺ���˾��\n\n");break; 
        case 6:
            printf("6:С����\n\n���������г���\n\n");break; 
        case 7:
            printf("7:��������ѧ\n\n����ǰ���๤ҵ��ѧ,�ڸ���ʡ�����������ѽ��Ρ�\n\n");break;
        case 8:
            printf("8:������԰\n\n      һ����ѵĹ�����԰��\n\n");break;
        case 9:
            printf("9:�Ļ���\n\n     �����Ļ��ļ���ء�\n\n");break;
        case 10:
            printf("10:����ʲ��\n\n�������������ġ�\n\n");break;

        case 11:
            printf("11:½����Ժ\n\n    ҽԺ��������ҽ����ʩ�Ƚ���ҽԺ��\n\n");break;
        case 12:
            printf("12:ʯ�ʹ���\n\n    һ�����ڻƺ��ԱߵĴ��ã���һ��д��¥��\n\n");break;
        case 13:
            printf("13:��ɽ��\n\n�����ƺӵ�һ�ţ���Ҫ����Ϊ�������죬��ʷ�ƾá�\n\n");break; 
        case 14:
            printf("14:���ݾ�Ժ\n\n     ������ʷ�ƾã���ģ�ϴ�ĵ�ӰԺ��\n\n");break;
        case 15:
            printf("15:�Ϲ�\n\n���������������ڵأ������ġ�\n\n");break;
        case 16:
            printf("16:��Ȫɽ\n\n     �����е�һ����԰���Ƚ�������\n\n");break;

        case 17:
            printf("17:�㳡����\n\n     ������㳡����Ŀ��ӣ�������㳡�������������Ĺ㳡��\n\n");break;
        case 18:
            printf("18:�㳡����\n\n     ������㳡����Ŀ��ӣ�������㳡�������������Ĺ㳡��\n\n");break;
        case 19:
            printf("19:���ݴ�ѧ\n\n     ������������һ�ĸ�У��\n\n");break;
        case 20:
            printf("20:���ݻ�վ\n\n������վ��ת����Ŧ��\n\n");break;
        case 21:
            printf("21:������\n\n     �������������������еĹ���ط���\n\n");break;
        case 22:
            printf("22:��̲\n\n�����ɻ��г���\n\n");break;

        case 23:
            printf("23:�����\n\n   ������������һ����Ҫ��ͨ��Ŧ��\n\n");break;
        case 24:
            printf("24:������\n\n   һ�����С�\n\n");break;
        case 25:
            printf("25:����������У��\n\n     ��������ѧ�ķ�У����\n\n");break;
        default:
            printf("Ŀ�ĵر���������������0->32�����ֱ�ţ�\n\n"); break; 
    }
}


void ShortwstPath(num) /*���·������*/
int num;
{ int v,w,i,t;
  int final[26];
  int min;
  for(v=0;v<26;++v)/*��ʼ��*/
  {
     final[v]=0; /*��־�����ʼ��*/
     D[v]=G.arcs[num][v].adj;
     for(w=0;w<26;++w)
        P[v][w]=0;/*���·��*/
       if(D[v]<23000)/*v,v0���бߴ���*/
       {P[v][num]=1;P[v][v]=1;/*��v�����·���ϰ���v0��v*/
        }/*if*/
   }
  D[num]=0;
  final[num]=1;/*��ʼ����v0��������B��*/
  /*��ʼ��ѭ����ÿ�����v0��ĳ��v��������·��������v��B��*/
  for(i=0;i<26;++i)/*����G.vexnum-1������*/
  {
     min=23000;
     for(w=0;w<26;++w)
       if(!final[w])/*w������V-S��*/
         if(D[w]<min){v=w;min=D[w];}/*w������v0����*/
        final[v]=1;/*��v0���������v����B*/
      for(w=0;w<26;++w)/*���µ�ǰ���·��������*/
        if(!final[w]&&((min+G.arcs[v][w].adj)<D[w]))
        {
          D[w]=min+G.arcs[v][w].adj;/*�޸�D��P����*/
          for(t=0;t<26;t++) P[w][t]=P[v][t];
          P[w][w]=1;
        }/*if*/
   }/*for*/
}




void output(place1,place2) /*�������*/
int place1;
int place2;
{
   int a,b,c,d,q=0;
   a=place2;
   if(a!=place1)
    {
      printf("\n���·���� %s �� %s\n",G.vex[place1].place,G.vex[place2].place);
      printf("\n��̾��� %dm.\n",D[a]);
      printf("%s",G.vex[place1].place);
      d=place1;
      for(c=0;c<26;++c)
      {
         gate:;
         P[a][place1]=0;
         for(b=0;b<26;b++)
         {
            if(G.arcs[d][b].adj<20000&&P[a][b])
            {
                printf("----->%s",G.vex[b].place);
                q=q+1;
                P[a][b]=0;
                d=b;
                if(q%4==0) printf("\n");
                goto gate;
             }
          }
      }
     }
}




void main() /*������*/
{
  void CreateUGN();
  void ShortwstPath();
  void narrate();
  void introduce();
  void output();
  int k,z;
  char c;
  int v0,v1;
  CreateUDN(26,26);
  printf("\n��ã���������øó���������'Y' or 'y'!\n");
  scanf("%c",&c);
  if(c=='y'||c=='Y')
  {
   narrate();
   printf("\n�����������Ŀ \n");
   printf("(1) �ص����\n");
   printf("(2) ���·����ѯ\n");
   scanf("%d",&z);
   if(z==1)
   {
       printf("�ص���Ϣ:\n");
       introduce();
   } 
    if(z==2)
    {
    printf("\n�����뿪ʼ�ص�!\n");
    scanf("%d",&v0);
    printf("����������ص�!\n");
    scanf("%d",&v1);
    ShortwstPath(v0);
    output(v0,v1);
    }
 }
  getch();
}
