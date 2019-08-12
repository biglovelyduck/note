/*λͼ��*/
class Bitmap{
private:
	char *M,int N;//λͼ��ŵĿռ�M[],����ΪN*sizeof(char)*8
protected:
	void init(int n){
		M=new char[N=(n+7)/8)];
		memset(M,0,N);
	} 
public:
	Bitmap(int n=8){//��ָ������Ĭ�ϣ���ģ��������ͼ 
		init(n);
	}
	Bitmap(char* file,int n=8){//��ָ������Ĭ�ϣ���ģ����ָ���ļ��ж�ȡ����ͼ 
		init(n);
		FILE* fp=fopen(file,"r");
		fread(M,sizeof(char),N,fp);
		fclose(fp);
	}
	~Bitmap(){
		delete []M;
		M=NULL;
	} 
	
	void set(int k){//���� 
		expand(k);
		M[k>>3]|=(0x80 >> (k & 0x07)); 
	}
	void clear(int k){//ɾ�� 
		expand(k);
		M[k >> 3] &= ~(0x80 >> (k & 0x07));
	}
	bool test(int k){//���� 
		expand(k);
		return M[k >> 3] & (0x80 >> (k & 0x07));
	} 
	
	//��λͼ���嵼����ָ�����ļ����Ա���ź����λͼ������ʼ�� 
	void dump(char *file){
		FILE *fp=fopen(file,"w");
		fwrite(M,sizeof(char),N,fp);
		fclose(fp);
	} 
	//��ǰnλת��Ϊ�ַ��� 
	char *bits2string(int n){
			expand(n-1);//��ʱ���ܱ����ʵ����λΪbitmap[n-1]
			char *s=new char[n+1];
			s[n]="\0";
			for(int i=0;i<n;i++)
				s[i]=test(i)?'1':'0';
			return s;//�����ַ���λ�� 
	}
	
	//�������ʵ�Bitmap[k]���磬������ 
	void expand(int k){
		if(k<8*N) return;
		int oldN=N;
		char *oldM=M;
		init(2*k);
		memcpy_s(M,N,oldM,oldN);
		delete []oldM;
	} 
}; 

//ʵ�ּ��װ��bitmap

#include<iostream>
#include<vector>
#pragma once
using namespace std;
class BitMap
{
public:
	//λͼ�Ĺ���
	BitMap(size_t N = 1024) //
	{
		_bm.resize((N/32)+1);  //ע��˴�����������ȼ�
	}
	//����λͼ�ķ�ʽ������ֵ����λ
	void SetMap(size_t v)
	{
		//ͨ�����õ���������һ���±��д洢��
		size_t index = v>>5;
		//ͨ��ģ�õ������ľ���λ��
		size_t num = v%32;
		//���������ڵ�λ����Ϊ1
		_bm[index] |= (1<<num);
 
	}
	//������ֵ�ĸ�λ
	void RetsetMap(size_t v)
	{
		size_t index = v>>5;
		size_t num = v%32;
 
		_bm[index] &= ~(1<<num);
	}
	//����һ����������������Ƿ���
	bool TestMap(size_t v)
	{
		size_t index = v>>5;
		size_t num = v%32;
 
		return _bm[index] & (1<<num);
	}
protected:
	vector<size_t> _bm;
};

