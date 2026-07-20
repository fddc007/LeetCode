#include<iostream>
#include<vector>
#include<random>

using namespace std;


class Solution {
public:
    Solution():gen_(random_device{}()){}
    int first = 0;
    int last = 0;
    int getInt(int min,int max)
    {
        uniform_int_distribution<int> dist(min,max);
        return dist(gen_);
    }

    double getdouble(int min,int max)
    {
        uniform_real_distribution<double> dist(min,max);
        return dist(gen_);
    }
    void swap(int &a,int &b)
    {
        if(a== b)
        {
            return ;
        }
        a ^= b;
        b ^= a;
        a ^= b;
    }
    void quicksort(int l,int r,vector<int>& nums)
    {
        /*
        生成一个随机值x
        遍历数组
        如果当前值小于x则先交换i与left对应的值，left++，向右扩大小于x的边界
        如果当前值大于x则先交换i与right对应的值，right--，此时i不变，向左扩大大于x的边界
        始终保持left与right之间是等于x的值
        */
        int left = l;//记录随机值的左边界
        int right = r;//记录随机值的右边界
        int x_sit = getInt(l,r);
        int x = nums[x_sit];
        int i = l;
        while (i<=r && i<=right)
        {
            if(nums[i]>x)
            {
                swap(nums[i],nums[right]);
                right--;
            }
            else if(nums[i]==x)
            {
                i++;
            }
            else if(nums[i]<x)
            {
                swap(nums[i],nums[left]);
                left++;
                i++;
            }
        }
        first = left;
        last = right;
    }
    void solve(int l,int r,vector<int>& nums)
    {
        if(l >=r)
        {
            return ;
            
        }
        quicksort(l,r,nums);
        int left = first;
        int right = last;
        solve(l,left-1,nums);
        solve(right+1,r,nums);

    
    }
    vector<int> sortArray(vector<int>& nums) {
        first = 0;
        last = nums.size()-1;
        solve(first,last,nums);
        return nums;
    }
    private:
    mt19937 gen_;
};


int main()
{
    vector<int> arr = {5,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,};
    for(auto i = arr.begin();i!=arr.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<"\n";
    Solution a;
    a.sortArray(arr);
    for(auto i = arr.begin();i!=arr.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<"\n";
    return 0;
}