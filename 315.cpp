#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    struct num
    {
        int numer;
        int site;
        int account;
    };
    vector<num> data;
    num tmp[50001] ={};
    void init_num(vector<int>& nums)
    {
        if(nums.size()<=0)
        {
            return ;
        }
        for(int i=0;i<nums.size();i++)
        {
            data.push_back({nums[i],i,0});
        }
    }
    void merge(int l,int r,int m, vector<num>& data)
    {
        int left = l;
        int right = m+1;
        int i = l;
        while(left<=m&&right<=r)
        {
            
            if(data[left].numer > data[right].numer)
            {
                data[left].account++;
                tmp[i++] = data[right++];
            }
            else
            {
                if(left<m)
                {
                    data[left+1].account += right -m -1;
                }
                tmp[i++] = data[left++];
            }
        }
        while(left<=m)
        {
            tmp[i++] = data[left++];
            if(left <m)
            {
                data[left].account += right -m -1;
            }
        }
        while(right<=r)
        {
            tmp[i++]= data[right++];
        }
        for(int i = l;i<=r;i++)
        {
            data[i] = tmp[i];
        }
    }
    void sort(int l,int r,vector<num>& data)
    {
        if(l == r)
        {
            return ;
        }
        int m = l + ((r-l)>>1);
        sort(l,m,data);
        sort(m+1,r,data);
        merge(l,r,m,data);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int len = nums.size();
        vector<int> ret(len,0);
        if(len <=1)
        {
            return ret;
        }
        init_num(nums);
        sort(0,len-1,data);
        for(int i =0;i<len;i++)
        {
            ret[data[i].site] = data[i].account;
        }
        for(int i =0;i<len;i++)
        {
            cout<<ret[i]<<" ";
        }
        cout<<"\n";
        return ret;
    }
};


int main()
{
    vector<int> nums = {26,78,27,100,33,67,90,23,66,5,38,7,35,23,52,22,83,51,98,69,81,32,78,28,94,13,2,97,3,76,99,51,9,21,84,66,65,36,100,41};
    Solution a;
    a.countSmaller(nums);

    cout<<"\n";
    return 0;
}