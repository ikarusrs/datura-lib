#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T> *next;

    Node(T val) : data(val), next(nullptr) {}
    void display() const{
        cout << "Node: " << data << endl;
    }
};

template <typename T>
class SLL {
    private: 
    Node<T> *head;
    Node<T> *tail;

    public:
    SLL() : head(nullptr), tail(nullptr) {}

    SLL(T data) {
        Node<T> *newNode = new Node<T>(data);
        head = newNode;
        tail = newNode;
    }

    ~SLL() {
        clear();
    }

    void insertStart(T data) {
        Node<T> *newNode = new Node<T>(data);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void insertEnd(T data) {
        Node<T> *newNode = new Node<T>(data);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    void deleteStart() {
        if (head == nullptr) return;

        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }

        Node<T> *temp = head;
        head = head->next;
        delete temp;
    }

    void deleteEnd() {
        if (head == nullptr) return;

        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }

        Node<T> *temp = head;
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

    void display() const{
        if (head == nullptr) {
            std::cout << "Empty List\n";
            return;
        }

        Node<T> *temp = head;
        while (temp != nullptr) {
            temp->display();
            temp = temp->next;
        }
    }
};

template<typename T>
class Queue {
    private:
    SLL<T> list;

    public:
    void enqueue(T data){
        list.insertEnd(data);
    }

    void dequeue(){
        list.deleteStart();
    }  

    void display() const{
        list.display();
    }
};