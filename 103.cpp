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
vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
{
        vector<vector<int>> nums;
        if(root == nullptr)
        {
            return nums;
        }
        vector<TreeNode*> tmp;
        int left = 0;
        tmp.push_back(root);
        bool reverse = false;
        while (left<tmp.size())
        {
            int right = tmp.size()-1;
            nums.emplace_back();
            nums.back().reserve(right-left+1);
            if(reverse == false)
            {
                int i = left;
                while(i<=right)
                {
                    nums.back().push_back(tmp[i++]->val);
                }
                reverse = true;
            }
            else
            {
                int i = right;
                while(i>=left)
                {
                    nums.back().push_back(tmp[i--]->val);
                }
                reverse = false;
            }

            while(left<=right)
            {
                if(tmp[left]->left != nullptr)
                {
                    tmp.push_back(tmp[left]->left);
                }
                if(tmp[left]->right != nullptr)
                {
                    tmp.push_back(tmp[left]->right);
                }
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
    a.zigzagLevelOrder(&root);
    return 0;
}