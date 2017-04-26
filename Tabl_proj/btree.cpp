#include "btree.h"
ostream& operator<<(ostream& os, const Node_tree& t) {
	{
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

		os << "row: " << t.row_->name << "   " <<
			*(t.row_->ptr_p) << endl;
		return os;
	}
}

Row* btree::search(string t)
{
	Node_tree* tmp = root;
	if (tmp->row_ == NULL)
	{
		return NULL;
	}
	if (tmp != NULL)
	{
		
		while (tmp->row_->name != t)
		{
			if (tmp->row_->name > t)
			{
				if (tmp->left)
					tmp = tmp->left;
				else
				{
					tmp = NULL;
					break;
				}
			}
			else
			{
				if (tmp->right)
					tmp = tmp->right;
				else
				{
					tmp = NULL;
					break;
				}
			}
		}
	}
	return tmp->row_;
}

void btree::tree_ins(Node_tree* n)
{
	if (root == NULL)
	{
		root = n;
		root->parent = root;
	}
	else
		if (search(n->row_->name) != nullptr)
		{
			throw "Error. Equal names";
		}
		else
		{
			Node_tree* prev = root;
			Node_tree* tmp = root;
			while (tmp != NULL)
			{
				prev = tmp;
				if (tmp->row_->name < n->row_->name)
					tmp = tmp->right;
				else
					tmp = tmp->left;
			}
			if (prev->row_->name > n->row_->name)
			{
				prev = n->left;
				prev->parent = prev->left;
				
			}
			else
			{
				prev = n->right;
				prev->parent = prev->right;
			}
		}
}


Node_tree* btree::search_min(Node_tree* root)
{
	Node_tree* tmp = root;
	while (tmp->left != NULL)
	{
		tmp = tmp->left;
	}
	return tmp;
}
Node_tree* btree::search_max(Node_tree* root)
{
	Node_tree*  tmp = root;
	while (tmp->right != NULL)
	{
		tmp = tmp->right;
	}
	return tmp;
}
Node_tree* btree::search_next(Node_tree* root)
{
	Node_tree* tmp = NULL;
	if (root->right != NULL)
		tmp = search_min(root->right);
	return tmp;
}
Node_tree* btree::search_prev(Node_tree* root)
{
	Node_tree* tmp = NULL;
	if (root->left != NULL)
		tmp = search_max(root->left);
	else if (root->parent != NULL)
		tmp = root->parent;
	return tmp;
}
