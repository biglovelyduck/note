//�ַ�����ȫ����
#include <bits/stdc++.h>

class Permutation {
public:
    vector<string> getPermutation(string A) {
        vector<string> res;
        if(A.size() == 0)
            return res;
        permutation(A, res, 0);
        sort(res.begin(), res.end(), greater<string>());//����
        return res;
    }
 
    void permutation(string A, vector<string>& res, int cur){
        int len = A.size();
        if(cur == len -1){//�����һ���ַ����Ͳ�����
            res.push_back(A);
            return;
        }
        for(int i = cur; i < len; ++i){
            swap(A[i], A[cur]);//����Ԫ��
            permutation(A, res, cur+1);//�ݹ����
            swap(A[i], A[cur]);//������
        }
    }
};
