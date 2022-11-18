#include <memory>
using namespace std;
// 智能指针版本
// class MyLinkedList {
// private:
//     struct Node {
//         int val;
//         shared_ptr<Node> next;
//     };
//     int size;
//     shared_ptr<Node> head;

// public:
//     MyLinkedList() : head(make_shared<Node>()), size(0) {
//     }
//     // 由于是智能指针，默认析构即可
//     ~MyLinkedList() = default;

//     int get(int index) {
//         if (index >= size || index < 0) {
//             return -1;
//         }
//         auto ptr = head->next;
//         while (index--) {
//             ptr = ptr->next;
//         }
//         return ptr->val;
//     }

//     void addAtHead(int val) {
//         auto ptr = make_shared<Node>();
//         ptr->next = head->next;
//         ptr->val = val;
//         head->next = ptr;
//         size++;
//     }

//     void addAtTail(int val) {
//         auto ptr = head;
//         while (ptr->next != nullptr) {
//             ptr = ptr->next;
//         }
//         ptr->next = make_shared<Node>();
//         ptr->next->val = val;
//         size++;
//     }

//     void addAtIndex(int index, int val) {
//         if (index <= 0) {
//             addAtHead(val);
//         } else if (index == size) {
//             addAtTail(val);
//         } else if (index > size) {
//             return;
//         } else {
//             auto ptr = head;
//             // 在index之前插入
//             while (index--) {
//                 ptr = ptr->next;
//             }
//             auto np = make_shared<Node>();
//             np->val = val;
//             np->next = ptr->next;
//             ptr->next = np;
//             size++;
//         }
//     }

//     void deleteAtIndex(int index) {
//         if (index < 0 || index >= size) {
//             return;
//         }
//         // 走到要删除的前一个位置
//         auto ptr = head;
//         while (index--) {
//             ptr = ptr->next;
//         }
//         // 一定是可删除的，因为上面size已经判断过了
//         // 智能指针，不用我们手动去释放。
//         ptr->next = ptr->next->next;
//         size--;
//     }
// };

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

class MyLinkedList {
private:
    struct Node {
        int val = 0;
        Node* next = nullptr;
    };

    Node* head;
    int size;

public:
    MyLinkedList() : head(new Node), size(0) {
    }
    ~MyLinkedList(){
        while(head){
            auto ptr = head->next;
            delete head;
            head = ptr;
        }
    }

    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }
        auto ptr = head->next;
        while (index--) {
            ptr = ptr->next;
        }
        return ptr->val;
    }

    void addAtHead(int val) {
        auto ptr = new Node;
        ptr->next = head->next;
        ptr->val = val;
        head->next = ptr;
        size++;
    }

    void addAtTail(int val) {
        auto ptr = head;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        ptr->next = new Node;
        ptr->next->val = val;
        size++;
    }

    void addAtIndex(int index, int val) {
        if(index<=0){
            addAtHead(val);
        }else if(index==size){
            addAtTail(val);
        }else if(index>size){
            return;
        }else{
            auto ptr = head;
            while (index--) {
                ptr = ptr->next;
            }
            auto np = new Node;
            np->next = ptr->next;
            np->val = val;
            ptr->next = np;
            size++;
        }
    }

    void deleteAtIndex(int index) {
        if(index <0||index>=size){
            return;
        }else{
            auto ptr = head;
            while(index--){
                ptr = ptr->next;
            }
            auto tmp = ptr->next;
            ptr->next = tmp->next;
            delete tmp;
            size--;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */