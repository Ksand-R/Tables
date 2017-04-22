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
	friend ostream& operator << (ostream& os, const Node_tree& t) {
		if (t.parent)
			os << "Parent:" << *t.parent;
		else
			os << "Parent: NULL;	";

		if (t.left)
			os << "Left:" << *t.left;
		else
			os << "Left: NULL;	";

		if (t.right)
			os << "Right:" << *t.right << endl;
		else
			os << "Right: NULL;	" << endl;

		os	<< "row: " << t.row_->name << "   " <<
			*(t.row_->ptr_p) << endl;
		return os;
	}
};

