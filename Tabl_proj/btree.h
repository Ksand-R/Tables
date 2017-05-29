#pragma once
#include "Tabl_proj.h"

struct Node_tree {
	Row* row_;
	Node_tree* left;
	Node_tree* right;
	int height;

	Node_tree() {
		left = nullptr;
		right = nullptr;
		height = 0;
		row_ = nullptr;
	}

	Node_tree(string t, Polynomial* p) {
		row_ = new Row(t, new Polynomial(*p));
		left = nullptr;
		right = nullptr;
		height = 1;
	}

	Node_tree(Row* t) {
		row_ = new Row(t->name, t->ptr_p);
		left = nullptr;
		right = nullptr;
		height = 1;
	}

	Node_tree(const Node_tree& t) {
		left = t.left;
		right = t.right;
		row_ = new Row(*(t.row_));
		height = t.height;
	}

	Node_tree& Node_tree::operator=(const Node_tree& t) {
		if (this != &t) {
			left = t.left;
			right = t.right;
			row_ = new Row(*(t.row_));
			height = t.height;
		}
	}

	~Node_tree() {
		delete row_;
		left = nullptr;
		right = nullptr;
		height = 0;
	}

	friend ostream& operator << (ostream& os, const Node_tree& t);
};

class btree : public Table {	
public:
	Node_tree* root;
	void remove(string name) {}
	inline void print_table(){cout << *root << endl;}
	Row* search(string name);
	void insert(const Row& r) {}
	btree() { root = NULL; }
	~btree() { root = NULL; }

	Node_tree* insert_(Node_tree*& tmp_root, const Row& r) {
		if (tmp_root == nullptr)
		{
			tmp_root = new Node_tree(r.name, r.ptr_p);
			return tmp_root;
		}
		if (r.name < tmp_root->row_->name)
			tmp_root->left = insert_(tmp_root->left, r);
		else
			tmp_root->right = insert_(tmp_root->right, r);

		tmp_root = balance(tmp_root);
		return tmp_root;
	}
	Node_tree* remove(Node_tree* root, string name); 
	inline int height(Node_tree* p){return p ? p->height : 0;}
	inline int bfactor(Node_tree* p){return height(p->right) - height(p->left);}

	void fixheight(Node_tree* p)
	{
		int hl = height(p->left);
		int hr = height(p->right);
		p->height = (hl > hr ? hl : hr) + 1;
	}

	Node_tree* rotateright(Node_tree* p); // правый поворот вокруг p
	Node_tree* rotateleft(Node_tree* q); // левый поворот вокруг q
	Node_tree* balance(Node_tree* p);
	Node_tree* findmin(Node_tree* p){return p->left ? findmin(p->left) : p;	}
	// поиск узла с минимальным ключом в дереве p 
	Node_tree* removemin(Node_tree* p) // удаление узла с минимальным ключом из дерева p
	{
		if (p->left == nullptr)
			return p->right;
		p->left = removemin(p->left);
		return balance(p);
	}
};

