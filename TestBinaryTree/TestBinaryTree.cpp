#include "pch.h"
#include "CppUnitTest.h"
#include "../ADS_CA2_Tree/BinaryTree.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestBinaryTree
{
	TEST_CLASS(TestBinaryTree)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
		}
		TEST_METHOD(TestAddToEmptyTree)
		{
			BinaryTree<int> tree;
			tree.add(1);
			Assert::IsNotNull(tree.root);
			Assert::AreEqual(1, tree.root->getItem());
		}
		TEST_METHOD(TestAddToRootLeft)
		{
			BinaryTree<int> tree;
			tree.add(2);
			tree.add(1);
			Assert::IsNotNull(tree.root);
			Assert::AreEqual(2, tree.root->getItem());
			BSTNode<int>* left = tree.root->getLeft();
			Assert::IsNotNull(left);
			Assert::AreEqual(1, left->getItem());
		}
		/*
	This test ensures a node is created at the root when
	an element is added to an empty binary tree
*/
		TEST_METHOD(TestAddToEmptyTree)
		{
			BinaryTree<int> tree;
			tree.add(1);
			Assert::IsNotNull(tree.root);
			Assert::AreEqual(1, tree.root->getItem());
		}
        TEST_METHOD(BinaryTreeTest, AddTest)
        {
            // Create a new BinaryTree object.
            BinaryTree<int, int> tree;

            // Add some test data to the tree.
            tree.insert(10, 100);
            tree.insert(20, 200);
            tree.insert(15, 150);

            // Verify that the data was added to the tree correctly.
            EXPECT_EQ(tree.get(10), 100);
            EXPECT_EQ(tree.get(20), 200);
            EXPECT_EQ(tree.get(15), 150);
        }
	};
}
