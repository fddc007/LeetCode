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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode* first  = head;
        ListNode* last = head->next;
        head = last;
        first->next = head->next;
        head->next = first;
        ListNode* end = first;
        first = first->next;
        while (first != nullptr)
        {
            if((last = first->next) == nullptr)
            {
                return head;
            }
            end->next = last;
            first->next = last->next;
            last->next = first;
            end = first;
            first = first->next;
        }
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
    ListNode* head = a.swapPairs(&L1);
    printfList(head);
}