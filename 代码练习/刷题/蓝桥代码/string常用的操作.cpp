#include <iostream>
#include <string>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

//字符串初始化
void strInit(){
	cout<<"字符串初始化："<<endl;
	
	string s1="abcdefg";//初始化方式1 
	string s2("sbcdrfg");//初始化方式2
	string s3=s2;//通过拷贝初始化方式3
	string s4(7,'s');//初始化7个s的字符串
	
	cout<<"s1="<<s1<<endl; 
	cout<<"s2="<<s2<<endl; 
	cout<<"s3="<<s3<<endl; 
	cout<<"s4="<<s4<<endl; 
} 

//字符串遍历
void strErgo(){
	cout<<"字符串遍历："<<endl;
	
	string s1="abcdefg";
	
	//数组方式遍历
	cout<<"1.通过数组方式遍历："<<endl;
	for(int i=0;i<s1.length();i++){
		cout<<s1[i]<<" ";
	} 
	cout<<endl;
	
    //通过迭代器遍历
	cout<<"2.通过迭代器遍历：" <<endl;
	for(string::iterator it=s1.begin();it!=s1.end();it++){ 
		cout<<*it<<" "; 
	}
	cout<<endl;
	
	//通过at()方式遍历
	cout<<"3.通过at()方式遍历："<<endl;
	for(int i=0;i<s1.length();i++){
		cout<<s1.at(i)<<" ";
	}
	cout<<endl;
}

//字符指针和字符串的转换
void strConvert(){
	cout<<"字符指针和字符串的转换"<<endl;
	string s1="abcdefg";
	
	cout<<"string转换为char*"<<endl;
	cout<<s1.c_str()<<endl; //const char *str = s1.c_str();   c_str()返回一个指向常量数组的指针
	
	cout<<"char*获取string的内容："<<endl;
	char buf[64]={0};
	s1.copy(buf,7);
	cout<<buf<<endl;
} 

//字符串连接
void strAdd(){
	cout<<"字符串连接："<<endl;
	
	cout<<"方式1："<<endl;
	string s1="123";
	string s2="456";
	s1+=s2;
	cout<<"s1="<<s1<<endl;
	
	cout<<"方式2："<<endl;
	string s3="123";
	string s4="456";
	s3.append(s4);
	cout<<"s3="<<s3<<endl;
} 

int main(int argc, char** argv) {
	//初始化  
    strInit();  
    cout << endl;  
    //遍历  
    strErgo();  
    cout << endl;  
    //字符指针类型和字符串转换  
    strConvert();  
    cout << endl;  
    //字符串连接  
    strAdd();  
    cout << endl;  
    system("pause");  
    return 0;  
}
