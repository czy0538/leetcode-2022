#include <vector>
#include <unordered_map>
#include <ctime>
#include <iostream>
using namespace std;

// 使用链表存储尽管能做到随便的删除
// 但是没有做到随机的访问某个元素
// 为了实现这一点，还是需要用vector

class RandomizedSet {
    vector<int> data;
    unordered_map<int, int> pos;

public:
    RandomizedSet() {
        srand(time(nullptr));
    }

    bool insert(int val) {
        auto it = pos.find(val);
        if (it != pos.end()) {
            return false;
        }
        data.push_back(val);
        pos[val] = data.size() - 1;
        return true;
    }

    bool remove(int val) {
        auto it = pos.find(val);
        if (it == pos.end()) {
            return false;
        }
        // 删除的时候把要删除的元素移动到最后的位置
        // 然后删除最后一个元素，这样就可以实现O(1)的删除了。
        data[it->second] = data.back();
        pos[data.back()] = it->second;

        data.pop_back();
        pos.erase(it);
        return true;
    }

    int getRandom() {
        return data[rand() % data.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */