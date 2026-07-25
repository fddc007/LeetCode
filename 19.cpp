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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //指向要删除的前一个元素,如果为head节点,则为空
        ListNode* pre = nullptr;
        //最终指向要删除的元素
        ListNode* cur = head;
        ListNode* next = head;
        int i = 1;
        while(next->next != nullptr)
        {
            next = next->next;
            if(i >=n)
            {
                pre = cur;
                cur = cur->next;
            }
            i++;
        }
        //删除节点
        if(pre == nullptr)
        {
            head = cur->next;
        }
        else
        {
            pre->next = cur->next;
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
    a.removeNthFromEnd(&L1,2);
    printfList(&L1);
}