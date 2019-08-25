//快手-小数点
#include<bits/stdc++.h>
using namespace std;
#define N 1000
 
int main()
{
//    freopen("input.txt", "r", stdin);
    int a, b, t;
    cin >> a >> b;
    cout << a / b;
    a = a % b;	
    if(a == 0) return 0;
    cout << ".";
    map<int, int> m;
    vector<int> vec;
    t = 0;
    while(a != 0) {			//有余数 
        if(m.count(a) != 0) break;
        vec.push_back(a * 10 / b);
        m[a] = t++;
        a = a * 10 % b;
    }
    if(a == 0) {
        for(int i = 0; i < t; i++) cout << vec[i];
    } else {
        int k = m[a];
        for(int i = 0; i < k; i++) cout << vec[i];
        cout << "(";
        for(int i = k; i < t; i++) cout << vec[i];
        cout << ")";
    }
    cout << endl;
    return 0;
} 
