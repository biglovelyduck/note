#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

int main(){
    //���ڴ�ŷָ����ַ��� 
    vector<string> res;
    //���ָ���ַ��������кܶ�ո� 
    string word="   Hello, I want   to learn C++!   ";
    //�ݴ��word�ж�ȡ���ַ��� 
    string result;
    //���ַ�������input�� 
    stringstream input(word);
    //���������result�У�������res�� 
    while(input>>result)
        res.push_back(result);
    //���res 
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
    return 0;
}

