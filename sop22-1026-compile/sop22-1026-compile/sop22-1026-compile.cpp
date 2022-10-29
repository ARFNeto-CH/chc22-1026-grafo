#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class LinkedList {
public:
    struct Node {
        T data;
        Node* prev;
        Node* next;
    };
    void PrintForward();
    void PrintReverse();
    void PrintForwardRecursive(const Node*);
    void PrintReverseRecursive(const Node*);
    int NodeCount() const;
    void FindAll(vector<Node*>&, const T&);
    Node* Find(const T&) const;
    Node* GetNode(int&) const;
    Node* Head() const;
    Node* Tail() const;
    void AddHead(const T&);
    void AddTail(const T&);
    void AddNodesHead(const T&, int);
    void AddNodesTail(const T&, int);
    void InsertAfter(Node*, const T&);
    void InsertBefore(Node*, const T&);
    void InsertAt(const T&, int);
    bool RemoveHead();
    bool RemoveTail();
    int Remove(const T&);
    bool RemoveAt(int);
    void clear();
    T& operator[](int);
    bool operator==(const LinkedList<T>&);
    LinkedList<T>& operator=(const LinkedList<T>&);
    LinkedList();
    LinkedList(const LinkedList<T>&);
    ~LinkedList();
private:
    int n;
    Node* head;
    Node* tail;
};

template<typename T>
void LinkedList<T>::PrintForward() {
    PrintForwardRecursive(head->next);
}

template<typename T>
void LinkedList<T>::PrintReverse() {
    PrintReverseRecursive(tail->prev);
}

template<typename T>
void LinkedList<T>::PrintForwardRecursive(const Node* node) {
    cout << node->data << " ";
    if (node->next != tail)
        PrintForwardRecursive(node->next);
}

template<typename T>
void LinkedList<T>::PrintReverseRecursive(const Node* node) {
    cout << node->data << " ";
    if (node->next != prev)
        PrintForwardRecursive(node->prev);
}

template<typename T>
int LinkedList<T>::NodeCount() const {
    int num = 1;
    Node* ptr = head;
    while (ptr != tail) {
        ptr = ptr->next;
        num++;
    }
    return num;
}

template<typename T>
void LinkedList<T>::FindAll(vector<Node*>& matches, const T& val) {
    Node* ptr = head->next;
    while (ptr != tail) {
        if (ptr->data == val)
            matches.push_back(*ptr);
        ptr = ptr->next;
    }
}

template<typename T>
Node* LinkedList<T>::Find(const T& val) {
    Node* itr = nullptr;
    Node* ptr = head->next;
    while (ptr != tail) {
        if (ptr->data == val) {
            *itr = *ptr;
            break;
        }
        ptr = ptr->next;
    }
    return *itr;
}

template<typename T>
LinkedList<T>::LinkedList() {
    head = new Node;
    tail = new Node;
    head->next = tail;
    tail->prev = head;
    n = 0;
}

template<typename T>
LinkedList<T>::~LinkedList() {
    bool empty = false;
    while (!empty) {
        empty = RemoveHead();
    }
    delete head;
    delete tail;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}