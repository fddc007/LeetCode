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
    
    int get(int key)
    {
        auto i = map.find(key);
        
        if(i == map.end())
        {
            return -1;
        }
        if(i->second == end)
        {
            return i->second->value;
        }
        //调整节点,需要先删除,再插入到末尾
        if(i->second->pre != nullptr)
        {
            i->second->pre->next = i->second->next;
        }
        else
        {
            head = i->second->next;
        }
        if(i->second->next != nullptr)
        {
            i->second->next->pre = i->second->pre;
        }
        i->second->pre = end;
        i->second->next = end->next;
        end->next = i->second;
        end = i->second;
        return i->second->value;
    }
    
    void put(int key, int value)
    {
        ListNode* tmp= new ListNode(key,value);
        if(map.empty())
        {
            head = tmp;
            end = tmp;
            map.insert({key,tmp});
            size++;
            return ;
        }
        unordered_map<int,ListNode*>::iterator i = map.find(key);
        //如果存在则更新值,并且插入到末尾
        if(i != map.end())
        {
            if(end == i->second)
            {
                i->second->value = value;
                delete tmp;
                return ;
            }
            if(i->second->pre != nullptr)
            {
                i->second->pre->next = i->second->next;
            }
            else
            {
                head = i->second->next;
            }
            if(i->second->next != nullptr)
            {
                i->second->next->pre = i->second->pre;
            }
            i->second->value = value;
            i->second->pre = end;
            i->second->next = end->next;
            end->next = i->second;
            end = i->second;
            delete tmp;
        }
        //不存在,则插入,如果满了,则删除头元素
        else
        {
            if(capacity == 1)
            {
                ListNode* cur = head;
                map.erase(cur->key);
                delete cur;
                head = tmp;
                end = tmp;
                map.insert({key,tmp});
                return ;
            }
            if(size == capacity)
            {
                //删除头结点
                ListNode* cur = head;
                head = head->next;
                head->pre = cur->pre;
                map.erase(cur->key);
                delete cur;
                size--;
            }
            //将节点插入到链表尾端
            tmp->pre = end;
            tmp->next = end->next;
            end->next = tmp;
            end = tmp;                
            //加入到集合中
            map.insert({key,tmp});
            size++;
        }
    }
private:
    struct ListNode
    {
        ListNode(int key)
        {
            this->key = key;
            this->value = -1;
            pre = nullptr;
            next = nullptr;
        }
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
    unordered_map<int,ListNode*> map;
    ListNode* head;
    ListNode* end;
    int capacity;
    int size;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

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
    // l1.put(3,3);
    // l1.get(2);
    // cout<<"键值2的值为:"<<l1.get(2)<<"\n";
    // l1.put(4,4);
    // l1.get(1);
    // cout<<"键值1的值为:"<<l1.get(1)<<"\n";
    // l1.get(3);
    // cout<<"键值3的值为:"<<l1.get(3)<<"\n";
    // l1.get(4);
    // cout<<"键值4的值为:"<<l1.get(4)<<"\n";
    return 0;
}