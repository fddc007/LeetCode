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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return trim(root,low,high);
    }

    TreeNode* trim(TreeNode* root, int low, int high)
    {
        if(root == nullptr)
        {
            return nullptr;
        }
        if(root->val < low)
        {
            return trim(root->right,low,high);
        }
        if(root->val > high)
        {
            return trim(root->left,low,high);
        }
        root->left = trim(root->left,low,high);
        root->right = trim(root->right,low,high);
        return root;
    }
};

int main()
{
    
}