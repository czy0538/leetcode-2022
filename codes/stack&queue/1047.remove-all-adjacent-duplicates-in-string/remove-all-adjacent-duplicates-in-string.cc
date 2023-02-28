#include <stack>
#include <string>

using namespace std;
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for (auto i = s.cbegin(); i < s.cend(); i++) {
            if (st.empty()) {
                st.push(*i);
                continue;
            }
            if (st.top() == *i) {
                st.pop();
            } else {
                st.push(*i);
            }
        }
        s.resize(st.size());
        for (auto i = s.rbegin(); i < s.rend(); i++) {
            *i = st.top();
            st.pop();
        }
        return s;
    }
};