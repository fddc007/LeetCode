#include<iostream>
#include<vector>
#include<string>

using namespace std;



class Bitset {
public:
    Bitset(int size) {
        count_0 = size;
        count_1 = 0;
        this->size = size;
        reverse = false;
        nums = new vector<int>((size+31)/32);
    }
    //更新idx的值为1
    void fix(int idx) {
        int site = idx/32;
        int mod = idx%32;
        if((nums->at(site)&(1<<mod))==0)
        {
            count_1++;
            count_0--;
            nums->at(site) |= (1<<mod);
        }
    }
    
    void unfix(int idx) {
        int site = idx/32;
        int mod = idx%32;
        if((nums->at(site)&(1<<mod))!=0)
        {
            count_1--;
            count_0++;
            nums->at(site) ^= (1<<mod);
        }
    }
    
    void flip() {
        reverse ^= 1;
        for(auto i=nums->begin();i!=nums->end();i++)
        {
            (*i) ^= 0xffffffff;
        }
        int tmp = count_0;
        count_0 = count_1;
        count_1 = tmp;
    }
    
    bool all() {
        return count_0 <= 0;
    }
    
    bool one() {
        return count_1 >0;
    }
    
    int count() {
        return count_1;
    }
    
    string toString() {
        string a(size,'0');
        for(int i=0;i<size;i++)
        {
            int site = i/32;
            int mod = i%32;
            if(((nums->at(site)>>mod)&1)!=0)
            {
                a.at(i) = '1';
            }
        }
        return a;
    }
private:
    int size;
    int count_1;
    int count_0;
    bool reverse;
    vector<int>* nums;
    
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */


int main()
{
    Bitset a(5);
    a.fix(3);
    a.fix(1);
    a.flip();
    a.all();
    a.unfix(0);
    a.flip();
    a.one();
    a.unfix(0);
    a.count();
    a.toString();
}