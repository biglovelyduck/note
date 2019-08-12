//2018 天梯赛题集分享码  天梯赛座位分配 
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
//	cin>>N;	//N所学校
//	int a[N];	//保存每个学校的人数
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
//				if(N-sum==1){	//只剩下一个队 
//				//cout<<"只剩下一个队"<<endl;
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
//						 v[i].push_back(1+i);		//每个队的第一个元素
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

//来自柳神代码
#include <iostream>
#include <vector>
/*分析：让每个学校的学生排成一排，为每一个座位安排学生。
num[i]是一个学校的队伍数，id_school[i]是第i个座位上做的是哪个学校的学生。
每把椅子依次从每个学校面前走过，如果这个学校还有学生没被安排座位，那就安排，安排方案为：
如果此座位前一个不是本校学生，那么抓一个此校学生做在这把椅子上，并标记这把椅子被此校学生坐了，
如果此座位前一个是本校学生，那此位置空着，抓一个此校学生做在这把椅子的后一把上，并标记这把椅子的后一把被此校学生坐了，
设置flag标志，如果所有的学校学生都被安排座位，说明安排完毕，可退出。
注意：输出时候注意行末不留空格*/
using namespace std;
int main(){
	int n,sum=0,cnt=1,num[110]={0},id_school[100001]={0};
	cin>>n;
	vector<vector<int> > v(n+1);
	for(int i=1;i<=n;i++)
		cin>>num[i];	//每个学校的队伍数
	while(1){
		bool flag=true;
		for(int i=1;i<v.size();i++){	//i表示哪个学校 
			if(v[i].size()<num[i]*10){
				if(id_school[cnt-1]!=i){	//前一个座位坐的不是本校学生 
					id_school[cnt]=i;
					v[i].push_back(cnt);
					cnt++;
				}
				else{
					//前一个座位坐的是本校学生
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
