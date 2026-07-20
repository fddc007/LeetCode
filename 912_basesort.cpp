#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    
    vector<int> sortArray(vector<int>& nums) 
    {
        int len = nums.size();
        if(len<=1)
        {
            return nums;
        }
        int min = nums[0];
        int max = nums[0];
        //获取数组里面最小值和最大值
        for(auto i = nums.begin();i!=nums.end();i++)
        {
            if((*i)<min)
            {
                min = (*i);
            }
            if((*i)>max)
            {
                max =(*i);
            }
        }
        
        if(min<0)
        {
            max = max-min;
            for(auto num = nums.begin();num!=nums.end();num++)
            {
                *num = *num -min;
            }
        }
        vector<vector<int>> base(10);
        //获取个,十,百....位数进行排序
        //先将个位进行排序,然后是十位
        for(int div = 1;(max/div) != 0;div=div*10)
        {
            for(auto num = nums.begin();num!=nums.end();num++)
            {
                int tmp = (*num)/div;
                base[tmp%10].push_back((*num));
            }
            //刷回原数组
            int cur = 0;
            for(auto arr = base.begin();arr!= base.end();arr++)
            {
                if((*arr).size()== 0)
                {
                    continue;
                }
                for(auto number = (*arr).begin();number!= (*arr).end();number++)
                {
                    nums[cur++] = *number;
                }
                (*arr).clear();
            }
        }
        if(min<0)
        {
            for(auto num =nums.begin();num != nums.end();num++)
            {
                (*num) = (*num)+min;
            }
        }
        return nums;
    }
};




int main()
{
    vector<int> nums = {50000,49999,3666,5,1,1,2,0,0,-1,-2,-99,-500000};
    Solution a;
    a.sortArray(nums);
    for(auto i = nums.begin();i!= nums.end();i++)
    {
        cout<<(*i)<<" ";
    }
    cout<<"\n";
    return 0;

}