#include <vector>
using namespace std;

pair<int, int> operator++(pair<int, int> &raw, int) {
    auto temp = raw;
    if (++raw.second == 9) {
        raw.first++;
        raw.second = 0;
    }
    return temp;
}

class Solution {
public:
    void solveSudoku(vector<vector<char>> &board) {
        backtracing(pair<int, int>{0, 0}, board);
    }

    bool isValid(pair<int, int> pos, char val, const vector<vector<char>> &board) {
        for (int i = 0; i < 9; i++) {
            if (val == board[pos.first][i] || val == board[i][pos.second]) {
                return false;
            }
        }

        int startRow = pos.first / 3 * 3;
        int startCol = pos.second / 3 * 3;
        for (int i = startRow; i < startRow + 3; ++i) {
            for (int j = startCol; j < startCol + 3; ++j) {
                if (val == board[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool backtracing(pair<int, int> pos, vector<vector<char>> &board) {
        for (auto i = pos; i.first < 9; i++) {
            if (board[i.first][i.second] != '.') {
                continue;
            }
            auto next = i;
            next++;
            for (auto k = '1'; k <= '9'; k++) {
                if (isValid(i, k, board)) {
                    board[i.first][i.second] = k;
                    if (backtracing(next, board)) {
                        return true;
                    }
                    board[i.first][i.second] = '.';
                }
            }
            return false;
        }
        return true;
    }
};
