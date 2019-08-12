/*问题描述
　　回文串，是一种特殊的字符串，它从左往右读和从右往左读是一样的。小龙龙认为回文串才是完美的。现在给你一个串，它不一定是回文的，请你计算最少的交换次数使得该串变成一个完美的回文串。
　　交换的定义是：交换两个相邻的字符
　　例如mamad
　　第一次交换 ad : mamda
　　第二次交换 md : madma
　　第三次交换 ma : madam (回文！完美！)
输入格式
　　第一行是一个整数N，表示接下来的字符串的长度(N <= 8000)
　　第二行是一个字符串，长度为N.只包含小写字母
输出格式
　　如果可能，输出最少的交换次数。
　　否则输出Impossible
样例输入
5
mamad
样例输出
3*/ 

#include<iostream>
 using namespace std;
 
 int main()
 {
     int n;
     cin >> n;
     string s;    
     cin >> s;
    
     int end = n - 1;    //字符串最后一个字符 
    int cnt = 0;        //交换次数 
     int oddNum = 0;        //判断是否已经有一个单独的奇个数的字符了
     
     for (int i = 0; i < end; i++)//从第一个字符到倒数第二个字符遍历 
     {
         for (int j = end; j >= i; j--)//从最后一个开始，到第i个字符，寻找与s[i]相同的字符
         {        
             if (i == j)       //如果没找到 
             {
                 if (n % 2 == 0 || oddNum == 1)  //不可能的两种情况 
                {
                     cout << "Impossible";
                     return 0;
                 }
                 oddNum = 1;            //找到一个字符出现的次数为奇数 ,表示已经有一个字符出现的次数为奇数了
				  
                 cnt += n / 2 - i;    //将次字符交换到中间位置的次数 
             } 
             else if (s[i] == s[j])    //如果找到了，将s[j]交换到s[end]位置 
             {
                 for (int k = j; k < end; k++)    //交换相邻两个位置的字符 
                 {
                     swap(s[k], s[k+1]);
                     cnt++;
                 }
                 end--;                //末尾递减 
                 break;                //开始从i+1处重复操作 
             }
         }
     }
     
     cout << cnt;
     
     return 0;
 }
