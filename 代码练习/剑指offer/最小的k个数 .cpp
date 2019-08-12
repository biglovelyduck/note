//��С��k���� 
//1.ȫ����ķ���
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

//2.Partiton˼�� ʱ�临�Ӷ�O(n)   *ͨ��VS2013��ţ�ͳ�ʱ�������ƣ���ӭ�Ҵ�*
/* 
class Solution {
public:
    int Partition(vector<int>& input, int begin, int end)
    {
        int low=begin;
        int high=end;
         
        int pivot=input[low];	//��ѡ����Ǹ���־λ 
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
        return low;		//���ر�־λ��λ�ã���ʱС�Ķ��ڱ�־λ����ߣ���Ķ��ڱ�־λ���ұ� 
    }
     
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
         
        int len=input.size();
        if(len==0||k>len) return vector<int>();
        if(len==k) return input;
         
        int start=0;
        int end=len-1;
        int index=Partition(input,start,end);	//�����һ��λ�� 
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

//���ѣ�����������
/* 
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int len=input.size();
        if(len<=0||k>len) return vector<int>();
         
        vector<int> res(input.begin(),input.begin()+k);	//��ʼ�� 
        //����,�����󶥶� 
        make_heap(res.begin(),res.end());
         
        for(int i=k;i<len;i++)
        {
            if(input[i]<res[0])
            {
                //��pop,Ȼ����������ɾ��
                pop_heap(res.begin(),res.end());
                res.pop_back();
                //���������м��룬��push
                res.push_back(input[i]);
                push_heap(res.begin(),res.end());	//�������ж� 
            }
        }
        //ʹ���С�������
        sort_heap(res.begin(),res.end());
         
        return res;        
    }
};*/

//�������multiset���ϣ����÷º����ı�����˳��


class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int len=input.size();
        if(len<=0||k>len) return vector<int>();
         
        //�º����е�greater<T>ģ�壬�Ӵ�С����
        multiset<int, greater<int> > leastNums;
        vector<int>::iterator vec_it=input.begin();
        for(;vec_it!=input.end();vec_it++)
        {
            //��ǰk��Ԫ�ز��뼯��
            if(leastNums.size()<k)
                leastNums.insert(*vec_it);
            else
            {
                //��һ��Ԫ�������ֵ
                multiset<int, greater<int> >::iterator greatest_it=leastNums.begin();
                //�������Ԫ��<��һ��Ԫ�أ�ɾ����һ�������뵱ǰԪ��
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
