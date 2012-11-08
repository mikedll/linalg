// Author: Michael Rivera
// Term class: A constant coefficient and a variable, as in the world of mathmatics.
// Requries Term class, standard namespace
// Value Semantics: Copy Constructor & Assignment Operator are untested.

#ifndef TERM
#define TERM

class Term {

public:
  Term();
  int getCo() { return coefficient; }
  int getVar() { return variable; }
  int getVarPower() { return power; }
  void setCo(int n) { coefficient = n; }
  void setVar(int n) { variable = n; }
  void setVarPower(int n) { power = n; }

private:
  int coefficient;
  int variable;
  int power;

};

#endif
