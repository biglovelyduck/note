#include <iostream>
#include <vector>
#include <string>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

struct BigInteger{
	static const int BASE=100000000;//每8位为一个单元进行处理，第一个八位数据num%BASE,下一个八位数据num/=BASE,num%BASE 
	static const int WIDTH=8;
	vector<int> v;
	
	BigInteger operator=(const string& s){//引用避免不必要的值发生复制，可以减少只用一个参数，另一个默认参数是该类的实例，若放类外部，则要用两个参数 
	int x,start,end,i,blocks;
	blocks=(s.length()-1)/WIDTH+1;//31位，分成（31-1）/8+1=4块；33位分成五块；32位分成四块，牛逼技巧
	for(i=0;i<blocks;i++){
		end=s.length()-i*WIDTH;//每一个块的结束位置
		start=max(0,end-WIDTH);//i=0,返回最后一个块的起始位置 
		sscanf(s.substr(start,end).c_str(),"%d",&x);// sscanf返回值 成功则返回参数数目，失败则返回-1返回0表示失败;c_str()提供了这样一种方法，它返回一个客户程序可读不可改的指向字符数组的指针。
        v.push_back(x);		
	}
	return *this;//返回实例对象 
	}
	
	BigInteger operator + (const BigInteger &b){//重载加号运算符，返回c 
	    BigInteger c;//会产生一个vector v ，返回值 c ；s[i]越大位数越高 
		int i,g,x;
		for(i=0,g=0;;i++){
			if(g==0&&i>=v.size()&&i>=b.v.size()){//无进位，两个Integer实例均已遍历完成
			    break; 
			}
			x=g;
			if(i<v.size()) x+=v[i];//x是一个八位的数 
			if(i<b.v.size()) x+=b.v[i];
			c.v.push_back(x%BASE);
			g=x/BASE;
		}	
		return c;
	} 
};

   istream& operator >> (istream &in,BigInteger &b){//暂时不懂 ,本来不可以输入大整数，重载就可以放入流in中 
   	    string x;
   	    in>>x;
   	    b=x;//重载的等号运算符
		return in; 
   }
   
   ostream& operator << (ostream &out,const BigInteger &b){//const只读不可以修改 
   	   int i;
   	   char buf[20];//存储要输出的每一位大整数 
   	   out<<b.v.back();//最高位不足八位的预防处理
	   for(i=b.v.size()-2;i>=0;i--){
	   	   sprintf(buf,"08d",b.v[i]);//不足8位补0
		   cout<<buf; 
	   } 
	   return out;
   } 
   
   int main(){
   	   BigInteger a,b;
   	   cin>>a>>b;
   	   cout<<a+b<<endl;
   	   return 0;
   }
    
