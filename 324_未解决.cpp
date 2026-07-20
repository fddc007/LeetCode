#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;




class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int len = nums.size();
        if(len<=1)
        {
            return ;
        }
        sort(nums.begin(),nums.end());
        int left = 1;
        int right = (len%2) == 0?(len-2):(len-1);
        while(left<=right)
        {  
            swap(nums[left],nums[right]);
            left = left+2;
            right = right-2;
        }
    }
};


int main()
{
    vector<int> nums = {1,5,1,1,6,4};
    for(auto i = nums.begin();i!= nums.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<"\n";
    Solution a;
    a.wiggleSort(nums);
    for(auto i = nums.begin();i!= nums.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<"\n";
    return 0;
}