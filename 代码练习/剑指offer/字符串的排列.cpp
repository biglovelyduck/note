//字符串的全排列
#include <bits/stdc++.h>

class Permutation {
public:
    vector<string> getPermutation(string A) {
        vector<string> res;
        if(A.size() == 0)
            return res;
        permutation(A, res, 0);
        sort(res.begin(), res.end(), greater<string>());//排序
        return res;
    }
 
    void permutation(string A, vector<string>& res, int cur){
        int len = A.size();
        if(cur == len -1){//到最后一个字符，就插入结果
            res.push_back(A);
            return;
        }
        for(int i = cur; i < len; ++i){
            swap(A[i], A[cur]);//交换元素
            permutation(A, res, cur+1);//递归调用
            swap(A[i], A[cur]);//换回来
        }
    }
};
