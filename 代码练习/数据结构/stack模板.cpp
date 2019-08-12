/*stackģ��*/
#include "Vector.h"
template <typename T>
class Stack:public Vector<T>{
public:
	void push(T const &e){
		insert(size(),e);
	}
	T pop(){
		return remove(size()-1); 
	}
	T& top(){
		return (*this)[size()-1];
	}
};

//����ת��,��ʮ������nת��Ϊbase����
//�ݹ�ʵ�� 
void convert(Stack<char> &S,_int64 n,int base) {
	static char digit[] //0 < n, 1 < base <= 16
 	= { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };	
	if(0<n){
		convert(S,n/base,base);
		S.push(digit[n%base]);
	} 
} 
//����ʵ�� 
void convert(Stack<char> &S,_int64 n,int base) {
	static char digit[] //0 < n, 1 < base <= 16
 	= { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };	
	while(0<n){
		S.push(digit[n%base]);
		n/=base;
	} 
} 

//����������ʽ 
//���ȼ���̫�鷳�� 
#define N_OPTR 9 //���������
typedef enum {ADD, SUB, MUL, DIV, POW, FAC, L_P, R_P, EOE} Operator; //���������
//�ӡ������ˡ������˷����׳ˡ������š������š���ʼ������ֹ��

const char pri[N_OPTR][N_OPTR] = { //��������ȵȼ� [ջ��] [��ǰ]
/* |-------------- ��ǰ����� --------------| */
/* 			+ 	 -    *    /    ^    !    (    )    \0 */
/* -- + */ '>', '>', '<', '<', '<', '<', '<', '>', '>',
/* | - */ '>', '>', '<', '<', '<', '<', '<', '>', '>',
/* ջ * */ '>', '>', '>', '>', '<', '<', '<', '>', '>',
/* �� / */ '>', '>', '>', '>', '<', '<', '<', '>', '>',
/* �� ^ */ '>', '>', '>', '>', '>', '<', '<', '>', '>',
/* �� ! */ '>', '>', '>', '>', '>', '>', ' ', '>', '>',
/* �� ( */ '<', '<', '<', '<', '<', '<', '<', '=', ' ',
/* | ) */ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
/* -- \0 */ '<', '<', '<', '<', '<', '<', '<', ' ', '='
};

//��ֵ�㷨���Ա��ʽS��ֵ��ת��ΪRPN�沨�����ʽ 
float evaluate(char* S, char*& RPN) { //�ԣ����޳��׿ո�ģ����ʽS��ֵ����ת��Ϊ�沨��ʽRPN
	Stack<float> opnd; Stack<char> optr; //������ջ�������ջ
	optr.push('\0'); //β�ڱ�'\0'Ҳ��Ϊͷ�ڱ�������ջ
	while (!optr.empty()) { //�������ջ�ǿ�֮ǰ�����������ʽ�и��ַ�
		if (isdigit(*S)) { //����ǰ�ַ�Ϊ����������
			readNumber(S, opnd); append(RPN, opnd.top()); //��������������������RPNĩβ
		} 
		else //����ǰ�ַ�Ϊ���������
			switch(orderBetween(optr.top(), *S)) { //������ջ�������֮������ȼ��ߵͷֱ��� 
				case '<': //ջ����������ȼ�����ʱ
					optr.push(*S); S++; //�����Ƴ٣���ǰ�������ջ
					break;
				case '=': //���ȼ���ȣ���ǰ�����Ϊ�����Ž���β���ڱ�'\0'��ʱ
					optr.pop(); S++; //�����Ų�������һ���ַ�
					break;
				case '>': { //ջ����������ȼ�����ʱ����ʵʩ��Ӧ�ļ��㣬�������������ջ
					char op = optr.pop(); append(RPN, op); //ջ���������ջ��������RPNĩβ
					if ('!' == op) { //����ءһԪ�����
						float pOpnd = opnd.pop(); //���腨��һ������������
						opnd.push(calcu(op, pOpnd)); //ʵ��һԪ���㣬�ᖈ��ջ
					} 
					else { //��ء��������Ԫ�������
						float pOpnd2 = opnd.pop(), pOpnd1 = opnd.pop(); //������ǰ������
						opnd.push(calcu(pOpnd1, op, pOpnd2)); //ʵ�۶�Ԫ���㣬�ᖈ��ջ
					}
					break;
				}
				default : exit(-1); //���﷨����آ������ֱ���˳�
			}//switch
	}//while
	return opnd.pop(); //������ކ�����m����ᖈ
} 

//�沨�����ʽRPN 
