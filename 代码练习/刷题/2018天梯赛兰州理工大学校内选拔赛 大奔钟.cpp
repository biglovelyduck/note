//2018��������������ѧУ��ѡ���� ���� 
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
/*
int main(){
	string s;
	cin>>s;
	string h_s=s.substr(0,2);
	string m_s=s.substr(3,5);
	//���ַ���ת��������
	//1.c���ת��
	//int h=atoi(h_s.c_str());int m=atoi(m_s.c_str()) ;
	//2.c++���ת��
	int h,m;
	stringstream(h_s)>>h;stringstream(m_s)>>m; 
	//cout<<h<<m;
	if(h>=0&&h<=12) cout<<"Only "<<h_s<<":"<<m_s<<".  Too early to Dang.";
	else{
		int num=h-12;
		if(m==0){
			for(int i=0;i<num;i++){
				cout<<"Dang";
			}
		}
		else{
			for(int i=0;i<=num;i++){
				cout<<"Dang";
			}
		}
	}
	return 0;
}*/

//������Сʱ�������۷��� 
#include <stdio.h>
int main () {
	int hh, mm;
	scanf("%d:%d", &hh, &mm);
	if ( hh >= 0 && hh <= 11 ) 
		printf("Only %02d:%02d.  Too early to Dang.", hh, mm);
	else if ( hh == 12 ) { //12�Ƚ����� 
		if ( mm == 0 )
			printf("Only %02d:%02d.  Too early to Dang.", hh, mm);
		else 
			printf("Dang");
	}
	else {
		for ( int i = 0 ; i < hh % 12; i++ )
			printf("Dang");
		if ( mm != 0 ) //�����������һ�� 
			printf("Dang");
	}
	return 0;
}

