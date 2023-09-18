#include <iostream>
using namespace std;
int lowbit(int x) {
    return x & -x;
}
int main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        int c = 0;
        int lx = lowbit(x);
        while (lx) {
            c++;
            x &= ~lx;
            lx = lowbit(x);
        }
        cout << c << " ";
    }
    return 0;
}