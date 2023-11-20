#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;
class Data {
public:
    int key;
    int val;
    Data(int k, int v) : key(k), val(v) {
    }
};

class LRUCache {
private:
    int size;
    int cap;
    // 对与list，由于其底层是双链表，因此除非指向的节点本身被删除，否则不会导致迭代器失效
    // vector这种插入或者删除元素则可能导致迭代器失效
    unordered_map<int, list<Data>::iterator> k;
    list<Data> v;

public:
    // c++中的变量一定要进行初始化，否则其值不可预测
    // 多个变量的情况下，最好按照声明顺序进行列表初始化
    // 变量个数和列表中变量个数不一致，最好使用explicit关键字禁止隐式转换
    explicit LRUCache(int capacity) : size(0), cap(capacity) {
    }

    int get(int key) {
        auto it = k.find(key);
        if (it == k.end()) {
            return -1;
        }
        v.push_front(*(it->second));
        v.erase(it->second);
        it->second = v.begin();
        return v.front().val;
    }

    void put(int key, int value) {
        auto it = k.find(key);
        if (it == k.end()) {
            if (size == cap) {
                k.erase(v.back().key);
                v.pop_back();
            } else {
                size++;
            }
        } else {
            v.erase(it->second);
        }
        // 用emplace_front替代push_front可以减少头部的开销
        // push_front 先调用构造函数，再调用移动/拷贝构造函数
        // emplace_front 则是直接构造
        v.emplace_front(key, value);
        k[key] = v.begin();
    }
};
