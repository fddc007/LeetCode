class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while(left<right)
        {
            right-=right&-right;
        }
        return right;
    }
};