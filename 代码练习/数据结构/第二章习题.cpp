/*第二章习题*/
//2-36,利用Bitmap类设计算法，快速计算不大于10^8的所有素数
#include <bitset>
#include <iostream> 
#include <vector>
//Eratosthenes筛法
void Eratosthenes(int n,char* file){
	bitset B(n);
	B.set(0);B.set(1);//0和1都不是素数
	for(int i=2;i<n;i++){
		if(!B.test(i)){//反复的，从下一个可认定的素数i起 
			for(int j=__min(i, 46340) * __min(i, 46340); j < n; j += i) {
				B.set(j);
			}
		}
	}
	B.dump(file); 
} 
