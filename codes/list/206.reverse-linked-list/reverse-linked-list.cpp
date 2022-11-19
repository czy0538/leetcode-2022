#include "ListNode.h"
// 使用栈
// #include <stack>
// using namespace std;
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         stack<ListNode*> s;
//         if(head==nullptr){
//             return head;
//         }
//         auto p = head;
//         while (p->next) {
//             s.push(p);
//             p = p->next;
//         }
//         head = p;
//         while (!s.empty()) {
//             p->next = s.top();
//             s.pop();
//             p = p->next;
//         }
//         p->next = nullptr;
//         return head;
//     }
// };

// 递归法1
// class Solution {
// public:
//     ListNode* end;
//     ListNode* reverse(ListNode* current) {
//         if (current->next == nullptr) {
//             end = current;
//             return current;
//         }
//         auto ret = reverse(current->next);
//         ret->next = current;
//         return current;
//     }

//     ListNode* reverseList(ListNode* head) {
//         if (head == nullptr){
//             return head;
//         }
//         reverse(head);
//         head->next = nullptr;
//         return end;
//     }
// };

// 双指针法1
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode *i, *j, *t;
//         i = head;
//         if (head == nullptr) {
//             return nullptr;
//         }
//         i = head;
//         j = head->next;
//         while (j) {
//             t = j->next;
//             j->next = i;
//             i = j;
//             j = t;
//         }
//         head->next = nullptr;
//         return i;
//     }
// };

// 上面的方法都是在关注当前节点和下一个节点，因此需要单独处理第一个节点
// 如果我们改变下思路，关注上一个节点和当前节点

// 双指针法2
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        decltype(head) pre, cur, t;
        pre = nullptr;
        cur = head;
        while(cur){
            t = cur->next;
            cur->next = pre;
            pre = cur;
            cur = t;
        }
        return pre;
    }
};