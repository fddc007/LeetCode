#include<iostream>

using namespace std;


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 获取最大值
     * @param a int整型 
     * @param b int整型 
     * @return int整型
     */
    int getSymbol(int a)
    {
        return reserverSymbol(static_cast<uint32_t>(a)>>31);
    }
    int reserverSymbol(int a)
    {
        return a^1;
    }
    int getMax(int a, int b) {
        int SymbolA = getSymbol(a);
        int SymbolB = getSymbol(b);
        int result = a-b;
        int SymbolC = getSymbol(result);
        int diffAB = SymbolA ^ SymbolB;
        int reserverdiffAB = reserverSymbol(diffAB);
        int returnA = diffAB* SymbolA + reserverdiffAB* SymbolC;
        int returnB = reserverSymbol(returnA);
        return a*returnA + b*returnB;

    }
};

/*
a,b异号,a-b会溢出
如果不存在溢出返回表达式
a-b 符号位1,表示正数返回a
a-b 符号位0,表示负数返回b
sign(a-b)*a + sign(a-b)*b 

如果存在溢出,只有一种可能ab异号
ab的符号异或值为1
a的符号值为1,返回a
b的符号值为1,返回b
signab =1
signA*a + signB*b;


于是整体表达式:
signab * (signA*a + signB*b) + ~signab *(sign(a-b)*a + sign(a-b)*b )
整理可以得出
返回A的式子
(signab * signA + ~signab * sign(a-b) ) * a

将A前面的系数记为returnA
则: return returnA * a + (~returnA) * a;
*/