#include<iostream>
#include <cstdint>
using namespace std;


class Solution {
public:
    int add(int a,int b)
    {
        //先进行异或运算,无进位相加
        int x = a^b;
        //在进行与运算获得进位
        int y = a&b;
        //循环往复,知道进位为0为止
        while(y != 0)
        {
            int tmp1 = x^(y<<1);
            int tmp2 = x&(y<<1);
            x = tmp1;
            y = tmp2;
        }
        return x;
    }

    int sub(int a,int b)
    {
        return add(a,-b);
    }

    int mul(int a,int b)
    {
        //每次取b的一位和a进行与&运算,然后相加,直到32为取完
        int i = 0;
        int sum = 0;
        while(i<=31)
        {
            if((b>>i)&1)
            {
                sum = add(sum,a<<i);
            }
            i++;
        }
        return sum;
    }

    int divide(int dividend, int divisor) {
        if(divisor== 1 || divisor == -1)
        {
            if(dividend ==-2147483648 )
            {
                return divisor == 1?dividend:2147483647;
            }
            return divisor == 1?dividend:-dividend;
        }
        if(dividend == divisor)
        {
            return 1;
        }
        if(divisor == -2147483648)
        {
            return 0;
        }
        int ret = 0;
        if(dividend == -2147483648)
        {
            dividend += abs(divisor);
            ret++;
        }
        int absDividend = abs(dividend);
        int absDivisor = abs(divisor);
        if(absDividend < absDivisor)
        {
            return (divisor^dividend)>0?ret:-ret;
        }
        
        
        int a = 31;
        while(a >=0 && absDividend >=absDivisor)
        {
            if(absDividend>>a >= absDivisor)
            {
                ret =add(ret,1<<a);
                absDividend = sub(absDividend,absDivisor<<a);
            }
            a--;
        }
        return (divisor^dividend)>=0?ret:-ret;
    }
};

//简化后
class SolutionA {
public:
    int add(int a,int b)
    {
        //先进行异或运算,无进位相加
        int ans = a;
        //在进行与运算获得进位
        //循环往复,知道进位为0为止
        while(b != 0)
        {
            ans = a^b;
            b = (a&b)<<1;
            a = ans;   
        }
        return ans;
    }

    int neg(int n)
    {
        return add(~n,1);
    }

    int sub(int a,int b)
    {
        return add(a,neg(b));
    }

    int mul(int a,int b)
    {
        //每次取b的一位和a进行与&运算,然后相加,直到32为取完
        int ans = 0;
        while(b!=0)
        {
            if((b&1)!=0)
            {
                ans = add(ans,a);
            }
            a<<=1;
            b = static_cast<uint32_t>(b)>>1;
        }
        return ans;
    }

    int divide(int dividend, int divisor) 
    {
        if(divisor == dividend)
        {
            return 1;
        }
        
        if(dividend == -2147483648)
        {   int ret = 0;
            if(divisor == -1)
            {
                return 2147483647;
            }
            dividend =add(dividend,divisor>0?divisor:neg(divisor));
            ret = div(dividend,divisor);
            int offset = divisor>0?neg(1):1;
            return add(ret,offset);
        }
        if(divisor == -2147483648)
        {
            return 0;
        }
        if(divisor == 1)
        {
            return dividend;
        }
        return div(dividend,divisor);
    }

    int div(int a,int b)
    {
        int absDividend = a<0?neg(a):a;
        int absDivisor = b<0?neg(b):b;
        int ret = 0;
        int i = 31;
        while(i >=0 && absDividend >=absDivisor)
        {
            if(absDividend>>i >= absDivisor)
            {
                ret |=1<<i;
                absDividend = sub(absDividend,absDivisor<<i);
            }
            i--;
        }
        return ((a^b)<0)?neg(ret):ret;
    }
};



int main()
{
    SolutionA a;
    cout<<a.divide(7,-3)<<"      "<<  7/-3    <<"\n";
}