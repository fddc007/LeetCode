#include<iostream>
#include<queue>
#include<math.h>


using namespace std;




struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution_One{
public:
    int minDepth(TreeNode* root) {
        //层序遍历
        if(root == nullptr)
        {
            return 0;
        }
        int minDeep = 0;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            minDeep++;
            int len = que.size();
            for(int i= 0;i<len;i++)
            {
                TreeNode* cur = que.front();
                if(cur->left == nullptr && cur->right == nullptr)
                {
                    return minDeep;
                }
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
        return minDeep;
    }
};


class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr)
        {
            return 0;
        }
        if(root->left == nullptr && root->right == nullptr)
        {
            return 1;
        }
        int leftmin = 2147483467;
        int rightmin = 2147483467;
        if(root->left != nullptr)
        {
            leftmin = minDepth(root->left);
        }
        if(root->right != nullptr)
        {
            rightmin = minDepth(root->right);
        }
        return min(leftmin,rightmin)+1;
    }
};