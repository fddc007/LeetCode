#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    int halveArray(vector<int>& nums) {
        int count = 0;
        double sum = 0;
        double object = 0;
        priority_queue<double> pq;
        //建立大根堆,每次操作数均从大根堆里面取出
        for(int i:nums)
        {
            sum += i;
            pq.push(i);
        }
        //每个操作数除以2,当满足nums之和的一半时返回操作数.
        while(object<(sum/2.0))
        {
            double tmp = pq.top()/2.0;
            object += tmp;
            pq.pop();
            pq.push(tmp);
            count++;
        }
        return count;
    }
};

int main()
{
    vector<int> nums = {3,8,20};
    Solution a;
    int x = a.halveArray(nums);
    cout<<x<<"\n";
}