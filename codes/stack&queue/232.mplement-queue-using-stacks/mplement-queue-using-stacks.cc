#include <stack>
using namespace std;
// class MyQueue {
// public:
//     MyQueue() {

//     }

//     void push(int x) {
//         while(!dsout.empty()){
//             dsin.push(dsout.top());
//             dsout.pop();
//         }
//         dsin.push(x);
//         while(!dsin.empty()){
//             dsout.push(dsin.top());
//             dsin.pop();
//         }
//     }

//     int pop() {
//         auto ret = dsout.top();
//         dsout.pop();
//         return ret;
//     }

//     int peek() {
//         return dsout.top();
//     }

//     bool empty() {
//         return dsout.empty();
//     }

// private:
//     stack<int> dsin, dsout;
// };

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

class MyQueue {
public:
    MyQueue() {
    }

    void push(int x) {
        stin.push(x);
    }

    int pop() {
        int ret = peek();
        stout.pop();
        return ret;
    }

    int peek() {
        if(!stout.empty()){
            return stout.top();
        }
        while(!stin.empty()){
            stout.push(stin.top());
            stin.pop();
        }
        return stout.top();
    }

    bool empty() {
        return stin.empty() && stout.empty();
    }

    private:
        stack<int> stin, stout;
};
