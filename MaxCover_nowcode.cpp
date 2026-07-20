/*
https://www.nowcoder.com/practice/1ae8d0b6bb4e4bcdbf64ec491f63fc37
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<fstream>

using namespace std;
struct cmp
{
    bool operator()(vector<int>&nums1,vector<int>& nums2)
    {
        return nums1[0] == nums2[0]?(nums1[1] < nums2[1]):(nums1[0]<nums2[0]);
    }
};

int Solution(vector<vector<int>>& nums)
{
    int len = nums.size();
    {
        if(len<=1)
        {
            return len;
        }
    }
    int ret = 0;
    sort(nums.begin(),nums.end(),cmp());
    priority_queue<int,vector<int>,greater<int>> pq;
    for(auto& i:nums)
    {
        while(!pq.empty() && i[0]>=pq.top())
        {
            pq.pop();
        }
        pq.push(i[1]);
        ret = ret>pq.size()?ret:pq.size();
    }
    return ret;
}


int main()
{
    // 将控制台代码页修改为 UTF-8
    system("chcp 65001 > nul");
    // vector<vector<int>> nums = {{1,2},{1,3},{1,4},{1,6},{2,3},{2,4},{5,8},{6,7},{6,9}};
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("data.txt");

    int N;
    fin >> N;
    fin.ignore();
    vector<vector<int>> nums(N,vector<int>(2));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<2;j++)
        {
            int x;
            fin>>nums[i][j];
        }
    }
    cout<< Solution(nums);
}


