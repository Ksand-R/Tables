#include "btree.h"

Node_tree* btree::rotateright(Node_tree* p) {
		Node_tree* q = p->left;
		p->left = q->right;
		q->right = p;
		fixheight(p);
		fixheight(q);
		return q;
}

Node_tree* btree::rotateleft(Node_tree* q){
	Node_tree* p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);
	return p;
}

Node_tree* btree::balance(Node_tree* p){
	fixheight(p);
	if (bfactor(p) == 2)
	{
		if (bfactor(p->right) < 0)
			p->right = rotateright(p->right);
		return rotateleft(p);
	}
	if (bfactor(p) == -2)
	{
		if (bfactor(p->left) > 0)
			p->left = rotateleft(p->left);
		return rotateright(p);
	}
	return p; 
}

Node_tree* btree::remove(Node_tree*root, string name){
	if (!root) return nullptr;
	if (name < root->row_->name)
		root->left = remove(root->left, name);
	else if (name > root->row_->name)
		root->right = remove(root->right, name);
	else //  name == root->row_name 
	{
		Node_tree* q = root->left;
		Node_tree* r = root->right;
		delete root;
		if (!r) return q;
		Node_tree* min = findmin(r);
		min->right = removemin(r);
		min->left = q;
		return balance(min);
	}
	return balance(root);
}

Row* btree::search(string t)
{
	Node_tree* tmp = root;
	if (!tmp->row_) { return NULL; }
	if (!tmp)
	{
		while (tmp->row_->name != t) //? && tmp
		{
			if (tmp->row_->name > t)
			{
				if (tmp->left)
					tmp = tmp->left;
				else {tmp = NULL; break;}
			}
			else
			{
				if (tmp->right)
					tmp = tmp->right;
				else { tmp = NULL; break; }
			}
		}
	}
	if (tmp->row_->name == t) {return tmp->row_;} 
	else return nullptr;
}

ostream& operator<<(ostream& os, const Node_tree& t) {
	{
		os << "row: " << t.row_->name << "   " <<
			*(t.row_->ptr_p) << endl;
		os << "Height:" << t.height << endl;;

		if (t.left)
			os << "Left:" << *t.left;
		else
			os << "Left: NULL;	";

		if (t.right)
			os << "Right:" << *t.right << endl;
		else
			os << "Right: NULL;	" << endl;

		return os;
	}
}

