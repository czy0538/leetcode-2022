#include <stack>
#include <unordered_map>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

unordered_map<char, int> priority = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

stack<char> op;
stack<int> num;

int eval() {
    int b = num.top();
    num.pop();
    int a = num.top();
    num.pop();
    char o = op.top();
    op.pop();

    if (o == '+') {
        return a + b;
    } else if (o == '-') {
        return a - b;
    } else if (o == '*') {
        return a * b;
    } else if (o == '/') {
        return a / b;
    }
    return 0;
}

int main() {
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            int x = 0;
            while (i < s.size() && isdigit(s[i])) {
                x = x * 10 + s[i] - '0';
                i++;
            }
            num.push(x);
            i--;
        } else if (s[i] == '(') {
            op.push('(');
        } else if (s[i] == ')') {
            // 遇到右括号开始运算，直到遇到左括号
            // 遇到右括号以后，一定可以按照从右向左的顺序进行运算
            // 如果不按照这个顺序，则之前已经完成运算了，不会在栈中
            while (op.top() != '(') {
                num.push(eval());
            }
            op.pop();
        } else {
            // 处理其他符号
            while (!op.empty() && priority[op.top()] >= priority[s[i]]) {
                // 待入栈运算符优先级低，则先计算，而且要计算完全以保证顺序
                num.push(eval());
            }
            op.push(s[i]);
        }
    }
    while (!op.empty()) {
        num.push(eval());
    }
    cout << num.top();
    return 0;
}