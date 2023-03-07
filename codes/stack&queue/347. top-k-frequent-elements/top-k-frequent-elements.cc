#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

// 小顶堆
class mycomparison {
public:
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
        return lhs.second > rhs.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for_each(nums.begin(), nums.end(), [&](const int& num) -> void { count[num]++; });

        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pq;

        for (auto it = count.cbegin(); it != count.cend(); it++) {
            pq.push(*it);
            if (pq.size()>k){
                pq.pop();
            }
        }

        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};