#include "ListNode.h"

// 第一版写法，头结点需要单独的去处理
// class Solution {
// public:
//     ListNode* removeElements(ListNode* head, int val) {
//         while(head){
//             if(head->val==val){
//                 auto ptr = head;
//                 head = head->next;
//                 delete ptr;
//             }else{
//                 break;
//             }
//         }
//         if (head == nullptr) {
//             return head;
//         }
//         auto ptr = head->next;
//         auto pre = head;
//         while(ptr){
//             if(ptr->val==val){
//                 pre->next = ptr->next;
//                 delete ptr;
//                 ptr = pre->next;
//             }else{
//                 pre = ptr;
//                 ptr = ptr->next;
//             }
//         }
//         return head;
//     }
// };

// 加一个空的头，可以更简单的处理
// class Solution {
// public:
//     ListNode* removeElements(ListNode* head, int val) {
//         auto ph = new ListNode;
//         ph->next = head;
//         auto pre = ph;
//         while (head) {
//             if(head->val==val){
//                 pre->next = head->next;
//                 delete head;
//                 head = pre->next;
//             }else{
//                 pre = head;
//                 head = head->next;
//             }
//         }
//         return ph->next; // 内存泄露了
//     }
// };

// 最佳版本
// class Solution {
// public:
//     ListNode* removeElements(ListNode* head, int val) {
//         ListNode* dummyHead = new ListNode(0); // 设置一个虚拟头结点
//         dummyHead->next = head; // 将虚拟头结点指向head，这样方面后面做删除操作
//         ListNode* cur = dummyHead;
//         while (cur->next != nullptr) {
//             if (cur->next->val == val) {
//                 ListNode* tmp = cur->next;
//                 cur->next = cur->next->next;
//                 delete tmp;
//             } else {
//                 cur = cur->next;
//             }
//         }
//         head = dummyHead->next;
//         delete dummyHead;
//         return head;
//     }
// };

// 递归版本
// class Solution {
// public:
//     void remove(ListNode* ptr, int val) {
//         if (ptr->next == nullptr) {
//             return;
//         }
//         if (ptr->next->val == val) {
//             auto tmp = ptr->next;
//             ptr->next = tmp->next;
//             delete tmp;
//             remove(ptr,val);
//         }else{
//             remove(ptr->next, val);
//         }
//     }
//     ListNode* removeElements(ListNode* head, int val) {
//         ListNode* p = new ListNode(0, head);
//         remove(p, val);
//         head = p->next;
//         delete p;
//         return head;
//     }
// };

// 递归版本进阶,这个效率很低，比我们上面的版本都要低
// 相当于是走到最后一个节点，然后再倒着删除，所有的节点信息都被压到了栈中
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) {
            return head;
        }
        head->next = removeElements(head->next, val);
        if(head->val==val){
            auto tmp = head->next;
            delete head;
            return tmp;
        }else{
            return head;
        }
    }
};
