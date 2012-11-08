// Author: Michael Rivera
// Equation class, consisting of multiple Terms
// Requires: The Term class
// Value Semantics: Assignment operator and copy constructor untested.

#ifndef EQUATION
#define EQUATION

#include "Term.h"
#include "Node.h"

class Equation {
// Invariant: _leadterm_ points to the first term in the equation, or
//            to NULL if there are no terms.
// Invariant: termCount holds the number of terms in the equation.
//            (0 if there are none)
// Invariant: currentTerm is -1 if no terms exist, otherwise refers to
//            index of a persistent current term (it's like an iterator).

public:
  Equation();
  // Post: _leadterm_ = NULL, _currentTerm_ = 0;
  void addTerm(Term t);
  void getTermByI(int i);
  void getNextTerm(int i);

private:
  Node *leadterm;
  int currentTerm;
  int termCount;

};

#endif
