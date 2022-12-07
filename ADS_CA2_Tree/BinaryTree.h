#pragma once
#include "TNode.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <regex>
#include <random>
using namespace std;
//if E == Student (email, dob, address, id,...)
//then K = Key(email, dob, address)

template <typename K, typename E>
class BinaryTree
{
	void insertItem(TNode<K, E>* node, int& pos, int* arr);
	bool hasPath(TNode* root, vector<int>& arr, int x)
	{
		if (!root)
			return false;

		arr.push_back(root->data);

		if (root->data == x)
			return true;

		if (hasPath(root->getLeft(), arr, x) ||
			hasPath(root->getRight(), arr, x))
			return true;
  
		arr.pop_back();
		return false;
	}
	void printPath(TNode* root, int x)
	{
		vector<int> arr;

		if (hasPath(root, arr, x))
		{
			for (int i = 0; i < arr.size() - 1; i++)
				cout << arr[i] << "->";
			cout << arr[arr.size() - 1];
		}
		else
			cout << "No Path";
	}
	void createBalancedTree(BinaryTree<int>& tree, int min, int max, int* arr)
	{
		if (min < max)
		{
			int mid = (min + max) / 2;
			tree.add(arr[mid]);
			createBalancedTree(tree, min, mid, arr);
			createBalancedTree(tree, mid + 1, max, arr);
		}
	}
	void balance(BinaryTree<int>& tree)
	{
		int* arr = tree.toArray();
		int max = tree.count();
		tree.clear();
		createBalancedTree(tree, 0, max, arr);
		delete[] arr;
	}
public:
	TNode<K,E>* root;
	BinaryTree();
	void insert(K key, E data);
	bool remove(K key, E data);
	void clear();
	int count();

	void printInOrder();
	void printInOrder(TNode<K,E>* node);
	void printPreOrder();
	void printPreOrder(TNode<K,E>* node);
	void printPostOrder();
	void printPostOrder(TNode<K,E>* node);
	E* toArray(K);
	~BinaryTree();
	E* search(K key) {
		return nullptr;
	}

};
template <typename K, typename E>
BinaryTree<K,E>::BinaryTree()
{
	root = nullptr;
}

template <typename K, typename E>
void BinaryTree<K,E>::insert(K key, E data)
{
	if (root == nullptr)
	{
		root = new TNode<K key, E data>();
		root->setKey(key);
		root->setData(data);
	}
	else
	{
		root->insert(key,data);
	}
}
template <typename K, typename E>
int BinaryTree<K,E>::count()
{
	if (root == nullptr)
		return 0;
	return root->count();
}
template <typename K, typename E>
bool BinaryTree<K,E>::remove(K key,E data)
{
	TNode<K,E>* toBeRemoved = root;
	TNode<K,E>* parent = nullptr;
	bool found = false;

	while (!found && toBeRemoved != nullptr)
	{

		if (toBeRemoved->getData() == data)
		{

			found = true;
		}
		else
		{
			parent = toBeRemoved;
			if (toBeRemoved->getData() > data)
			{
				toBeRemoved = toBeRemoved->getLeft();
			}
			else
			{
				toBeRemoved = toBeRemoved->getRight();
			}
		}
	}
	if (!found)
		return false;

	if (toBeRemoved->getLeft() == nullptr || toBeRemoved->getRight() == nullptr)
	{
		BSTNode<T>* newChild;
		if (toBeRemoved->getLeft() == nullptr)
		{
			newChild = toBeRemoved->getRight();
		}
		else
		{
			newChild = toBeRemoved->getLeft();
		}
		if (parent == nullptr)
		{
			root = newChild;
		}
		else if (parent->getLeft() == toBeRemoved)
		{
			parent->setLeft(newChild);
		}
		else
		{
			parent->setRight(newChild);
		}
		return true;
	}

	TNode<K,E>* smallestParent = toBeRemoved;
	TNode<K,E>* smallest = toBeRemoved->getRight();
	while (smallest->getLeft() != nullptr)
	{
		smallestParent = smallest;
		smallest = smallest->getLeft();
	}
	toBeRemoved->setItem(smallest->getItem());
	if (smallestParent == toBeRemoved)
	{
		smallestParent->setRight(smallest->getRight());
	}
	else
	{
		smallestParent->setLeft(smallest->getRight());
	}

}

template <typename K, typename E>
void BinaryTree<K,E>::insertItem(TNode<K,E>* node, int& pos, int* arr)
{
	if (node != nullptr)
	{
		insertItem(node->getLeft(), pos, arr);
		arr[pos] = node->getData();
		pos++;
		insertItem(node->getRight(), pos, arr);
	}

}

template <typename K, typename E>
E* BinaryTree<K,E>::toArray(K)
{
	E* arr = new E[root->count()];
	int pos = 0;
	insertItem(root, pos, arr);
	return arr;
}

template <typename K, typename E>
void BinaryTree<K,E>::clear()
{
	delete root;
	root = nullptr;
}
template <typename K, typename E>
BinaryTree<K,E>::~BinaryTree()
{
	delete root;
}
template <typename K, typename E>
void printBT(const std::string& prefix, TNode<K,E>* node, bool isLeft)
{
	if (node != nullptr)
	{
		std::cout << prefix;

		std::cout << (isLeft ? "<--" : ">--");

		// print the value of the node
		std::cout << node->getKey() << std::endl;
		std::cout << node->getData() << std::endl;

		// enter the next tree level - left and right branch
		printBT(prefix + (isLeft ? "|   " : "    "), node->getLeft(), true);
		printBT(prefix + (isLeft ? "|   " : "    "), node->getRight(), false);
	}
}

template <typename K, typename E>
void printBT(TNode<K,E>* node)
{
	printBT("", node, true);
}

template <typename K, typename E>
void BinaryTree<K,E>::printInOrder()
{
	this->printInOrder(root);
	cout << endl;
}
template <typename K, typename E>
void BinaryTree<K,E>::printInOrder(TNode<K,E>* node)
{

	if (node != nullptr)
	{
		printInOrder(node->getLeft());
		cout << node->getItem() << " ";
		printInOrder(node->getRight());
	}
}

template <typename K, typename E>
void BinaryTree<K,E>::printPreOrder()
{
	this->printPreOrder(root);
	cout << endl;
}
template <typename K, typename E>
void BinaryTree<K,E>::printPreOrder(TNode<K,E>* node)
{

	if (node != nullptr)
	{
		cout << node->getData() << " ";
		printPreOrder(node->getLeft());
		printPreOrder(node->getRight());
	}
}

template <typename K, typename E>
void BinaryTree<K,E>::printPostOrder()
{
	this->printPostOrder(root);
	cout << endl;
}
template <typename K, typename E>
void BinaryTree<K,E>::printPostOrder(TNode<K,E>* node)
{

	if (node != nullptr)
	{

		printPostOrder(node->getLeft());
		printPostOrder(node->getRight());
		cout << node->getItem() << " ";
	}
}