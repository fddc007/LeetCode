#include<iostream>
#include<queue>

using namespace std;


class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty())
        {
            maxHeap.push(num);
            return ;
        }
        //保证一边一半,长度相差不能1,左边的为大根堆,右边位小根堆
        if(num > maxHeap.top())
        {
            minHeap.push(num);
        }
        else
        {
            maxHeap.push(num);
        }
        int minLen = minHeap.size();
        int maxLen = maxHeap.size();
        //如果超过1,则进行调整
        if(abs(minLen -maxLen)>1)
        {
            if(minLen > maxLen)
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            else
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }
    }
    
    double findMedian() {
        if(minHeap.size() == maxHeap.size())
        {
            return ((minHeap.top()+maxHeap.top())/2.0);
        }
        else
        {
            return minHeap.size()>maxHeap.size()?minHeap.top():maxHeap.top();
        }
    }
private:
    priority_queue<int,vector<int>,greater<int>> minHeap;
    priority_queue<int> maxHeap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


 int main()
 {
    system("chcp 65001 > nul");
    MedianFinder* medianFinder = new MedianFinder();
    medianFinder->addNum(-1);
    cout<<"中位数"<<medianFinder->findMedian()<<"\n";
    medianFinder->addNum(-2);
    cout<<"中位数"<<medianFinder->findMedian()<<"\n";
    medianFinder->addNum(-3);
    cout<<"中位数"<<medianFinder->findMedian()<<"\n";
    medianFinder->addNum(-4);
    cout<<"中位数"<<medianFinder->findMedian()<<"\n";
    medianFinder->addNum(-5);
    cout<<"中位数"<<medianFinder->findMedian()<<"\n";
    return 0;
 }