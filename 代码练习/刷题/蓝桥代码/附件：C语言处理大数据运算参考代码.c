#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct bigint
{
	char *num;                //ָ���������飨���0�б��������λ�� 
	char minus;               //���ţ�1��ʾ������-1��ʾ������ 
	int digit;                 //���������λ����ʵ��λ���� 
}BIGINT, *pBIGINT;


void BigIntTrim(pBIGINT num1);
void BigIntPrint(pBIGINT result);
int BigIntEqual(pBIGINT num1, pBIGINT num2);
void BigIntAdd(pBIGINT num1, pBIGINT num2, pBIGINT result);
void BigIntSub(pBIGINT num1, pBIGINT num2, pBIGINT result);
void BigIntSub1(pBIGINT num1, pBIGINT num2, pBIGINT result);
void BigIntMul(pBIGINT num1, pBIGINT num2, pBIGINT result);
void BigIntDiv(pBIGINT num1, pBIGINT num2, pBIGINT result, pBIGINT residue);
void BigIntAdd1(pBIGINT num1, pBIGINT num2, pBIGINT result);

void BigIntTrans(pBIGINT num1)    //���ַ���תΪ���ֱ�ʾ 
{
	char *temp;                   //��ʱ���� 
	int i, k, len;
	len = strlen(num1->num);       //�ַ������� 
	//�����ڴ�
	if (!(temp = (char *)malloc(sizeof(char)* len)))
	{
		printf("�ڴ����ʧ�ܣ�\n");
		exit(0);
	}
	i = 0;
	num1->minus = 1;                 //����Ϊ���� 
	if (num1->num[0] == '-')          //�ж��Ƿ�Ϊ���� 
	{
		num1->minus = -1;
		i++;
	}
	k = 0;                            //����λ�������� 
	while (num1->num[i] != '\0')       //�ַ���δ���� 
	{
		if (num1->num[i] >= '0' && num1->num[i] <= '9')     //����Ϊ0~9 
		{	//��ASCII��ת��Ϊ��Ӧ���� 
			temp[k] = num1->num[i] - '0';
			k++;
		}
		i++;
	}

	for (i = 0; i < num1->digit; i++)     //��������Ԫ�� 
		num1->num[i] = 0;
	num1->digit = k;                     //ת���������λ�� 
	for (i = 0, k--; k >= 0; k--, i++)          //����ʱ�����λ�÷��ñ��浽����num�� 
		num1->num[i] = temp[k];
	BigIntTrim(num1);                   //��������Ĵ����� 
}

void BigIntTrim(pBIGINT num1)           //�����������ȥ��ǰ������0 
{
	int i;
	for (i = num1->digit - 1; i >= 0; i--)      //�Ӹ�λ����Ƿ�Ϊ0 
	{
		if (num1->num[i] != 0)             //������Ϊ0�����λ 
			break;                     //����ѭ�� 
	}
	if (i < 0)                         //������ȫ��Ϊ0 
	{
		num1->digit = 1;                     //��������λ��Ϊ1 
		num1->num[0] = 0;
	}
	else
		num1->digit = i + 1;                 //����λ�� 
}

void BigIntPrint(pBIGINT result)      //��������� 
{
	int j;
	if (result->minus == -1)           //�Ǹ��� 
		printf("-");                 //������� 
	//��������Ϊ0 
	if (result->digit == 1 && result->num[0] == 0)
		printf("0");
	else                         //��Ϊ0 
	{
		//�Ӹ�λ����λ��� 
		for (j = result->digit - 1; j >= 0; j--)
			printf("%d", result->num[j]);
	}
}

int BigIntEqual(pBIGINT num1, pBIGINT num2)         //�ȽϾ���ֵ��С 
{
	int i;
	//num1��λ������num2 
	if (num1->digit > num2->digit)
		return 1;
	//num1��λ��С��num2 
	else if (num1->digit<num2->digit)
		return -1;
	else                                 //����λ����� 
	{
		i = num1->digit - 1;                  //num1������λ�� 
		while (i >= 0)                       //�Ӹ�λ���λ�� 
		{
			//num1��Ӧλ����num2 
			if (num1->num[i]>num2->num[i])
				return 1;
			//num1��ӦλС��num2
			else if (num1->num[i] < num2->num[i])
				return -1;
			else                            //�Ƚ���һλ 
				i--;
		}
	}
	return 0;                               //��� 
}


