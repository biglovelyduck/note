#include <iostream>
#include <cstdio>
#include <stack> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

const int MAXN=1000+10;

int n,target[MAXN];

int main(int argc, char** argv) {
	while(scanf("%d",&n)==1){
		stack<int> s;
		int A=1,B=1;//A:入栈的元素1,2,3,4,5;B:目标数组的下标 
		for(int i=1;i<=n;i++){
			scanf("%d",&target[i]);
		}
		int ok=1;//假设可以
		while(B<=n){
			if(A==target[B]){//目标数组：12345 
				A++;
				B++;
			}
			else if(!s.empty()&&s.top()==target[B]){//s不为空并且栈顶元素与目标数组中的元素相等 54321
				s.pop();
				B++; 
			}
			else if(A<=n) s.push(A++);//s为空54321
			else {
				ok=0;
				break;
			} 
		}
		printf("%s\n",ok?"Yes":"No");
	}
	return 0;
}
