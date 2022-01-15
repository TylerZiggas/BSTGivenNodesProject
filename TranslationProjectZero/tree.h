#pragma once
#ifndef TREE_H
#define TREE_H

#include <string>
#include "node.h"
using namespace std;

Node* createRoot(string fileName);
Node* createNode(int currentDepth, string label, string word);
Node* buildTree(Node* currentNode, int currentDepth, string label, string word);

#endif