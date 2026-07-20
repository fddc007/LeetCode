#include<iostream>
#include<vector>

using namespace std;




class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size()<=2)
        {
            return nums[0];
        }
        int slow = nums[0];
        int fast = nums[nums[0]];
        while(slow!=fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow = 0;
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }   
};


int main()
{
    vector<int> nums = {3,3,3,3,3,3,3,3,3,3};
    Solution s;
    cout<<s.findDuplicate(nums)<<"\n";
    return 0;
}