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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr)
        {
            return {};
        }
        int sum = 0;
        f(root,sum,targetSum);
        return ans;
    }
    int f(TreeNode* root,int sum,int targetSum)
    {
        if(root == nullptr)
        {
            return 0;
        }
     path.push_back(root);
        sum = sum + root->val;
        if((sum == targetSum) && (root->left == nullptr) && (root->right == nullptr))
        {
            ans.emplace_back();
            auto& tmp = ans.back();
            for(auto i = path.begin();i != path.end();++i)
            {
                tmp.push_back((*i)->val);
            }
        }
        f(root->left,sum,targetSum);
        f(root->right,sum,targetSum);
     path.pop_back();
        return sum;
    }
private:
    vector<TreeNode*> path;
    vector<vector<int>> ans;
};

//优化后的代码
class Solution_Plus {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        f(root,sum,targetSum);
        return ans;
    }
    void f(TreeNode* root,int sum,int targetSum)
    {
        if(root == nullptr)
        {
            return ;
        }
        path.push_back(root->val);
        sum = sum + root->val;
        if((sum == targetSum) && (root->left == nullptr) && (root->right == nullptr))
        {
            ans.emplace_back(path.begin(),path.end());
        }
        f(root->left,sum,targetSum);
        f(root->right,sum,targetSum);
        path.pop_back();
    }
private:
    vector<int> path;
    vector<vector<int>> ans;
};

int main()
{
    // 1. 构建根节点
    TreeNode* root = new TreeNode(5);
    
    // // 2. 构建第二层
    // root->left = new TreeNode(4);
    // root->right = new TreeNode(8);
    
    // // 3. 构建第三层
    // root->left->left = new TreeNode(11);
    // // root->left->right 默认为 nullptr
    
    // root->right->left = new TreeNode(13);
    // root->right->right = new TreeNode(4);
    
    // // 4. 构建第四层
    // root->left->left->left = new TreeNode(7);
    // root->left->left->right = new TreeNode(2);
    
    // // root->right->left (13) 的左右子节点为空
    
    // root->right->right->left = new TreeNode(5);
    // root->right->right->right = new TreeNode(1);




    Solution s;
    vector<vector<int>> path = s.pathSum(root,22);
    if (path.size() == 0)
    {
        cout<<"空"<<"\n";
    }
    for(auto i = path.begin();i != path.end();++i)
    {
        for(auto j = (*i).begin();j != (*i).end();++j)
        {
            cout<<(*j) << " ";
        }
        cout<<"\n";
    }
    return 0;
}