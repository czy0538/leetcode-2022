#include <vector>
#include <stack>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

// class Solution {
// public:
//     stack<int> s;
//     int evalRPN(vector<string>& tokens) {
//         int a, b;
//         for (const auto& c : tokens) {
//             switch (c[0]) {
//             case '+':
//                 pop_2_nums(a, b);
//                 s.push(a + b);
//                 break;
//             case '-':
//                 if (c.size() > 1) {
//                     s.push(atoi(c.c_str()));
//                     break;
//                 }
//                 pop_2_nums(a, b);
//                 s.push(b - a);
//                 break;
//             case '*':
//                 pop_2_nums(a, b);
//                 s.push(a * b);
//                 break;
//             case '/':
//                 pop_2_nums(a, b);
//                 s.push(b / a);
//                 break;
//             default:
//                 s.push(atoi(c.c_str()));
//                 break;
//             }
//         }
//         return s.top();
//     }
//     void pop_2_nums(int& a, int& b) {
//         a = s.top();
//         s.pop();
//         b = s.top();
//         s.pop();
//     }
// };

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                long long num1 = st.top();
                st.pop();
                long long num2 = st.top();
                st.pop();
                if (tokens[i] == "+") st.push(num2 + num1);
                if (tokens[i] == "-") st.push(num2 - num1);
                if (tokens[i] == "*") st.push(num2 * num1);
                if (tokens[i] == "/") st.push(num2 / num1);
            } else {
                st.push(stoll(tokens[i]));
            }
        }

        int result = st.top();
        st.pop(); // 把栈里最后一个元素弹出（其实不弹出也没事）
        return result;
    }
};
