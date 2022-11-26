#include <string>
#include <algorithm>
#include <unordered_map>
#include <array>
using namespace std;

// 方法1：排序然后逐个比较
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if (s.size() != t.size()) {
//             return false;
//         }
//         sort(s.begin(), s.end());
//         sort(t.begin(), t.end());
//         for (auto sb = s.cbegin(), tb = t.cbegin(); sb != s.cend(); sb++, tb++) {
//             if (*sb!=*tb){
//                 return false;
//             }
//         }
//         return true;
//     }
// };

// 方法2 哈希表
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if (s.size() != t.size()) {
//             return false;
//         }
//         unordered_map<char, int> dict;
//         for (const auto &i : s) {
//             dict[i]++;
//         }
//         for (const auto &i : t) {
//             auto iter = dict.find(i);
//             if (iter == dict.end()) {
//                 return false;
//             } else {
//                 iter->second--;
//                 if (iter->second == 0) {
//                     dict.erase(iter);
//                 }
//             }
//         }
//         return true;
//     }
// };

// 方法3 土哈希表（数组）
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        array<int, 26> dict;
        for (const auto& i : s) {
            dict[i - 'a']++;
        }
        for (const auto& i : t) {
            if (--dict[i - 'a']<0) {
                return false;
            }
        }
        return true;
    }
};