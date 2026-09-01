#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

/*
1. 用path来记录每一种情况,共用
2. 用len来记录path的实际长度
3. 用count表示每一种数的实际加入个数
4. 当count>0时,在len位置插入元素
5. next_site表示同种元素的末尾(方便找到下一个元素的起始位置)
6. 当next_site>= nums.size()时则将path添加到ret中

*/



class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(),nums.end());
        vector<int> path;
        path.resize(nums.size());
        f(ret,path,nums,0,0);
        return ret;
    }

    void f(vector<vector<int>>& ret,vector<int>& path,vector<int>& nums,int i,int len)
    {
        if(i>=nums.size())
        {
            ret.emplace_back(path.begin(),path.begin()+len);
        }
        else
        {
            int next_site = i;
            while(next_site < nums.size()-1 && nums[next_site] == nums[next_site+1])
            {
                next_site++;
            }
            int number = next_site-i+1;
            for(int count = 0;count<=number;count++)
            {
                if(count >0)
                {
                    path[len] = nums[i];
                    len++;
                }
                f(ret,path,nums,next_site+1,len);
            }
        }
    }
};



int main()
{
    vector<int> nums = {};
    Solution s;
    s.subsetsWithDup(nums);
}