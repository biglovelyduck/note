/*题意：给你一个置换P,问是否存在一个置换M，使M^2=P

思路：资料参考 《置换群快速幂运算研究与探讨》 https://wenku.baidu.com/view/0bff6b1c6bd97f192279e9fb.html

结论一： 一个长度为 l 的循环 T，l 是 k 的倍数，则 T^k 是 k 个循环的乘积，每个循环分别是循环 T 中下标 i mod k=0,1,2… 的元素按顺序的连接。 

结论二：一个长度为 l 的循环 T，gcd(l,k)=1，则 T^k 是一个循环，与循环 T 不一定相同。

结论三：一个长度为 l 的循环 T，T^k 是 gcd(l,k)个循环的乘积，每个循环分别是循环 T 中下标 i mod gcd(l,k)=0,1,2… 的元素的连接

 

考虑某个置换的平方。对于其中长度为奇数的轮换，平方以后这个轮换仍然为一个轮换只是元素顺序换了。
一个长度为偶数的轮换，平方以后就变为两个大小相等的轮换了。因此，对于给定的置换，
当中所有长度为奇数的轮换，可以直接当做是它原先平方产生的。而长度为偶数的轮换，必须一一配对，
当做原先拆出来的。满足这个条件，就是平方。*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int main(){
	int t;
	int num[26];
	bool visit[26];
	string str;
	cin>>t;
	while(t--){
		cin>>str;
		for(int i=0;i<str.length();i++){
			num[i]=str[i]-'A';
		}
		int cnt[27];
		memset(visit,false,sizeof(visit));
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<26;i++){
			if(!visit[i]){
				visit[i]=true;
				int tmp=num[i];
				int len=1;
				while(tmp!=i){
					visit[tmp]=true;
					tmp=num[tmp];
					len++;
				}
				cnt[len]++;
			}
		}
		int flag=1;
		for(int i=2;i<=26;i+=2){
			if(cnt[i]%2){
				//奇数
				flag=0;
				break; 
			}
		}
		if(flag) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
