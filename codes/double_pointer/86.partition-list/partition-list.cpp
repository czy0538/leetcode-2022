struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {
    }
    ListNode(int x) : val(x), next(nullptr) {
    }
    ListNode(int x, ListNode* next) : val(x), next(next) {
    }
};
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        auto l = new ListNode();
        auto be = new ListNode();
        auto i = l, j = be;
        for (auto t = head; t != nullptr; t = t->next) {
            if (t->val < x) {
                i->next = t;
                i = i->next;
            } else {
                j->next = t;
                j = j->next;
            }
        }
        i->next = be->next;
        j->next = nullptr;
        return l->next;
    }
};