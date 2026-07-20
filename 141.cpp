#include<iostream>

using namespace std;


/*
结论:当一个环存在的时候,快慢指针,快慢指针指向同一个位置时,
    此时另一个指正从头结点出发,与慢指针会在环的入口相遇

*/



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr)
        {
            return nullptr;
        }
        //定义一个快慢指针
        ListNode* cur1 = head->next;
        ListNode* cur2 = head->next->next;
        //判断是否存在环
        while(cur1 !=cur2)
        {
            if(cur2->next == nullptr || cur2->next->next == nullptr)
            {
                return nullptr;
            }
            cur1 = cur1->next;
            cur2 = cur2->next->next;
        }
        cur2 = head;
        while(cur1 != cur2)
        {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return cur1;
    }
};


int main()
{

    ListNode* L3 = new ListNode(-4);
    ListNode* L2 = new ListNode(0);
    ListNode* L1 = new ListNode(2);
    ListNode* head = new ListNode(3);
    head->next = L1;
    L1->next = L2;
    L2->next = L3;
    L3->next = L1;

    Solution a;
    a.detectCycle(head);
}