#include <iostream>
using namespace std;

struct Node {
    static inline int counter = 0; 
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {counter++;}
    void display() {
        cout << "Node " << counter << ": " << data << endl;
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
        head->next = head;
        delete temp;
    }

    void deleteEnd() {
        if (head == tail) {
           delete head;
           head = nullptr;
           tail = nullptr; // List is now safely empty
           return;
        }

        Node *temp = head;
        while (temp->next != tail){
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

    void display() const{
        if (head == nullptr){
            cout << "Empty list\n";
            return;
        }

        Node *current = head;
        while(current != nullptr) {
            current->display();
            current = current->next;
        }
    }
};