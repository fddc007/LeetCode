#include<iostream>
#include<vector>
#include<queue>
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
struct cmp
{
    bool operator()(ListNode* a,ListNode* b)
    {
        return a->val >b->val;
    }
};
class Solution 
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
        ListNode* head = nullptr;
        ListNode* cur = nullptr;
        //将每个链表的首元素建立一个小根堆
        for(ListNode* i:lists)
        {
            if(nullptr != i)
            {
                pq.push(i);
            }
        }
        if(pq.empty())
        {
            return head;
        }
        //head = cur = pq.top();
        //pq.pop();
        //如果将最小的元素加入head链表中,并且删除原有的根节点
        while (!pq.empty())
        {
            /*
            if(nullptr!= cur->next)
            {
                pq.push(cur->next);
            }
            cur->next = pq.top();
            cur = cur->next;
            pq.pop();  
            
            */
            if(nullptr == head)
            {
                head = pq.top();
                cur = head;
                pq.pop();
                if(nullptr!= cur->next)
                {
                    pq.push(cur->next);
                }
                cur->next = nullptr;
                continue;
            }
            cur->next = pq.top();
            cur = cur->next;
            pq.pop();                
            if(nullptr!= cur->next)
            {
                pq.push(cur->next);
            }
            cur->next = nullptr;
        }
        return head;
    }
};

int main()
{
    ListNode* l8 = new ListNode(6,nullptr);
    ListNode* l7 = new ListNode(2,l8);
    ListNode* l6 = new ListNode(4,nullptr);
    ListNode* l5 = new ListNode(3,l6);
    ListNode* l4 = new ListNode(1,l5);
    ListNode* l3 = new ListNode(5,nullptr);
    ListNode* l2 = new ListNode(4,l3);
    ListNode* l1 = new ListNode(1,l2);
    vector<ListNode*> lists = {l1,l4,l7};
    Solution a;
    // ListNode* tmp = a.mergeKLists(lists);
    vector<ListNode*> lists2 = {};
    ListNode* tmp = a.mergeKLists(lists2);
    while(nullptr != tmp)
    {
        cout<<tmp->val <<" ";
        tmp = tmp->next;
    }
    cout<<"\n";
    return 0;
}