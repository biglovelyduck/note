freopen("./in.txt","r",stdin); //�����ض����������ݽ���in.txt�ļ��ж�ȡ 
freopen("./out.txt","w",stdout); //����ض���������ݽ�������out.txt�ļ���

//C++�﷨��

#include<iostream>

#include<fstream>

using namespace std;

void main()

{

	ifstream fin("in.txt");

	ofstream fout("out.txt");

	int a,b;

	while(fin>>a>>b)

	fout<<a+b<<endl;

	fin.close();

	fout.close();

}

//C�﷨��

#include <stdio.h>

void main()

{

	FILE *fin,*fout;

	int a,b;

	fin=fopen("in.txt","r");

	fout=fopen("out.txt","w");

	while(fscanf(fin,"%d %d",&a, &b) != EOF)

	fprintf(fout,"%d\n",a+b);

	fclose(fin);

	fclose(fout);

}
