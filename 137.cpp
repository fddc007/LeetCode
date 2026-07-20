#include<iostream>
#include<vector>


using namespace std;



class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sit[32] = {0};
        //累加每一位的数
        for(auto i = nums.begin();i!= nums.end();i++)
        {
            for(int j = 0;j<32;j++)
            {
                sit[j] += ((*i)>>j)&1;
            }
        }
        //对于每一位取模,只要不为0,则对应的位数置1
        int ret = 0;
        for(int i = 0;i<32;i++)
        {
            if((sit[i]%3) != 0)
            {
                ret = ret | (1<<i);
            }
        }
        return ret;
    }
};

int main()
{
    vector<int> nums = {30000,500,100,30000,100,30000,100};
    Solution a;
    cout<<a.singleNumber(nums)<<" ";
    cout<<"\n";
}


