#include "string.h"
#include "stdio.h"
typedef struct ArcCell{
int adj;
char *info;
}ArcCell; /*定义边的类型*/



typedef struct VertexType{
int number;
char *place;
}VertexType; /*定义顶点的类型*/




typedef struct{
VertexType vex[26];//顶点数组
ArcCell arcs[26][26];
int vexnum,arcnum;
}MGraph; /*定义图的类型*/



MGraph G; /*把图定义为全局变量*/
int P[26][26];
long int D[26];



void CreateUDN(v,a) /*造图涵数,顶点数量，边数量*/
int v,a;
{ int i,j;
G.vexnum=v;
G.arcnum=a;
for(i=0;i<G.vexnum;++i)//i先加1，后取值
   G.vex[i].number=i;//for循环结束,顶点赋值
G.vex[0].place="兰州交通大学";//字符串赋值给指针就是将地址值赋给指针
G.vex[1].place="甘肃政法学院";
G.vex[2].place="兰州师范大学";
G.vex[3].place="师大附中";
G.vex[4].place="西站";
G.vex[5].place="公交公司";
G.vex[6].place="小西湖";
G.vex[7].place="兰州理工大本部";
G.vex[8].place="西湖公园";
G.vex[9].place="文化宫";
G.vex[10].place="西关十字";
G.vex[11].place="陆军总院";
G.vex[12].place="石油大厦";
G.vex[13].place="中山桥";
G.vex[14].place="兰州剧院";
G.vex[15].place="南关十字";
G.vex[16].place="五泉山";
G.vex[17].place="广场西口";
G.vex[18].place="广场东口";
G.vex[19].place="兰州大学";
G.vex[20].place="火车站";
G.vex[21].place="市政府";
G.vex[22].place="雁滩";
G.vex[23].place="杨家桥";
G.vex[24].place="龚家湾";
G.vex[25].place="兰州理工大西校区";

for(i=0;i<G.vexnum;++i)
   for(j=0;j<G.vexnum;++j)
      G.arcs[i][j].adj=23000;//for循环结束
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




    void narrate() /*说明函数*/
{
int i,k=0;
printf("\n*****************************欢迎使用该程序!*************************\n");

printf("\n以下是选项:\n\n");
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
    printf("您想查询哪个地方的详细信息?请输入地点编号:");
    scanf("%d",&b);
    getchar();
    printf("\n");
    switch(b)
    {   case 0:
            printf("0:兰州交通大学\n\n　　前兰州铁道学院。\n\n");break;
        case 1: 
            printf("1:甘肃政法学院\n\n   兰州的一所重要的学校。\n\n");break;
        case 2: 
            printf("2:兰州师范大学\n\n　　兰州一所重要的师范类学校。\n\n");break; 

        case 3:
            printf("3:师大附中\n\n　　兰州市第一的高中学校。\n\n");break; 

        case 4:
            printf("4:兰州西站\n\n　　火车西站兼购物市场，车多人多。\n\n");break;
        case 5:
            printf("5:公交公司\n\n　　公交车的管理公司。\n\n");break; 
        case 6:
            printf("6:小西湖\n\n　　购物市场。\n\n");break; 
        case 7:
            printf("7:兰州理工大学\n\n　　前甘肃工业大学,在甘肃省内稳做第三把交椅。\n\n");break;
        case 8:
            printf("8:西湖公园\n\n      一所免费的公共公园。\n\n");break;
        case 9:
            printf("9:文化宫\n\n     甘肃文化的集结地。\n\n");break;
        case 10:
            printf("10:西关什字\n\n　　兰州市中心。\n\n");break;

        case 11:
            printf("11:陆军总院\n\n    医院，兰州市医疗设施先进的医院。\n\n");break;
        case 12:
            printf("12:石油大厦\n\n    一座立在黄河旁边的大厦，是一座写字楼。\n\n");break;
        case 13:
            printf("13:中山桥\n\n　　黄河第一桥，主要构架为钢铁所造，历史悠久。\n\n");break; 
        case 14:
            printf("14:兰州剧院\n\n     兰州历史悠久，规模较大的电影院。\n\n");break;
        case 15:
            printf("15:南关\n\n　　政府部门所在地，市中心。\n\n");break;
        case 16:
            printf("16:五泉山\n\n     兰州市的一座公园，比较著名。\n\n");break;

        case 17:
            printf("17:广场西口\n\n     东方红广场西面的口子，东方红广场是兰州最大，最繁华的广场。\n\n");break;
        case 18:
            printf("18:广场东口\n\n     东方红广场东面的口子，东方红广场是兰州最大，最繁华的广场。\n\n");break;
        case 19:
            printf("19:兰州大学\n\n     兰州市排名第一的高校。\n\n");break;
        case 20:
            printf("20:兰州火车站\n\n　　火车站，转运枢纽。\n\n");break;
        case 21:
            printf("21:市政府\n\n     兰州市市政府，兰州市的管理地方。\n\n");break;
        case 22:
            printf("22:雁滩\n\n　　旧货市场。\n\n");break;

        case 23:
            printf("23:杨家桥\n\n   七里河区西面的一个重要交通枢纽。\n\n");break;
        case 24:
            printf("24:龚家湾\n\n   一个集市。\n\n");break;
        case 25:
            printf("25:兰州理工大西校区\n\n     兰州理工大学的分校区。\n\n");break;
        default:
            printf("目的地编号输入错误！请输入0->32的数字编号！\n\n"); break; 
    }
}


void ShortwstPath(num) /*最短路径函数*/
int num;
{ int v,w,i,t;
  int final[26];
  int min;
  for(v=0;v<26;++v)/*初始化*/
  {
     final[v]=0; /*标志数组初始化*/
     D[v]=G.arcs[num][v].adj;
     for(w=0;w<26;++w)
        P[v][w]=0;/*设空路径*/
       if(D[v]<23000)/*v,v0间有边存在*/
       {P[v][num]=1;P[v][v]=1;/*到v的最短路径上包含v0及v*/
        }/*if*/
   }
  D[num]=0;
  final[num]=1;/*初始化，v0顶点属于B集*/
  /*开始主循环，每次求得v0到某个v顶点的最短路径，并加v到B集*/
  for(i=0;i<26;++i)/*其余G.vexnum-1各顶点*/
  {
     min=23000;
     for(w=0;w<26;++w)
       if(!final[w])/*w顶点在V-S中*/
         if(D[w]<min){v=w;min=D[w];}/*w顶点离v0更近*/
        final[v]=1;/*离v0顶点最近的v加入B*/
      for(w=0;w<26;++w)/*更新当前最短路径及距离*/
        if(!final[w]&&((min+G.arcs[v][w].adj)<D[w]))
        {
          D[w]=min+G.arcs[v][w].adj;/*修改D和P数组*/
          for(t=0;t<26;t++) P[w][t]=P[v][t];
          P[w][w]=1;
        }/*if*/
   }/*for*/
}




void output(place1,place2) /*输出函数*/
int place1;
int place2;
{
   int a,b,c,d,q=0;
   a=place2;
   if(a!=place1)
    {
      printf("\n最短路径从 %s 到 %s\n",G.vex[place1].place,G.vex[place2].place);
      printf("\n最短距离 %dm.\n",D[a]);
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




void main() /*主函数*/
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
  printf("\n你好！如果你想用该程序，请输入'Y' or 'y'!\n");
  scanf("%c",&c);
  if(c=='y'||c=='Y')
  {
   narrate();
   printf("\n请输入服务项目 \n");
   printf("(1) 地点介绍\n");
   printf("(2) 最短路径查询\n");
   scanf("%d",&z);
   if(z==1)
   {
       printf("地点信息:\n");
       introduce();
   } 
    if(z==2)
    {
    printf("\n请输入开始地点!\n");
    scanf("%d",&v0);
    printf("请输入结束地点!\n");
    scanf("%d",&v1);
    ShortwstPath(v0);
    output(v0,v1);
    }
 }
  getch();
}
