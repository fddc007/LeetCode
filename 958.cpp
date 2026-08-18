#include<iostream>
#include<queue>

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
    bool isCompleteTree(TreeNode* root) {
        if(root == nullptr)
        {
            return false;
        }
        bool trade = false;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            TreeNode* cur = que.front();
            if((cur->left == nullptr && cur->right != nullptr) || (trade && (cur->left != nullptr || cur->right != nullptr)))
            {
                return false;
            }
            if(cur->left != nullptr)
            {
                que.push(cur->left);
            }
            if(cur->right != nullptr)
            {
                que.push(cur->right);
            }
            if(cur->left == nullptr || cur->right == nullptr)
            {
                trade = true;
            }
            que.pop();
        }
        return true;
    }
};


int main()
{
    TreeNode* root = new TreeNode(1);
    TreeNode* a = new TreeNode(2);
    TreeNode* b = new TreeNode(3);
    TreeNode* c = new TreeNode(5);
    TreeNode* d = new TreeNode(7);
    TreeNode* e = new TreeNode(8);
    root->left = a;
    root->right = b;
    a->left = c;
    b->left = d;
    b->right = e;
    Solution s;
    cout<<s.isCompleteTree(root)<<"\n";
    return 0;
}
