#pragma once
#include<iostream>
#include<stack>
#include<string>
using namespace std;

template<class Key, class Value>
struct Node {
	pair<Key, Value> key_value;
	int balance;
	Node<Key, Value>* lchild;
	Node<Key, Value>* rchild;
};

template<class Key, class Value>
class map {
private:
	Node<Key, Value>* avl_tree;
	int number;
	int RRotate(Node<Key, Value>*& p) {
		Node* temp = p;
		p = p->lchild;
		temp->lchild = p->rchild;
		p->rchild = temp;
		return 0;
	}
	int LRotate(Node<Key, Value>*& p) {
		Node* temp = p;
		p = p->rchild;
		temp->rchild = p->lchild;
		p->lchild = temp;
		return 0;
	}
	int LLAdjust(Node<Key, Value>*& p) {
		RRotate(p);
		p->balance = 0;
		p->rchild->balance = 0;
		return 0;
	}
	int RRAdjust(Node<Key, Value>*& p) {
		LRotate(p);
		p->balance = 0;
		p->lchild->balance = 0;
		return 0;
	}
	int LRAdjust(Node<Key, Value>*& p) {
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
	int RLAdjust(Node<Key, Value>*& p) {
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
	int DestroyTree(Node<Key, Value>*& t) {
		if (t == nullptr) return 0;
		DestroyTree(t->lchild);
		DestroyTree(t->rchild);
		delete t;
		t = nullptr;
		return 0;
	}
public:
	typedef Node<Key, Value> Node, * Tree;
	map(int n = 0) {
		number = n;
		avl_tree = nullptr;
	}
	~map() {
		clear();
	}
	Node* Find(Key aKey) {
		Node* p = avl_tree;
		while (p != NULL && p->key_value.first != aKey) {
			p = aKey < p->key_value.first ? p->lchild : p->rchild;
		}
		return p;
	}
	int insert(pair<Key, Value> e) {
		Node** p = &avl_tree;
		stack<pair<Node**, int>> ancestors;
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
		*p = new Node;
		(*p)->balance = 0;
		(*p)->lchild = nullptr;
		(*p)->rchild = nullptr;
		(*p)->key_value = e;
		number++;

		// 自底向上沿祖先链修正各祖先结点的平衡因子
		while (!ancestors.empty()) {
			// 修正祖先结点的平衡因子
			auto aPair = ancestors.top(); ancestors.pop();
			Node*& curr = *aPair.first;
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
		Node** p = &avl_tree;
		stack<pair<Node**, int>> ancestors;

		//第一步：寻找对应的键
		while (*p != nullptr) {
			if (aKey < (*p)->key_value.first) {
				ancestors.push(make_pair(p, -1));
				p = &(*p)->lchild;
			}
			else if (aKey > (*p)->key_value.first) {
				ancestors.push(make_pair(p, 1));
				p = &(*p)->rchild;
			}
			else
				break;
		}
		//未找到该键，返回1代表删除失败
		if (*p == nullptr)
			return 1;

		//第二步：更新需要删除的结点
		Node** WillRemove = p;
		if ((*p)->lchild != nullptr && (*p)->rchild != nullptr) {
			Node** temp = nullptr;
			if ((*p)->balance = -1) {
				*temp = (*p)->rchild;
				while (*temp != nullptr && (*temp)->lchild != nullptr) {
					ancestors.push(make_pair(temp, -1));
					*temp = (*temp)->lchild;
				}
			}
			else {
				*temp = (*p)->lchild;
				while (*temp != nullptr && (*temp)->rchild != nullptr) {
					ancestors.push(make_pair(temp, 1));
					*temp = (*temp)->rchild;
				}
			}
			//交换内容
			Key a;
			Value b;
			a = (*temp)->key_value.first;
			b = (*temp)->key_value.second;
			(*temp)->key_value.first = (*p)->key_value.first;
			(*temp)->key_value.second = (*p)->key_value.second;
			(*p)->key_value.first = a;
			(*p)->key_value.second = b;
			//更新要删除的结点
			*WillRemove = *temp;
		}

		//第三步：进行删除操作
		if ((*WillRemove)->lchild != nullptr && (*WillRemove)->rchild == nullptr) {
			//只含有左子树
			Node* parent = *(ancestors.top().first);
			if (ancestors.top().second == -1) {
				parent->lchild = (*WillRemove)->lchild;
			}
			else {
				parent->rchild = (*WillRemove)->lchild;
			}
		}
		else if ((*WillRemove)->lchild == nullptr && (*WillRemove)->rchild != nullptr) {
			//只含有右子树
			Node* parent = *(ancestors.top().first);
			if (ancestors.top().second == -1) {
				parent->lchild = (*WillRemove)->rchild;
			}
			else {
				parent->rchild = (*WillRemove)->rchild;
			}
		}
		delete *WillRemove;
		*WillRemove = nullptr;
		number--;

		//第四步：自底向上沿祖先链修正各祖先结点的平衡因子
		while (!ancestors.empty()) {
			Node* A;
			A = *(ancestors.top().first);
			A->balance += ancestors.top().second;
			ancestors.pop();
			if (A->balance > 1) {
				Node* temp = A->lchild;
				if (temp->balance == 1)
					LLAdjust(A);
				else if (temp->balance == -1)
					LRAdjust(A);
			}
			else if (A->balance == -1) {
				Node* temp = A->rchild;
				if (temp->balance == -1)
					RRAdjust(A);
				else if (temp->balance == 1)
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
	void clear() {
		DestroyTree(avl_tree);
	}
	Node* lower_bound(Key aKey) {
		Node* temp = Find(aKey);
		return temp;
	}
	Node* upper_bound(Key aKey) {
		Node* temp = Find(aKey);
		if (temp != nullptr)
			return temp->rchild;
		else
			return nullptr;
	}
	//重载赋值运算符
	Value& operator[](Key aKey) {
		Node* p = Find(aKey);
		if (p != nullptr)
			return p->key_value.second;
		else {
			return -1;
		}
	}
};