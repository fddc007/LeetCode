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
    ListNode* swapNodes(ListNode* head, int k) {
        int i = 1;
        ListNode* first = head;
        ListNode* cur = head;
        ListNode* next = head;
        while(next->next != nullptr)
        {
            //next指向第i个元素
            i++;
            next = next->next;
            //当next指向第k个元素时,first保存地址
            if(i == k)
            {
                first = next;
            }
            //当i == k+1时,cur向后移动一位,始终保持窗口长度为k;
            if(i>k)
            {
                cur = cur->next;
            }
        }
        i = first->val;
        first->val = cur->val;
        cur->val = i;
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
    ListNode L1(5);
    ListNode L4(4,&L1);
    ListNode L3(3,&L4);
    // ListNode L2(2,&L3);
    // ListNode L1(1,&L2);
    printfList(&L1);

    Solution a;
    a.swapNodes(&L1,2);
    printfList(&L1);
    return 0;
}