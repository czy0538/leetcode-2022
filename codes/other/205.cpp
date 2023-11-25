#include <iostream>
#include <string>
#include <iostream>
using namespace std;
// 注意，该题满足 s[i]->t[i],t[i]->s[i]映射唯一即可
// 而不是说 s[i]<->t[i]
// 如 er，le；e->l,l->e;r->l,e->r 也是可以的
// 但是 e->{l,r} 就是不可以的了
class Solution {
public:
    unordered_map<char, char> s2t;
    unordered_map<char, char> t2s;
    bool isIsomorphic(string s, string t) {
        for (int i = 0; i < s.size(); i++) {
            auto is = s2t.find(s[i]);
            auto it = t2s.find(t[i]);
            if ((is != s2t.end() && is->second != t[i]) || (it != t2s.end() && it->second != s[i])) {
                return false;
            }
            s2t[s[i]] = t[i];
            t2s[t[i]] = s[i];
        }
        return true;
    }
};