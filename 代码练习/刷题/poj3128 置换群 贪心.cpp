/*���⣺����һ���û�P,���Ƿ����һ���û�M��ʹM^2=P

˼·�����ϲο� ���û�Ⱥ�����������о���̽�֡� https://wenku.baidu.com/view/0bff6b1c6bd97f192279e9fb.html

����һ�� һ������Ϊ l ��ѭ�� T��l �� k �ı������� T^k �� k ��ѭ���ĳ˻���ÿ��ѭ���ֱ���ѭ�� T ���±� i mod k=0,1,2�� ��Ԫ�ذ�˳������ӡ� 

���۶���һ������Ϊ l ��ѭ�� T��gcd(l,k)=1���� T^k ��һ��ѭ������ѭ�� T ��һ����ͬ��

��������һ������Ϊ l ��ѭ�� T��T^k �� gcd(l,k)��ѭ���ĳ˻���ÿ��ѭ���ֱ���ѭ�� T ���±� i mod gcd(l,k)=0,1,2�� ��Ԫ�ص�����

 

����ĳ���û���ƽ�����������г���Ϊ�������ֻ���ƽ���Ժ�����ֻ���ȻΪһ���ֻ�ֻ��Ԫ��˳���ˡ�
һ������Ϊż�����ֻ���ƽ���Ժ�ͱ�Ϊ������С��ȵ��ֻ��ˡ���ˣ����ڸ������û���
�������г���Ϊ�������ֻ�������ֱ�ӵ�������ԭ��ƽ�������ġ�������Ϊż�����ֻ�������һһ��ԣ�
����ԭ�Ȳ�����ġ������������������ƽ����*/

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
				//����
				flag=0;
				break; 
			}
		}
		if(flag) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
