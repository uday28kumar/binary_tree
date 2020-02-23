#include<iostream>
#include<vector>
#include "binarytree.h"
using namespace std;

int main()
{
    /* Construct below tree
              1
            /   \
           /     \
          2       3
         /      /  \
        /      /    \
       4      5      6
             / \
            /   \
           7     8
	*/

	Node<int> *root = new Node<int>(1);
    root->left = new Node<int>(2);
    root->right = new Node<int>(3);
    root->left->left = new Node<int>(4);
    root->right->left = new Node<int>(5);
	root->right->right = new Node<int>(6);
	root->right->left->left = new Node<int>(7);
	root->right->left->right = new Node<int>(8);

	/* Construct below tree
              1
            /   \
           /     \
          2       3
         / \     / \
        /   \   /   \
       4     5 6     7
              / \
             /   \
            8     9
	*/

	Node<int> *root1 = new Node<int>(1);
    root1->left = new Node<int>(2);
    root1->right = new Node<int>(3);
    root1->left->left = new Node<int>(4);
    root1->left->right = new Node<int>(5);
    root1->right->left = new Node<int>(6);
	root1->right->right = new Node<int>(7);
	root1->right->left->left = new Node<int>(8);
	root1->right->left->right = new Node<int>(9);

	/* Construct below tree
              1
            /   \
           /     \
          2       3
         / \     / \
        /   \   /   \
       4     5 6     7
              / \
             /   \
            8     9
	*/

	Node<int> *root2 = new Node<int>(1);
    root2->left = new Node<int>(2);
    root2->right = new Node<int>(3);
    root2->left->left = new Node<int>(4);
    root2->left->right = new Node<int>(5);
    root2->right->left = new Node<int>(6);
	root2->right->right = new Node<int>(7);
	root2->right->left->left = new Node<int>(8);
	root2->right->left->right = new Node<int>(9);



    cout<<"Recursive Pre-Order Traversal: "; printBinaryTree(preOrderTraversal(root));
    cout<<"Iterative Pre-Order Traversal: "; printBinaryTree(iPreOrderTraversal(root));
    cout<<"Recursive Post-Order Traversal: "; printBinaryTree(postOrderTraversal(root));
    cout<<"Iterative Post-Order Traversal: "; printBinaryTree(iPostOrderTraversal(root));
    cout<<"Recursive In-Order Traversal: "; printBinaryTree(inOrderTraversal(root));
    cout<<"Iterative In-Order Traversal: "; printBinaryTree(iInOrderTraversal(root));
    cout<<"Recursive Level-Order Traversal: "; printBinaryTreeLevelWise(levelOrderTraversal(root));
    cout<<"Iterative Level-Order Traversal: "; printBinaryTreeLevelWise(iLevelOrderTraversal(root));
    cout<<"Reverse Level-Order Traversal: "; printBinaryTree(reverseLevelOrderTraversal(root));
    cout<<"Is Identical: "<<isIdentical(root1, root2)<<endl;
    cout<<"Height: "<<height(root)<<endl;

	return 0;
}
