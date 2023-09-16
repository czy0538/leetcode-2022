// 思路1 通过hash表记录是否出现过
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> f;
        int res = 0;
        for (int i = 0, j = 0; i < s.size(); i++) {
            while (f.find(s[i]) != f.end()) {
                f.erase(s[j]);
                j++;
            }
            res = max(i - j + 1, res);
            f.insert(s[i]);
        }
        return res;
    }
};

// 思路2 记录上次出现的位置
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> pre;
        int res = 0;
        for (int i = 0, j = 0; i < s.size(); i++) {
            if (pre.find(s[i]) != pre.end()) {
                while (j <= pre[s[i]]) {
                    pre.erase(s[j]);
                    j++;
                }
            }
            res = max(i - j + 1, res);
            pre[s[i]] = i;
        }
        return res;
    }
};