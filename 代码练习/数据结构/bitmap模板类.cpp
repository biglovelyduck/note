/*位图类*/
class Bitmap{
private:
	char *M,int N;//位图存放的空间M[],容量为N*sizeof(char)*8
protected:
	void init(int n){
		M=new char[N=(n+7)/8)];
		memset(M,0,N);
	} 
public:
	Bitmap(int n=8){//按指定（或默认）规模创建比特图 
		init(n);
	}
	Bitmap(char* file,int n=8){//按指定（或默认）规模，从指定文件中读取比特图 
		init(n);
		FILE* fp=fopen(file,"r");
		fread(M,sizeof(char),N,fp);
		fclose(fp);
	}
	~Bitmap(){
		delete []M;
		M=NULL;
	} 
	
	void set(int k){//插入 
		expand(k);
		M[k>>3]|=(0x80 >> (k & 0x07)); 
	}
	void clear(int k){//删除 
		expand(k);
		M[k >> 3] &= ~(0x80 >> (k & 0x07));
	}
	bool test(int k){//测试 
		expand(k);
		return M[k >> 3] & (0x80 >> (k & 0x07));
	} 
	
	//将位图整体导出至指定的文件，以便对伺候的新位图批量初始化 
	void dump(char *file){
		FILE *fp=fopen(file,"w");
		fwrite(M,sizeof(char),N,fp);
		fclose(fp);
	} 
	//将前n位转换为字符串 
	char *bits2string(int n){
			expand(n-1);//此时可能被访问的最高位为bitmap[n-1]
			char *s=new char[n+1];
			s[n]="\0";
			for(int i=0;i<n;i++)
				s[i]=test(i)?'1':'0';
			return s;//返回字符串位置 
	}
	
	//若被访问的Bitmap[k]出界，则扩容 
	void expand(int k){
		if(k<8*N) return;
		int oldN=N;
		char *oldM=M;
		init(2*k);
		memcpy_s(M,N,oldM,oldN);
		delete []oldM;
	} 
}; 

//实现简易版的bitmap

#include<iostream>
#include<vector>
#pragma once
using namespace std;
class BitMap
{
public:
	//位图的构造
	BitMap(size_t N = 1024) //
	{
		_bm.resize((N/32)+1);  //注意此处的运算符优先级
	}
	//按照位图的方式进行数值的置位
	void SetMap(size_t v)
	{
		//通过除得到此数在哪一个下标中存储中
		size_t index = v>>5;
		//通过模得到此数的具体位置
		size_t num = v%32;
		//将此数存在的位置置为1
		_bm[index] |= (1<<num);
 
	}
	//进行数值的复位
	void RetsetMap(size_t v)
	{
		size_t index = v>>5;
		size_t num = v%32;
 
		_bm[index] &= ~(1<<num);
	}
	//给定一个数，测试这个数是否在
	bool TestMap(size_t v)
	{
		size_t index = v>>5;
		size_t num = v%32;
 
		return _bm[index] & (1<<num);
	}
protected:
	vector<size_t> _bm;
};

