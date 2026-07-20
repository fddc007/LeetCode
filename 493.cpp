#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    int tmp[50001] = {0};
    int merge(int l,int r,int m,vector<int>& nums)
    {
        int left = l;
        int right = m+1;
        int i = l;
        int account = 0;
        while(left<=m&&right<=r)
        {
            if((long)nums[left]>(long)nums[right]*2)
            {
                account += m-left+1;
                right++;
            }
            else
            {
                left++;
            }
        }
        left = l;
        right = m+1;
        while (left <= m && right <= r)
        {
            tmp[i++] = nums[left] <= nums[right]?nums[left++]:nums[right++];
        }
        while(left<=m)
        {
            tmp[i++] = nums[left++];
        }
        while(right<=r)
        {
            tmp[i++] = nums[right++];
        }
        for(int i =l;i<=r;i++)
        {
            nums[i] = tmp[i];
        }
        return account;
    }
    int solve(int l,int r,vector<int>& nums)
    {
        if(l == r)
        {
            return 0;
        }
        int m = l + ((r-l)>>1);
        return solve(l,m,nums)+solve(m+1,r,nums)+merge(l,r,m,nums);
    }
    int reversePairs(vector<int>& nums) {
        if(nums.size()<=1)
        {
            return 0;
        }
        return solve(0,nums.size()-1,nums);
    }
};


int main()
{
    Solution a;
    vector<int> nums = {2,4,3,5,1};
    cout<<a.reversePairs(nums);
}