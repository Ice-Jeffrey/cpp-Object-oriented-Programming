#pragma once
#include<iostream>
#include<stack>
using namespace std;

template<class Key, class T>
typedef struct Node {
    pair<Key, T> key_value;
    int balance;
    Node<Key, T> *lchild;
    Node<Key, T> *rchild;
    Node(Key aKey, T aT) {
        key_value = make_pair(aKey, aT);
        balance = 0;
        lchild = rchild = nullptr;
    }
    ~Node();
};

template<class Key, class T>
class map {
    private:
        Node<Key, T>* avl_tree;
        int number;
        int RRotate(Node *&p) {
            Node *temp = p;
            p = p->lchild;
            temp->lchild = p->rchild;
            p->rchild = temp;
            return 0;
        }
        int LRotate(Node *&p) {
            Node *temp = p;
            p = p->rchild;
            temp->rchild = p->lchild;
            p->lchild = temp;
            return 0;
        }
        int LLAdjust(Node *&p) {
            RRotate(p);
            p->balance = 0;
            p->rchild->balance = 0;
            return 0;
        }
        int RRAdjust(Node *&p) {
            LRotate(p);
            p->balance = 0;
            p->lchild->balance = 0;
            return 0;
        }
        int LRAdjust(Node *&p) {
            LRotate(p->lchild);
            RRotate(p);
            switch (p->balance) {
                case 1:
                    p->lchild->balance = 0;
                    p->rchild->balance = -1;
                    break;
                case 0:
                    p->lchild->balance = 0;
                    p->rchild->balance = 0;
                    break;
                case -1:
                    p->lchild->balance = 1;
                    p->rchild->balance = 0;
                    break;
            }
            p->balance = 0;
            return 0;
        }
        int RLAdjust(Node *&p) {
            RRotate(p->rchild);
            LRotate(p);
            switch (p->balance)
            {
                case -1:
                    p->lchild->balance = 1;
                    p->rchild->balance = 0;
                    break;
                case 0:
                    p->lchild->balance = 0;
                    p->rchild->balance = 0;
                    break;
                case 1:
                    p->lchild->balance = 0;
                    p->rchild->balance = -1;
                    break;
            }
            p->balance = 0;
            return 0;
        }
    public:
        typedef Node<Key, T> Node, *Tree;
        map() {
            number = 0;
        }
        Node* BSTSearch(Key aKey) {
            Node *p = avl_tree;
            while (p != NULL && p->key != aKey) {
                p = aKey < p->key_value.first ? p->lchild : p->rchild;
            }
            return p;
        }
        int Insert(pair<key, T> e) {
            Node **p = &avl_tree;
            stack<pair<Node **, int>> ancestors;
            while (*p != nullptr) {
                if (e.first < (*p)->key_value.first) {
                    ancestors.push(make_pair(p, 1));
                    p = &(*p)->lchild;
                }
                else if (e.first > (*p)->key_value.first) {
                    ancestors.push(make_pair(p, -1));
                    p = &(*p)->rchild;
                }
                else {
                    return 1;
                }
            }
            *p = new Node(e.first, e.second);
            number++;

            // 自底向上沿祖先链修正各祖先结点的平衡因子
            while (!ancestors.empty()) {
                // 修正祖先结点的平衡因子
                auto aPair = ancestors.top(); ancestors.pop();
                Node *&curr = *aPair.first;
                curr->balance += aPair.second;

                // 检查祖先结点的平衡状态
                switch (curr->balance) {
                    case 0: // 祖先结点的平衡因子不会再变化，结束修正过程
                        return 0; 
                    case -1:
                    case 1: // 没有失衡，但平衡因子的变化还需要继续向上传递
                        break; 
                    case 2: // 失衡，新结点在左子树上
                        switch (curr->lchild->balance) {
                            case 1:
                                LLAdjust(curr); break; // 新结点在左子的左子上（LL型）
                            case -1:
                                LRAdjust(curr); break; // 新结点在左子的右子上（LR型）
                        }
                        return 0;
                    case -2: // 失衡，新结点在右子树上
                        switch (curr->rchild->balance) {
                            case 1:
                                RLAdjust(curr); break; // 新结点在右子的左子上（RL型）
                            case -1:
                                RRAdjust(curr); break; // 新结点在右子的右子上（RR型）
                        }
                        return 0;
                }
            }
            return 0;
        }
        //删除某个key对应的键值对
        int erase(Key aKey) {
            Node **p = &avl_tree;
            stack<pair<Node **, int>> ancestors;

            //第一步：寻找对应的键
            while (*p != nullptr) {
                if (e.first < (*p)->key_value.first) {
                    ancestors.push(make_pair(p, -1));
                    p = &(*p)->lchild;
                }
                else if (e.first > (*p)->key_value.first) {
                    ancestors.push(make_pair(p, 1));
                    p = &(*p)->rchild;
                }
                else
                    break;
            }
            //未找到该键，返回1代表删除失败
            if(*p == nullptr)
                return 1; 

            //第二步：更新需要删除的结点
            Node* WillRemove = *p;
            if((*p)->lchild != nullptr && (*p)->rchild != nullptr) {
                Node* temp;
                if((*p)->balance = -1) {
                    temp = (*p)->rchild;
                    while(temp != nullptr && temp->lchild != nullptr) {
                        ancestors.push(make_pair(&temp, -1));
                        temp = temp->lchild;
                    }
                }
                else {
                    temp = (*p)->lchild;
                    while(temp != nullptr && temp->rchild != nullptr) {
                        ancestors.push(make_pair(&temp, 1));
                        temp = temp->rchild;
                    }
                }        
                //交换内容
                Key a;
                T b;
                a = temp->key_value.first;
                b = temp->key_value.second;
                temp->key_value.first = (*p)->key_value.first;
                temp->key_value.second = (*p)->key_value.second;
                (*p)->key_value.first = a;
                (*p)->key_value.second = b;
                //更新要删除的结点
                WillRemove = temp;
            }
            
            //第三步：进行删除操作
            if (WillRemove->lchild != nullptr && WillRemove->rchild == nullptr) {
                //只含有左子树
                Node* parent = *(ancestors.top().first)
                if(ancestors.top().second == -1) {
                    parent->lchild = WillRemove->lchild;
                }
                else {
                    parent->rchild = WillRemove->lchild;
                }
            }
            else if (WillRemove->lchild == nullptr && WillRemove->rchild != nullptr) {
                //只含有右子树
                Node* parent = *(ancestors.top().first)
                if(ancestors.top().second == -1) {
                    parent->lchild = WillRemove->rchild;
                }
                else {
                    parent->rchild = WillRemove->rchild;
                }
            }
            delete WillRemove;
            number--;
            
            //第四步：自底向上沿祖先链修正各祖先结点的平衡因子
            while (!ancestors.empty()) {
                Node* A;
                A = *(ancestors.top().first);
                A->balance += ancestors.top().second;
                ancestors.pop();
                if(A->balance > 1) {
                    Node* temp = A->lchild;
                    if(temp->balance == 1) 
                        LLAdjust(A);
                    else if(temp->balance == -1)
                        LRAdjust(A);
                }
                else if(A->balance == -1) {
                    Node* temp = A->rchild;
                    if(temp->balance == -1) 
                        RRAdjust(A);
                    else if(temp->balance == 1)
                        RLAdjust(A);
                }
            }
            return 0;
        }
        int size() {
            return number;
        }
        bool empty() {
            return number == 0;
        }
};