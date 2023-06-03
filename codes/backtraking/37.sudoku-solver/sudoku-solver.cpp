#include <vector>
#include <iostream>
using namespace std;
class Solution {
    using v = vector<vector<char>>;

public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracing(pair<int, int>{0, 0}, board);
        return;
    }

    bool isValid(v& board, int row, int col, char val) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == val || board[i][col] == val) {
                return false;
            }
        }
        int startRow = row / 3 * 3, startCol = col / 3 * 3;
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == val) {
                    return false;
                }
            }
        }
        return true;
    }

    bool backtracing(pair<int, int> pos, v& board) {
        for (auto p = pos; p.first < 9; p = next(p)) {
            if (board[p.first][p.second] != '.') {
                continue;
            }

            for (char k = '1'; k <= '9'; k++) {
                if (isValid(board, p.first, p.second, k)) {
                    board[p.first][p.second] = k;
                    if (backtracing(next(p), board)) {
                        return true;
                    }
                    board[p.first][p.second] = '.';
                }
            }
            return false;
        }
        return true;
    }

    pair<int, int> next(pair<int, int> pos) {
        if (++pos.second == 9) {
            pos.second = 0;
            pos.first++;
        }
        return pos;
    }
};