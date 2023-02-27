#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto c : s)
            // 如果c是 ({[ 则入栈
            if (c == '(' || c == '{' || c == '[') stk.push(c);
            // 如果c是 )}] 并且栈不为空 则 判断栈顶是否为与之对应的左括号 是则出栈，不是则返回fasle
            else if (c == ')' && !stk.empty() && stk.top() == '(') {
                stk.pop();
            } else if (c == '}' && !stk.empty() && stk.top() == '{') {
                stk.pop();
            } else if (c == ']' && !stk.empty() && stk.top() == '[') {
                stk.pop();
            } else {
                // 如果c是 )}] 栈为空 那么返回false
                // 如果c是 )}] 栈不为空， 但是 栈顶不是与c对应的左括号 那么返回false
                return false;
            }
        // 例如"(){}[" ， 如果最后栈不为空，那么就是有多余的左括号了
        return stk.empty();
    }
};
