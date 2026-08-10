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

//BFS 层序遍历
class Solution_One {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
        {
            return 0;
        }
        queue<TreeNode*> que;
        que.push(root);
        int maxDeep = 0;
        while(!que.empty())
        {
            maxDeep++;
            int len = que.size();
            for(int i = 0;i<len;i++)
            {
                TreeNode* cur = que.front();
                if(cur->left != nullptr)
                {
                    que.push(cur->left);
                }
                if(cur->right != nullptr)
                {
                    que.push(cur->right);
                }
                que.pop();
            }
        }
        return maxDeep;
    }
};

//递归
class Solution {
public:
    int maxDepth(TreeNode* root) {
        return root == nullptr?0:max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};

int main()
{
    TreeNode* a = new TreeNode(3);
    TreeNode* b = new TreeNode(9);
    TreeNode* c = new TreeNode(20);
    TreeNode* d = new TreeNode(15);
    TreeNode* e = new TreeNode(7);
    a->left = b;
    a->right = c;
    c->left = d;
    c->right = e;

    Solution A;
    A.maxDepth(a);

}