#include<iostream>
#include<vector>
#include<stack>

using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        ret = true;
        first(root);
        return ret;
    }

    //先序遍历
    void first(TreeNode* root)
    {
        if(ret == false)
        {
            return ;
        }
        if(root == nullptr)
        {
            return ;
        }
        first(root->left);
        if(!s.empty())
        {
            if(root->val >s.top())
            {
                s.push(root->val);
            }
            else
            {
                ret = false;
            }
        }
        else
        {
            s.push(root->val);
        }
        first(root->right);
    }
private:
    stack<int> s;
    bool ret;
};


int main()
{
    TreeNode* root = new TreeNode(5);
    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(4);
    TreeNode* c = new TreeNode(3);
    TreeNode* d = new TreeNode(6);
    root->left = a;
    root->right = b;
    b->left = c;
    b->right = d;
    Solution s;
    cout<<s.isValidBST(root);
}

