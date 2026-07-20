#include<iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr)
        {
            return nullptr;
        }
        //用于判断那个链表更长
        int len = 0;
        ListNode* cur1 = headA;
        ListNode* cur2 = headB;
        //遍历A链表
        while (cur1->next != nullptr)
        {
            cur1 = cur1->next;
            len++;
        }
        //遍历B链表
        while (cur2->next != nullptr)
        {
            cur2 = cur2->next;
            len--;
        }
        //如果相交,尾节点必相同
        if(cur1 != cur2)
        {
            return nullptr;
        }
        cur1 = headA;
        cur2 = headB;
        //谁长谁先移动
        ListNode* &tmp = len>0?cur1:cur2;
        len = abs(len);
        while(len>0)
        {
            tmp = tmp->next;
            len--;
        }
        //两节点相等时相交
        while(cur1 != cur2)
        {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return cur1;
        
        
    }
};