#include <iostream>
#include <fstream>
#include <string>
#include "binarySearch.h"
using namespace std;
BST::BST()
{
    //opens the morse table file to read
    ifstream input("MorseTable.txt");
    //makes two string variables 
    string line;
    string morse;
    char character;
    //sets the root node to null
    mpRoot = NULL;
    //goes through the entire file line by line
    while(!input.eof()){
        //input gets the line string
        input >> line;
        //setting the character variable to get the character from the file
        character=line[0];
        input >> line;
        //setting the morse variable to the morse code string
        morse=line;
        //calls the insert function and sends the parameters character and morse code
        insert(character, morse);
    }    
    //closes morse file
    input.close();
}
BST::~BST(){
    //destroys the tree
    if(mpRoot != NULL){
        delete mpRoot;
    }
}

void BST::insert(const char& newChar, const string& newCode) // public version
{
	insert(this->mpRoot, newChar, newCode);
}

void BST::inOrderTraversal()
{
	inOrderTraversal(this->mpRoot);
}

void BST::preOrderTraversal()
{
	preOrderTraversal(this->mpRoot);
}

void BST::insert(TreeNode* pTree, const char& newChar, const string& newCode)
{
	// base case?
	if (pTree == NULL)
	{
		// inserting into an empty tree
		this->mpRoot = new TreeNode(newCode, newChar);
	}
	else
	{
		// the tree is not empty
		if (newChar > pTree->getChar())
		{
			// traverse down right subtree
			if (pTree->getRightPtr() == NULL)
			{
				// insert now
				pTree->setRightPtr(new TreeNode(newCode, newChar));
			}
			else
			{
				// we have to traverse further down the right subtree
				insert(pTree->getRightPtr(), newChar, newCode);
			}
		}
		else if (newChar < pTree->getChar())
		{
			// insert into the left subtree
			if (pTree->getLeftPtr() == NULL)
			{
				pTree->setLeftPtr(new TreeNode(newCode, newChar));
			}
			else
			{
				// go further down left subtree
				insert(pTree->getLeftPtr(), newChar, newCode);
			}
		}
		else
		{
			cout << "duplicate name: " << newChar << endl;
		}
	}
}

void BST::inOrderTraversal(TreeNode* pTree)
{
    
	if (pTree != NULL)
	{
		//recursion so it keeps going left until the left is pointing to null
		inOrderTraversal(pTree->getLeftPtr());
        //prints out the morse code and character
		cout << pTree->getData() << " " << pTree->getChar() << endl;
        //goes through the right side until it points to null
		inOrderTraversal(pTree->getRightPtr());
	}
    if(pTree == NULL){
        //if the tree equals null that means its the last node, so using return, goes back a node
        return;
    }
}

void BST::preOrderTraversal(TreeNode* pTree)
{
	if (pTree != NULL)
	{
		//prints the first node in the tree
		cout << pTree->getChar() << endl;
        //traverses to the left side untill it points to null
		preOrderTraversal(pTree->getLeftPtr());
        //traverses to the right side untill it points to null
		preOrderTraversal(pTree->getRightPtr());
	}
    if(pTree == NULL){
        //if the tree equals null that means its the last node, so using return, goes back a node
        return;
    }
}
string BST::search(char character){
    //makes a string variable and a temp node
    string code;
    TreeNode *temp = NULL;
    //setting the temp node to the root node
    temp = mpRoot;
    while(temp != NULL){
        //traverses left if the character we are looking for is less than the node to the left
        if(character < temp->getChar()){
            temp = temp->getLeftPtr();
        }
        //traverses right if the character we are looking for is less than the node to the right
        else if(character > temp->getChar()){
            temp = temp->getRightPtr();
        }
        //if the character matches with the character that we are looking for it sets the code string as the correct morse code and then returns that morse code
        else if(character == temp->getChar()){
            code = temp->getData();
            return code;
        }
    }
    return "";
}
TreeNode *BST::getRoot(){
    //returns the root node
    return mpRoot;
}