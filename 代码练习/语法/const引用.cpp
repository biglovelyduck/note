#include <cstdio>
#include <cstdlib> 
int  main()
{
	const int b1 = 10;
	printf("b1:%d", &b1);
	int b2=10;
	printf("b2:%d", &b2);
	//int &a1 = 19; �������const����ʧ��
	const int &a1 = 10;//���� 
	const int &a2 = b1;//���� 
	const int &a3 = b2;//δ�����ַ 
	const int &a4 = 10;//����
	printf("&a1:%d \n", &a1);
	printf("&a2:%d \n", &a2);
	printf("&a3:%d \n", &a3);
	printf("&a4:%d \n", &a4);
	system("pause");
	return 0; 
}

