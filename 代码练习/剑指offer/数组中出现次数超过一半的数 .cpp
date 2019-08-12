//�����г��ִ�������һ����� 
#include <vector>
#include <algorithm>
using namespace std;
//1.����˼�� 
/*
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        // ��Ϊ�õ���sort��ʱ�临�Ӷ�O(NlogN)����������
        if(numbers.empty()) return 0;
         
        sort(numbers.begin(),numbers.end()); // ����ȡ�����м��Ǹ���
        int middle = numbers[numbers.size()/2];
         
        int count=0; // ���ִ���
        for(int i=0;i<numbers.size();++i)
        {
            if(numbers[i]==middle) ++count;
        }
         
        return (count>numbers.size()/2) ? middle :  0;
    }
};*/
//2.��������
class Solution{
public:
	int MoreThanHalfNum_Solution(vector<int> numbers){
		if(numbers.empty()) return 0;
		int len=numbers.size();
		int result=numbers[0];
		int times=1;
		for(int i=1;i<len;i++){
			if(times==0){
				result=numbers[i];
				times=1;
			}
			else if(numbers[i]==result) times++;
			else	times--;
		}
		//verify
		times=0;
		for(int i=0;i<len;i++){
			if(numbers[i]==result) times++;
		}
		return times*2>len?result:0;
	}
}; 
