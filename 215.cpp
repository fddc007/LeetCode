#include<iostream>
#include<vector>
#include<random>


using namespace std;


class Solution {
public:
    int first = 0;
    int last = 0;
    int sit = 0;
    Solution():gen_(random_device{}()){};
    int getInt(int min,int max)
    {
        uniform_int_distribution<int> dist(min,max);
        return dist(gen_);
    }

    void quicksort(int l,int r,vector<int>& nums)
    {
        //或许随机位置上的值,作为标杆
        int x = nums[getInt(l,r)];
        //设置值等于x的左右边界left,right
        int left = l;
        int right = r;
        //设置遍历下标
        int i = l;
        //如果nums[i]小于x则进行与left的值交换,left++,i++
        //如果大于则right的值与i的值交换,right--
        //如果等于则i++
        while (i<=right)
        {
            if(nums[i]<x)
            {
                swap(nums[i],nums[left]);
                i++;
                left++;
            }
            else if(nums[i] == x)
            {
                i++;
            }
            else if(nums[i]>x)
            {
                swap(nums[i],nums[right]);
                right--;
            }
        }
        first = left;
        last = right;
    }
    void solve(int l,int r,vector<int>& nums)
    {

        quicksort(l,r,nums);        
        int left = first;
        int right = last;
        if(sit<=last && sit >= first)
        {
            return ;
        }
        if(sit<first)
        {
            solve(l,left -1,nums);
        }
        else if(sit > last)
        {
            solve(right+1,r,nums);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        first = 0;
        last = nums.size()-1;
        sit = nums.size()-k;
        solve(first,last,nums);
        return nums[first];
    }
private:
    mt19937 gen_;
};



int main()
{
        // 将控制台代码页修改为 UTF-8
    system("chcp 65001 > nul");
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    Solution a;
    cout<<"第"<<k<<"大的元素为:"<<a.findKthLargest(nums,k)<<"\n";
}