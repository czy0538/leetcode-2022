#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

// 滑动窗口
// class Solution {
// public:
//     unordered_map<char, int> dic, cnt;
//     // 检查是否符合要求，因为可能出现有多个子字符的情况，所以要检查字符的大小
//     bool check() {
//         for (const auto& i : dic) {
//             if (i.second > cnt[i.first]) {
//                 return false;
//             }
//         }
//         return true;
//     }
//     string minWindow(string s, string t) {
//         // build character dictionary
//         for (const auto& i : t) {
//             dic[i]++;
//         }

//         int size = INT_MAX;
//         auto ans_beg = s.cend();
//         auto i = s.cbegin();
//         auto j = s.cbegin();
//         while (j != s.cend()) {
//             if (dic.find(*j) != dic.end()) {
//                 cnt[*j]++;
//             }
//             while (check() && i <= j) {
//                 if (j - i + 1 < size) {
//                     size = j - i + 1;
//                     ans_beg = i;
//                 }
//                 if (cnt.find(*i) != cnt.end()) {
//                     cnt[*i]--;
//                 }
//                 i++;
//             }
//             j++;
//         }
//         string ans;
//         if (size != INT_MAX) {
//             while (size--) {
//                 ans += *ans_beg;
//                 ans_beg++;
//             }
//         }
//         return ans;
//     }
// };

// 上面的代码是对的，但是用了太多的查找，算法太耗时了
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hs, ht;
        // 构建字典ht
        for (auto c : t) ht[c]++;
        string res;
        int cnt = 0; // 记录当前字符数
        // 滑动窗口
        for (int r = 0, l = 0; r < s.size(); r++) {
            // 空间换时间，不管是否属于字典的都存进去
            hs[s[r]]++;
            if (hs[s[r]] <= ht[s[r]]) cnt++; // 满足该条件，说明字符数目不够，所以加入字符
            // 注意这里，先对所有的字符执行了++，所以如果字典中没有的字符，则会为0，故cnt不会++
            // 而且如果在字典中的字符，假如该字符的数量超过了要求数量，也不会存入

            while (l <= r && hs[s[l]] > ht[s[l]]) hs[s[l++]]--; // 舍弃多余的字符
            if (cnt == t.size()) {
                if (res.empty() || r - l + 1 < res.size()) res = s.substr(l, r - l + 1);
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.minWindow("a", "b") << endl;
}
