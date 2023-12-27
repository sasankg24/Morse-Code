#include "binarySearch.h"

// C++ has a standard template library (STL)
#include <list>

int main(void)
{
	BST tree; // default constructor makes it empty

	// the compiler will see the types of the arguments and then generate code for
	// a specific version of add () that works on those types based on our function template (found in BST.h)
	
    //sets a new node equal to null
    TreeNode *newNode = NULL;
    //calls the in order traversal which puts it in number and letter order
    tree.inOrderTraversal();
    //calls pre order traversal which puts it in the binary order
    tree.preOrderTraversal();
    //sets the new node equal to the root node
    newNode = tree.getRoot();
    //opens the convert text to be able to read the characters
    ifstream convert("Convert.txt");
    char character;
    //gets each character from the convert file
    while (convert.get(character)){
        //converts all characters to uppercase 
        character = toupper(character);
        //if there is a space in the file, it adds three spaces to the morse code
        if(character == ' '){
            cout << "   ";
        }
        //if there is a new line in the file, it adds a new file to the morse code
        else if(character == '\n'){
            cout << endl;
        }
        //if the letter matches, it calls the search function to display the morse code, and adds a space between each piece of morse code
        else{
            cout << tree.search(character) << " ";
        }
    }
    //closes the file
    convert.close();

	return 0;
}