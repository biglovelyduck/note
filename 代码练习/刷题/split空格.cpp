#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

int main(){
    //用于存放分割后的字符串 
    vector<string> res;
    //待分割的字符串，含有很多空格 
    string word="   Hello, I want   to learn C++!   ";
    //暂存从word中读取的字符串 
    string result;
    //将字符串读到input中 
    stringstream input(word);
    //依次输出到result中，并存入res中 
    while(input>>result)
        res.push_back(result);
    //输出res 
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
    return 0;
}

