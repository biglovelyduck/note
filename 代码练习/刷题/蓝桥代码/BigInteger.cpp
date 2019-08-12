#include <iostream>
#include <vector>
#include <string>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

struct BigInteger{
	static const int BASE=100000000;//ÿ8λΪһ����Ԫ���д�����һ����λ����num%BASE,��һ����λ����num/=BASE,num%BASE 
	static const int WIDTH=8;
	vector<int> v;
	
	BigInteger operator=(const string& s){//���ñ��ⲻ��Ҫ��ֵ�������ƣ����Լ���ֻ��һ����������һ��Ĭ�ϲ����Ǹ����ʵ�����������ⲿ����Ҫ���������� 
	int x,start,end,i,blocks;
	blocks=(s.length()-1)/WIDTH+1;//31λ���ֳɣ�31-1��/8+1=4�飻33λ�ֳ���飻32λ�ֳ��Ŀ飬ţ�Ƽ���
	for(i=0;i<blocks;i++){
		end=s.length()-i*WIDTH;//ÿһ����Ľ���λ��
		start=max(0,end-WIDTH);//i=0,�������һ�������ʼλ�� 
		sscanf(s.substr(start,end).c_str(),"%d",&x);// sscanf����ֵ �ɹ��򷵻ز�����Ŀ��ʧ���򷵻�-1����0��ʾʧ��;c_str()�ṩ������һ�ַ�����������һ���ͻ�����ɶ����ɸĵ�ָ���ַ������ָ�롣
        v.push_back(x);		
	}
	return *this;//����ʵ������ 
	}
	
	BigInteger operator + (const BigInteger &b){//���ؼӺ������������c 
	    BigInteger c;//�����һ��vector v ������ֵ c ��s[i]Խ��λ��Խ�� 
		int i,g,x;
		for(i=0,g=0;;i++){
			if(g==0&&i>=v.size()&&i>=b.v.size()){//�޽�λ������Integerʵ�����ѱ������
			    break; 
			}
			x=g;
			if(i<v.size()) x+=v[i];//x��һ����λ���� 
			if(i<b.v.size()) x+=b.v[i];
			c.v.push_back(x%BASE);
			g=x/BASE;
		}	
		return c;
	} 
};

   istream& operator >> (istream &in,BigInteger &b){//��ʱ���� ,������������������������ؾͿ��Է�����in�� 
   	    string x;
   	    in>>x;
   	    b=x;//���صĵȺ������
		return in; 
   }
   
   ostream& operator << (ostream &out,const BigInteger &b){//constֻ���������޸� 
   	   int i;
   	   char buf[20];//�洢Ҫ�����ÿһλ������ 
   	   out<<b.v.back();//���λ�����λ��Ԥ������
	   for(i=b.v.size()-2;i>=0;i--){
	   	   sprintf(buf,"08d",b.v[i]);//����8λ��0
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
    
