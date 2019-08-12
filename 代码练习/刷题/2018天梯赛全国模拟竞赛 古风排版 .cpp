
//#include <iostream>
//#include <string>
//#include <cstring>
//using namespace std;
//const int maxn=1000;
//int main(){
//	int N;	//列数 
//	cin>>N;
//	getchar();
//	string s;
//	getline(cin,s);
//	int col=s.length()/N+1;
//	char c[N][col];
//	//cout<<"分赔偿"<<endl;
//	//memset(c,0,sizeof(0));
//	for(int i=0;i<N;i++){
//		for(int j=0;j<col;j++){
//			c[i][j]='1';
//		}
//	}	
//	//cout<<"分赔偿"<<endl;
////	for(int i=0;i<N;i++){
////		for(int j=0;j<N;j++){
////			c[i][j]='1';
////		}
////	}
//	//cout<<"memeset成功"<<endl;
//	int num=0;
//	for(int j=col-1;j>=0;j--){
//		for(int i=0;i<N;i++){
//			c[i][j]=s[num++];
//		}
//		if(num==s.length()) break;
//	}
//	//cout<<"分配成功"<<endl;
//	for(int i=0;i<N;i++){
//		for(int j=0;j<col;j++){
//			if(c[i][j]!='1')
//				cout<<c[i][j];
//		}
//		cout<<endl;
//	}
//	return 0;
//}


//2018天梯赛全国模拟竞赛 古风排版  代码来自柳神  哭了。。 
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    string s;
    cin >> n;
    getchar();
    getline(cin, s);
    int col = (s.length() - 1) / n + 1;
    vector<vector<char> > v(n, vector<char>(col, ' '));
    int index = 0;
    for (int j = col - 1; j >= 0; j--) {
        for (int i = 0; i < n; i++) {
            if (index < s.length())
                v[i][j] = s[index++];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < col; j++)
            cout << v[i][j];
        cout << endl;
    }
    return 0;
}

