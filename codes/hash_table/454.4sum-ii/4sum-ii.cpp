#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
// 时间和空间负责度均为O(n2)
// 这个题是通过空间换时间的一种方法

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> dict;
        int count = 0;
        for (const auto& a : nums1) {
            for (const auto& b : nums2) {
                dict[a + b]++;
            }
        }

        for(const auto&c :nums3){
            for(const auto&d :nums4){
                auto iter = dict.find(-(c + d));
                if (iter!= dict.end()) {
                    count += iter->second;
                }
            }
        }
        return count;
    }
};