//poj2718-Smallest Difference(ö��ȫ����)
/*һ�����⣺
�����������10�����֣������ǻ���Ϊ�������������ֵ��С��ֵ������ֻ��һλ����������������ȵ�0��
��������Ȼ����ܹ���n��������Ȼ��һ��������n/2,��һ����n-n/2��
����˼·��
��������next_permutation()����ö�����ֵ�ÿ������
�������裺
����1�������ַ����飬��ת��Ϊ��������;
����2������next_permutation()������ö�������ÿһ�����У���������������ֵ����������Ĳ�ֵ��Сֵ��*/

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
	char s[1000];//�洢�����һ�� 
	int t;
	cin>>t;
	getchar();//���ջس���
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
