// Author: Michael Rivera
// Node struct: Nodes for linked lists, initially designed for the Term class.

#ifndef TERM_NODE
#define TERM_NODE

#include "Term.h"

typedef Term dataType;

struct Node {
  dataType data;
  Node *nextNode;
};

#endif
