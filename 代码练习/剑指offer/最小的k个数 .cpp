//最小的k个数 
//1.全排序的方法
/*
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(input.empty()||k>input.size()) return res;
         
        sort(input.begin(),input.end());
         
        for(int i=0;i<k;i++)
            res.push_back(input[i]);
         
        return res;   
    }
}; */

//2.Partiton思想 时间复杂度O(n)   *通过VS2013，牛客超时，很纳闷，欢迎找错*
/* 
class Solution {
public:
    int Partition(vector<int>& input, int begin, int end)
    {
        int low=begin;
        int high=end;
         
        int pivot=input[low];	//我选择的那个标志位 
        while(low<high)
        {
            while(low<high&&pivot<=input[high])
                high--;
            input[low]=input[high];
            while(low<high&&pivot>=input[low])
                low++;
            input[high]=input[low];
        }
        input[low]=pivot;
        return low;		//返回标志位的位置，此时小的都在标志位的左边，大的都在标志位的右边 
    }
     
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
         
        int len=input.size();
        if(len==0||k>len) return vector<int>();
        if(len==k) return input;
         
        int start=0;
        int end=len-1;
        int index=Partition(input,start,end);	//随便找一个位置 
        while(index!=(k-1))
        {
            if(index>k-1)
            {
                end=index-1;
                index=Partition(input,start,end);
            }
            else
            {
                start=index+1;
                index=Partition(input,start,end);
            }
        }
         
        vector<int> res(input.begin(), input.begin() + k);
         
        return res;
    }
 
};*/

//最大堆，处理海量数据
/* 
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int len=input.size();
        if(len<=0||k>len) return vector<int>();
         
        vector<int> res(input.begin(),input.begin()+k);	//初始堆 
        //建堆,建立大顶堆 
        make_heap(res.begin(),res.end());
         
        for(int i=k;i<len;i++)
        {
            if(input[i]<res[0])
            {
                //先pop,然后在容器中删除
                pop_heap(res.begin(),res.end());
                res.pop_back();
                //先在容器中加入，再push
                res.push_back(input[i]);
                push_heap(res.begin(),res.end());	//重新排列堆 
            }
        }
        //使其从小到大输出
        sort_heap(res.begin(),res.end());
         
        return res;        
    }
};*/

//红黑树：multiset集合，利用仿函数改变排序顺序


class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int len=input.size();
        if(len<=0||k>len) return vector<int>();
         
        //仿函数中的greater<T>模板，从大到小排序
        multiset<int, greater<int> > leastNums;
        vector<int>::iterator vec_it=input.begin();
        for(;vec_it!=input.end();vec_it++)
        {
            //将前k个元素插入集合
            if(leastNums.size()<k)
                leastNums.insert(*vec_it);
            else
            {
                //第一个元素是最大值
                multiset<int, greater<int> >::iterator greatest_it=leastNums.begin();
                //如果后续元素<第一个元素，删除第一个，加入当前元素
                if(*vec_it<*(leastNums.begin()))
                {
                    leastNums.erase(greatest_it);
                    leastNums.insert(*vec_it);
                }
            }
        }
         
        return vector<int>(leastNums.begin(),leastNums.end());
    }
}; 
