#include <iostream>
#include <list> 
#include<algorithm>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std; 

/*void PrintIt(int& IntToPoint)
{
cout << IntToPoint << endl;
}

int main(int argc, char** argv) {
	list<int> l;
	list<int> :: iterator it;
    l.push_back(34);
	l.push_front(2);
	//l.assign(3,250);//覆盖掉原来的链表值
	l.push_front(5);
	l.push_front(6);
	l.push_back(-1);
	l.sort();
	for_each(l.begin(),l.end(),PrintIt);
	return 0;
}*/
main()
{
	int a[100],b[100],c[100]={0},i,j;
	//a数组放随机数
	//b数组放是否被统计的标志，1未统计，0已统计
	//c数组放对应a数组中随机数出现的次数
	for(i=0;i<100;i++)
	{
		a[i]=rand()%21;//产生0~20的随机数
		b[i]=1;//未统计
		printf("%5d",a[i]); //打印a数组的值
		if((i+1)%10==0)     //一行打印10个数
			printf("\n");
	}
	printf("\n");
	for(i=0;i<100;i++)
	{
		if(b[i])  //若a[i]未被统计
		{
			c[i]++;  //次数加1
			for(j=i+1;j<100;j++)//从下一个开始向后查找
				if(a[j]==a[i]) //若相等
				{
					c[i]++;   //则次数增1
					b[j]=0;   //改为已统计
				}
		}
	}
	for(i=0,j=1;i<100;i++)
	{
		if(c[i])  //若某随机数出现了，则打印其值和出现次数
			printf("%3d:%5d 出现 %3d次\n",j++,a[i],c[i]);
	}
}