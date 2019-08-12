//数据流中的中位数
/*链接：https://www.nowcoder.com/questionTerminal/9be0172896bd43948f8a32fb954e1be1
来源：牛客网

如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后
位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。*/ 
#include <iostream>
#include <vector>
//#include <functional>
#include <algorithm>
#include <stdexcept> 

using namespace std; 

/*make_heap()生成堆，他有两个参数，也可以有三个参数，前两个参数是指向开始元素的迭代器和指向结束元素的下一个元素的迭代器。第三个参数是可选的，可以用伪函数less()和greater()来生成大顶堆和小顶堆，其中type为元素类型。如果只传入前两个参数，默认是生成大顶堆。 
push_heap()是在堆的基础上进行数据的插入操作，参数与make_heap()相同，需要注意的是，只有make_heap（）和push_heap（）同为大顶堆或小顶堆，才能插入。 
pop_heap()是在堆的基础上，弹出堆顶元素。这里需要注意的是，pop_heap()并没有删除元素，而是将堆顶元素和数组最后一个元素进行了替换，如果要删除这个元素，还需要对数组进行pop_back()操作。
*/
class Solution {
public:
	//要保证最大堆中的所有数据都小于最小堆 
	//总数目为偶数时插入最小堆总数目就是奇数，奇数插入最大堆总数目就是偶数 
    void Insert(int num)
    {
    	//偶数个数字
        if((min.size()+max.size())&1==0){
        	if(max.size()>0&&num<max[0]){
        		max.push_back(num);
				push_heap(max.begin(),max.end(),less<int>()); 	//重构造最大堆 
				
				num=max[0];		//num始终保存着最大堆的最大数 
				
				pop_heap(max.begin(),max.end(),less<int>());
				max.pop_back();
			}
			min.push_back(num); 
			push_heap(min.begin(),min.end(),greater<int>());
		}
		//奇数个数字 
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

//得到中位数 
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
	vector<int> max;	//max和min存放数据的总个数 
	vector<int> min;
};
