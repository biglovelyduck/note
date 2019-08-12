#include <iostream>
#include <cstdio>
using namespace std ;

int filecopy01(const char *filename2, const char *filename1 )
{
	FILE *fp1= NULL,  *fp2 = NULL;

	fp1 = fopen(filename1, "rb");
	if (fp1 == NULL)
	{
		return 1;//文件1打开失败 
	}

	fp2 = fopen(filename2, "wb");
	if (fp1 == NULL)
	{
		return 2;//文件2打开失败 
	}

	char buf[256];
	int  readlen, writelen;
	int count=1;
	while ( (readlen = fread(buf, 1, 256, fp1)) > 0 ) //如果读到数据，则大于0 
	{
		cout<<"count:"<<count<<"    "<<readlen<<endl;
		writelen = fwrite(buf, 1, readlen, fp2);
		if (readlen != readlen)
		{
			return 3;//拷贝时的失败 
		}
	}

	fclose(fp1);
	fclose(fp2);
	return 0;
}

int main()
{
	int ret;
	ret = filecopy01("h:/文件Test/c2.txt","h:/文件Test/c1.txt");//ret返回错误 
	if (ret !=0 )
	{
		switch(ret)
		{
		case 1:
			printf("打开源文件时出错!\n");
			break;
		case 2:
			printf("打开目标文件时出错!\n");
			break;
		case 3:
			printf("拷贝文件时出错!\n");
			break;
		default:
			printf("发生未知错误!\n");
			break;
		}
	}
	return 0;
}

