//2018 �������⼯������  ��������λ���� 
#include <algorithm> 
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set> 
#include <map>
#include <iostream>
#include <cstring>
#include <sstream>
#include <iterator>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))
#define closeio std::ios::sync_with_stdio(false)
//int main(){
//	int N;
//	cin>>N;	//N��ѧУ
//	int a[N];	//����ÿ��ѧУ������
//	int num; 
//	for(int i=0;i<N;i++){
//		cin>>num;
//		a[i]=num*10;
//	} 
//	vector<vector<int> > v;
//	v.resize(N);
//	bool flag=false;
//	bool flag2=false;
//	int cs=0;
//	while(true){
//		int sum=0;
//		for(int i=0;i<N;i++){
//			if(a[i]==0){
//				sum++;
//			}
//		}
//		for(int i=0;i<N;i++){
//			if(a[i]!=0){
//				if(N-sum==1){	//ֻʣ��һ���� 
//				//cout<<"ֻʣ��һ����"<<endl;
//					int last=v[i].back();
//					v[i].push_back(last+2);
//					last=v[i].back();
//					a[i]--;
//					while(a[i]--){
//						last=v[i].back();
//						v[i].push_back(last+2);
//					}
//					flag=true;
//				}
//				else{
//					if(v[i].size()>0){
//						if(cs){
//							int last=v[i].back();
//							v[i].push_back(last+N-sum+1);
//							cs--;
//						}
//						else{
//							int last=v[i].back();
//							v[i].push_back(last+N-sum);
//						}
//					}
//					else{
//						 v[i].push_back(1+i);		//ÿ���ӵĵ�һ��Ԫ��
//					}
//					a[i]--;
//					if(a[i]==0){
//						cs=N-(sum+1);
//						break;
//					}
//				}
//			}
//		}
//		if(flag) break;
//	}
//	for(int i=0;i<N;i++){
//		cout<<"#"<<i+1<<endl;
//		for(int j=0;j<v[i].size();j++){
//			if((j+1)%10==0) cout<<v[i][j]<<endl;
//			else cout<<v[i][j]<<" ";
//		}
//	}
//	return 0;
//}

//�����������
#include <iostream>
#include <vector>
/*��������ÿ��ѧУ��ѧ���ų�һ�ţ�Ϊÿһ����λ����ѧ����
num[i]��һ��ѧУ�Ķ�������id_school[i]�ǵ�i����λ���������ĸ�ѧУ��ѧ����
ÿ���������δ�ÿ��ѧУ��ǰ�߹���������ѧУ����ѧ��û��������λ���ǾͰ��ţ����ŷ���Ϊ��
�������λǰһ�����Ǳ�Уѧ������ôץһ����Уѧ��������������ϣ������������ӱ���Уѧ�����ˣ�
�������λǰһ���Ǳ�Уѧ�����Ǵ�λ�ÿ��ţ�ץһ����Уѧ������������ӵĺ�һ���ϣ������������ӵĺ�һ�ѱ���Уѧ�����ˣ�
����flag��־��������е�ѧУѧ������������λ��˵��������ϣ����˳���
ע�⣺���ʱ��ע����ĩ�����ո�*/
using namespace std;
int main(){
	int n,sum=0,cnt=1,num[110]={0},id_school[100001]={0};
	cin>>n;
	vector<vector<int> > v(n+1);
	for(int i=1;i<=n;i++)
		cin>>num[i];	//ÿ��ѧУ�Ķ�����
	while(1){
		bool flag=true;
		for(int i=1;i<v.size();i++){	//i��ʾ�ĸ�ѧУ 
			if(v[i].size()<num[i]*10){
				if(id_school[cnt-1]!=i){	//ǰһ����λ���Ĳ��Ǳ�Уѧ�� 
					id_school[cnt]=i;
					v[i].push_back(cnt);
					cnt++;
				}
				else{
					//ǰһ����λ�����Ǳ�Уѧ��
					id_school[cnt+1]=i;
					v[i].push_back(cnt+1);
					cnt+=2; 
				}
				flag=false;
			}
		}
		if(flag) break;
	} 
	for(int i = 1; i < v.size(); i++) {
        cout << "#" << i << endl;
        for(int j = 0; j < v[i].size(); j++) {
            if(j != 0 && j % 10 != 0) cout << " ";
            if(j != 0 && j % 10 == 0) cout << endl;
            cout << v[i][j];
        }
        cout << endl;
    }
} 
