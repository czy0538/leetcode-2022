#include <iostream>
#include <vector>
using namespace std;

// 没有剪枝的版本
// class Solution {
// public:
//     vector<vector<int>> result;
//     vector<int> path;
//     vector<vector<int>> combine(int n, int k) {
//         backtracing(1, n, k);
//         return result;
//     }
//     void backtracing(int beg, int n, int k) {
//         if (k == 0) {
//             result.push_back(path);
//             return;
//         }
//         for (int i = beg; i <= n; i++) {
//             path.push_back(i);
//             backtracing(i + 1, n, k - 1);
//             path.pop_back();
//         }
//     }
// };

// 剪枝版本
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    vector<vector<int>> combine(int n, int k) {
        backtracing(1, n, k);
        return result;
    }
    void backtracing(int beg, int n, int k) {
        if (k == 0) {
            result.push_back(path);
            return;
        }
        for (int i = beg; i <= n && (n - i + 1) >= k; i++) {
            path.push_back(i);
            backtracing(i + 1, n, k - 1);
            path.pop_back();
        }
    }
};
