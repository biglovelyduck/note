#include<list> 
#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

//����Ĵ�ӡ
void print(list<int>& l) {
	list<int>::iterator i,iend;//ÿ���������������Լ��ĵ������������������൱��ָ�� 
	iend=l.end(); //end()��������һ����������ָ�������ĩβ��
	for(i=l.begin();i!=iend;i++)// begin()��������һ����������ָ��list�ĵ�һ��Ԫ�ء������������� 
	cout<<*i<<' ';
}

int main(int argc, char** argv) {
	list<int> l;
	for(int j=1;j<=10;j++){
		l.push_back(j);//�﷨:void push_back( const TYPE &val );�����ڸ�������push_back()��val���ӵ���������
	} 
	list<int> carry; 
	//splice()����  
    /* 
        �﷨:
    void splice( iterator pos, list &lst );
    void splice( iterator pos, list &lst, iterator del );
    void splice( iterator pos, list &lst, iterator start, iterator end );
    splice()������lst���ӵ�pos��λ�á����ָ�����������������lst��del��ָԪ�ص��������pos�ϣ�������start��endָ����Χ��
    */  
    carry.splice(carry.begin(),l,l.begin());//��l�д�begin��ʼ�ĵ�������ʼ���뵽carry��
	cout<<"carry������Ԫ��Ϊ��";
	print(carry); //??????
	cout<<endl;
	
	cout<<"l������Ԫ��Ϊ��";
	print(l);
	cout<<endl;
	
	list<int> x;
	x.push_back(34); 
	x.push_back(33);
	x.push_back(32);
	/* �﷨:
    void merge( list &lst );
    void merge( list &lst, Comp compfunction );
    merge()�������Լ���lst����������һ�𣬲���һ���������е�����������ָ��compfunction����ָ��������Ϊ�Ƚϵ����ݡ�*/
    l.merge(x);//������x���ӵ�����l�ϣ�����l
	cout<<"l������Ԫ��Ϊ��";
	print(l);
	cout<<endl; 
	getchar();//Ŀ�ľ���Ϊ�����˳�֮ǰ�����õ�����������һ���ַ�����ʱ��ϵͳ��I/O��ͣ���ڶ���֮�ϣ������߾Ϳ��Կ�������ˡ�
	return 0;
}
