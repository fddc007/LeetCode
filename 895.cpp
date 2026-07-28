#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class FreqStack 
{
private:
    int max;
    vector<vector<int>> nums;
    unordered_map<int,int> map;
public:
    FreqStack() {
        max = 0;
        nums.emplace_back();
    }
    
    void push(int val) 
    {
        auto tmp = map.find(val);
        //如果不存在,则加入到1这个桶里面
        if(tmp == map.end())
        {
            if(nums.size()<=1)
            {
                nums.emplace_back();
                max++;
            }
            nums[1].push_back(val);
            map.insert({val,1});
        }
        else
        {
            tmp->second +=1;
            if(tmp->second>max)
            {
                nums.emplace_back();
                max++;
            }
            nums[tmp->second].push_back(val);
        }
    }
    
    int pop() 
    {
        int ret = nums[max].back();
        nums[max].pop_back();
        auto tmp = map.find(ret);
        tmp->second -= 1;
        //当计数为0时,从map中删除
        if(tmp->second == 0)
        {
            map.erase(ret);
        }
        //当最大的max的数组为空时,max-1
        if(nums[max].size() == 0)
        {
            max--;
        }
        return ret;
    }
};



int main()
{
    FreqStack a;
    a.push(5);
    a.push(7);
    a.push(5);
    a.push(7);
    a.push(4);
    a.push(5);
    cout<<a.pop()<<"\n";
    cout<<a.pop()<<"\n";
    cout<<a.pop()<<"\n";
    cout<<a.pop()<<"\n";
    return 0;
}