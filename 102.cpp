#include<iostream>
#include<vector>
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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> nums;
        vector<TreeNode*> tmp;
        int size = 1;
        if(root == nullptr)
        {
            return nums;
        }
        tmp.push_back(root);
        int left  = 0;
        int right = 1;
        while(left<right)
        {
            nums.emplace_back();
            size = right-left;
            for(int i= 0;i<size;i++)
            {
                if(tmp[left]->left != nullptr)
                {
                    tmp.push_back(tmp[left]->left);
                    right++;
                }
                if(tmp[left]->right != nullptr)
                {
                    tmp.push_back(tmp[left]->right);
                    right++;
                }
                nums.back().push_back(tmp[left]->val);
                left++;
            }
        }
        return nums;
    }
};


int main()
{
    TreeNode L7(9);
    TreeNode L6(15);
    TreeNode L5(7);
    TreeNode L4(20,&L6,&L5);
    TreeNode root(3,&L7,&L4);
    Solution a;
    a.levelOrder(&root);
}