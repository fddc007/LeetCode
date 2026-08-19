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
    TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode* p,TreeNode* q)
    {
        if(root == nullptr)
        {
            return nullptr;
        }
        if(root == p || root == q)
        {
            return root;
        }
        TreeNode* l = lowestCommonAncestor(root->left,p,q);
        TreeNode* r = lowestCommonAncestor(root->right,p,q);
        if((l == p || l == q) && (r == p || r == q))
        {
            return root;
        }
        return l != nullptr?l:r;
    }
};



int main()
{
    TreeNode* root = new TreeNode(1);
    TreeNode* a = new TreeNode(2);
    TreeNode* b = new TreeNode(3);
    TreeNode* c = new TreeNode(4);
    TreeNode* d = new TreeNode(5);
    TreeNode* e = new TreeNode(6);
    root->left = a;
    root->right = b;
    a->left = c;
    a->right = d;
    b->left = e;
    Solution s;
    TreeNode* tmp = s.lowestCommonAncestor(root,b,e);
    cout<< (tmp == b)<<"\n";
    return 0;
}