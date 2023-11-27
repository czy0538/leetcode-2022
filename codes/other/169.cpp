class Solution {
    unordered_map<int, int> cnt;

public:
    int majorityElement(vector<int>& nums) {
        auto half = nums.size() / 2;
        for (const auto& i : nums) {
            if (++cnt[i] > half) {
                return i;
            }
        }
        return 0;
    }
};