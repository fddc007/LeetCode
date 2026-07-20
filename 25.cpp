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
    ListNode* reverseList(ListNode* head,ListNode* &end)
    {
        end = head;
        ListNode* tmp = nullptr;
        ListNode* cur = nullptr;
        while (head != nullptr)
        {
            cur = head;
            head = head->next;
            cur->next = tmp;
            tmp = cur;
        }
        return cur;
    }

    ListNode* find_next_head(ListNode* head,int k,int &sit)
    {
        if(head == nullptr)
        {
            return head;
        }
        ListNode* tmp = nullptr;
        while(k>0 && head != nullptr)
        {
            sit++;
            tmp = head;
            head = head->next;
            k--;
        }
        tmp->next = nullptr;
        return head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int sit = 0;
        ListNode* next_head = nullptr;
        next_head = find_next_head(head,k,sit);
        ListNode* ret =head;
        ListNode* end = nullptr;
        ListNode* tmp_end = nullptr;
        ListNode* tmp_head = head;
        ret = reverseList(tmp_head,tmp_end);
        end = tmp_end;
        while(next_head != nullptr)
        {
            sit = 0;
            tmp_head = next_head;
            next_head = find_next_head(next_head,k,sit);
            if(next_head == nullptr && sit<k)
            {
                end->next = tmp_head;
                break;
            }
            tmp_head = reverseList(tmp_head,tmp_end);
            end->next = tmp_head;
            end = tmp_end;
        }
        return ret;
    }
};



class SolutionA
{
public:
    //找到此次翻转的尾节点,这是翻转后的头结点
    ListNode* find(ListNode* head,int k)
    {
        while(k>1&&head != nullptr)
        {
            head = head->next;
            k--;
        }
        return head;
    }
    //翻转链表,并链接到原链表中
    void reverseList(ListNode* head,ListNode* end)
    {
        end = end->next;
        ListNode* pre,*cur,*last;
        cur = head;
        last = head->next;
        while(last != end)
        {
            pre = cur;
            cur = last;
            last = last->next;
            cur->next = pre;
        }
        head->next = end;
    }
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        //初始处理,获取头结点
        if(head == nullptr ||head->next == nullptr)
        {
            return head;
        }
        ListNode* ret = nullptr;
        ListNode* end = nullptr;
        end = find(head,k);
        //如果需要处理范围内的尾节点为空,则说明处理长度不够,直接返回
        if(end == nullptr)
        {
            return head;
        }
        ret = end;
        reverseList(head,end);
        end = head;
        ListNode* next_head =end->next;
        ListNode* tmp_end = nullptr;
        //依次处理节点
        while(next_head != nullptr)
        {
            tmp_end = find(next_head,k);
            if(tmp_end == nullptr)
            {
                return ret;
            }
            reverseList(next_head,tmp_end);
            end->next = tmp_end;
            end = next_head;
            next_head = end->next;
        }
        return ret;
    }
};

int main()
{
    ListNode* L1 = new ListNode(1);
    ListNode* L2 = new ListNode(2);
    ListNode* L3 = new ListNode(3);
    ListNode* L4 = new ListNode(4);
    ListNode* L5 = new ListNode(5);

    // L1->next = L2;
    // L2->next = L3;
    // L3->next = L4;
    // L4->next = L5;

    ListNode* tmp= L1;
    while(tmp != nullptr)
    {
        cout<<tmp->val<< ' ';
        tmp = tmp->next;
    }
    cout<<"\n";
    SolutionA a;
    tmp = a.reverseKGroup(L1,3);
    while(tmp != nullptr)
    {
        cout<<tmp->val<< ' ';
        tmp = tmp->next;
    }
    cout<<"\n";
    return 0;
}