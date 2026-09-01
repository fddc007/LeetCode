#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;


/*
1. i管理需要处理的位置,j管理在i位置数的下表
2. 刚开始j处理是0-(n-1)个数,然后是1-(n-1)个数一次类推
3. 枚举i位置的情况,再调用递归处理i+1的情况
4. 当i==nums.size()时将nums的状态加入到ret中

*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        find_list(ret,nums,0);
        return ret;
    }
    void find_list(vector<vector<int>>& ret,vector<int>& nums,int i)
    {
        if(i >= nums.size())
        {
            ret.emplace_back(nums.begin(),nums.end());
        }
        else
        {
            for(int j = i;j<nums.size();j++)
            {
                swap(nums[j],nums[i]);
                find_list(ret,nums,i+1);
                swap(nums[j],nums[i]);
            }
        }
    }
};


int main()
{
    vector<int> nums = {1,2,3,4};
    Solution s;
    s.permute(nums);
}