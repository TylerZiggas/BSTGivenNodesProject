#pragma once
#ifndef NODE_H
#define NODE_H

#include <string>
#include <set>

using namespace std;

// Our struct for the nodes of the binary search tree

typedef struct node { 
	int depth;
	string label;           
	set<string> listOfWords;         
	struct node *left, *right;
} Node;

#endif