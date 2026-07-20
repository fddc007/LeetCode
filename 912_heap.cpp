#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:


    //将节点向上调整,如果节点大于父节点,则向上调整满足大根堆
    void NodeUp(vector<int>& nums,int i)
    {
        while (nums[i]>nums[(i-1)/2])
        {
            swap(nums[i],nums[(i-1)/2]);
            i = (i-1)/2;
        }
        
    }
    //将节点向下调整,如果节点小于子节点,当向下调整满足大根堆
    void NodeDown(vector<int>& nums,int i,int size)
    {
        int left = 2*i+1;
        //向下调整首先左右子节点需要存在
        while(left<size)
        {
            int right = left+1;
            int best = right<size && nums[left]<nums[right]?right:left;
            // if(nums[i]<nums[best])
            // {
            //     swap(nums[i],nums[best]);
            //     i = best;
            // }
            // else
            // {
            //     break;
            // }

            best = nums[i]<nums[best]?best:i;
            if(best == i)
            {
                break;
            }
            swap(nums[i],nums[best]);
            i = best;
            left = 2*i+1;
        }
    }

    void creatTopHeap(vector<int>& nums)
    {
        for(int size = 1;size<=nums.size();size++)
        {
            NodeUp(nums,size-1);
        }
    }
    void creatBaseHeap(vector<int>& nums)
    {
        for(int size = nums.size();size>0;size--)
        {
            NodeDown(nums,size-1,nums.size());
        }
    }

    void heapSort(vector<int>& nums)
    {
        creatBaseHeap(nums);
        int size = nums.size();
        while(size>1)
        {
            swap(nums[size-1],nums[0]);
            size--;
            NodeDown(nums,0,size);
        }
    }

    vector<int> sortArray(vector<int>& nums) 
    {
        if(nums.size()<=1)
        {
            return nums;
        }
        heapSort(nums);
        return nums;
    }
};



int main()
{
    vector<int> nums = {5,1,1,2,0,0};
    Solution a;
    for(auto i = nums.begin();i!=nums.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<"\n";
    a.sortArray(nums);
        for(auto i = nums.begin();i!=nums.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<"\n";


    return 0;
}