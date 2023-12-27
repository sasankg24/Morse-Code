#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "treeNode.h"

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;

class BST
{
public:
	BST();
    ~BST();
	void insert(const char &newChar, const string &newCode);
	void inOrderTraversal();
	void preOrderTraversal();
    string search(char character);
    TreeNode *getRoot();
private:
	TreeNode* mpRoot;
	void insert(TreeNode* pTree, const char& newChar, const string& newCode);
	void inOrderTraversal(TreeNode* pTree);
	void preOrderTraversal(TreeNode* pTree);
};

// all template declarations and definitions must be placed in a .h or .hpp file.
// if placed in a .cpp file, it will cause linker errors
template <class T>
T add(T n1, T n2); // declare the function template

// template? 
template <class T>
T add(T n1, T n2) // define the function template - T is replaced by a specific type when a call is made
{
	return n1 + n2; // we could be adding integers, floating-point numbers, strings, etc.
}