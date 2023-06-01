#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

// 不使用高级数据结构的方法，能出来但是效率很低。而且如果不做剪枝的话会超时。

// class Solution {
// public:
//     vector<string> path;
//     vector<string> result;
//     bool used[300] = {};
//     vector<string> findItinerary(vector<vector<string>>& tickets) {
//         if (tickets.size() == 1) {
//             return tickets.front();
//         }
//         sort(tickets.begin(), tickets.end(), [](auto a, auto b) -> bool {
//             if (a[0] == b[0]) {
//                 return a[1] < b[1];
//             }
//             return a[0] < b[0];
//         });

//         for (int i = 0; i < tickets.size(); i++) {
//             if (tickets[i][0] == "JFK") {
//                 path.push_back("JFK");
//                 path.push_back(tickets[i][1]);
//                 used[i] = true;
//                 backtracing(tickets);
//                 if (!result.empty()) {
//                     return result;
//                 }
//                 path.clear();
//                 used[i] = false;
//             }
//         }
//         return result;
//     }
//     // 因为只需要找一个路径，因此这里为 bool 提前结束。
//     bool backtracing(const vector<vector<string>>& tickets) {
//         for (int i = 0; i < tickets.size() && tickets[i][0] <= path.back(); i++) {
//             if (used[i] == false && path.back() == tickets[i][0]) {
//                 path.push_back(tickets[i][1]);
//                 used[i] = true;
//                 if (path.size() == tickets.size() + 1) {
//                     result = path;
//                     return true;
//                 }

//                 if (backtracing(tickets) == true) {
//                     return true;
//                 }
//                 path.pop_back();
//                 used[i] = false;
//             }
//         }
//         return false;
//     }
// };

// 这个方法的优点在于大大的减少了查找的时间

class Solution {
public:
    vector<string> result;
    map<string, map<string, int>> routes;
    int size;
    vector<string> findItinerary(vector<vector<string>> &tickets) {
        size = tickets.size();
        for (auto &t : tickets) {
            routes[t[0]][t[1]]++;
        }
        result.push_back("JFK");
        backtracing();
        return result;
    }

    bool backtracing() {
        if (result.size() == size + 1) {
            return true;
        }
        for (auto &i : routes[result.back()]) {
            if (i.second > 0) {
                i.second--;
                result.push_back(i.first);
                if (backtracing()) {
                    return true;
                }
                result.pop_back();
                i.second++;
            }
        }
        return false;
    }
};