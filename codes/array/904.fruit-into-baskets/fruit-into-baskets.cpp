// map与unordered_map选择指南
// https://zhuanlan.zhihu.com/p/48066839
// 在需要有序性或者对单次查询有时间要求的应用场景下，应使用map，其余情况应使用unordered_map。
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> backet;
        auto i = fruits.begin(), j = fruits.begin();
        decltype(fruits.size()) size = 0;
        while (j != fruits.end()) {
            // if (backet.find(*j) == backet.end()) {
            //     backet[*(j++)] = 1;
            // } else {
            //     backet[*(j++)]++;
            // }
            backet[*(j++)]++; // c++里面value貌似也直接按照0值了
            while (backet.size() > 2) {
                if (j - i > size) {
                    size = j - i - 1; // 注意这里的j已经完成++了，因此要再减去一个1
                }
                if (--backet[*i] == 0) {
                    backet.erase(*i);
                }
                i++;
            }
        }
        if (j - i > size) {
            size = j - i;
        }
        return size;
    }
};