#include<iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
        {
            return nullptr;
        }
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* tmp = head;
        //当tmp步长2时,遍历完节点,cur刚好在中间节点
        while (tmp!= nullptr && tmp->next != nullptr)
        {
            tmp = tmp->next->next;
            pre = cur;
            cur = cur->next;
        }
        //删除cur节点
        pre->next = cur->next;
        return head;
    }
};
void printfList(ListNode* head)
{
    while(head != nullptr)
    {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<"\n";
}

int main()
{
    ListNode L5(5);
    ListNode L4(4,&L5);
    ListNode L3(3,&L4);
    ListNode L2(2,&L3);
    ListNode L1(1,&L2);
    printfList(&L1);

    Solution a;
    a.deleteMiddle(&L1);
    printfList(&L1);
    return 0;
}