#pragma once
#include "Tabl_proj.h"

struct Node_tree {
	Row* row_;
	Node_tree* left;
	Node_tree* right;
	Node_tree* parent;
	
	Node_tree() {
		parent = NULL;
		left = NULL;
		right = NULL;
	}

	Node_tree(Row* t) {
		row_ = t;
		parent = NULL;
		left = NULL;
		right = NULL;
	}

	Node_tree(const Node_tree& t) {
		parent = t.parent;
		left = t.left;
		right = t.right;
		row_ = t.row_;
	}

	Node_tree& Node_tree::operator=(const Node_tree& t) {
		if (this != &t) {
			parent = t.parent;
			left = t.left;
			right = t.right;
			row_ = t.row_;
		}
	}

	~Node_tree() {
		row_ = NULL;
		parent = NULL;
		left = NULL;
		right = NULL;
	}
	friend ostream& operator << (ostream& os, const Node_tree& t);
	
};

class btree
{
public:
	Node_tree* root;
	btree() { root = NULL; }
	~btree() { root = NULL; }

	void insert(const Row& r);
	void remove(string name){}
	void repacking() {}
	void print_table() {}
	void tree_ins(Node_tree* t);


	Row* search(string name);
	Node_tree* search_min(Node_tree* r);
	Node_tree* search_max(Node_tree* r);
	Node_tree* search_next(Node_tree* r);
	Node_tree* search_prev(Node_tree* r);
};
