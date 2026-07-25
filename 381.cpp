#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<random>
using namespace std;


class RandomizedCollection {
private:
    vector<int> nums;
    unordered_map<int,unordered_set<int>> map;
    mt19937 gen_;
public:
    RandomizedCollection():gen_(random_device{}()){}
    int getInt(int min,int max)
    {
        uniform_int_distribution<int> dist(min,max);
        return dist(gen_);
    }
    
    bool insert(int val) 
    {
        nums.push_back(val);
        int last = nums.size()-1;
        map[val].insert(last);
        return map[val].size()==1;
    }
    
    bool remove(int val) 
    {
        auto tmp = map.find(val);
        if(tmp == map.end())
        {
            return false;
        }
        int site = *tmp->second.begin();
        if(nums.back() == val)
        {
            nums.pop_back();
            site = nums.size();
        }
        else
        {
            int lastVal = nums.back();
            int lastSite = nums.size()-1;
            nums[site] = lastVal;
            nums.pop_back();
            map[lastVal].erase(lastSite);
            map[lastVal].insert(site);
        }
        tmp->second.erase(site);
        if(tmp->second.size()==0)
        {
            map.erase(val);
        }
        return true;
    }
    
    int getRandom() {
        int last = nums.size()-1;
        return nums[getInt(0,last)];
    }
};

int main()
{
    RandomizedCollection a;
    cout<<a.insert(1)<<"\n";
    cout<<a.insert(1)<<"\n";
    cout<<a.remove(1)<<"\n";
    cout<<a.getRandom();
    return 0;
}