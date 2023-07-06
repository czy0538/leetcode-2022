#include <vector>
#include <cstdio>
using namespace std;
int main() {
    int n, q, target;
    scanf("%d %d", &n, &q);
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    for (int i = 0; i < q; i++) {
        scanf("%d", &target);
        int left = -1;
        int mid, l = 0, r = n - 1;
        while (l < r) {
            mid = l + r >> 1;
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if(nums[l]!=target){
            printf("-1 -1\n");
        }
        left = l;
        r = n - 1;
        while (l < r) {
            mid = l + r + 1 >> 1;
            if (nums[mid] <= target) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        printf("%d %d\n", left, l);
    }
}