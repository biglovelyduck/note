#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
#include <cstring>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std; 

int main(int argc, char** argv) {
	/*
	//set���� set����������Ԫ������ͬ�ļ�ֵ��
	int i;
    int arr[5] = {0,1,2,3,4};
    set<int> iset(arr,arr+5);

    iset.insert(5);
    cout<<"size:"<<iset.size()<<endl;//�������������ʼ�����С 
    cout<<"3 count = "<<iset.count(3)<<endl;//����ĳ��ֵԪ�صĸ��� 
    iset.erase(1);//ɾ�������е�Ԫ��1

    set<int>::iterator ite1 = iset.begin();
    set<int>::iterator ite2 = iset.end();
    for(;ite1!=ite2;ite1++)
    {
        cout<<*ite1;
    }
    cout<<endl;

    ite1 = iset.find(3);//����һ��ָ�򱻲��ҵ�Ԫ�صĵ�����
    if(ite1!=iset.end())//ĩβ�ĺ�һ��λ�õĵ����� 
        cout<<"3 found"<<endl;

    ite1 = iset.find(1);
    if(ite1!=iset.end())
        cout<<"1 not found"<<endl;
    */
    
    /*
    //1.set�ⷨ
	set<int> s1,s2;
	int n;
	while(1) {//cin.get()�����س��� 
		cin>>n;
		s1.insert(n);
		if(n==-1) break;
	} 
		while(1) {//cin.get()�����س��� 
		cin>>n;
		s2.insert(n);
		if(n==-1) break;
	}
	set<int>::iterator it1=s1.begin();
	set<int>::iterator it2=s2.begin();
	s1.erase(-1);
	s2.erase(-1);
	set<int> s;
	set_union(s1.begin(),s1.end(),s2.begin(),s2.end(),inserter(s, s.begin()));
	set<int>::iterator it=s.begin();
	for(;it!=s.end();it++){
		if(it==--s.end())
		cout<<*it;
		else
	    cout<<*it<<" ";
	}
	*/
	
	//2.����ⷨ
	int a[10],b[10];
	int i=0;
	while(1){
		scanf("%d",&a[i++]);
		if(a[i-1]==-1) break;
	} 
	int len_a=i;
	i=0;
	while(1){
		scanf("%d",&b[i++]);
		if(a[i-1]==-1) break;
	}
	int len_b=i;
	sort(a,a+i-1);
	sort(b,b+i-1);
//	for(i=0;i<len_a-1;i++)
//	    cout<<a[i]<<" ";
    int c[len_a+len_b];
    for(i=0;i<max(len_a,len_b);i++){
    	
	}
	return 0;
}
