#include<iostream>
#include<vector>
#include<unordered_map>


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
    TreeNode* f(vector<int>& preorder,int l,int r, vector<int>& inorder,int left,int right,unordered_map<int,int>& map)
    {
        if(l>r || left>right)
        {
            return nullptr;
        }
        int cur = preorder[l];
        int site = map[cur];
        int left_len = site-left;
        int right_len = right-site;
        TreeNode* root = new TreeNode(cur);
        root->left = f(preorder,l+1,l+left_len,inorder,left,site-1,map);
        root->right = f(preorder,l+left_len+1,r,inorder,site+1,right,map);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len =inorder.size();
        int len_preorder = preorder.size();
        if(len == 0 || len_preorder == 0 || len != len_preorder)
        {
            return nullptr;
        }
        unordered_map<int,int> map;
        for(int i= 0;i<len;i++)
        {
            map.insert({inorder[i],i});
        }
        return f(preorder,0,len-1,inorder,0,len-1,map);
    }
};

int main()
{
    vector<int> a = {3,9,20,15,7};
    vector<int> b = {9,3,15,20,7};
    Solution s;
    TreeNode* cur = s.buildTree(a,b);


    return 0;
}