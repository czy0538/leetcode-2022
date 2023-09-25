#include <iostream>
using namespace std;
constexpr int N = 1e5 + 10;

int head = 0, idx = 0;
int q[N];

int main() {
    int n;
    cin >> n;
    while (n--) {
        string op;
        cin >> op;
        if (op == "push") {
            int x;
            cin >> x;
            q[idx++] = x;
        } else if (op == "pop") {
            head++;
        } else if (op == "empty") {
            cout << (head == idx ? "YES" : "NO") << endl;
        } else if (op == "query") {
            cout << q[head] << endl;
        }
    }
    return 0;
}