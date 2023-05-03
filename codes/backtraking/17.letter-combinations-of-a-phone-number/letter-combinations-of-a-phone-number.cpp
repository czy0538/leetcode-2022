#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
class Solution {
    unordered_map<char, vector<char>> dict;
    string path;
    vector<string> ans;

public:
    using sit = string::iterator;

    Solution() {
        dict['2'] = vector<char>{'a', 'b', 'c'};
        dict['3'] = vector<char>{'d', 'e', 'f'};
        dict['4'] = vector<char>{'g', 'h', 'i'};
        dict['5'] = vector<char>{'j', 'k', 'l'};
        dict['6'] = vector<char>{'m', 'n', 'o'};
        dict['7'] = vector<char>{'p', 'q', 'r', 's'};
        dict['8'] = vector<char>{'t', 'u', 'v'};
        dict['9'] = vector<char>{'w', 'x', 'y', 'z'};
    }

    void backtracing(sit beg, sit end) {
        if (beg == end) {
            ans.push_back(path);
            return;
        }
        for (const auto &i : dict[*beg]) {
            path.push_back(i);
            backtracing(beg + 1, end);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return ans;
        }
        backtracing(digits.begin(), digits.end());
        return ans;
    }
};

int main() {
    Solution s;

    auto ans = s.letterCombinations("23");
    for (const auto &i : ans) {
        cout << i << endl;
    }
}