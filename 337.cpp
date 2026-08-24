#include<iostream>


using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int rob(TreeNode* root) {
        f(root);
        return max(yes,no);
    }
private:
    int yes;
    int no;
    int sumNode(TreeNode* root)
    {
        if(root == nullptr)
        {
            return 0;
        }
        int left = root->left?root->left->val:0;
        int right = root->right?root->right->val:0;
        if(root->val >= left && root->val >= right)
        {
            return root->val + (root->left?(sumNode(root->left->left)+ sumNode(root->left->right)):0) + (root->right?(sumNode(root->right->left)+ sumNode(root->right->right)):0);
        }
        else
        {
            // return sumNode(root->left) + sumNode(root->right);
        }
    }
    void f(TreeNode* root)
    {
        if(root == nullptr)
        {
            yes = 0;
            no = 0;
        }
        int y = root->val;
        int n = 0;
        f(root->left);
        y += no;
        n += max(yes,no);
        f(root->right);
        y += no;
        n += max(yes,no);
        yes = y;
        no = n;
    }
};






int main()
{
    TreeNode* root = new TreeNode(3);
    TreeNode* a = new TreeNode(2);
    TreeNode* b = new TreeNode(3);
    TreeNode* c = new TreeNode(3);
    TreeNode* d = new TreeNode(1);

    root->left = a;
    root->right = b;
    a->right = c;
    b->right = d;

    Solution s;
    cout<<s.rob(root)<<"\n";
    return 0;
}