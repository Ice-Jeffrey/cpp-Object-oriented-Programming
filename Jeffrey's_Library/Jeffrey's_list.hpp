#include<iostream>
using namespace std;

template<class T>
struct Node {
    T element;
    Node<T>* previous;
    Node<T>* next;
};

template<class T> 
class list {
    private:
        Node<T>* head;
        Node<T>* tail;
        int s = 0;
        int msize = 100;
    public:
        list() {
            //产生空的list，初始时将结点指向自身
            head = new Node<T>();
            tail = new Node<T>();
            head->next = tail;
            tail->previous = head;
        }
        list(int n) {
            //生成一个大小为n的list
            head = new Node<T>;
            tail = new Node<T>;
            head->next = tail;
            tail->previous = head;
            Node<T>* node = head;
            s = n;
            for(int i=0; i<n; i++) {
                insert(1, 0);
            }
        }
        list(int n, T e) {
            //生成一个大小为n的list，每个元素都是e
            head = new Node<T>;
            tail = new Node<T>;
            head->next = tail;
            tail->previous = head;
            for(int i=0; i<n; i++)
                insert(1, e);
        }
        ~list() {
            //析构函数
            clear();
            delete head;
            delete tail;
            s = 0;
        }
        void insert(int position, const T& val) {
            Node<T>* node = head;
            for(int i=0; i<position; i++)
                node = node->next;
            Node<T>* tmp = new Node<T>;
            tmp->element = val;
            tmp->previous = node->previous;
            tmp->next = node;
            node->previous->next = tmp;
            node->previous = tmp;
            s++;
        }
        void erase(int position) {
            Node<T>* temp;
            temp = head;
            for(int i=0; i<position; i++)
                temp = temp->next;
            temp->next->previous = temp->previous;
            temp->previous->next = temp->next;
            delete temp;
            s--;
        }
        void push_front(T e) {
            //在头部添加一个e的副本
            Node<T>* tmp = new Node<T>;
            tmp->element = e;
            tmp->previous = head;
            tmp->next = head->next;
            head->next->previous = tmp;
            head->next = tmp;
            s++;
        }
        void push_back(T e) {
            //在尾部添加一个e的副本
            Node<T>* tmp = new Node<T>;
            tmp->element = e;
            tmp->next = tail;
            tmp->previous = tail->previous;
            tail->previous->next = tmp;
            tail->previous = tmp;
            s++;
        }
        void remove(T e) {
            Node<T>* node = head;
            for(int i=0; i<s; i++) {
                Node<T>* temp = node;
                node = node->next;
                if(temp->element == e) {
                    temp->next->previous = temp->previous;
                    temp->previous->next = temp->next;
                    delete temp;
                    s--;
                }
            }
        }
        void reverse() {
            Node<T>* first;
            Node<T>* last;
            first = head->next;
            last = tail->previous;
            int loc1 = 1;
            int loc2 = s;
            while(loc1 < loc2) {
                T temp;
                temp = first->element;
                first->element = last->element;
                last->element = temp;
                first = first->next;
                last = last->previous;
                loc1++;
                loc2--;
            }
        }
        void pop_front() {
            erase(1);
        }
        void pop_back() {
            erase(s);
        }
        void clear() {
            while(!empty()) {
                pop_front();
            }
        }
        int size() {
            //返回元素个数
            return s;
        }
        bool empty() {
            //判断容器是否为空
            return s == 0;
        }
        int max_size() {
            //返回元素最大可能数量
            return msize;
        }
        void assign(int n, T e) {
            //将e的n个拷贝赋值给c
            for(int i=0; i<n; i++)
                insert(1, e);
        }
        T front() {
            //返回第一个元素的引用
            return head->next->element;    
        }
        T back() {
            return tail->previous->element;
        }
        void test_print() {
            Node<T>* node = head->next;
            int count = s;
            while(count--) {
                cout << node->element << " ";
                node = node->next;
            }
            cout << endl;
        }
};