 #include <cstdio>  //cstdio���ǽ�stdio.h��������C++��ͷ�ļ���ʽ���ֳ�����   stdio.h����ʽ��C,C++ͷ�ļ���cstdio�Ǳ�׼ C++��STL������cstdio�еĺ������Ƕ�����һ�����ֿռ�std����ģ����Ҫ����������ֿռ�ĺ���������ü�std::�������ļ�������use namespace std
 #include <algorithm>//1��algorithm��Ϊ"�㷨",��C++�ı�׼ģ��⣨STL��������Ҫ��ͷ�ļ�֮һ���ṩ�˴������ڵ������ķǳ�Աģ�溯���������֮������һ������ǿ����㷨�⣬�����������ҵ�����ͨ�õ��㷨��
 #include <cstring>//C++��� cstring��ӦC���Ե�string.h���泣�õ���strcmp(a,b)==0 �Ƚ��ַ����Ƿ���ͬ����ͬ����ֵ��0����ͬ�Ͳ���0memset(a,0,sizeof(a)); ���ַ������(�����ַ�Ԫ��ȫ���\0strlen(a); ��������ַ����ĳ���(����һ��\0Ϊֹ)����⼸���������Ķ�û��ô�ù�
 #include <queue>
 #include <vector> //vector��һ��˳����������ʵ�Ϻ������࣬�������������Խ��һ����˵���鲻�ܶ�̬��չ������ڳ������е�ʱ�����˷��ڴ棬�������Խ�硣��vector�����ֲ������ȱ�ݣ������������൱�ڿɷ�����չ�����飬����������ʿ죬���м�����ɾ����������ĩ�˲����ɾ���죬�����������.at()���ʵĻ���Ҳ������Խ���顣
 
 using namespace std;
 
 const int N = 20005; //����int const N,���Ǳ�ʾ���ɸı���ֵ��int��������const �ڶ���ָ��ʱ��const int *a��int const *a��������const int *a ��ʾaֻ��ֻ������int;int *const a ��ʾa��һ����ָ�룬ֻ��ָ��ĳһ�̶���int������
 // 2.1 ��:����һ��int���������һά������:vector <int> a;(����������һ��int����a[],��Сû��ָ��,���Զ�̬�����������ɾ��)��
 //2.2 ��:��vector�����ά����.��ʵֻҪ����һ��һά������������,��һ�������������ʵ������������׵�ַ,����ֻҪ����һ����ַ����������,��:vector <int *> a.ͬ����������������ά����Ҳ��һ��,vector <int**>a;����������������. 
 const int inf = 0x3f3f3f3f;
 
 typedef struct
 {
     int to;
     int dis;
 }PP;
 //ȫ�ֱ��� 
 int n,m;//�㣬�� 
 vector<PP> bian[N];//ȷ�е�˵��һ����.���൱��һ����̬������,������Ա�޷�֪���Լ���Ҫ������Ĺ�ģ���ʱ,���������������Դﵽ����Լ�ռ��Ŀ��. 
 int v[N];
 int vis[N];
 
 void bellman()
 {
     queue<int> que;
     int te,nt;
     que.push(1);
     vis[1]=1;
     int i;
     int dis;
     while(que.size()>=1)
     {
         te=que.front();
         que.pop();
         for(i=0;i<bian[te].size();i++){
             nt=bian[te][i].to;
             dis=bian[te][i].dis;
             if(v[nt]>v[te]+dis){
                 v[nt]=v[te]+dis;
                 if(vis[nt]==0){
                     vis[nt]=1;
                     que.push(nt);
                 }
             }
         }
         vis[te]=0;
     }
 }
 
 int main()
 {
     int i,j;
     int uu,vv,l;
     PP te;
     //freopen("data.in","r",stdin);
     //while(scanf("%d%d",&n,&m)!=EOF)
     scanf("%d%d",&n,&m);
     {
         memset(vis,0,sizeof(vis));//��ʼ��visȫ��û�з��� 
         fill(v,v+n+1,inf);//��һ�������Ԫ�ض�����valֵ������������fill(first,last,val);//firstΪ�������׵�������lastΪ������ĩ��������valΪ��Ҫ�滻��ֵ��   fill_n�����������ǣ�����һ����ʼ�㣬Ȼ���ٸ���һ����ֵcount��val���Ѵ���ʼ�㿪ʼ���θ���count��Ԫ��val��ֵ��
                           //ע�⣺ ������û��Ԫ�صĿ������ϵ���fill_n����
         v[1]=0;
         for(i=0;i<=n;i++){
             bian[i].clear();
             //printf(" i=%d v=%d\n",i,v[i]);
         }
         for(i=1;i<=m;i++){
             scanf("%d%d%d",&uu,&vv,&l);
             te.to=vv;te.dis=l;
             bian[uu].push_back(te);
         }
         bellman();
         for(i=2;i<=n;i++){
            printf("%d\n",v[i]);
         }
     }
     return 0;
 }
