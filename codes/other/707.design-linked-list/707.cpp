#include <iostream>
#include <memory>
using namespace std;

class Node {
public:
    Node *prev;
    Node *next;
    int val;
    explicit Node(int v, Node *p, Node *n) : prev(p), next(n), val(v){};
    Node() = default;
};
class MyLinkedList {
    Node *head;
    Node *tail;
    int size;

public:
    MyLinkedList() : head(nullptr), tail(nullptr), size(0) {
    }

    int get(int index) {
        if (index >= size) {
            return -1;
        }
        Node *p;
        for (p = head; index > 0; p = p->next, index--) {
        }
        return p->val;
    }

    void addAtHead(int val) {
        auto p = new Node(val, nullptr, head);
        if (head != nullptr) {
            p->next = head;
            head->prev = p;
        }
        if (tail == nullptr) {
            tail = p;
        }
        size++;
        head = p;
    }

    void addAtTail(int val) {
        auto p = new Node(val, tail, nullptr);
        if (tail != nullptr) {
            p->prev = tail;
            tail->next = p;
        }
        if (head == nullptr) {
            head = p;
        }
        tail = p;
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index == size) {
            addAtTail(val);
            return;
        }
        if (index == 0) {
            addAtHead(val);
            return;
        }
        if (index > size) {
            return;
        }
        Node *p;
        for (p = head; index > 0; index--, p = p->next) {
        }
        Node *n = new Node(val, p->prev, p);
        p->prev = n;
        n->prev->next = n;
        size++;
    }
    void deleteHead() {
        if (head == nullptr) {
            return;
        }
        size--;
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }
        auto p = head;
        head = p->next;
        head->prev = nullptr;
        delete p;
    }
    void deleteTail() {
        if (tail == nullptr) {
            return;
        }
        size--;
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }
        auto p = tail;
        tail = p->prev;
        tail->next = nullptr;
        delete p;
    }

    void deleteAtIndex(int index) {
        if (index >= size) {
            return;
        }
        if (index == size - 1) {
            deleteTail();
            return;
        }
        if (index == 0) {
            deleteHead();
            return;
        }
        Node *p;
        for (p = head; index > 0; p = p->next, index--) {
        }
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        size--;
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

int main() {
    auto obj = new MyLinkedList;
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1, 2);
    cout << obj->get(1) << endl;
    obj->deleteAtIndex(1);
    cout << obj->get(1) << endl;
}