void BigIntAdd(pBIGINT num1, pBIGINT num2, pBIGINT result)
{
	int i;
	i = BigIntEqual(num1, num2);            //�Ƚ���������ֵ��С 
	if (i < 0)                              //num1����ֵС��num2 
	{
		pBIGINT temp;
		temp = num1;                      //�������� 
		num1 = num2;
		num2 = temp;
	}
	if (num1->minus * num2->minus < 0)         //���Ų�ͬ����ִ���� 
	{
		if (i == 0)                              //������� 
		{
			//�������Ϊһλ����������ֵ0 
			result->digit = 1;
			result->num[0] = 0;                 //���ֵΪ0 
			result->minus = 1;                 //�����Ϊ���� 
			return;                            //���� 
		}
		//�������������������� 
		BigIntSub1(num1, num2, result);
	}
	else
		//������Ӻ������ͬ����� 
		BigIntAdd1(num1, num2, result);
}

void BigIntAdd1(pBIGINT num1, pBIGINT num2, pBIGINT result)
{
	int i, carry;
	carry = 0;                              //�����λ 
	result->minus = num1->minus;           //������� 
	//�����������Ƶ���������� 
	for (i = 0; i < num1->digit; i++)
		result->num[i] = num1->num[i];
	//num2�е���С������λ��Ҳ��Щ 
	for (i = 0; i < num2->digit; i++)
	{
		//����Ӧλ�����ͽ�λ����� 
		result->num[i] = result->num[i] + num2->num[i] + carry;
		carry = result->num[i] / 10;       //�����λ���� 
		result->num[i] = result->num[i] % 10;     //����һλ 
	}
	if (carry)                       //������н�λ 
		result->num[i] = result->num[i] + carry;
	BigIntTrim(result);                //������ 
}

//��������
void BigIntSub(pBIGINT num1, pBIGINT num2, pBIGINT result)
{
	num2->minus = -1 * num2->minus;       //�������ķ���ȡ�� 
	BigIntAdd(num1, num2, result);          //���üӷ����� 
}

//���������� 
void BigIntSub1(pBIGINT num1, pBIGINT num2, pBIGINT result)
{
	int i, borrow;
	result->minus = num1->minus;         //������� 
	borrow = 0;
	//�������������ݸ��Ƶ������ 
	for (i = 0; i < num1->digit; i++)
		result->num[i] = num1->num[i];
	for (i = 0; i <= num2->digit; i++)
	{
		//num1��ȥnum2������ȥ��λ�Ľ�λ 
		result->num[i] = result->num[i] - num2->num[i] - borrow;
		if (result->num[i] < 0)             //��Ϊ���� 
		{
			result->num[i] = 10 + result->num[i];    //���λ��λ 
			borrow = 1;                   //���ý�λ�� 
		}
		else
			borrow = 0;
	}
	if (borrow == 1)
		result->num[i] = result->num[i] - borrow;
	i = num1->digit;
	while (i > 0)
	{
		if (result->num[i] == 0)
			i--;
		else
			break;
	}
	result->digit = i + 1;               //������λ�� 
	BigIntTrim(result);              //������ 
}

void BigIntMul(pBIGINT num1, pBIGINT num2, pBIGINT result)
{
	char carry, temp;
	int i, j, pos;
	//���������м�����0 
	for (i = 0; i < num1->digit + num2->digit; i++)
		result->num[i] = 0;
	//�ó�����ÿһλ���Ա����� 
	for (i = 0; i < num2->digit; i++)
	{
		carry = 0;                              //�����λ 
		//��������ÿһλ 
		for (j = 0; j < num1->digit; j++)
		{
			//��˲����Ͻ�λ 
			temp = num2->num[i] * num1->num[j] + carry;
			//�����λcarry 
			carry = temp / 10;
			//���㵱ǰλ��ֵ                       
			temp = temp % 10;
			pos = i + j;
			//�������ۼӵ���ʱ������ 
			result->num[pos] += temp;
			carry = carry + result->num[pos] / 10;           //�����λ 
			result->num[pos] = result->num[pos] % 10;
		}
		if (carry > 0)
		{
			result->num[i + j] = carry;                //�������λ��λ 
			result->digit = i + j + 1;                  //������λ�� 
		}
		else
			result->digit = i + j;                   //������λ�� 
	}
	result->minus = num1->minus * num2->minus;        //����ķ��� 
}

