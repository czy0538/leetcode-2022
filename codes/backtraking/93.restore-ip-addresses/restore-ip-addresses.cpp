#include <string>
#include <vector>
using namespace std;
class Solution {
    vector<string> result;
    string path;
    using sit = string::const_iterator;

public:
    vector<string> restoreIpAddresses(string s) {
        backtracing(s.cbegin(), s.cend(), 4);
        return result;
    }
    void backtracing(sit beg, sit end, int layer) {
        if (layer == 0) {
            if (beg == end) {
                result.push_back(path);
                // remove the last '.' in result, can't do it in path.
                result.back().pop_back();
            }
            return;

        } else if (end - beg < layer) {
            return;
        }

        for (int i = 1; i <= 3 && beg + i <= end; i++) {
            auto cur = string(beg, beg + i);
            // judge cur is valid
            if (cur.front() == '0' && cur.size() > 1) {
                return;
            }
            int num = 0;
            for (int j = 0; j < cur.size(); ++j) {
                if (isdigit(cur[j])) {
                    num = num * 10 + cur[j] - '0';
                }
            }
            if (num > 255) {
                return;
            }
            path.append(cur);
            path.push_back('.');
            backtracing(beg + i, end, layer - 1);
            path = path.substr(0, path.size() - cur.size() - 1);
        }
    }
};