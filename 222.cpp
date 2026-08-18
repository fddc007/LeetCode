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
    int countNodes(TreeNode* root) {
        if(root == nullptr)
        {
            return 0;
        }
        int h = 0;
        int h_right = 0;
        int count = 0;
        TreeNode* tmp = root;
        while(tmp != nullptr)
        {
            tmp = tmp->left;
            h++;
        }
        tmp = root->right;
        while(tmp != nullptr)
        {
            tmp = tmp->left;
            h_right++;
        }
        if(h == (h_right+1))
        {
            count = (1<<(h-1))+ countNodes(root->right);
        }
        else
        {
            count = (1<<(h_right)) + countNodes(root->left);
        }
        return count;
    }
};

int main()
{
    TreeNode* root = new TreeNode(1);
    TreeNode* a = new TreeNode(2);
    TreeNode* b = new TreeNode(3);
    TreeNode* d = new TreeNode(4);
    TreeNode* e = new TreeNode(5);
    root->left = a;
    root->right = b;
    a->left = d;
    a->right = e;
    Solution s;
    cout<<s.countNodes(root);
    return 0;
}