#include "ListNode.h"
#include <unordered_set>
using namespace std;

// 最笨的做法
// 时间复杂度和空间复杂度均为O(n)
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         unordered_set<ListNode *> s;
//         auto ptr = head;
//         while (ptr != nullptr) {
//             if (s.count(ptr)!=0) {
//                 return true;
//             }
//             s.insert(ptr);
//             ptr = ptr->next;
//         }
//         return false;
//     }
// };

// 快慢指针法，空间复杂度为O(1)，时间复杂度为O(Cn),C是一个常数
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         auto slow = head, fast = head;
//         while(true){
//             if(fast==nullptr){
//                 return false;
//             }
//             fast = fast->next;
//             if (fast == nullptr) {
//                 return false;
//             }
//             fast = fast->next;
//             slow = slow->next;
//             if(fast==slow){
//                 return true;
//             }
//         }
//     }
// };

// 精简下代码的结构
class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto slow = head, fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};