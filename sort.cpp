#include<vector>
#include<iostream>
using namespace std;
class SolutionA{
public:
    int tmp[500001] = {0};
    void merge(int l,int r,int min,vector<int>& nums)
    {
        int i=l;
        int left = l;
        int right = min+1;
        while(i<=r&&left<=min&&right<=r)
        {
            tmp[i++] = nums[left]<=nums[right]?nums[left++]:nums[right++];
        }
        while(left<=min)
        {
            tmp[i++] = nums[left++];
        }
        while(right<=r)
        {
            tmp[i++] = nums[right++];
        }
        //刷新nums
        for(int i =l;i<=r;i++)
        {
            nums[i] = tmp[i];
        }
    }
    void Mysort(int l,int r,vector<int>& nums)
    {
        if(l==r)
        {
            return ;
        }
        int min = l + ((r-l)>>1);
        Mysort(l,min,nums);
        Mysort(min+1,r,nums);
        merge(l,r,min,nums);
    }
    vector<int> sortArray(vector<int>& nums) {
        Mysort(0,nums.size()-1,nums);
        return nums;
    }
};




class Solution {
public:
    int tmp[500001] = {0};
    void merge(int l,int r,int min,vector<int>& nums)
    {
        int i=l;
        int left = l;
        int right = min+1;
        while(i<=r&&left<=min&&right<=r)
        {
            tmp[i++] = nums[left]<=nums[right]?nums[left++]:nums[right++];
        }
        while(left<=min)
        {
            tmp[i++] = nums[left++];
        }
        while(right<=r)
        {
            tmp[i++] = nums[right++];
        }
        //刷新nums
        for(int i =l;i<=r;i++)
        {
            nums[i] = tmp[i];
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int l,r,m;
        int len = nums.size();
        for(int step = 1;step<nums.size();step<<=1)
        {
            l = 0;
            while(l<len)
            {
                r = l + (step<<1)-1;
                r = r < len?r:len-1;
                m = l+ step-1;
                m = m < len?m:len-1;
                merge(l,r,m,nums);
                l = l + (step<<1);
            }   

        }
        return nums;
    }
};








int main()
{
    // 将控制台代码页修改为 UTF-8
    system("chcp 65001 > nul");
    vector<int> nums = {-4,0,7,4,9,-5,-1,0,-7,-1};
    cout<<"nums排序前：";
    for(int i=0;i<nums.size();i++)
    {
        cout<<nums[i]<<" ";
    }

    Solution a;
    a.sortArray(nums);
    cout<<"nums排序后:";
    for(int i=0;i<nums.size();i++)
    {
        cout<<nums[i]<<" ";
    }
    return 0;
}