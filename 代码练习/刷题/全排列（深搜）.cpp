/*ȫ����*/
bool used[MAX_N];
int perm[MAX_N];
// ����{0,1,2,3,4,...,n-1}��n!������
void permutation1(int pos, int n) {
	if (pos == n) {
	/*
	* �����д��Ҫ��perm���еĲ���
	*/
	return ;
	}
// ���perm�ĵ�pos��λ�ã�����ʹ��0~n-1�е���һ������ѭ��
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
		perm[pos] = i;
	// i�Ѿ���ʹ���ˣ����԰ѱ�־����Ϊtrue
		used[i] = true;
		permutation1(pos + 1, n);
	// ����֮��ѱ�־��λ
		used[i] = false;
		}
	}
	return ;
}
#include <algorithm>
// ��ʹ���ظ���Ԫ��Ҳ���������е�����
// next_permutation�ǰ����ֵ�����������һ�����е�
int perm2[MAX_N];
void permutation2(int n) {
	for (int i = 0; i < n; i++) {
		perm2[i] = i;
	}
	do {
	/*
	* �����д��Ҫ��perm2���еĲ���
	*/
	} while (next_permutation(perm2, perm2 + n));
	// ���е����ж����ɺ�next_permutation�᷵��false
	return ;
}
