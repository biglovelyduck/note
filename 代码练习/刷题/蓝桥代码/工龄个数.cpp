#include <iostream>
#include <list> 
#include<algorithm>
#include<vector>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std; 
/*int main(int argc, char** argv) {
	list<int> l;
	int a[100]={0};
	int i=0,n;
	list<int>::iterator it;
	do{
		cin>>n;
		l.push_back(n);
	}while(l.back()!=-1);
	cout<<"������"<<endl;
	l.sort();
	
	cout<<endl;
	i=0;
	l.pop_front();
	for(it=l.begin();it!=l.end();it++){
		if(*it==*++it) {
			a[i]+=1;
			it--;
		}
		else i++;
	}
	l.unique();
	i=0;
	for(it=l.begin();it!=l.end();it++){
		cout<<*it<<":"<<a[i++]<<endl;
	}
	return 0;
}

/*int main(){
	int b[100],c[100]={0};
	//a:���湤������Ľ��
	//b;�����Ƿ��Ѿ���ͳ�ƹ�,1��ʾ�Ѿ�ͳ�ƹ���0��ʾδͳ�ƹ� 
	//c:�����Ӧ��a��Ӧλ������ĸ���
	/*int i=0;
	scanf("%d",&a[i++]);
	int length=i;*/
	/*int a[100]={1,2,3,3,5,5,5,5,7,7,7};
	for(int i=0;i<11;i++){
		if(b[i]==0){
			c[i]++;
			for(int j=i+1;j<11;j++){
				if(a[j]==a[i]){
			    c[i]++;
				b[j]=1;
				}
			}
		}
	} 
	for(int i=0;i<11;i++){
		if(c[i]!=0){
			cout<<"���䣺"<<a[i]<<"��"<<c[i]<<"��"<<endl; 
		}
	}
	return 0;
}*/

/*main()
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
}*/
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
    vector<int> :: iterator first=unique(v.begin(),v.end());
    v.erase(first,v.end());
	for(it=v.begin();it!=v.end();it++)
	    cout<<*it<<":"<<count(v1.begin(),v1.end(),*it)<<endl;
	return 0;
}
