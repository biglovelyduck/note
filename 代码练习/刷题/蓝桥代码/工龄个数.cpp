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
	cout<<"结束了"<<endl;
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
	//a:保存工人年龄的结合
	//b;保存是否已经被统计过,1表示已经统计过，0表示未统计过 
	//c:保存对应于a相应位置年龄的个数
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
			cout<<"工龄："<<a[i]<<"有"<<c[i]<<"人"<<endl; 
		}
	}
	return 0;
}*/

/*main()
{
	int a[100],b[100],c[100]={0},i,j;
	//a数组放随机数
	//b数组放是否被统计的标志，1未统计，0已统计
	//c数组放对应a数组中随机数出现的次数
	for(i=0;i<100;i++)
	{
		a[i]=rand()%21;//产生0~20的随机数
		b[i]=1;//未统计
		printf("%5d",a[i]); //打印a数组的值
		if((i+1)%10==0)     //一行打印10个数
			printf("\n");
	}
	printf("\n");
	for(i=0;i<100;i++)
	{
		if(b[i])  //若a[i]未被统计
		{
			c[i]++;  //次数加1
			for(j=i+1;j<100;j++)//从下一个开始向后查找
				if(a[j]==a[i]) //若相等
				{
					c[i]++;   //则次数增1
					b[j]=0;   //改为已统计
				}
		}
	}
	for(i=0,j=1;i<100;i++)
	{
		if(c[i])  //若某随机数出现了，则打印其值和出现次数
			printf("%3d:%5d 出现 %3d次\n",j++,a[i],c[i]);
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
