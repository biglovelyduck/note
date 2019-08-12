/*这是一个纵横火柴棒游戏。
如图1，在3x4的格子中，游戏的双方轮流放置火柴棒。
其规则是：
1. 不能放置在已经放置了火柴棒的地方（即只能在空格中放置）。
2. 火柴棒的方向只能是竖直或水平放置。
3. 火柴棒不能与其它格子中的火柴“连通”。
所谓连通是指两根火柴棒可以连成一条直线，且中间没有其它不同方向的火柴“阻拦”。
例如：
图1所示的局面下，可以在C2位置竖直放置（为了方便描述格子位置，图中左、下都添加了标记），但不能水平放置，因为会与A2连通。
同样道理，B2，B3，D2此时两种方向都不可以放置。
但如果C2竖直放置后，D2就可以水平放置了，因为不再会与A2连通（受到了C2的阻挡）。
4. 游戏双方轮流放置火柴，不可以弃权，也不可以放多根。

如某一方无法继续放置，则该方为负（输的一方）。

游戏开始时可能已经放置了多根火柴。
你的任务是：编写程序，读入初始状态，计算出对自己最有利的放置方法并输出放置后的局面。
图1的局面表示为：
00-1
-000
0100
即用“0”表示空闲位置，用“1”表示竖直放置，用“-”表示水平放置。

解法不唯一，找到任意解法即可。

例如，局面：
0111
-000
-000
的解：
-111
-000
-000

再例如，局面：
1111
----
0010
的解：
1111
----
0110

#include <iostream>
using namespace std;
void main()
{
//用new创建一个二维数组,有两种方法,是等价的
//一:
int (*p)[10] = new int[5][10];
//二:
int **p = new int* [5];
for(int i=0;i <5;i++)
p[i] = new int[10];
//指针数组的创建,也有两种方法
//一:
char **pa = new char* [4];
for (int i=0;i <4;i++)
{
pa[i] = new char[8]; //为每个指针都分配8个char元素空间。
}
//二:
char *pa[4];//可以不用new创建
for (int i=0;i <4;i++)
{
pa[i] = new char[8]; //为每个指针都分配8个char元素空间。
}
//delete二维数组
//for一:
delete []p;
//for二:
for(int i=0; i <5; ++i)
delete []p[i];
delete []p;
//delete指针数组
//for一:
for(int i=0; i <4; ++i)
delete []pa[i];
delete []pa;
//for二:
for(int i=0; i <4; ++i)
delete []pa[i];
}


*/

#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

string trim(char* s){
	char *str1;
	char *str2=s;
	while(*str2!='\0'){
		if(*str2!=' '){
			*str1=*str2;
			str1++;
			str2++;
			cout<<*str2<<endl; 
		}
		else{
			str2++;
		}
	}
	return string(str1);
}

int main(int argc, char** argv) {
//	char (*data)[10]=new char[3][10];  正确

//    char **data=new char* [3] ;//三行
//	for(int i=0;i<3;i++){
//		data[i]=new char[10];
//	} 

//    char data[3][10];

//    cin.get(data[0],10);
//    cin.getline(data[0],10); 
    //cout<<trim(data[0])<<endl;
    
    char (*data)[10]=new char[3][10];
    //gets(data[0]);
//    gets(data[1]);
//    gets(data[2]);
   // cout<<trim(data[0])<<endl;


    char s[20]="fang xi kai";//指针s的地址不可变 
//    char* p=s;//p存放字符串的地址 
////    cin.get(s,10);
//    while(*p!='\0'){
//    	cout<<*p<<endl;
//    	p++;
//	
	char *str2=s;
	char *str1=s;
	cout<<"str1="<<str1<<endl;
	cout<<"str2="<<str2<<endl;
	cout<<"s="<<s<<endl; 
	cout<<endl;
	cout<<"&str1="<<&str1<<endl;
	cout<<"&str2="<<&str2<<endl;
	cout<<"&s="<<&s<<endl; 
	cout<<endl;

	while(*str2!='\0'){
		if(*str2!=' '){
			*str1=*str2;
			str1++;
			str2++;
			//cout<<*str2<<endl; 
		}
		else{
			str2++;
		}
	}
	*str1=*str2;
	cout<<"s="<<s<<endl;
	return 0;
}
