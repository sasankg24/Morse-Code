#include "treeNode.h"

TreeNode::TreeNode()
{
    mpLeft = NULL;
    mpRight = NULL;
}
TreeNode::TreeNode(const string& newData)
{
	this->morseCode = newData;
	this->mpRight = this->mpLeft = nullptr;
}

string TreeNode::getData() const
{
	return this->morseCode;
}
char TreeNode::getChar() const
{
    return character;
}
void TreeNode::setChar(char letter)
{
    character = letter;
}
void TreeNode::setData(string morse)
{
    morseCode = morse;
}
TreeNode* TreeNode::getRightPtr() const
{
	return this->mpRight;
}

void TreeNode::setRightPtr(TreeNode* newpRight)
{
	this->mpRight = newpRight;
}

TreeNode* TreeNode::getLeftPtr() const
{
	return this->mpLeft;
}

void TreeNode::setLeftPtr(TreeNode* newpLeft)
{
	this->mpLeft = newpLeft;
}
TreeNode::TreeNode(const string mName, char single){
    morseCode = mName;
    character = single;
}