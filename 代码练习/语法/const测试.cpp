#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{//ͨ�������εı�������Ҫ��ʼ�� 
const int a=100;//��һ���ڶ�����˼һ�� ����һ����������
int const b=100;

const int *c;//������ c��һ��ָ����������ָ��(��ָ����ڴ����ݲ��ܱ��޸ģ����Ǳ�������޸�)
int * const d=NULL;//���ĸ� d ��ָ�루ָ��������ܱ��޸ģ���������ָ���ڴ�ռ���Ա��޸ģ�
const int * const e =NULL;//����� eһ��ָ�����εĳ�ָ�루ָ�������ָ����ڴ�ռ䣬�����ܱ��޸ģ�

return 0;
}

int func1(const ); 
//�ô��� int setTeacher_err( const Teacher *p)
//Const�޸��βε�ʱ���������ββ����޸�ָ��������ڴ�ռ�


