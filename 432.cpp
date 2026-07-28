#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<unordered_map>


using namespace std;


class AllOne {
private:
    struct Node
    {  
        int val;
        unordered_set<string> set;
        struct Node* pre;
        struct Node* next;
        Node(int val)
        {
            this->val = val;
            pre = nullptr;
            next = nullptr;
        }
    };
    Node* head;
    Node* end;
    unordered_map<string,Node*> map;

public:
    AllOne() 
    {
        head = new Node(0);
        end = new Node(0);
        head->next = end;
        head->pre = end;
        end->next = head;
        end->pre = head;    
    }
    ~AllOne()
    {
        while(head->next != end)
        {
            moveNode(head->next);
        }
        delete head;
        delete end;
    }

    void insertNode(Node* cur,int val)
    {
        Node* tmp = new Node(val);
        cur->next->pre = tmp;
        tmp->next = cur->next;
        cur->next = tmp;
        tmp->pre = cur;
    }

    void moveNode(Node* cur)
    {
        cur->pre->next = cur->next;
        cur->next->pre = cur->pre;
        delete cur;
    }



    //如果在map中已经存在,则桶的值加1,不存在加入桶1
    void inc(string key) 
    {
        auto tmp = map.find(key);
        if(tmp == map.end())
        {
            if(head->next->val!=1)
            {
                //没有桶,需要插入桶
                insertNode(head,1);
            }
            head->next->set.insert(key);
            map.insert({key,head->next});
        }
        else
        {
            //存在于map中,则判断右边的桶是否比自身的值大于1
            int count = tmp->second->val + 1;
            if(tmp->second->next->val != count)
            {
                insertNode(tmp->second,count);
            }
            Node* nextNode = tmp->second->next;
            nextNode->set.insert(key);
            tmp->second->set.erase(key);
            if(tmp->second->set.size()==0)
            {
                moveNode(tmp->second);
            }
            tmp->second = nextNode;
        }
    }
    
    void dec(string key) 
    {
        auto tmp = map.find(key);
        int count = tmp->second->val-1;
        if(tmp->second->pre->val != count)
        {
            insertNode(tmp->second->pre,count);
        }
        tmp->second->set.erase(key);
        Node* curNode = tmp->second;
        if(count != 0)
        {
            curNode->pre->set.insert(key);
            tmp->second = curNode->pre;
        }
        else
        {
            map.erase(key);
        }
        if(curNode->set.size()== 0)
        {
            moveNode(curNode);
        }
    }
    
    string getMaxKey() {
        return end->pre == head?"":*(end->pre->set.begin());
    }
    
    string getMinKey() {
        return head->next == end?"":*(head->next->set.begin());
    }
};


int main()
{
    AllOne a;
    a.inc("hello");
    a.inc("hello");
    cout<<a.getMaxKey()<<"\n";
    cout<<a.getMinKey()<<"\n";
    a.dec("hello");
    a.dec("hello");
    cout<<a.getMaxKey()<<"  "<<"\n";
    return 0;
}