#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        for (auto i = 0; i < s.size(); i += 2 * k) {
            auto t = min(i + k , static_cast<int>(s.size()));
            reverse(s.begin() + i, s.begin() + t);
        }
        return s;
    }
};