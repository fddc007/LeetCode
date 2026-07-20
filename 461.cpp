#include<iostream>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x^y;
        n = (n&0x55555555) + ((n&0xaaaaaaaa)>>1);
        n = (n&0x33333333) + ((n&0xcccccccc)>>2);
        n = (n&0x0f0f0f0f) + ((n&0xf0f0f0f0)>>4);
        n = (n&0x00ff00ff) + ((n&0xff00ff00)>>8);
        n = (n&0x0000ffff) + ((n&0xffff0000)>>16);
        return n;
    }

};

int main()
{
    Solution a;
    
    cout<<a.hammingDistance(1,4)<<"\n";
}