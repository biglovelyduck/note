/*�ڶ���ϰ��*/
//2-36,����Bitmap������㷨�����ټ��㲻����10^8����������
#include <bitset>
#include <iostream> 
#include <vector>
//Eratosthenesɸ��
void Eratosthenes(int n,char* file){
	bitset B(n);
	B.set(0);B.set(1);//0��1����������
	for(int i=2;i<n;i++){
		if(!B.test(i)){//�����ģ�����һ�����϶�������i�� 
			for(int j=__min(i, 46340) * __min(i, 46340); j < n; j += i) {
				B.set(j);
			}
		}
	}
	B.dump(file); 
} 
