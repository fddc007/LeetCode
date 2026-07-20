#include<iostream>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)
        {
            return head;
        }
        Node* cur = head;
        //复制每个节点,并连接到该节点的下一个的位置
        while (cur != nullptr)
        {
            Node* tmp = new Node(cur->val);
            tmp->next = cur->next;
            tmp->random = cur->random;
            cur->next = tmp;
            cur = tmp->next;
        }
        cur = head;
        while (cur != nullptr)
        {
            cout<<cur->val <<"  "<<(cur->random != nullptr?cur->random->val:0)<<"\n";
            cur = cur->next;
        }
        
        Node* ret = head->next;
        Node* tmp = ret;
        //修改新节点的random值
        while(tmp != nullptr)
        {
            tmp->random = tmp->random?tmp->random->next:nullptr;
            tmp = tmp->next?tmp->next->next:nullptr;
        }
        //分离复制好的节点,随机下一个节点的值就是当前值的下一个;
        cur = head;
        tmp = ret;
        while(cur!=nullptr && tmp!= nullptr)
        {
            cur->next = tmp->next;
            cur = cur->next;
            tmp->next = tmp->next?tmp->next->next:nullptr;
            tmp = tmp->next;
        }
        
        cur = ret;
        while (cur != nullptr)
        {
            cout<<cur->val <<"  "<<(cur->random != nullptr?cur->random->val:0)<<"\n";
            cur = cur->next;
        }
        return ret;
    }
};


int main()
{
    Node* L5 = new Node(1);
    Node* L4 = new Node(10);
    Node* L3 = new Node(11);
    Node* L2 = new Node(13);
    Node* L1 = new Node(7);

    L1->next = L2;
    L1->random = nullptr;
    L2->next = L3;
    L2->random = L1;
    L3->next = L4;
    L3->random = L5;
    L4->next = L5;
    L4->random = L3;
    L5->next = nullptr;
    L5->random = L1;

    Solution a;
    Node* tmp = a.copyRandomList(L1);
    return 0;
}