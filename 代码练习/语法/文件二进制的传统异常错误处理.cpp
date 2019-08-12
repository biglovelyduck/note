#include <iostream>
#include <cstdio>
using namespace std ;

int filecopy01(const char *filename2, const char *filename1 )
{
	FILE *fp1= NULL,  *fp2 = NULL;

	fp1 = fopen(filename1, "rb");
	if (fp1 == NULL)
	{
		return 1;//�ļ�1��ʧ�� 
	}

	fp2 = fopen(filename2, "wb");
	if (fp1 == NULL)
	{
		return 2;//�ļ�2��ʧ�� 
	}

	char buf[256];
	int  readlen, writelen;
	int count=1;
	while ( (readlen = fread(buf, 1, 256, fp1)) > 0 ) //����������ݣ������0 
	{
		cout<<"count:"<<count<<"    "<<readlen<<endl;
		writelen = fwrite(buf, 1, readlen, fp2);
		if (readlen != readlen)
		{
			return 3;//����ʱ��ʧ�� 
		}
	}

	fclose(fp1);
	fclose(fp2);
	return 0;
}

int main()
{
	int ret;
	ret = filecopy01("h:/�ļ�Test/c2.txt","h:/�ļ�Test/c1.txt");//ret���ش��� 
	if (ret !=0 )
	{
		switch(ret)
		{
		case 1:
			printf("��Դ�ļ�ʱ����!\n");
			break;
		case 2:
			printf("��Ŀ���ļ�ʱ����!\n");
			break;
		case 3:
			printf("�����ļ�ʱ����!\n");
			break;
		default:
			printf("����δ֪����!\n");
			break;
		}
	}
	return 0;
}

