#include <queue>
using namespace std;
class MyStack {
public:
    MyStack() {
    }

    void push(int x) {
        q1.push(x);
    }

    int pop() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        if (q1.size() == 1) {
            auto ret = q1.front();
            q1.pop();
            return ret;
        }
        while (q2.size() > 1) {
            q1.push(q2.front());
            q2.pop();
        }
        auto ret = q2.front();
        q2.pop();
        return ret;
    }

    int top() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        if (q1.size() == 1) {
            return q1.front();
        }
        while (q2.size() > 1) {
            q1.push(q2.front());
            q2.pop();
        }
        auto ret = q2.front();
        q1.push(ret);
        q2.pop();
        return ret;
    }

    bool empty() {
        return q1.empty() && q2.empty();
    }

private:
    queue<int> q1, q2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */