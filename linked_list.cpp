#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
    void display() {
        cout << "Node: " << data << endl;
    }
};

class SLL {
    private: 
    Node *head;
    Node *tail;

    public:
    SLL(int data) {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }

    void insertStart(int data) {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void insertEnd(int data) {
        Node *newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
    }

    void deleteStart() {
        if (head == tail) {
            delete head;
            head == nullptr;
            tail == nullptr;
            return;
        }

        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void deleteEnd() {
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }

        Node *temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }

        delete tail;
        tail = temp;
        tail->next = nullptr;
    }

    void clear() {
        while (head != nullptr) {
            deleteStart();
        }
    }


    void display() const {
        if (head == nullptr) {
            std::cout << "Empty List\n";
            return;
        }

        Node *temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
    }
};