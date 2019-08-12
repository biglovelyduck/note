/*小明参加了学校的趣味运动会，其中的一个项目是：跳格子。
地上画着一些格子，每个格子里写一个字，如下所示：（也可参见下图）

从我做起振
我做起振兴
做起振兴中
起振兴中华

比赛时，先站在左上角的写着“从”字的格子里，可以横向或纵向跳到相邻的格子里，但不能跳到对角的格子或其它位置。一直要跳到“华”字结束。

要求跳过的路线刚好构成“从我做起振兴中华”这句话。
请你帮助小明算一算他一共有多少种可能的跳跃路线呢？*/ 

#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int f(int x,int y); 

int main(int argc, char *argv[]) {
	printf("%d",f(5,4)); 
	return 0;
}
//从某个位置走一共有多少种走法
 
int f(int x,int y){
	if(x==1||y==1) return 1;
	return f(x-1,y)+f(x,y-1);
}
