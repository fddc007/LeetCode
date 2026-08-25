#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    vector<string> generatePermutation(string s) 
    {
        int len = s.size();
        char* buf = new char[len+1];
        unordered_set<string> set;
        f(s,0,buf,0,set,len);
        vector<string> ret(set.begin(),set.end());
        delete[] buf;
        return ret;
    }
    void f(const string &s,int i,char* buf,int size,unordered_set<string> &set,int len)
    {
        if(i == len)
        {
            buf[size] = '\0';
            set.insert(buf);
        }
        else
        {
            buf[size] = s[i];
            f(s,i+1,buf,size+1,set,len);
            f(s,i+1,buf,size,set,len);
        }
    }
};


int main()
{
    string str = "aab";
    Solution s;
    vector<string> nums = s.generatePermutation(str);
    for(auto i = nums.begin();i != nums.end();++i)
    {
        cout<<*i <<"\n";
    }
}