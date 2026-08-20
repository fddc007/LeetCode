#include<iostream>



using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    bool isBalanced(TreeNode* root) {
        ret = true;
        treeHight(root);
        return ret;
    }
    int treeHight(TreeNode* root)
    {
        if(root == nullptr || ret == false)
        {
            return 0;
        }
        int h_left = 0;
        int h_right = 0;
        h_left = treeHight(root->left) + 1;
        h_right = treeHight(root->right) + 1;
        if(abs(h_left-h_right) >1)
        {
            ret = false;
        }
        return h_left > h_right?h_left:h_right;
    }
private:
    bool ret;
};


int main()
{
    TreeNode* root = new TreeNode(1);
    TreeNode* a  = new TreeNode(2);
    TreeNode* b  = new TreeNode(3);

    root->left = a;
    a->left = b;
    Solution s;
    cout<< s.isBalanced(root)<<"\n";
    return 0;
}