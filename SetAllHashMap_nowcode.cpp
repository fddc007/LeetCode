https://www.nowcoder.com/practice/7c4559f138e74ceb9ba57d76fd169967


#include<iostream>
#include<unordered_map>
#include<fstream>
using namespace std;


class hashMap
{
public:
    hashMap()
    {
        count=0;
        gloab_value=0;
        count_setALL=0;
    }
    void put(int key,int value)
    {
        count++;
        map[key].value = value;
        map[key].cint = count;
    }

    int get(int key)
    {
        if(map.find(key) != map.end())
        {
            return map[key].cint >= count_setALL?map[key].value:gloab_value;
        }
        else
        {
            return -1;
        }
    }

    bool containsKey(int key)
    {
        return map.find(key) != map.end();
    }

    void setALL(int value)
    {
        count_setALL = ++count;
        gloab_value = value;

    }


private:
    struct Node
    {
        int value;
        int cint;
    };
    unordered_map<int,Node> map;
    int count;
    int gloab_value;
    int count_setALL;
};

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    hashMap map;
    ifstream fin("data.txt");
    int n;
    fin>>n;
    fin.ignore();
    int x,y,z;
    for(int i = 0;i<n;i++)
    {
        fin>>x;
        if(x ==1)
        {
            fin>>y;
            fin>>z;
            map.put(y,z);
        }
        else if(x==2)
        {
            fin>>y;
            cout<<map.get(y)<<"\n";
        }
        else if(x == 3)
        {
            fin>>y;
            map.setALL(y);
        }
    }
    return 0;
}