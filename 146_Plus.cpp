#include<iostream>
#include<unordered_map>

using namespace std;




class LRUCache {
public:    

    LRUCache(int capacity)
    {
        size = 0;
        head = nullptr;
        end = nullptr;
        this->capacity = capacity;
    }

    ~LRUCache()
    {
        while(head != nullptr)
        {
            end = head->next;
            delete head;
            head = end;
        }
    }
        struct ListNode
    {
        ListNode(int key,int value)
        {
            this->key = key;
            this->value = value;
            pre = nullptr;
            next = nullptr;
        }
        int key;
        int value;
        ListNode* pre;
        ListNode* next;
    };

    void addNode(ListNode* node)
    {
        if(head == nullptr)
        {
            head =node;
            end = node;
        }
        else
        {
            end->next = node;
            node->pre = end;
            node->next = nullptr;
            end = node;
        }
    }


    void moveNodeToTail(ListNode* node)
    {
        if(node == end)
        {
            return ;
        }
        if(head == node)
        {
            head = node->next;
            head->pre = node->pre;
        }
        else
        {
            node->pre->next = node->next;
            node->next->pre = node->pre;
        }
        end->next = node;
        node->pre = end;
        node->next = nullptr;
        end = node;
    }
    

    ListNode* removeHead()
    {
        if(head==nullptr)
        {
            return nullptr;
        }
        ListNode* tmp = head;
        if(head == end)
        {
            head = nullptr;
            end = nullptr;
        }
        else
        {
            head = head->next;
            head->pre = nullptr;
            tmp->next = nullptr;
        }
        return tmp;
    }
    int get(int key)
    {
        //查询key是否在map里面
        auto cur = map.find(key);
        //不在返回-1;
        if(cur == map.end())
        {
            return -1;
        }
        moveNodeToTail(cur->second);
        return cur->second->value;
    }
    
    void put(int key, int value)
    {
        auto i = map.find(key);
        if(i != map.end())
        {
            i->second->value = value;
            moveNodeToTail(i->second);
        }
        else
        {
            if(capacity == size)
            {
                ListNode* tmp = removeHead();
                map.erase(tmp->key);
                delete tmp;
                size--;
            }
            ListNode* cur = new ListNode(key,value);
            addNode(cur);
            map.insert({key,cur});
            size++;
        }
    }

private:    

    unordered_map<int,ListNode*> map;
    ListNode* head;
    ListNode* end;
    int capacity;
    int size;
};


int main()
{
    system("chcp 65001 > nul");
    LRUCache l1(2);
    l1.put(2,1);
    l1.put(3,2);
    cout<<"键值3的值为:"<<l1.get(3)<<"\n";
    cout<<"键值2的值为:"<<l1.get(2)<<"\n";
    l1.put(4,3);
    cout<<"键值2的值为:"<<l1.get(2)<<"\n";
    cout<<"键值4的值为:"<<l1.get(3)<<"\n";
    cout<<"键值4的值为:"<<l1.get(4)<<"\n";
    return 0;
}