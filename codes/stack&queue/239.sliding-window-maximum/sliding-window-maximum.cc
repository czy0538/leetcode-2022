#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*
 * 这个题既然是困难，那么就肯定不是常规的思路可以在规定的时间复杂度内解决的。
 * 最笨的方法例如：每次引入一个数然后排序肯定是不行的。
 * 我们可以构建一个最大值队列，这个队列中存储着当前几个元素情况下的按照值被移出的顺序的最大值。
 * 例如 1 1 3 ， 那么我们的队列值就是 3 3 3
 * 当有新的值进入时，我们与其进行比较，并且一致出队，直到找到一个比他大的，如果没有的话，那么就把该元素入队
 */

// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int> &nums, int k) {
//         queue<int> q;
//         vector<int> ans;
//         auto tk = k;
//         int b = 0;
//         while (tk) {
//             vector<int> temp(nums.begin() + b, nums.begin() + b + tk);
//             sort(temp.begin(), temp.end());
//             q.push(temp.back());
//             b++;
//             tk--;
//         }
//         ans.push_back(q.front());
//         q.pop();
//         for (int i = 1, j = i + k - 1; j < nums.size(); ++i, ++j) {
//             if (nums[j] <= q.front()) {
//                 ans.push_back(q.front());
//                 q.pop();
//             } else {
//                 ans.push_back(nums[j]);
//                 q.pop();
//             }
//             int os = 0;
//             while (q.size() > 0 && q.front() < nums[j]) {
//                 q.pop();
//                 os++;
//             }
//             while (os > 0) {
//                 q.push(nums[j]);
//                 os--;
//             }
//             q.push(nums[j]);
//         }
//         return ans;
//     }
// };

template <class T>
class SingleQueue {
private:
    deque<T> d;

public:
    void pop_front(T value) {
        if (!d.empty() && d.front() == value) {
            d.pop_front();
        }
    }
    T front() {
        return d.front();
    }

    void push(T value) {
        while (!d.empty() && d.back() < value) {
            d.pop_back();
        }
        d.push_back(value);
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        SingleQueue<int> q;
        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            q.push(nums[i]);
        }
        ans.push_back(q.front());
        for (int i = k; i < nums.size(); ++i) {
            q.pop_front(nums[i - k]);
            q.push(nums[i]);
            ans.push_back(q.front());
        }
        return ans;
    }
};