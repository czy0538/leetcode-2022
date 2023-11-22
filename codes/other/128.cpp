class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> h;
        for (const auto& i : nums) {
            h.insert(i);
        }
        int ans = 0;

        for (auto i = 0; i < nums.size(); i++) {
            int tmp = 0;
            auto t = nums[i];
            while (h.find(t) != h.end()) {
                h.erase(t);
                t++;
                tmp++;
            }
            t = nums[i] - 1;
            while (h.find(t) != h.end()) {
                h.erase(t);
                t--;
                tmp++;
            }
            ans = max(ans, tmp);
        }
        return ans;
    }
};