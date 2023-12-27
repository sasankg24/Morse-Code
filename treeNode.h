#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::ifstream;
using std::ofstream;
using std::fstream;

using std::string;

class TreeNode
{
public:
	TreeNode(const string& newData);
    TreeNode(const string mName, char single);
    TreeNode();
	string getData() const;
    void setData(string morse);
    char getChar() const;
    void setChar(char letter);
	TreeNode* getRightPtr() const;
	void setRightPtr(TreeNode* newpRight);
	TreeNode* getLeftPtr() const;
	void setLeftPtr(TreeNode* newpLeft);
    
private:
	string morseCode;
    char character;
	TreeNode* mpLeft, 
		* mpRight;
};