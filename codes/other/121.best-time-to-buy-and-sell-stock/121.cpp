class Solution {
public:
    vector<int> s;
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for (const auto& i : prices) {
            if (!s.empty() && i <= s.back()) {
                if (s.size() > 1) {
                    ans = max(ans, s.back() - s.front());
                }
                while (!s.empty() && i <= s.back()) {
                    s.pop_back();
                }
            }
            s.push_back(i);
        }
        if (s.size() > 1) {
            ans = max(ans, s.back() - s.front());
        }
        return ans;
    }
};