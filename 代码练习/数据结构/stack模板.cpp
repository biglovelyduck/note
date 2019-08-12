/*stack模板*/
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

//进制转换,将十进制数n转换为base进制
//递归实现 
void convert(Stack<char> &S,_int64 n,int base) {
	static char digit[] //0 < n, 1 < base <= 16
 	= { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };	
	if(0<n){
		convert(S,n/base,base);
		S.push(digit[n%base]);
	} 
} 
//迭代实现 
void convert(Stack<char> &S,_int64 n,int base) {
	static char digit[] //0 < n, 1 < base <= 16
 	= { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };	
	while(0<n){
		S.push(digit[n%base]);
		n/=base;
	} 
} 

//求运算符表达式 
//优先级表（太麻烦） 
#define N_OPTR 9 //运算符总数
typedef enum {ADD, SUB, MUL, DIV, POW, FAC, L_P, R_P, EOE} Operator; //运算符集合
//加、减、乘、除、乘方、阶乘、左括号、右括号、起始符与终止符

const char pri[N_OPTR][N_OPTR] = { //运算符优先等级 [栈顶] [弼前]
/* |-------------- 当前运算符 --------------| */
/* 			+ 	 -    *    /    ^    !    (    )    \0 */
/* -- + */ '>', '>', '<', '<', '<', '<', '<', '>', '>',
/* | - */ '>', '>', '<', '<', '<', '<', '<', '>', '>',
/* 栈 * */ '>', '>', '>', '>', '<', '<', '<', '>', '>',
/* 顶 / */ '>', '>', '>', '>', '<', '<', '<', '>', '>',
/* 运 ^ */ '>', '>', '>', '>', '>', '<', '<', '>', '>',
/* 算 ! */ '>', '>', '>', '>', '>', '>', ' ', '>', '>',
/* 符 ( */ '<', '<', '<', '<', '<', '<', '<', '=', ' ',
/* | ) */ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
/* -- \0 */ '<', '<', '<', '<', '<', '<', '<', ' ', '='
};

//求值算法，对表达式S求值并转换为RPN逆波兰表达式 
float evaluate(char* S, char*& RPN) { //对（已剔除白空格的）表达式S求值，并转换为逆波兰式RPN
	Stack<float> opnd; Stack<char> optr; //运算数栈、运算符栈
	optr.push('\0'); //尾哨兵'\0'也作为头哨兵首先入栈
	while (!optr.empty()) { //在运算符栈非空之前，逐个处理表达式中各字符
		if (isdigit(*S)) { //若当前字符为操作数，则
			readNumber(S, opnd); append(RPN, opnd.top()); //读入操作数，并将其接至RPN末尾
		} 
		else //若当前字符为运算符，则
			switch(orderBetween(optr.top(), *S)) { //视其余栈顶运算符之间的优先级高低分别处理 
				case '<': //栈顶运算符优先级更低时
					optr.push(*S); S++; //计算推迟，当前运算符迕栈
					break;
				case '=': //优先级相等（当前运算符为右括号戒者尾部哨兵'\0'）时
					optr.pop(); S++; //脱括号并接收下一个字符
					break;
				case '>': { //栈顶运算符优先级更高时，可实施相应的计算，并将结果重新入栈
					char op = optr.pop(); append(RPN, op); //栈顶运算符出栈并续接至RPN末尾
					if ('!' == op) { //若属亍一元运算符
						float pOpnd = opnd.pop(); //叧需叏出一个操作数，幵
						opnd.push(calcu(op, pOpnd)); //实斲一元计算，结枅入栈
					} 
					else { //对亍其它（二元）运算符
						float pOpnd2 = opnd.pop(), pOpnd1 = opnd.pop(); //叏出后、前操作数
						opnd.push(calcu(pOpnd1, op, pOpnd2)); //实斲二元计算，结枅入栈
					}
					break;
				}
				default : exit(-1); //逢语法错误，丌做处理直接退出
			}//switch
	}//while
	return opnd.pop(); //弹出幵迒回最后癿计算结枅
} 

//逆波兰表达式RPN 
