#include "ListNode.h"
#include <vector>
using namespace std;

// 最笨的思路就是看清楚有几个节点，然后删除，需要两遍扫描
// 这样时间复杂度是O(2n)，空间复杂度O(1)
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         int size = 0;
//         head = new ListNode(0, head);
//         auto ptr = head->next;
//         while (ptr) {
//             size++;
//             ptr = ptr->next;
//         }
//         size -= n;
//         auto pre = head;
//         while(size--){
//             pre = pre->next;
//         }
//         ptr = pre->next;
//         pre->next = ptr->next;
//         delete ptr;
//         ptr = head->next;
//         delete head;
//         return ptr;
//     }
// };

// 最笨的一趟方法，我记住，这样时间复杂度和空间复杂度均为O(n)
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         vector<ListNode*> list;
//         head = new ListNode(0, head);
//         auto ptr = head;
//         while (ptr) {
//             list.push_back(ptr);
//             ptr = ptr->next;
//         }
//         auto pre = list[list.size() - n - 1];
//         ptr = pre->next;
//         pre->next = ptr->next;
//         delete ptr;
//         ptr = head->next;
//         delete head;
//         return ptr;
//     }
// };

// 双指针法
// 要删除谁，就是要保持一个距离，因此让两个指针保持距离n，
// 当快指针到最后的时候，慢指针就到要删除元素的前边了
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head = new ListNode(0, head);
        ListNode *l = head, *r = head;
        while (n--)
        {
            r = r->next;
        }
        while(r->next!=nullptr){
            l = l->next;
            r = r->next;
        }
        auto ptr = l->next;
        l->next = ptr->next;
        delete ptr;
        ptr = head->next;
        delete head;
        return ptr;
    }
};