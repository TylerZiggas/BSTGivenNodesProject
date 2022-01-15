/*
Author: Tyler Ziggas
Date: September 20, 2021
Project Description: This project takes in a file (optional) or user input and builds a binary search tree from the information given. 
	This information is placed into the BST by checking the first letter in the string, then placing it into the group it shares that letter with,
	or places itself in a different node depending on whether it is less or more than the last letter.  After the file or input has been fully read
	and put into the tree, we then run preorder, inorder, and postorder traversal.  We print each of the traversals into separate files while also 
	outputting the results of each traversal to the screen.
*/


#include <iostream> // Project inclusions for basics such as cout, cin, getline, files, etc
#include <string>  
#include <cstring>   
#include <cstdio>       
#include <fstream>     
#include "node.h" // Headers for our programmer created files
#include "tree.h"
#include "traversal.h"

using namespace std;

int main(int argc, char* argv[]) {
	string fileName; // Create strings necessary for the project
	string outputFileName;
	string userInput;
	Node* root = NULL; // Declare the root as NULL until we are given a root

	switch (argc) { 
		case 1: { // If there was one argument, no file name was given, prepare to take user input
			ofstream tempFile;
			fileName = "input.fl2021";
			tempFile.open(fileName.c_str()); // Open a temporary file to start storing information given to us by the user

			cout << "Please enter alphanumeric characters and enter an empty line when you are finished." << endl;

			do { // Loop through user input and store it into our temporary file
				getline(cin, userInput);

				tempFile << userInput << " ";
			} while (!userInput.empty());

			tempFile.close();
			outputFileName = "output";
			break;

		} case 2: { // If there were two arguments, a potential file name was given
			cout << "File name given..." << endl << endl;

			fileName = argv[1];
			size_t fileType = fileName.find("."); // Search for our period in the file name, will need to append our own if none is found

			if (fileType == string::npos) {
				outputFileName = fileName;
				fileName.append(".fl2021"); // Appending out file with .fl2021, for our season and year of this course

			} else {
				outputFileName = fileName.substr(0, fileType);

			}
			break;

		} default: { // If there are more than two arguments, user should either have only executed the code, or executed it with a file name
			cout << "Too many arguments received!" << endl;
			return EXIT_FAILURE;

		}
	}

	root = createRoot(fileName); // Attempt to build the tree and create the root node
	if (root == NULL) { // Exit our program if no node could be created, nothing can be done after this
		cout << "No root found, exiting..." << endl;
		return EXIT_FAILURE;

	}

	ofstream outputFile;

	// Preorder Traversal file created, output preorder traversal and then write it to the newly created file 
	outputFile.open((outputFileName + ".preorder").c_str());
	cout << "Preorder Traversal of This Tree: " << endl;
	cout << "---------------------------------" << endl;
	outputFile << "Preorder Traversal of This Tree: " << endl;
	outputFile << "---------------------------------" << endl;
	printPreorder(outputFile, root);
	cout << "End of Preorder Traversal" << endl << endl;
	outputFile << "End of Preorder Traversal" << endl << endl;
	outputFile.close();

	// Inorder Traversal file created, output inorder traversal and then write it to the newly created file 
	outputFile.open((outputFileName + ".inorder").c_str());
	cout << "Inorder Traversal of This Tree: " << endl;
	cout << "---------------------------------" << endl;
	outputFile << "Inorder Traversal of This Tree: " << endl;
	outputFile << "---------------------------------" << endl;
	printInorder(outputFile, root);
	cout << "End of Inorder Traversal" << endl << endl;
	outputFile << "End of Inorder Traversal" << endl << endl;
	outputFile.close();

	// Postorder Traversal file created, output postorder traversal and then write it to the newly created file 
	outputFile.open((outputFileName + ".postorder").c_str());
	cout << "Postorder Traversal of This Tree: " << endl;
	cout << "---------------------------------" << endl;
	outputFile << "Postorder Traversal of This Tree: " << endl;
	outputFile << "---------------------------------" << endl;
	printPostorder(outputFile, root);
	cout << "End of Postorder Traversal" << endl << endl;
	outputFile << "End of Postorder Traversal" << endl << endl;
	outputFile.close();

	return EXIT_SUCCESS;
}
