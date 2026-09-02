#include<iostream>
#include<stack>

using namespace std;


class ReverseStackWithRecursive
{
public:
    //递归栈,每一个栈拥有独立的空间
    //ans每次存储栈底元素
    //bottomOut的返回值是弹出后的栈底元素,还未入栈
    //递归调用reverse,利用递归栈的特性,先进后出,实现栈的逆序
    //相当于第二个栈容器为递归栈,将s的栈元素通过递归展开的方式压入递归栈中
    //非递归方法是按照一个栈弹出,另一栈压入
    void reverse(stack<int>& s)
    {
        if(s.empty())
        {
            return ;
        }
        int ans = bottomOut(s);
        reverse(s);
        s.push(ans);
    }
    //将栈底元素一层层的向上返回,最后通过调用者将返回值压入栈中
    //实现栈底元素转化为栈头元素,其他元素顺序不变
    //利用递归栈,每一层递归都有自己独立的空间,通过每一层的返回,来保存栈底元素
    int bottomOut(stack<int>& s)
    {
        int ans = s.top();
        if(s.size()==1)
        {
            ans = s.top();
            s.pop();
            return ans;
        }
        int last = s.top();
        s.pop();
        ans = bottomOut(s);
        s.push(last);
        return ans;
    }
    int bottomOut_One(stack<int>& s)
    {
        int ans = s.top();
        s.pop();
        if(s.empty())
        {
            return ans;
        }
        int last = ans;
        ans = bottomOut_One(s);
        s.push(last);
        return ans;
    }
};



int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);

    ReverseStackWithRecursive r;
    r.reverse(s);
    while(!s.empty())
    {
        cout<<s.top()<< " ";
        s.pop();
    }
    return 0;

}