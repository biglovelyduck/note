
/*7 ͳ�ƹ��䣨25 �֣�
������˾N��Ա���Ĺ��䣬Ҫ�󰴹����������ÿ��������ж���Ա����

�����ʽ:

�������ȸ���������N����10
?5
?? ������Ա����������������N����������ÿ��Ա���Ĺ��䣬��Χ��[0, 50]��

�����ʽ:

������ĵ���˳�����ÿ�������Ա����������ʽΪ��������:��������ÿ��ռһ�С��������Ϊ0��������

��������:

8
10 2 0 5 7 2 5 2
�������:

0:1
2:3
5:2
7:1
10:1*/
#include <iostream> 
#include<algorithm>
#include<vector>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std; 

bool comp(int a,int b){
	    return (a<b);
}
int main(){
	vector<int> v,v1;
	vector<int> :: iterator it;
	int n,num;
	cin>>n;
	while(n--){
		scanf("%d",&num);
		v.push_back(num);
	}
    sort(v.begin(),v.end(),comp);
    v1.assign(v.begin(),v.end());
    vector<int> :: iterator first=unique(v.begin(),v.end());//�������ظ���Ԫ�ط���������� 
    v.erase(first,v.end());
	for(it=v.begin();it!=v.end();it++)
	    cout<<*it<<":"<<count(v1.begin(),v1.end(),*it)<<endl;
	return 0;
}
