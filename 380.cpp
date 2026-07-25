#include<iostream>
#include<vector>
#include<unordered_map>
#include<random>
using namespace std;



class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int,int> map;
    mt19937 gen_;
public:
    RandomizedSet():gen_(random_device{}()){}
    int getInt(int min,int max)
    {
        uniform_int_distribution<int> dist(min,max);
        return dist(gen_);
    }

    bool insert(int val) {
        if(map.find(val) != map.end())
        {
            return false;
        }
        else
        {
            map.insert({val,nums.size()});
            nums.push_back(val);
            return true;
        }
    }
    
    bool remove(int val) {
        auto tmp = map.find(val);
        if(tmp == map.end())
        {
            return false;
        }
        else
        {
            int last = nums.size()-1;
            map[nums[last]] = tmp->second;
            nums[tmp->second] = nums[last];
            map.erase(val);
            nums.pop_back();
            return true;
        }
    }
    
    int getRandom() {
        int last = nums.size()-1;
        return nums[getInt(0,last)];
    }
};

int main()
{
    RandomizedSet a;
    cout<<a.insert(0)<<"\n";
    cout<<a.insert(1)<<"\n";
    cout<<a.remove(0)<<"\n";
    cout<<a.insert(2)<<"\n";
    cout<<a.remove(1)<<"\n";
    cout<<a.getRandom()<<"\n";
    // cout<<a.insert(2)<<"\n";
    // cout<<a.getRandom()<<"\n";
    return 0;
}