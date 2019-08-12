#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct bigint
{
	char *num;                //指向长整数数组（序号0中保存着最高位） 
	char minus;               //符号（1表示正数，-1表示负数） 
	int digit;                 //保存该数的位数（实际位数） 
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

void BigIntTrans(pBIGINT num1)    //将字符串转为数字表示 
{
	char *temp;                   //临时数组 
	int i, k, len;
	len = strlen(num1->num);       //字符串长度 
	//分配内存
	if (!(temp = (char *)malloc(sizeof(char)* len)))
	{
		printf("内存分配失败！\n");
		exit(0);
	}
	i = 0;
	num1->minus = 1;                 //保存为正数 
	if (num1->num[0] == '-')          //判断是否为负数 
	{
		num1->minus = -1;
		i++;
	}
	k = 0;                            //数字位数计数器 
	while (num1->num[i] != '\0')       //字符串未结束 
	{
		if (num1->num[i] >= '0' && num1->num[i] <= '9')     //数字为0~9 
		{	//将ASCII码转换为对应数字 
			temp[k] = num1->num[i] - '0';
			k++;
		}
		i++;
	}

	for (i = 0; i < num1->digit; i++)     //清空数组各元素 
		num1->num[i] = 0;
	num1->digit = k;                     //转换后的数据位数 
	for (i = 0, k--; k >= 0; k--, i++)          //将临时数组各位置反置保存到数组num中 
		num1->num[i] = temp[k];
	BigIntTrim(num1);                   //整理输入的大整数 
}

void BigIntTrim(pBIGINT num1)           //整理大整数，去掉前面多余的0 
{
	int i;
	for (i = num1->digit - 1; i >= 0; i--)      //从高位检查是否为0 
	{
		if (num1->num[i] != 0)             //遇到不为0的最高位 
			break;                     //跳出循环 
	}
	if (i < 0)                         //若余数全部为0 
	{
		num1->digit = 1;                     //设置余数位数为1 
		num1->num[0] = 0;
	}
	else
		num1->digit = i + 1;                 //余数位数 
}

void BigIntPrint(pBIGINT result)      //输出大整数 
{
	int j;
	if (result->minus == -1)           //是负数 
		printf("-");                 //输出负数 
	//若大整数为0 
	if (result->digit == 1 && result->num[0] == 0)
		printf("0");
	else                         //不为0 
	{
		//从高位到低位输出 
		for (j = result->digit - 1; j >= 0; j--)
			printf("%d", result->num[j]);
	}
}

int BigIntEqual(pBIGINT num1, pBIGINT num2)         //比较绝对值大小 
{
	int i;
	//num1的位数大于num2 
	if (num1->digit > num2->digit)
		return 1;
	//num1的位数小于num2 
	else if (num1->digit<num2->digit)
		return -1;
	else                                 //两数位数相等 
	{
		i = num1->digit - 1;                  //num1的数据位数 
		while (i >= 0)                       //从高位向地位比 
		{
			//num1对应位大于num2 
			if (num1->num[i]>num2->num[i])
				return 1;
			//num1对应位小于num2
			else if (num1->num[i] < num2->num[i])
				return -1;
			else                            //比较下一位 
				i--;
		}
	}
	return 0;                               //相等 
}


void BigIntAdd(pBIGINT num1, pBIGINT num2, pBIGINT result)
{
	int i;
	i = BigIntEqual(num1, num2);            //比较两数绝对值大小 
	if (i < 0)                              //num1绝对值小于num2 
	{
		pBIGINT temp;
		temp = num1;                      //交换两数 
		num1 = num2;
		num2 = temp;
	}
	if (num1->minus * num2->minus < 0)         //符号不同，则执减法 
	{
		if (i == 0)                              //两数相等 
		{
			//结果长度为一位数，就是数值0 
			result->digit = 1;
			result->num[0] = 0;                 //结果值为0 
			result->minus = 1;                 //结果设为正号 
			return;                            //返回 
		}
		//调用相减函数完成异号相加 
		BigIntSub1(num1, num2, result);
	}
	else
		//调用相加函数完成同号相加 
		BigIntAdd1(num1, num2, result);
}

void BigIntAdd1(pBIGINT num1, pBIGINT num2, pBIGINT result)
{
	int i, carry;
	carry = 0;                              //清除进位 
	result->minus = num1->minus;           //保存符号 
	//将被加数复制到结果数组中 
	for (i = 0; i < num1->digit; i++)
		result->num[i] = num1->num[i];
	//num2中的数小，可能位数也少些 
	for (i = 0; i < num2->digit; i++)
	{
		//将对应位的数和进位数相加 
		result->num[i] = result->num[i] + num2->num[i] + carry;
		carry = result->num[i] / 10;       //计算进位数据 
		result->num[i] = result->num[i] % 10;     //保留一位 
	}
	if (carry)                       //若最后还有进位 
		result->num[i] = result->num[i] + carry;
	BigIntTrim(result);                //整理结果 
}

//减法函数
void BigIntSub(pBIGINT num1, pBIGINT num2, pBIGINT result)
{
	num2->minus = -1 * num2->minus;       //将减数的符号取反 
	BigIntAdd(num1, num2, result);          //调用加法函数 
}

//异号相减函数 
void BigIntSub1(pBIGINT num1, pBIGINT num2, pBIGINT result)
{
	int i, borrow;
	result->minus = num1->minus;         //结果符号 
	borrow = 0;
	//将被减数的内容复制到结果中 
	for (i = 0; i < num1->digit; i++)
		result->num[i] = num1->num[i];
	for (i = 0; i <= num2->digit; i++)
	{
		//num1减去num2，并减去低位的借位 
		result->num[i] = result->num[i] - num2->num[i] - borrow;
		if (result->num[i] < 0)             //若为负数 
		{
			result->num[i] = 10 + result->num[i];    //向高位借位 
			borrow = 1;                   //设置借位数 
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
	result->digit = i + 1;               //保存结果位数 
	BigIntTrim(result);              //整理结果 
}

void BigIntMul(pBIGINT num1, pBIGINT num2, pBIGINT result)
{
	char carry, temp;
	int i, j, pos;
	//结果数组和中间数清0 
	for (i = 0; i < num1->digit + num2->digit; i++)
		result->num[i] = 0;
	//用乘数的每一位乘以被乘数 
	for (i = 0; i < num2->digit; i++)
	{
		carry = 0;                              //清除进位 
		//被乘数的每一位 
		for (j = 0; j < num1->digit; j++)
		{
			//相乘并加上进位 
			temp = num2->num[i] * num1->num[j] + carry;
			//计算进位carry 
			carry = temp / 10;
			//计算当前位的值                       
			temp = temp % 10;
			pos = i + j;
			//计算结果累加到临时数组中 
			result->num[pos] += temp;
			carry = carry + result->num[pos] / 10;           //计算进位 
			result->num[pos] = result->num[pos] % 10;
		}
		if (carry > 0)
		{
			result->num[i + j] = carry;                //加上最高位进位 
			result->digit = i + j + 1;                  //保存结果位数 
		}
		else
			result->digit = i + j;                   //保存结果位数 
	}
	result->minus = num1->minus * num2->minus;        //结果的符号 
}

void BigIntDiv(pBIGINT num1, pBIGINT num2, pBIGINT result, pBIGINT residue)
//除法函数 
{
	BIGINT quo1, residol, quo2;
	int i, j, k, m;               //k保存试商结果，m保存商的位数 
	char t;
	result->minus = num1->minus * num2->minus;        //商的符号 
	//分配余数的内存空间
	residue->num = (char *)malloc(sizeof(char)* num2->digit);
	for (i = 0; i<residue->digit; i++)            //将余数全部清0 
		residue->num[i] = 0;
	m = 0;
	for (i = num1->digit - 1; i >= 0; i--)
	{
		//重新设置余数的位数比除数多一位 
		residue->digit = num2->digit + 1;
		for (j = num2->digit - 1; j>0; j--)               //移余数 
			residue->num[j] = residue->num[j - 1];
		//复制被除数中的一位到余数的最低位中 
		residue->num[0] = num1->num[i];
		BigIntTrim(residue);                  //整理余数 
		k = 0;                                      //试商 
		//比较余数与除数的大小 
		while (BigIntEqual(residue, num2) >= 0)
		{
			BigIntSub1(residue, num2, residue);     //用余数减去除数，差值保存在余数中 
			k++;                       //试商加1 
		}
		result->num[m++] = k;           //保存商 
	}
	result->digit = m;                 //保存商的位数 
	for (i = 0; i < m / 2; i++)              //反转商的值            
	{
		t = result->num[i];
		result->num[i] = result->num[m - 1 - i];
		result->num[m - 1 - i] = t;
	}
	BigIntTrim(result);          //整理商 
	BigIntTrim(residue);            //整理余数 
}

int main()
{
	//参与运算的数，结果，余数 
	BIGINT num1, num2, result, residue;
	int i = 0, len;
	char op;
	printf("输入最大数的位数：");
	scanf("%d", &len);


	if (!(num1.num = (char *)malloc(sizeof(char)* (len + 1))))
	{
		printf("内存分配失败！\n");
		exit(0);
	}
	num1.digit = len + 1;

	if (!(num2.num = (char *)malloc(sizeof(char)* (len + 1))))
	{
		printf("内存分配失败！\n");
		exit(0);
	}
	num2.digit = len + 1;


	if (!(result.num = (char *)malloc(sizeof(char)* (2 * len + 1))))
	{
		printf("内存分配失败！\n");
		exit(0);
	}
	result.digit = 2 * len + 1;


	for (i = 0; i < result.digit; i++)             //清空结果集 
		result.num[i] = 0;
	printf("选择大整数的运算（+,-,*,/）:");


	fflush(stdin);
	scanf("%c", &op);

	switch (op)
	{
	case '+':
		printf("\n输入被加数：");
		scanf("%s", num1.num);
		printf("\n输入加数：");
		scanf("%s", num2.num);
		BigIntTrans(&num1);
		BigIntTrans(&num2);
		BigIntAdd(&num1, &num2, &result);     //加法 
		break;
	case '-':
		printf("\n输入被减数：");
		scanf("%s", num1.num);
		printf("\n输入减数：");
		scanf("%s", num2.num);
		BigIntTrans(&num1);
		BigIntTrans(&num2);
		BigIntSub(&num1, &num2, &result);      //减法 
		break;
	case '*':
		printf("\n输入被乘数：");
		scanf("%s", num1.num);
		printf("\n输入乘数：");
		scanf("%s", num2.num);
		BigIntTrans(&num1);
		BigIntTrans(&num2);
		BigIntMul(&num1, &num2, &result);      //乘法 
		break;
	case '/':
		printf("\n输入被除数：");
		scanf("%s", num1.num);
		printf("\n输入除数：");
		scanf("%s", num2.num);
		BigIntTrans(&num1);
		BigIntTrans(&num2);
		if (num2.digit == 1 && num2.num[0] == 0)        //大整数为0 
			printf("除数不能为0！\n");
		else
			BigIntDiv(&num1, &num2, &result, &residue);    //除法 
		break;
	}
	if (op == '/')
	{
		//为除法且除数不为0 
		if (!(num2.digit == 1 && num2.num[0] == 0))
		{
			printf("商：");
			BigIntPrint(&result);
			printf("\t余数：");
			BigIntPrint(&residue);
		}
	}
	else
	{
		printf("结果：");
		BigIntPrint(&result);
	}
	getch();
	return 0;
}
