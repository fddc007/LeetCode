#include<iostream>
#include<algorithm>
using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};




class Solution {
    public:
    //合并有序列表
    ListNode* mergeSort(ListNode* head1,ListNode* head2)
    {
        if(head1 == nullptr)
        {
            return head2;
        }
        if(head2 == nullptr)
        {
            return head1;
        }
        ListNode* head = nullptr;
        if(head1->val > head2->val)
        {
            head = head2;
            head2 = head2->next;
        }
        else
        {
            head = head1;
            head1 = head1->next;
        }
        ListNode* cur = head;
        while (head1 != nullptr && head2 != nullptr)
        {
            if(head1->val > head2->val)
            {
                cur->next = head2;
                head2 = head2->next;
            }
            else
            {
                cur->next = head1;
                head1 = head1->next;
            }
            cur = cur->next;
        }
        cur->next = head1 == nullptr?head2:head1;
        return head;
    }
    
    //获得链表的中间节点
    ListNode* mindNode(ListNode* head)
    {
        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode* last = nullptr;
        ListNode* cur1 = head;
        ListNode* cur2 = head;
        while(cur2 != nullptr)
        {
            last = cur1;
            cur1 = cur1->next;
            cur2 = cur2->next == nullptr?nullptr:cur2->next->next;
        }
        ListNode* ret = nullptr;
        ret = cur1;
        last->next = nullptr;
        return ret;
    }
    
    ListNode* sortList(ListNode* head)
    {
        ListNode* mind = mindNode(head);
        if(mind == head)
        {
            return head;
        }
        return mergeSort(sortList(head),sortList(mind));
    }

    
};


class SolutionA
{
    public:
    //切割链表
    ListNode* split(ListNode* head,int step)
    {
        if(head == nullptr)
        {
            return head;
        }
        ListNode* cur = head;
        for(int i = 1;i<step && cur != nullptr;i++)
        {
            cur = cur->next;
        }
        if(cur != nullptr)
        {
            cur->next = nullptr;
        }
        return head;
    }
    //切割链表优化
    ListNode* split(ListNode* head,ListNode* &head1,int step)
    {
        if(head == nullptr)
        {
            return head;
        }
        ListNode* cur = head;
        for(int i = 1;i<step && cur != nullptr;i++)
        {
            cur = cur->next;
        }
        if(cur != nullptr)
        {
            head1 = cur->next;
            cur->next = nullptr;
        }
        else
        {
            head1 = nullptr;
        }
        return head;
    }

    ListNode* move_Node(ListNode* head,int step)
    {
        if(head == nullptr)
        {
            return head;
        }
        for(int i=0;i<step && head != nullptr;i++)
        {
            head = head->next;
        }
        return head;
    }
    ListNode* mergeSort1(ListNode* head1,ListNode* head2,ListNode* &end)
    {
        if(head1 == nullptr)
        {
            return head2;
        }
        if(head2 == nullptr)
        {
            return head1;
        }
        ListNode* head = nullptr;
        if(head1->val > head2->val)
        {
            head = head2;
            head2 = head2->next;
        }
        else
        {
            head = head1;
            head1 = head1->next;
        }
        ListNode* cur = head;
    
        while (head1 != nullptr && head2 != nullptr)
        {
            if(head1->val > head2->val)
            {
                cur->next = head2;
                head2 = head2->next;
            }
            else
            {
                cur->next = head1;
                head1 = head1->next;
            }
            cur = cur->next;
        }
        cur->next = head1 == nullptr?head2:head1;
        while(cur->next != nullptr)
        {
            cur = cur->next;
        }
        end = cur;
        return head;
    }

    ListNode* sortList1(ListNode* head) 
    {
        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }
        int len = 0;
        ListNode* cur = head;
        while (cur != nullptr)
        {
            len++;
            cur = cur->next;
        }
        for(int step = 1;step<=len;step *=2)
        {
            ListNode* end = nullptr;
            ListNode* cur = head;
            ListNode* cur1 = nullptr;
            cur = move_Node(cur,step);
            ListNode* list1 = split(head,step);
            cur1 = move_Node(cur,step);
            ListNode* list2 = split(cur,step);
            head = mergeSort1(list1,list2,end);
            while(cur != nullptr && cur1 != nullptr)
            {
                cur = move_Node(cur1,step);
                list1 = split(cur1,step);
                cur1 = move_Node(cur,step);
                list2 = split(cur,step);
                ListNode* end1 = nullptr;
                ListNode* tmp = mergeSort1(list1,list2,end1);
                end->next = tmp;
                end = end1;
            }
        }
        return head;
    }
    //优化后split调用
    ListNode* sortList2(ListNode* head) 
    {
        if(head == nullptr || head->next == nullptr)
        {
            return head;
        }
        int len = 0;
        ListNode* cur = head;
        while (cur != nullptr)
        {
            len++;
            cur = cur->next;
        }
        for(int step = 1;step<=len;step *=2)
        {
            ListNode* end = nullptr;
            ListNode* cur = head;
            ListNode* cur1 = nullptr;
            ListNode* list1 = split(cur,cur1,step);
            ListNode* list2 = split(cur1,cur,step);
            head = mergeSort1(list1,list2,end);
            while (cur != nullptr && cur1 != nullptr)
            {
                list1 = split(cur,cur1,step);
                list2 = split(cur1,cur,step);
                ListNode* end1 = nullptr;
                end->next = mergeSort1(list1,list2,end1);
                end = end1;
            }            
        }
        return head;
    }
};



int main()
{
    SolutionA a;
    ListNode* L5 = new ListNode(0);
    ListNode* L4 = new ListNode(4,L5);
    ListNode* L3 = new ListNode(3,L4);
    ListNode* L2 = new ListNode(5,L3);
    ListNode* L1 = new ListNode(-1,L2);
    ListNode* head1 = L1;
    while (head1 != nullptr)
    {
        cout<<head1->val<<" ";
        head1 = head1->next;
    }
    cout<<"\n";
    ListNode* head = a.sortList2(L1);
    while (head != nullptr)
    {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<"\n";
    delete L1;
    delete L2;
    delete L3;
    delete L4;
    return 0;
}