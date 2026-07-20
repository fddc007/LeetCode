#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int tmp[50001] = {0};
    int account =0;
    void merge(int l,int r,int m,vector<int>& nums)
    {
        int left = l;
        int right = m+1;
        int i = l;
        while(left<=m && right<=r)
        {
            if(nums[left]>nums[right])
            {
                account += m - left + 1;
                tmp[i++] = nums[right++];
            }
            else
            {
                tmp[i++] = nums[left++];
            }
        }
        int x = i-1;
        while(left<=m)
        {
            
            tmp[i++] = nums[left++];
        }
        while(right<=r)
        {
            tmp[i++] = nums[right++];
        }
        for(int i = l;i<=r;i++)
        {
            nums[i] = tmp[i];
        }

    }
    void account_nums(int l,int r, vector<int>& nums)
    {
        if(l==r)
        {
            return;
        }
        int m= l + ((r-l)>>1);
        account_nums(l,m,nums);
        account_nums(m+1,r,nums);
        merge(l,r,m,nums);
    }
    int reversePairs(vector<int>& record) {
        int len = record.size();
        if(len <=1)
        {
            return account;
        }
        account_nums(0,len-1,record);
        return account;
    }
};

int main()
{
    Solution a;
    vector<int> nums = {9, 7, 5, 4, 6};
    int i = a.reversePairs(nums);
    cout<<"i= "<<i<<endl;

}