#include<iostream>
#include<string>
#include<sstream>
#include<queue>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



//层序遍历
class Codec_One {
public:

    // Encodes a tree to a single string.

    //层序序列化
    string serialize(TreeNode* root) {
        if(root == nullptr)
        {
            return "";
        }
        string str = "";
        str += to_string(root->val);
        str += " ";
        queue<TreeNode*> que;
        //层序遍历
        que.push(root);
        while(!que.empty())
        {
            int len = que.size();
            for(int i = 0;i<len;i++)
            {
                TreeNode* cur = que.front();
                if(cur->left != nullptr)
                {
                    que.push(cur->left);
                    str += to_string(cur->left->val);
                    str += " ";
                }
                else
                {
                    str += "#";
                    str += " ";
                }
                if(cur->right != nullptr)
                {
                    que.push(cur->right);
                    str += to_string(cur->right->val);
                    str += " ";
                }
                else
                {
                    str += "#";
                    str += " ";
                }
                que.pop();
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())
        {
            return nullptr;
        }
        stringstream ss(data);
        string tmp;
        ss >> tmp;
        TreeNode* root = new TreeNode(stoi(tmp));
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            TreeNode* cur = que.front();
            ss>>tmp;
            if(tmp != "#")
            {
                TreeNode* left = new TreeNode(stoi(tmp));
                que.push(left);
                cur->left = left;
            }
            ss>>tmp;
            if(tmp != "#")
            {
                TreeNode* right = new TreeNode(stoi(tmp));
                que.push(right);
                cur->right = right;
            }
            que.pop();
        }
        return root;
    }
};


//先序遍历
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr)
        {
            return "#";
        }
        string str = "";
        str = str + to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
        return str;
    }

    TreeNode* f(vector<string>& str,int& cnt)
    {
        string cur = str[cnt++];
        if(cur == "#")
        {
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(cur));
        root->left = f(str,cnt);
        root->right = f(str,cnt);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> str;
        stringstream ss(data);
        string tmp;
        while(ss>>tmp)
        {
            str.push_back(tmp);
        }
        int cnt = 0;
        return f(str,cnt);
    }
};


int main()
{
    TreeNode* root = new TreeNode(1);
    TreeNode* a = new TreeNode(2);
    TreeNode* b = new TreeNode(3);
    TreeNode* c = new TreeNode(4);
    TreeNode* d = new TreeNode(5);
    root->left = a;
    root->right = b;
    b->left = c;
    b->right = d;
    Codec code;
    // cout<<code.serialize(root);
    string str = code.serialize(root);
    code.deserialize(str);

    return 0;
}