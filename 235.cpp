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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q)
        {
            return root;
        }
        TreeNode* max = q;
        TreeNode* min = p;
        TreeNode* l = nullptr;
        TreeNode* r = nullptr;
        if(p->val > q->val)
        {
            max = p;
            min = q;
        }
        if(root->val >min->val && root->val <max->val)
        {
            return root;
        }
        if(root->val < min->val)
        {
            l = lowestCommonAncestor(root->right,p,q);
        }
        if(root->val > max->val)
        {
            r = lowestCommonAncestor(root->left,p,q);
        }
        return l != nullptr?l:r;
    }
};



int main()
{
    TreeNode* root = new TreeNode(6);
    TreeNode* a = new TreeNode(2);
    TreeNode* b = new TreeNode(8);
    TreeNode* c = new TreeNode(0);
    TreeNode* d = new TreeNode(4);
    TreeNode* e = new TreeNode(7);
    TreeNode* f = new TreeNode(9);
    root->left = a;
    root->right = b;
    a->left = c;
    a->right = d;
    b->left = e;
    b->right = f;
    Solution s;
    TreeNode* tmp = s.lowestCommonAncestor(root,a,d);
    cout<< (tmp == root)<<"\n";
    return 0;
}