#include<iostream>
#include<string>
#include<vector>

using namespace std;

/*
1. 用归纳思想进行递归
2. 一共n层汉罗塔
3. 将n-1层汉罗塔移动到中间,这样确保第n层放到最右边
4. 此时汉罗塔的规格变为n-1
5. 再将汉罗塔n-2层移动到右边
6. 此时汉罗塔的规格变为n-2,并跟n层时重合,做一样的事情:将n-2层移动到右边,确定n-1
7. 建立递归,i表示汉罗塔需要处理的规格,from表示左边 to表示右边(目标) other 表示中间
*/




class TowerOfHanoi
{
public:
    void f(int i,const string& from,const string& to,const string& other)
    {
        if(i == 1)
        {
            cout<<"圆盘"<<1<<"从"<<from<<"移动到"<<to<<"\n";
        }
        else
        {
            f(i-1,from,other,to);
            cout<<"圆盘"<<i<<"从"<<from<<"移动到"<<to<<"\n";
            f(i-1,other,to,from);
        }
    }
};


/*
1. 处理n层汉罗塔问题
2. 拆分为处理n-1层和处理第n层
3. 将n-1层移动到中间,将第n层放到右边,这样n层就简化成了n-1层
4. 右边永远是目标层,永远只放第n层的,只有左和中会出现空闲
5. 左右谁空,谁就是n-1层移动的目标
6. 所以只会出现左移动到中,中移动到左,这是递归一进去就需要处理的.
*/
class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) 
    {
        int len = A.size();
        f(len,A,B,C);
    }
    void f(int i,vector<int>& A, vector<int>& B, vector<int>& C)
    {
        if(i == 0)
        {
            return ;
        }
        f(i-1,A,C,B);
        C.push_back(A.back());
        A.pop_back();
        f(i-1,B,A,C);
    }
};


int main()
{
    // 将控制台代码页修改为 UTF-8
    system("chcp 65001 > nul");
    vector<int> A = {2,1,0};
    vector<int> B;
    vector<int> C;
    Solution s;
    s.hanota(A,B,C);
    for(auto i = C.begin();i != C.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<"\n";
    return 0;
}