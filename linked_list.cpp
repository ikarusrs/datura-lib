#include <iostream>
using namespace std;

struct Node {
    static inline int counter = 0; 
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {counter++;}
    void display() {
        cout << "Node " << counter << ": " << data;
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


};