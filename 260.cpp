#include<iostream>
#include<vector>

using namespace std;



class Solution {
public:
    //获取最右边的1状态,就是仅保留第一个出现的1,其他位置0
    int site(int nums)
    {
        return nums&((-nums));
    }
    vector<int> singleNumber(vector<int>& nums) {
        //结果是a^b
        int eor1 = 0;
        for(auto i = nums.begin();i!= nums.end();i++)
        {
            eor1 ^= *i;
        }
        //获取a或者b的第一次出现1的位置,用于切割a和b到两个不同的范围中
        //防止溢出,这个eor1为-2147483648,如果取反就会溢出,而目的是为了获取第一次出现的1,就是他本身
        int tmp =eor1 & (eor1 ==-2147483648?-2147483648:-eor1);
        //接收切割后的值
        int ero2 = 0;
        //切割a和b
        for(auto i = nums.begin();i!=nums.end();i++)
        {
            if((tmp&(*i)))
            {
                ero2 ^= *i;
            }
            
        }
        int a = ero2 ^ eor1;
        int b = a ^ eor1;
        return {a,b};
    }
};



int main()
{
    vector<int> nums = {1,1,0,-2147483648};
    Solution a;
    vector<int>  tmp = a.singleNumber(nums);
    cout<<tmp[0]<<" "<<tmp[1]<<"\n";
}