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
		if (Find(root, (n->GetData())->GetKey()) != NULL)
		{
			throw "The keys are equal. Paste imposible";
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
					tmp = tmp->GetLeft();
			}
			if (prev->GetData()->GetKey() > n->GetData()->GetKey())
			{
				prev->SetLeft(n);
				(prev->GetLeft())->SetParent(prev);
			}
			else
			{
				prev->SetRight(n);
				(prev->GetRight())->SetParent(prev);
			}
		}
}
