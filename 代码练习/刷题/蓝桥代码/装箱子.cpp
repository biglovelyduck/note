#include <iostream>
#include <vector> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*using namespace std;
int main(int argc, char** argv) {
	vector<int> v;
	int n,num,index=0;
	int a[100],b[100],c[100],d[100]={0};
	cin>>n;
	/*while(n--){
		scanf("%d",&num);
		v.push_back(num);
	}*/
	//cout<<v.at(1);
	/*while(n--){
		scanf("%d",&num);
		a[index++]=num;
		d[index++]=num;
	}
	b[1]=1;
	for(int i=0;i<v.size();i++){
		for(int j=i+1;j<v.size();j++){
			if(a[i]+a[j]<=100&&c[j]==0) {
				a[i]+=a[j];
				b[j]=i+1;
				c[j]=1;
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<d[i]<<":"<<b[i]<<endl;
	}
	return 0;
}*/

#define n 1000
int main(void)
{ int a[n],b[n],i=0,j,x,max=1;
scanf("%d",&x);//��Ʒ���� 
for(i=1;i<=x;i++)
scanf("%d",&a[i]);//ÿ����Ʒ������ 
for(j=1;j<=100;j++)
b[j]=100;//��ʾÿ���������洢�� 
for(i=1;i<=x;i++)
for(j=1;j<=100;j++)//ÿ�δӵ�һ�����ӿ�ʼ���� 
{ 
if(b[j]-a[i]>=0)
{  printf("%d:%d\n",a[i],j);
   b[j]=b[j]-a[i];
   if(max<j)
    max=j;
    
    break;
	}
}
printf("�����������ĿΪ%d\n",max);
return 0;
}
