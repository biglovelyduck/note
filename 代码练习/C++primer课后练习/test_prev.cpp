 #include <iostream>
 #include <iterator>
 #include <vector>
  
 int main() 
 {
     std::vector<int> v{ 3, 1, 4 };
  
     auto it = v.end();
     it--;
     auto pv = std::prev(it,1);//=pre(it):Ĭ���ƶ�һλ 
  
     std::cout << *pv << '\n';
 }
