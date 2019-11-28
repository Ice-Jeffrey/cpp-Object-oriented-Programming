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
            switch (p->balance)
            {
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
        int RLAdjust(Node *&p)
        {
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
        T BSTSearch(Key aKey) {
            Node *p = avl_tree;
            while (p != NULL && p->key != aKey) {
                p = aKey < p->key ? p->lchild : p->rchild;
            }
            return p->key_value.second();
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
        int erase(Key aKey) {
            // 定位被删除结点
            Node **p = &avl_tree;
            while (*p != nullptr && (*p)->key_value != aKey)
                p = aKey < (*p)->key_value.first ? &(*p)->lchild : &(*p)->rchild;
            if (*p == nullptr) return 1; // 保存待删除的结点
            Node *willRemove = *p;
            if ((*p)->lchild == nullptr)
                // 如果没有左子，直接用右子结点替换被删除结点
                *p = (*p)->rchild;
            else if ((*p)->rchild == nullptr)
                // 如果没有右子，直接用左子结点替换被删除结点
                *p = (*p)->lchild;
            else {
                // 找到右子的最左结点
                Node **q = &((*p)->rchild);
                while ((*q)->lchild != nullptr)
                    *q = (*q)->lchild;
                // 用右子最左结点的右子替换右子最左结点
                Node *temp = *q;
                *q = (*q)->rchild;
                // 用右子最左结点替换被删除结点
                temp->lchild = (*p)->lchild;
                temp->rchild = (*p)->rchild;
                *p = temp;
            }
            // 释放待删除结点
            delete willRemove;
            return 0;
        }
        
};