void BigIntDiv(pBIGINT num1, pBIGINT num2, pBIGINT result, pBIGINT residue)
//�������� 
{
	BIGINT quo1, residol, quo2;
	int i, j, k, m;               //k�������̽����m�����̵�λ�� 
	char t;
	result->minus = num1->minus * num2->minus;        //�̵ķ��� 
	//�����������ڴ�ռ�
	residue->num = (char *)malloc(sizeof(char)* num2->digit);
	for (i = 0; i<residue->digit; i++)            //������ȫ����0 
		residue->num[i] = 0;
	m = 0;
	for (i = num1->digit - 1; i >= 0; i--)
	{
		//��������������λ���ȳ�����һλ 
		residue->digit = num2->digit + 1;
		for (j = num2->digit - 1; j>0; j--)               //������ 
			residue->num[j] = residue->num[j - 1];
		//���Ʊ������е�һλ�����������λ�� 
		residue->num[0] = num1->num[i];
		BigIntTrim(residue);                  //�������� 
		k = 0;                                      //���� 
		//�Ƚ�����������Ĵ�С 
		while (BigIntEqual(residue, num2) >= 0)
		{
			BigIntSub1(residue, num2, residue);     //��������ȥ��������ֵ������������ 
			k++;                       //���̼�1 
		}
		result->num[m++] = k;           //������ 
	}
	result->digit = m;                 //�����̵�λ�� 
	for (i = 0; i < m / 2; i++)              //��ת�̵�ֵ            
	{
		t = result->num[i];
		result->num[i] = result->num[m - 1 - i];
		result->num[m - 1 - i] = t;
	}
	BigIntTrim(result);          //������ 
	BigIntTrim(residue);            //�������� 
}

int main()
{
	//���������������������� 
	BIGINT num1, num2, result, residue;
	int i = 0, len;
	char op;
	printf("�����������λ����");
	scanf("%d", &len);


	if (!(num1.num = (char *)malloc(sizeof(char)* (len + 1))))
	{
		printf("�ڴ����ʧ�ܣ�\n");
		exit(0);
	}
	num1.digit = len + 1;

	if (!(num2.num = (char *)malloc(sizeof(char)* (len + 1))))
	{
		printf("�ڴ����ʧ�ܣ�\n");
		exit(0);
	}
	num2.digit = len + 1;


	if (!(result.num = (char *)malloc(sizeof(char)* (2 * len + 1))))
	{
		printf("�ڴ����ʧ�ܣ�\n");
		exit(0);
	}
	result.digit = 2 * len + 1;


	for (i = 0; i < result.digit; i++)             //��ս���� 
		result.num[i] = 0;
	printf("ѡ������������㣨+,-,*,/��:");


	fflush(stdin);
	scanf("%c", &op);

	switch (op)
	{
	case '+':
		printf("\n���뱻������");
		scanf("%s", num1.num);
		printf("\n���������");
		scanf("%s", num2.num);
		BigIntTrans(&num1);
		BigIntTrans(&num2);
		BigIntAdd(&num1, &num2, &result);     //�ӷ� 
		break;
	case '-':
		printf("\n���뱻������");
		scanf("%s", num1.num);
		printf("\n���������");
		scanf("%s", num2.num);
		BigIntTrans(&num1);
		BigIntTrans(&num2);
		BigIntSub(&num1, &num2, &result);      //���� 
		break;
	case '*':
		printf("\n���뱻������");
		scanf("%s", num1.num);
		printf("\n���������");
		scanf("%s", num2.num);
		BigIntTrans(&num1);
		BigIntTrans(&num2);
		BigIntMul(&num1, &num2, &result);      //�˷� 
		break;
	case '/':
		printf("\n���뱻������");
		scanf("%s", num1.num);
		printf("\n���������");
		scanf("%s", num2.num);
		BigIntTrans(&num1);
		BigIntTrans(&num2);
		if (num2.digit == 1 && num2.num[0] == 0)        //������Ϊ0 
			printf("��������Ϊ0��\n");
		else
			BigIntDiv(&num1, &num2, &result, &residue);    //���� 
		break;
	}
	if (op == '/')
	{
		//Ϊ�����ҳ�����Ϊ0 
		if (!(num2.digit == 1 && num2.num[0] == 0))
		{
			printf("�̣�");
			BigIntPrint(&result);
			printf("\t������");
			BigIntPrint(&residue);
		}
	}
	else
	{
		printf("�����");
		BigIntPrint(&result);
	}
	getch();
	return 0;
}
