#include "ListNode.h"

// 循环写法
// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
//         ListNode *pre, *cur;
//         head = new ListNode(0, head);
//         pre = head;
//         cur = head->next;
//         while (cur != nullptr) {
//             if (cur->next == nullptr) {
//                 break;
//             }
//             auto next = cur->next;
//             cur->next = next->next;
//             pre->next = next;
//             next->next = cur;
//             pre = cur;
//             cur = cur->next;
//         }
//         cur = head->next;
//         delete head;
//         return cur;
//     }
// };

// 递归写法
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        //递归结束条件：头节点不存在或头节点的下一个节点不存在。此时不需要交换，直接返回head
        if (!head || !head->next) return head;
        //创建一个节点指针类型保存头结点下一个节点
        struct ListNode* newHead = head->next;
        //更改头结点+2位节点后的值，并将头结点的next指针指向这个更改过的list
        head->next = swapPairs(newHead->next);
        //将新的头结点的next指针指向老的头节点
        newHead->next = head;
        return newHead;
    }
};