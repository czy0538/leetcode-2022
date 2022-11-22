#include "ListNode.h"
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto curA = headA;
        auto curB = headB;
        int sizeA = 0, sizeB = 0;
        while (curA != nullptr) {
            sizeA++;
            curA = curA->next;
        }
        while (curB != nullptr) {
            sizeB++;
            curB = curB->next;
        }

        curA = headA;
        curB = headB;
        while (sizeA > sizeB) {
            curA = curA->next;
            sizeA--;
        }
        while (sizeB > sizeA) {
            curB = curB->next;
            sizeB--;
        }

        while(curA!=nullptr){
            if(curA==curB){
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return curA;
    }
};