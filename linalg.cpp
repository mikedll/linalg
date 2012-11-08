#include <iostream>
#include <fstream>

#include "Matrix.h"
#include "Equation.h"
#include "Term.h"
#include "Node.h"

// Test Suites - be careful not to double-define these
#include "TestRealNumber.cpp"
#include "TestMatrix.cpp"

using namespace std;

int menuChoice();

int main () {

   //TEST_REALNUMBER::testRealNumber();
   //TEST_MATRIX::testMatrix();

   int choice=menuChoice();
   while(choice != 4) {
      if(choice == 1) {
         cout << "Enter matrix to take determinant of\n";
         Matrix getdet;
         cin >> getdet;
         getdet.print();
         cout << "Determinant: " << getdet.getDeterminant() << endl;
      }
      if(choice == 2) {
         cout << "Enter matrix to row-reduce\n";
         Matrix reducable;
         cin >> reducable;
         reducable.rref(true);
         cout << "Reduced: \n";
         reducable.print();
      }
      if(choice == 3) {
         cout << "Enter 5 numbe1rs to add:\n";
         RealNumber r1, r2, r3, r4, r5;
         cin >> r1 >> r2 >> r3 >> r4 >> r5;
         cout << "Sum: " << r1 + r2 + r3 + r4 + r5 << endl;
      }
      choice=menuChoice();
   }

   return 0;
}

int menuChoice() {
   cout << "What would you like to do?\n";
   cout << "1) Take Determinant  2) Row-Reduce a Matrix  3) Add  4) Exit\n";
   int choice=4;
   cin >> choice;

   return choice;
}
