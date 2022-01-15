#pragma once
#ifndef TRAVERSAL_H
#define TRAVERSAL_H

#include "node.h"

void printToken(ofstream& file, int depth, set<string> listOfWords);
void printPreorder(ofstream& file, Node* node);
void printInorder(ofstream& file, Node* node);
void printPostorder(ofstream& file, Node* node);

#endif