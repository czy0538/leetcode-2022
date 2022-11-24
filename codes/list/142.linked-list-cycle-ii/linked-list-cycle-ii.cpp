#include "ListNode.h"
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        auto slow = head, fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                goto CYCLED;
            }
        }
        return nullptr;
    CYCLED:
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};