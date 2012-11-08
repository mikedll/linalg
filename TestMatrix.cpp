/* File:    TestMatrix.cpp
   Author:  Michael Rivera
   Descrip: A suite of tests to test the Matrix class.
   */

#include <iostream>
#include <fstream>

#include "Matrix.h"

using namespace std;

namespace TEST_MATRIX {

bool testClassBasics();

bool testMultiplyRows();

bool testAddRowMultiple();

int testMatrix() {
   cout << "Testing Matrix... MultiplyRows \t\t- "
      << (testMultiplyRows() ? "OKAY" : "FAILURE")
      << endl;
   cout << "Testing Matrix... AddRowMultiple \t- "
      << (testAddRowMultiple() ? "OKAY" : "FAILURE")
      << endl;

   cout << endl;
   return 0;
}

bool testClassBasics() {
   bool passedTests = true;

   return passedTests;
}

bool testMultiplyRows() {
   bool passedTests = true;

   // Multiply rows
   Matrix b(3,3);
   b.setEntryAt(1,1,1);  b.setEntryAt(1,2,2);  b.setEntryAt(1,3,3);
   b.setEntryAt(2,1,1);  b.setEntryAt(2,2,2);  b.setEntryAt(2,3,3);
   b.setEntryAt(3,1,1);  b.setEntryAt(3,2,2);  b.setEntryAt(3,3,3);
   b.multiplyRow(1,2);
   b.multiplyRow(2,3);
   b.multiplyRow(3,4);

   if(!(b.getEntryAt(1,2) == 4
      && b.getEntryAt(1,3) == 6
      && b.getEntryAt(2,3) == 9
      && b.getEntryAt(3,1) == 4
      && b.getEntryAt(3,2) == 8))
      passedTests = false;

   return passedTests;
}


bool testAddRowMultiple() {
   bool passedTests = true;

  // addRowMultiple
  Matrix c(3,3);
  c.setEntryAt(1,1,1);  c.setEntryAt(1,2,2);  c.setEntryAt(1,3,3);
  c.setEntryAt(2,1,1);  c.setEntryAt(2,2,2);  c.setEntryAt(2,3,3);
  c.setEntryAt(3,1,1);  c.setEntryAt(3,2,2);  c.setEntryAt(3,3,3);
  c.addRowMultiple(1,3,2); // 3,6,9
  c.addRowMultiple(2,3,4); // 7,14,21
  c.addRowMultiple(1,3,3); // 10,20,30
  if(!(c.getEntryAt(3,1) == 10
     && c.getEntryAt(3,2) == 20
     && c.getEntryAt(3,3) == 30))
     passedTests = false;

  return passedTests;
}

} // End Test Matrix
