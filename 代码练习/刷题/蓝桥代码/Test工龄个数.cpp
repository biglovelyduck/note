#include <iostream>
#include <list> 
#include<algorithm>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std; 

/*void PrintIt(int& IntToPoint)
{
cout << IntToPoint << endl;
}

int main(int argc, char** argv) {
	list<int> l;
	list<int> :: iterator it;
    l.push_back(34);
	l.push_front(2);
	//l.assign(3,250);//���ǵ�ԭ��������ֵ
	l.push_front(5);
	l.push_front(6);
	l.push_back(-1);
	l.sort();
	for_each(l.begin(),l.end(),PrintIt);
	return 0;
}*/
main()
{
	int a[100],b[100],c[100]={0},i,j;
	//a����������
	//b������Ƿ�ͳ�Ƶı�־��1δͳ�ƣ�0��ͳ��
	//c����Ŷ�Ӧa��������������ֵĴ���
	for(i=0;i<100;i++)
	{
		a[i]=rand()%21;//����0~20�������
		b[i]=1;//δͳ��
		printf("%5d",a[i]); //��ӡa�����ֵ
		if((i+1)%10==0)     //һ�д�ӡ10����
			printf("\n");
	}
	printf("\n");
	for(i=0;i<100;i++)
	{
		if(b[i])  //��a[i]δ��ͳ��
		{
			c[i]++;  //������1
			for(j=i+1;j<100;j++)//����һ����ʼ������
				if(a[j]==a[i]) //�����
				{
					c[i]++;   //�������1
					b[j]=0;   //��Ϊ��ͳ��
				}
		}
	}
	for(i=0,j=1;i<100;i++)
	{
		if(c[i])  //��ĳ����������ˣ����ӡ��ֵ�ͳ��ִ���
			printf("%3d:%5d ���� %3d��\n",j++,a[i],c[i]);
	}
}