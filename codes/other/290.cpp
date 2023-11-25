#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
    unordered_map<char, string> c2s;
    unordered_map<string, char> s2c;

public:
    bool wordPattern(string pattern, string s) {
        int pos = 0;
        s.push_back(' ');
        for (int i = 0; i < pattern.size(); i++) {
            auto c = pattern[i];
            auto p = s.find(' ', pos);
            // 说明pattern比s长
            if (p == s.npos) {
                return false;
            }
            auto t = s.substr(pos, p - pos);
            pos = p + 1;
            auto it_c2s = c2s.find(c);
            auto it_s2c = s2c.find(t);
            if (it_c2s != c2s.end() && it_c2s->second != t || it_s2c != s2c.end() && it_s2c->second != c) {
                return false;
            }
            c2s[c] = t;
            s2c[t] = c;
        }
        // 说明s比pattern长
        if (pos != s.size()) {
            return false;
        }
        return true;
    }
};
