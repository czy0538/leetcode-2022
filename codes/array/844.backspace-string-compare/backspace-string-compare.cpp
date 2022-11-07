#include <string>
#include <stack>
using namespace std;
// stack 方法
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> ss, ts;
        for (const auto& i : s) {
            if (i == '#') {
                if (!ss.empty()) {
                    ss.pop();
                }
            } else {
                ss.push(i);
            }
        }
        for (const auto& i : t) {
            if (i == '#') {
                if (!ts.empty()) {
                    ts.pop();
                }
            } else {
                ts.push(i);
            }
        }

        if(ss.size()!=ts.size()){
            return false;
        }

        while(!ss.empty()){
            if(ss.top()!=ts.top()){
                return false;
            }
            ss.pop();
            ts.pop();
        }
        return true;
    }
};