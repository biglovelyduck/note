//�������е���λ��
/*���ӣ�https://www.nowcoder.com/questionTerminal/9be0172896bd43948f8a32fb954e1be1
��Դ��ţ����

��εõ�һ���������е���λ����������������ж�����������ֵ����ô��λ������������ֵ����֮��
λ���м����ֵ��������������ж���ż������ֵ����ô��λ������������ֵ����֮���м���������ƽ��ֵ��
����ʹ��Insert()������ȡ��������ʹ��GetMedian()������ȡ��ǰ��ȡ���ݵ���λ����*/ 
#include <iostream>
#include <vector>
//#include <functional>
#include <algorithm>
#include <stdexcept> 

using namespace std; 

/*make_heap()���ɶѣ���������������Ҳ����������������ǰ����������ָ��ʼԪ�صĵ�������ָ�����Ԫ�ص���һ��Ԫ�صĵ������������������ǿ�ѡ�ģ�������α����less()��greater()�����ɴ󶥶Ѻ�С���ѣ�����typeΪԪ�����͡����ֻ����ǰ����������Ĭ�������ɴ󶥶ѡ� 
push_heap()���ڶѵĻ����Ͻ������ݵĲ��������������make_heap()��ͬ����Ҫע����ǣ�ֻ��make_heap������push_heap����ͬΪ�󶥶ѻ�С���ѣ����ܲ��롣 
pop_heap()���ڶѵĻ����ϣ������Ѷ�Ԫ�ء�������Ҫע����ǣ�pop_heap()��û��ɾ��Ԫ�أ����ǽ��Ѷ�Ԫ�غ��������һ��Ԫ�ؽ������滻�����Ҫɾ�����Ԫ�أ�����Ҫ���������pop_back()������
*/
class Solution {
public:
	//Ҫ��֤�����е��������ݶ�С����С�� 
	//����ĿΪż��ʱ������С������Ŀ��������������������������Ŀ����ż�� 
    void Insert(int num)
    {
    	//ż��������
        if((min.size()+max.size())&1==0){
        	if(max.size()>0&&num<max[0]){
        		max.push_back(num);
				push_heap(max.begin(),max.end(),less<int>()); 	//�ع������� 
				
				num=max[0];		//numʼ�ձ��������ѵ������ 
				
				pop_heap(max.begin(),max.end(),less<int>());
				max.pop_back();
			}
			min.push_back(num); 
			push_heap(min.begin(),min.end(),greater<int>());
		}
		//���������� 
		else{
			if(min.size()>0&&min[0]<num){
				min.push_back(num);
				push_heap(min.begin(),min.end(),greater<int>());
				
				num=min[0];
				
				pop_heap(min.begin(),min.end(),greater<int>());
				min.pop_back();
			} 
			max.push_back(num);
			push_heap(max.begin(),max.end(),less<int>()) ;
		}
    }

//�õ���λ�� 
    double GetMedian()
    { 
    	int size=min.size()+max.size();
    	if(size==0)
    		//throw std::logic_error("No numbers are available");
    		return 0;
    	double median=0;
    	if((size&1)==1){
    		median=min[0];
		}
		else 
			median=(double)(min[0]+max[0])/2;
		return median;
    }
private:
	vector<int> max;	//max��min������ݵ��ܸ��� 
	vector<int> min;
};
