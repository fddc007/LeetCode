#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;


/*
1 .因为有重复元素,引入set去重
2. 利用递归栈,每一层都有自己独立的空间,所以每一个set都是独立的,由栈管理建立和释放
3. 还可以利用位图实现set的功能

*/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        f(ret,nums,0);
        return ret;
    }
    void f(vector<vector<int>>& ret,vector<int>& nums,int i)
    {
        if(i>=nums.size())
        {
            ret.emplace_back(nums.begin(),nums.end());
        }
        else
        {
            unordered_set<int> tmp;
            for(int j = i;j<nums.size();j++)
            {
                if(tmp.find(nums[j]) != tmp.end())
                {
                    continue;
                }
                tmp.insert(nums[j]);
                swap(nums[i],nums[j]);
                f(ret,nums,i+1);
                swap(nums[i],nums[j]);
            }
        }
    }
};

int main()
{
    vector<int> nums = {1,1,2};
    Solution s;
    s.permuteUnique(nums);
    return 0;
}