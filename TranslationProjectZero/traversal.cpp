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
#include <cstdio>   
#include <string>        
#include <fstream>      
#include "traversal.h"

void printToken(ofstream& file, int depth, set<string> listOfWords) { // Generic function that prints the token we are currently on
	for (int counter = 0; counter < depth; counter++) { // For loop that creates spaces depending on the depth of the node
		cout << "  ";
		file << "  ";
	}

	cout << (*listOfWords.begin()).substr(0, 1) << ": "; // Putting the beginning letter of the string to show which node it is
	file << (*listOfWords.begin()).substr(0, 1) << ": ";

	for (set<string>::iterator iteration = listOfWords.begin(); iteration != listOfWords.end(); iteration++) { // Loop through the words to display them for the node
		cout << *iteration << " ";
		file << *iteration << " ";
	}

	cout << endl;
	file << endl;
}


// Traversal Template Used from https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/

void printPreorder(ofstream& file, Node* node) { // Print function for our preorder traversal
	if (node == NULL) {
		return;
	}

	printToken(file, node->depth, node->listOfWords);
	printPreorder(file, node->left);
	printPreorder(file, node->right);
}

void printInorder(ofstream& file, Node* node) { // Print function for our inorder traversal
	if (node == NULL) {
		return;
	}

	printInorder(file, node->left);
	printToken(file, node->depth, node->listOfWords);
	printInorder(file, node->right);
}

void printPostorder(ofstream& file, Node* node) { // Print function for our postorder traversal
	if (node == NULL) {
		return;
	}

	printPostorder(file, node->left);
	printPostorder(file, node->right);
	printToken(file, node->depth, node->listOfWords);
}
