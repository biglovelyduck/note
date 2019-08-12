freopen("./in.txt","r",stdin); //输入重定向，输入数据将从in.txt文件中读取 
freopen("./out.txt","w",stdout); //输出重定向，输出数据将保存在out.txt文件中

//C++语法：

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

//C语法：

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
