#include <iostream>
#include <stack>
using namespace std;
int main() {
    stack<int> s;
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        while (!s.empty() && s.top() >= x) {
            s.pop();
        }
        if (s.empty()) {
            cout << "-1 ";
        } else {
            cout << s.top() << " ";
        }
        s.push(x);
    }
    return 0;
}