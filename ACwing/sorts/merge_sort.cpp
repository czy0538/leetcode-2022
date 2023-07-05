#include <vector>
#include <cstdio>
using namespace std;
vector<int> tmp;

void merge_sort(vector<int>& nums, int l, int r) {
    if (l >= r) {
        return;
    }
    // 划分区间
    int mid = (l + r) >> 1;

    // 递归
    merge_sort(nums, l, mid);
    merge_sort(nums, mid + 1, r);

    // 合并
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (nums[i] <= nums[j]) {
            tmp[k++] = nums[i++];
        } else {
            tmp[k++] = nums[j++];
        }
    }
    while (i <= mid) {
        tmp[k++] = nums[i++];
    }
    while (j <= r) {
        tmp[k++] = nums[j++];
    }

    for (int i = l; i <= r; i++) {
        nums[i] = tmp[i];
    }
}

int main(){
    int n;
    scanf("%d", &n);
    vector<int> nums(n, 0);
    tmp.resize(n);
    for (int i = 0; i < n;i++){
        scanf("%d", &nums[i]);
    }
    merge_sort(nums, 0, n - 1);
    for(const auto&i:nums){
        printf("%d ", i);
    }
    return 0;
}