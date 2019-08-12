#include <stdio.h>
#include <stdlib.h>
#include "seqstack.h"
int main(){
	int i,a[10];
	SeqStack* stack = NULL;
	stack = SeqStack_Create(10);
	//Ñ¹Õ»
	for (i = 0; i < 5; i++){
		a[i] = i + 1;
		SeqStack_Push(stack, &a[i]);
	}
	printf("capacity:%d\n", SeqStack_Capacity(stack));
	printf("size:%d\n", SeqStack_Size(stack));
	printf("top:%d\n", *(int*)SeqStack_Top(stack));

	//³öÕ»
	while (SeqStack_Size(stack) > 0){
		printf("stack->pop:%d\n", *(int*)SeqStack_Pop(stack));
	}
	system("pause");
	return 0;
}