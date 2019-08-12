//PTA 估值一亿的AI核心代码 
#include <bits/stdc++.h>
using namespace std;
int n;
bool ok(string a,int i,int p){
	if(i-1>=0)
		return !isalpha(a[i+p])&&!isdigit(a[i+p])&&!isalpha(a[i-1])&&!isdigit(a[i-1]);
	else return !isalpha(a[i+p])&&!isdigit(a[i+p]);
}
int main(){
	cin>>n;
	getchar();
	while(n--){
		string a;
		getline(cin,a);
		cout<<a<<endl;
		int m=a.length();
		//移除后面多余的空格 
		for(int i=m-1;i>=0;i--){
			if(i==m-1){
				while(a[i]==' '){
					a.erase(i,1);
					i--;
				}
			}
		}
		m=a.length();
		for(int i=0;i<m;i++){
			if(i==0){	//删除开头的空格 
				while(a[i]==' ')
					a.erase(i,1);
			}
			while(a[i]==' '){
				if(!isalpha(a[i+1])&&!isdigit(a[i+1])&&i+1<m)
					a.erase(i,1);
				else
					break;
			}
			
			if(a[i]=='?') a[i]='!';
			if(a[i]!='I'&&a[i]>='A'&&a[i]<='Z')
				a[i]=a[i]-'A'+'a';
			m=a.length();	//更新一下字符串的长度 
		}
		
		for(int i=0;i<m;i++){
			if(a.substr(i,2)=="me"&&ok(a,i,2)&&i+1<m) a.replace(i,2,"you");
			else if(a[i]=='I'&&ok(a,i,1)) a.replace(i,1,"you");
			else if(a.substr(i,7)=="can you"&&ok(a,i,7)&&i+6<m) a.replace(i,7,"I can");
			else if(a.substr(i,9)=="could you"&&ok(a,i,9)&&i+8<m)
				a.replace(i,9,"I could");
			m=a.length();
		}
		cout<<"AI: "<<a<<endl;
	}
	return 0;
}

/*常用string的函数:
【】,push_back(),+=,==,size()/length()
substr(index,num)获取index开始，长度为num的子串
erase(index,num)删除index开始num个元素
insert(index,a) index处插入a
replace(index,num,a)从index开始num个元素替换为a字符串
3,4操作后string长度会改变！注意更新循环边界
*/
