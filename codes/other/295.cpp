#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

class MedianFinder {
    priority_queue<int, vector<int>, less<int>> l; // 大根堆
    priority_queue<int, vector<int>, greater<int>> r; // 小根堆

public:
    MedianFinder() {
    }

    void addNum(int num) {
        if (l.empty() || num < l.top()) {
            l.push(num);
            if (l.size() - r.size() > 1) {
                r.push(l.top());
                l.pop();
            }
        } else {
            r.push(num);
            if (r.size() > l.size()) {
                l.push(r.top());
                r.pop();
            }
        }
    }

    double findMedian() {
        if ((l.size() + r.size()) % 2) {
            return l.top();
        }
        return (l.top() + r.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */