 #include <cstdio>  //cstdio就是将stdio.h的内容用C++的头文件形式表现出来。   stdio.h是老式的C,C++头文件，cstdio是标准 C++（STL），且cstdio中的函数都是定义在一个名字空间std里面的，如果要调用这个名字空间的函数，必须得加std::或者在文件中声明use namespace std
 #include <algorithm>//1、algorithm意为"算法",是C++的标准模版库（STL）中最重要的头文件之一，提供了大量基于迭代器的非成员模版函数。简而言之，这是一个功能强大的算法库，可以在这里找到大量通用的算法。
 #include <cstring>//C++里的 cstring对应C语言的string.h里面常用的有strcmp(a,b)==0 比较字符串是否相同，相同返回值是0，不同就不是0memset(a,0,sizeof(a)); 把字符串清空(所有字符元素全变成\0strlen(a); 计算这个字符串的长度(到第一个\0为止)般就这几个，其它的都没怎么用过
 #include <queue>
 #include <vector> //vector是一种顺序容器，事实上和数组差不多，但它比数组更优越。一般来说数组不能动态拓展，因此在程序运行的时候不是浪费内存，就是造成越界。而vector正好弥补了这个缺陷，它的特征是相当于可分配拓展的数组，它的随机访问快，在中间插入和删除慢，但在末端插入和删除快，而且如果你用.at()访问的话，也可以做越界检查。
 
 using namespace std;
 
 const int N = 20005; //等于int const N,都是表示不可改变数值的int常量。而const 在定义指针时，const int *a和int const *a才有区别。const int *a 表示a只能只向常量的int;int *const a 表示a是一个常指针，只能指向某一固定的int变量。
 // 2.1 例:声明一个int向量以替代一维的数组:vector <int> a;(等于声明了一个int数组a[],大小没有指定,可以动态的向里面添加删除)。
 //2.2 例:用vector代替二维数组.其实只要声明一个一维数组向量即可,而一个数组的名字其实代表的是它的首地址,所以只要声明一个地址的向量即可,即:vector <int *> a.同理想用向量代替三维数组也是一样,vector <int**>a;再往上面依此类推. 
 const int inf = 0x3f3f3f3f;
 
 typedef struct
 {
     int to;
     int dis;
 }PP;
 //全局变量 
 int n,m;//点，边 
 vector<PP> bian[N];//确切的说是一个类.它相当于一个动态的数组,当程序员无法知道自己需要的数组的规模多大时,用其来解决问题可以达到最大节约空间的目的. 
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
         memset(vis,0,sizeof(vis));//初始化vis全部没有访问 
         fill(v,v+n+1,inf);//将一个区间的元素都赋予val值。函数参数：fill(first,last,val);//first为容器的首迭代器，last为容器的末迭代器，val为将要替换的值。   fill_n函数的作用是：给你一个起始点，然后再给你一个数值count和val。把从起始点开始依次赋予count个元素val的值。
                           //注意： 不能在没有元素的空容器上调用fill_n函数
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
