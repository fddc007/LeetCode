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

    ListNode* reverse(ListNode* head)
    {
        if(head == nullptr)
        {
            return head;
        }
        ListNode* tmp = nullptr;
        ListNode*cur = nullptr;
        while (head != nullptr)
        {
            cur = head;
            head =head->next;
            cur->next = tmp;
            tmp = cur;
        }
        return cur;
    }

    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
        {
            return false;
        }
        if(head->next->next == nullptr)
        {
            return head->val == head->next->val;
        }
        ListNode* fist = head;
        ListNode* last = head;
        //获取中间节点
        while(last != nullptr)
        {
            fist = fist->next;
            last = last->next == nullptr?nullptr:last->next->next;
        }
        ListNode* tmp = fist;
        ListNode* left = head;
        ListNode* right = reverse(fist);
        while(right != nullptr&& left != nullptr)
        {
            if(left->val == right->val)
            {
                left = left->next;
                right = right->next;
            }
            else
            {
                return false;
            }
        }
        return true;
        
    }
};


int main()
{
    ListNode* L3 = new ListNode(0);
    ListNode* L2 = new ListNode(0,L3);
    ListNode* L1 = new ListNode(1,L2);
    Solution a;
    cout<<a.isPalindrome(L1)<<"\n";
}