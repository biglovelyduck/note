
//#include <iostream>
//#include <string>
//#include <cstring>
//using namespace std;
//const int maxn=1000;
//int main(){
//	int N;	//���� 
//	cin>>N;
//	getchar();
//	string s;
//	getline(cin,s);
//	int col=s.length()/N+1;
//	char c[N][col];
//	//cout<<"���⳥"<<endl;
//	//memset(c,0,sizeof(0));
//	for(int i=0;i<N;i++){
//		for(int j=0;j<col;j++){
//			c[i][j]='1';
//		}
//	}	
//	//cout<<"���⳥"<<endl;
////	for(int i=0;i<N;i++){
////		for(int j=0;j<N;j++){
////			c[i][j]='1';
////		}
////	}
//	//cout<<"memeset�ɹ�"<<endl;
//	int num=0;
//	for(int j=col-1;j>=0;j--){
//		for(int i=0;i<N;i++){
//			c[i][j]=s[num++];
//		}
//		if(num==s.length()) break;
//	}
//	//cout<<"����ɹ�"<<endl;
//	for(int i=0;i<N;i++){
//		for(int j=0;j<col;j++){
//			if(c[i][j]!='1')
//				cout<<c[i][j];
//		}
//		cout<<endl;
//	}
//	return 0;
//}


//2018������ȫ��ģ�⾺�� �ŷ��Ű�  ������������  ���ˡ��� 
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

