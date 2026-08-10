#include<iostream>
#include<vector>
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


struct Site
{
    TreeNode* Node;
    unsigned long long site;
};



class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) 
    {
        if(root == nullptr)
        {
            return 0;
        }
        unsigned long long  maxWidth = 1;
        unsigned long long leftSite = 0;
        unsigned long long rightSite = 0;
        queue<Site> que;
        que.push({root,1});
        while (!que.empty())
        {
            int len = que.size();
            leftSite = que.front().site;
            for(int i = 0;i<len;i++)
            {
                Site cur = que.front();
                if(i == len-1)
                {
                    rightSite = cur.site;
                }
                if(cur.Node->left != nullptr)
                {
                    que.push({cur.Node->left,2*cur.site});
                }
                if(cur.Node->right != nullptr)
                {
                    que.push({cur.Node->right,2*cur.site+1});
                }
                que.pop();
            }
            maxWidth = (rightSite-leftSite+1)>maxWidth?(rightSite-leftSite+1):maxWidth;
        }
        return maxWidth;
    }
};

int main()
{
    TreeNode* f = new TreeNode(7);
    TreeNode* e = new TreeNode(6);
    TreeNode* d = new TreeNode(5);
    TreeNode* c = new TreeNode(9);
    TreeNode* b = new TreeNode(2);
    TreeNode* a = new TreeNode(3);
    TreeNode* root = new TreeNode(1);

    root->left = a;
    root->right = b;
    a->left = d;
    b->right = c;
    d->left = e;
    c->left = f;


    Solution A;
    cout<<A.widthOfBinaryTree(root)<<"\n";
    return 0;

}