#include<iostream>
using namespace std;

struct Node {
    T element;
    Node* previous;
    Node* next;
};

template<typename T> 
    
    class list {
        private:
            Node* buffer = new Node;
            buffer.previous = nullptr;
            buffer.next = nullptr;
            size = 0;
            max_size = 100;
        public:
            list() {}
            list(int n) {
                Node* node = buffer;
                size = n;
                for(int i=0; i<n; i++) {
                    node->next = new Node;
                    node->next->previous = node;
                }
            }
            list(int n, T e) {
                size = n;
                Node* node = buffer;
                for(int i=0; i<n; i++) {
                    node->next = new Node;
                    node->next->element = e;
                    node->next->previous = node;
                }
            }
            list(T begin, T end) {
                int n = end - begin;
                size = n;
                T e = begin;
                Node* node = buffer;
                for(int i=0; i<n; i++) {
                    node->next = new Node;
                    node->next->element = e;
                    e++;
                    node->next->previous = node;
                }
            }
            ~list() {
                Node* node = buffer->next;
                while(node != nullptr) {
                    Node* temp = node;
                    node->next->previous = node->previous;
                    node->previous->next = node->next;
                    node = temp->next;
                    delete[] temp;
                }
                size = 0;
            }
            int size() {
                return size;
            }
            bool empty() {
                return size == 0;
            }
            int max_size() {
                return max_size;
            }
            void assign(int n, T e) {
                size = n;
                Node* node = buffer;
                for(int i=0; i<n; i++) {
                    node->next = new Node;
                    node->next->element = e;
                    node->next->previous = node;
                }
            }
            void assign(T begin, T end) {
                int n = end - begin;
                size = n;
                T e = begin;
                Node node = buffer;
                for(int i=0; i<n; i++) {
                    node->next = new Node;
                    node->next->element = e;
                    e++;
                    node->next->previous = node;
                }
            }
            T front() {
                if(size)
                    return buffer->next->element;
                else
                    cout << "No element for the list" << endl;            
            }
            T back() {
                if(size) {
                    Node* node = buffer;
                    while(node.next != nullptr)
                        node = node->next;
                    return node->element;
                }
            }
            void insert(int pos, T e) {
                if(pos > size) 
                    cout << "Out of range!" << endl;
                else
                {
                    Node* node = buffer;
                    for(int i=0; i<pos; i++)
                        node = node->next;
                    Node *p = new Node;
                    p->element = e;
                    p->next = node->next;
                    node->next = p;
                    p->previous = node;
                    node->next->previous = p;
                    size++;
                }
            }
            void insert(int pos, int n, int e) {
                if(pos > size)
                    cout << "Out of range!" << endl;
                else
                {
                    Node* node = buffer;
                    for(int i=0; i<pos; i++)
                        node = node->next;
                    while(n--) {
                        Node *p = new Node;
                        p->element = e;
                        p->next = node->next;
                        node->next = p;
                        p->previous = node;
                        node->next->previous = p;
                    }
                    size += n;
                }
            }
            void insert(int pos, T begin, T end) {
                if(pos > size)
                    cout << "Out of range!" << endl;
                else
                {
                    int n = end - begin;
                    T t = begin;
                    Node* node = buffer;
                    for(int i=0; i<pos; i++)
                        node = node->next;
                    while(n--) {
                        Node *p = new Node;
                        p->element = t;
                        t++;
                        p->next = node->next;
                        node->next = p;
                        p->previous = node;
                        node->next->previous = p;
                        node = node->next;
                    }
                    size += n;
                }
            }
            void push_back(T e) {
                Node* node = buffer;
                while(node->next != nullptr) 
                    node = node->next;
                Node* p = new Node;
                p->element = e;
                p->next = nullptr;
                p->previous = node;
                node->next = p;
                size++;
            }
            void push_front(T e) {
                Node* node = buffer;
                Node* p;
                p = new Node;
                p->element = e;
                p->next = node->next;
                p->previous = node;
                node->next->previous = p;
                node->next = p;
                size++;            
            }
            void pop_back() {
                if(size != 0) {
                    Node* node = buffer;
                    while(node->next != nullptr) 
                        node = node->next;
                    node->previous->next = nullptr;
                    delete node;
                    size--;
                }
                else
                    cout << "No element to delete" << endl;
            }
            void pop_front() {
                if(size != 0) {
                    Node* node = buffer->next;
                    node->previous->next = node->next;
                    if(node->next)
                        node->next->previous = node->previous;
                    delete node;
                    size--;
                }
            }
    };

