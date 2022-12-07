#pragma once

template <class T>
class TNode
{

	TNode<T>* parent;
	TNode<T>* left;
	TNode<T>* right;
	T data;

public:
	TNode();
	TNode(T data);
	void setItem(T item);
	int count();
	void add(T item);
	TNode<T>* getParent();
	TNode<T>* getLeft();
	TNode<T>* getRight();
	void setLeft(TNode<T>* l);
	void setRight(TNode<T>* r);
	T getItem();
	~TNode();

};
template <class T>
TNode<T>::~TNode()
{
	delete left;
	delete right;
}
template <class T>
T TNode<T>::getItem()
{
	return this->data;
}
template <class T>
TNode<T>* TNode<T>::getLeft()
{
	return this->left;
}
template <class T>
TNode<T>* TNode<T>::getRight()
{
	return this->right;
}
template <class T>
TNode<T>* TNode<T>::getParent()
{
	return this->parent;
}
template <class T>
void TNode<T>::setLeft(TNode<T>* l)
{
	this->left = l;
}
template <class T>
void TNode<T>::setRight(TNode<T>* r)
{
	this->right = r;
}


template <class T>
TNode<T>::TNode()
{
	parent = nullptr;
	left = nullptr;
	right = nullptr;
}


template <class T>
TNode<T>::TNode(T data)
{
	parent = nullptr;
	left = nullptr;
	right = nullptr;
	this->data = data;
}
template <class T>
int TNode<T>::count()
{
	int c = 1;
	if (left != nullptr)
	{
		c += left->count();
	}
	if (right != nullptr)
	{
		c += right->count();
	}
	return c;
}

template <class T>
void TNode<T>::add(T item)
{
	if (item == this->data)
	{
		return;
	}
	else if (item < this->data)
	{
		if (left == nullptr)
		{
			left = new BSTNode<T>();
			left->data = item;
			left->parent = this;
		}
		else
		{
			left->add(item);
		}
	}
	else
	{
		if (right == nullptr)
		{
			right = new BSTNode<T>();
			right->data = item;
			right->parent = this;
		}
		else
		{
			right->add(item);
		}
	}
}

template <class T>
void TNode<T>::setItem(T item)
{
	this->data = item;
}