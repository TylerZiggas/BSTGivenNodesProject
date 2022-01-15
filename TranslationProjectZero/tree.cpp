/*
Author: Tyler Ziggas
Date: September 20, 2021
Project Description: This project takes in a file (optional) or user input and builds a binary search tree from the information given. 
	This information is placed into the BST by checking the first letter in the string, then placing it into the group it shares that letter with,
	or places itself in a different node depending on whether it is less or more than the last letter.  After the file or input has been fully read
	and put into the tree, we then run preorder, inorder, and postorder traversal.  We print each of the traversals into separate files while also 
	outputting the results of each traversal to the screen.
*/

#include <iostream>    
#include <string>    
#include <cstring>  
#include <cctype>    
#include <fstream>   
#include "tree.h"

Node* createRoot(string fileName) { // Attempt to create our tree by inserting our root node
	Node* root = NULL;
	ifstream file(fileName.c_str());

	if (file.is_open()) { // Check to see if hte file can be opened
		string input;
		while (getline(file, input)) {

			for (int counter = 0; counter < input.size(); counter++) {
				if (isalpha(input[counter])) {
					input[counter] = tolower(input[counter]);
				}
			}

			char* token = strtok(&input[0], " \t"); 

			while (token != NULL) { // If a suitable root was found, create it and insert it
				string word = token;
				string label = word.substr(0, 1);

				root = buildTree(root, 0, label, word);
				token = strtok(NULL, " \t");
			}
		}

	} else { // If the file cannot be opened, inform main that no root could be made
		cout << "File cannot be opened!" << endl;
		return NULL;
	}

	if (root == NULL) { // If the file could be read, but no root was given, inform main that no root could be made
		cout << "No Input received!" << endl;
	}

	file.close();
	return root;
}

// Node creation template found on https://www.geeksforgeeks.org/insert-a-node-in-binary-search-tree-iteratively/ 

Node* createNode(int currentDepth, string label, string word) { // Function for creation of our node with it's current depth, the label, and word given
	Node* tempNode = new Node;

	tempNode->depth = currentDepth;
	tempNode->label = label;
	tempNode->listOfWords.insert(word);

	tempNode->left = NULL; // Create left and right nodes for each node, set them to NULL initially as they don't have branches yet
	tempNode->right = NULL;

	return tempNode;
}


Node* buildTree(Node* currentNode, int currentDepth, string label, string word) { // Function to check where to insert the node into
	for (int counter = 0; counter < word.size(); counter++) {
		if (isalpha(word[counter])) {
			word[counter] = tolower(word[counter]);
		}
	}

	if (currentNode == NULL) { // Checking if the current node does not exist
		return createNode(currentDepth, label, word);

	} else if (label.compare(currentNode->label) < 0) { // If the label is less than 0, it becomes the left node
		currentDepth++;
		currentNode->left = buildTree(currentNode->left, currentDepth, label, word);

	} else if (label.compare(currentNode->label) > 0) { // If the label is greater than 0, it becomes the right node
		currentDepth++;
		currentNode->right = buildTree(currentNode->right, currentDepth, label, word);

	} else if (label.compare(currentNode->label) == 0) { // If the label is identical, it is inserted into the current node
		currentNode->listOfWords.insert(word);

	}

	return currentNode;
}
