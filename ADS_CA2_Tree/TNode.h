#pragma once

template <typename K, typename E>
class TNode
{
private:
	K key;
	E data;

	TNode* pLeft, * pRight;

public:
	TNode();
	TNode(K key, E data);
	bool insert(K key, E data) {
		return false;
	}

	void setData(E data) { this->data = data; }
	E getData() const { return this->data; }
	void setKey(K key) { this->key = key; }
	E getKey() const { return this->key; }
	TNode(K key, E data);
	int count();
	void add(K key, E data);
	TNode<K, E>* getParent();
	TNode<K, E>* getLeft();
	TNode<K, E>* getRight();
	void setLeft(TNode<K, E>* l);
	void setRight(TNode<K, E>* r);
	~TNode();

};
template <typename K, typename E>
TNode<K, E>::~TNode()
{
	delete left;
	delete right;
}
template <typename K, typename E>
TNode<K, E>* TNode<K,E>::getLeft()
{
	return this->left;
}
template <typename K, typename E>
TNode<K, E>* TNode<K,E>::getRight()
{
	return this->right;
}
template <typename K, typename E>
TNode<K,E>* TNode<K,E>::getParent()
{
	return this->parent;
}
template <typename K, typename E>
void TNode<K,E>::setLeft(TNode<K,E>* l)
{
	this->left = l;
}
template <typename K, typename E>
void TNode<K,E>::setRight(TNode<K,E>* r)
{
	this->right = r;
}


template <typename K, typename E>
TNode<K,E>::TNode()
{
	parent = nullptr;
	left = nullptr;
	right = nullptr;
}

template <typename K, typename E>
TNode<K,E>::TNode(K key, E data)
{
	parent = nullptr;
	left = nullptr;
	right = nullptr;
	this->key = key;
	this->data = data;
}
template <typename K, typename E>
int TNode<K,E>::count()
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

template <typename K, typename E>
void TNode<K,E>::add(K key, E data)
{
	if (item == this->data)
	{
		return;
	}
	else if (item < this->data)
	{
		if (left == nullptr)
		{
			left = new TNode<K,E>();
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
			right = new TNode<K,E>();
			right->data = item;
			right->parent = this;
		}
		else
		{
			right->add(item);
		}
	}
}
