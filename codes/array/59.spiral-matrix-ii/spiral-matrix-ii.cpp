#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int startx = 0, starty = 0; // start position of each loop
        int loop = n / 2; // 控制循环次数
        int offset = 1; // border control
        int count = 1;

        // 注意数组ans[y][x]，即第一个是控制列的，第二个才是控制行的
        while (loop--) {
            int i, j;
            for (i = startx; i < n - offset; i++) {
                ans[starty][i] = count++;
            }
            for (j = starty; j < n - offset; j++) {
                ans[j][i] = count++;
            }
            for (; i > startx;i--) {
                ans[j][i] = count++;
            }
            for (; j > starty; j--) {
                ans[j][i] = count++;
            }
            offset++;
            startx += 1;
            starty += 1;
        }
        // 奇数情况需要补上中间的元素
        if(n%2!=0){
            ans[starty][startx] = count;
        }

        return ans;
    }
};