#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
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

class SingleQueue {
    deque<int> d;

public:
    void pop_front(int val) {
        if (!d.empty() && d.front() == val) {
            d.pop_front();
        }
    }
    // 核心在这里，弹出所有比加入元素小的元素，因为他们无法被输出
    void push_back(int val) {
        // 注意这里不能加入等于，否则如果有多个相同元素，会被提前弹出
        while (!d.empty() && d.back() < val) {
            d.pop_back();
        }
        d.push_back(val);
    }

    int front() {
        return d.front();
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        SingleQueue s;
        for (int i = 0; i < k; i++) {
            s.push_back(nums[i]);
        }
        ans.push_back(s.front());
        for (int i = k; i < nums.size(); i++) {
            // 首先检查被移出的元素是否是队头元素，如果是则移出。
            s.pop_front(nums[i - k]);
            s.push_back(nums[i]);
            ans.push_back(s.front());
        }
        return ans;
    }
};