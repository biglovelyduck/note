//poj2718-Smallest Difference(枚举全排列)
/*一，题意：
　　给出最多10个数字，将它们划分为两个整数，求差值最小的值（除非只有一位数，否则不允许出现先导0）
　　很显然如果总共有n个数，必然有一个整数长n/2,另一个长n-n/2。
二，思路：
　　利用next_permutation()函数枚举数字的每个排列
三，步骤：
　　1，输入字符数组，并转换为整形数组;
　　2，利用next_permutation()函数，枚举数组的每一个排列，根据条件求出划分的两个整数的差值最小值。*/

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
	char s[1000];//存储输入的一行 
	int t;
	cin>>t;
	getchar();//接收回车符
	while(t--){
		int a[11],num=0,ans=0x3f3f3f3f;
		gets(s);
		for(int i=0;i<strlen(s);i++){
			if(s[i]>='0'&&s[i]<='9')
				a[num++]=s[i]-'0';
		}
		sort(a,a+num);
		do{
			int num1=0,num2=0;
			if(!a[0]||!a[num/2]&&num>2)
				continue;
			for(int i=0;i<num/2;i++){
				num1=num1*10+a[i];
			}
			for(int i=num/2;i<num;i++){
				num2=num2*10+a[i];
			}
			ans=min(ans,abs(num1-num2));
		}while(next_permutation(a,a+num));
		cout<<ans<<endl;
	} 
	return 0;
}
