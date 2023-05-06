#include <vector>
#include <string>
using namespace std;
class Solution {
    vector<vector<string>> result;
    vector<string> path;

public:
    vector<vector<string>> partition(string s) {
        backtracing(0, s);
        return result;
    }

    void backtracing(int beg, const string &s) {
        if (beg >= s.size()) {
            result.push_back(path);
            return;
        }
        // i is length but offset
        for (int i = 1; beg + i <= s.size(); i++) {
            // cur=s[beg:beg+i-1]
            auto cur = s.substr(beg, i);
            if (isPalindrome(cur)) {
                path.push_back(cur);
                backtracing(beg + i, s);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(const string &s) {
        for (auto i = s.cbegin(), j = s.cend() - 1; i < j; i++, j--) {
            if (*i != *j) {
                return false;
            }
        }
        return true;
    }
};