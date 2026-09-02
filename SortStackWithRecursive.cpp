#include<iostream>
#include<stack>

using namespace std;


class SortStackWithRecursive
{
public:
    void sort(stack<int>& s)
    {
        int height = deep(s);
        //按照高度进行递归,每次递归高度减少最大值的个数
        while(height>0)
        {
            int stack_max = getMax(s,height);
            int count = countMax(s,stack_max,height);
            down(s,stack_max,count,height);
            height = height - count;
        }
    }
private:
    //保证栈的数据不变,获取栈的深度
    //利用递归栈的特性,独立的空间
    //递归栈展开,每一层高度是独立的1,返回进行累加1
    int deep(stack<int>& s)
    {
        if(s.empty())
        {
            return 0;
        }
        int n = s.top();
        s.pop();
        int height = deep(s) + 1;
        s.push(n);
        return height;
    }
    //获取栈中的最大值
    //设置一个变量,初始值为整型的最小值
    //通过递归栈,获取top和剩下的元素最大值,进行比较
    int getMax(stack<int>& s,int height)
    {
        int stack_max = INT_MIN;
        if(height == 0)
        {
            return stack_max;
        }
        int tmp = s.top();
        s.pop();
        stack_max = max(tmp,getMax(s,height-1));
        s.push(tmp);
        return stack_max;
    }
    //统计最大值的个数
    //每一层递归栈都记录该层对于最大的个数,0或者1,最后累加
    int countMax(stack<int>& s,int stack_max,int height)
    {
        int count = 0;
        if(height == 0)
        {
            return count;
        }
        int tmp = s.top();
        if(tmp == stack_max)
        {
            count++;
        }
        s.pop();
        count = count + countMax(s,stack_max,height-1);
        s.push(tmp);
        return count;
    }
    //将最大值调整到最下面
    //递归栈展开高度由height控制
    //当hight为0时,到达最底层,按照最大值的个数进行入栈
    //在递归栈回溯时,等于最大值不进栈
    void down(stack<int>& s,int stack_max,int count,int height)
    {
        if(height == 0)
        {
            for(int i=0;i<count;i++)
            {
                s.push(stack_max);
            }
        }
        else
        {
            int tmp = s.top();
            s.pop();
            down(s,stack_max,count,height-1);
            if(tmp != stack_max)
            {
                s.push(tmp);
            }
        }
    }
};

int main()
{
    stack<int> s;
    s.push(88);
    s.push(88);
    s.push(88);
    s.push(27);
    s.push(27);
    s.push(33);
    s.push(3);
    s.push(999);
    s.push(84);
    s.push(84);
    s.push(84);
    s.push(84);
    s.push(2222);
    s.push(2222);

    SortStackWithRecursive a;
    a.sort(s);
    while(!s.empty())
    {
        cout<<s.top()<< " ";
        s.pop();
    }
    return 0;
}