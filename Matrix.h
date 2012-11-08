// Author: Michael Rivera
// Matrix class: Matrices with entries that are Terms, as meant in mathmatics.
// Value Semantics: Hazardous

#ifndef MATH_MATRIX
#define MATH_MATRIX

#include "RealNumber.h"
#include <iostream>

using namespace std;

class Matrix {

/* invariant: all entries are RealNumbers
   invariant: m = number of rows/equations in this Matrix
   invariant: n = number of columns/variables in this Matrix
   invariant: m >= 1 && n >= 1
   invariant: The smallest value for an index is 1; that is, 
              the first row is row 1, and the first column is colum 1.
              */

public:
/* Constructors, Destructors, Assignment Operators */

   Matrix();
   /* Post: 1x1 matrix has been created &&
            all entries are real numbers equal to 0;
            */

   Matrix(const Matrix& refToCopy);
   /* Post: A new matrix has been created and returned, identical to that
            of refToCopy.
            */
   void operator =(const Matrix& refToCopy);
   /* Post: Copies values from refToCopy into this Matrix. */

   Matrix(int rows, int cols);
   /* Pre:  m >= 1 && n >= 1
      Post: mxn matrix has been created &&
            all entries are real numbers equal to 0;
            */

   ~Matrix();
   /* Post: Dynamic memory for this matrix has been returned
            to the heap;
            */

/* Accessors, Mutators */

   RealNumber getEntryAt(int i, int j) const;
   /* Pre:  1 <= i <= m && 1 <= <= n
      Post: Returns entry at (i,j) index
      */

   void setEntryAt(int i, int j, RealNumber n);
   /* Pre: 1 <= i <= m && 1 <= j <= n
      Post: Entry of the matrix at (i,j) has been set to the real number n.
      */

   void setEntryAt(int i, int j, int n);
   /* Calls setEntryAt(i, j, RealNumber(n)); */

   void addStaticArray(int row[], int size);
   // Uncomplete

   void swapRows(int r1, int r2);
   // Pre: 1 <= r1 <= m && 1 <= r2 <= m
   // Post: All entries in r1 have been interchanged with entries in r2.

   void addRowMultiple(int r1, int receivingRow, RealNumber factor);
   // Pre: 1 <= r1 <= m && 1 <= r2 <= m && factor != 0
   // Post: All entries in _r1_ have been multiplied by _factor_ and added
   //       to entries of _r2_ with respect to corresponding columns.

   void multiplyRow(int r1, RealNumber factor);
   // Pre: 1 <= _r1_ <= m && _factor_ != 0
   // Post: All entries in _r1_ have been multiplied by _factor_.

   void setToZero();
   /* Post: All entries == 0; */

/* Member Methods */

   int lTermLength();
   /* Post: Returns number of characters that the entry with the most
            characters to print takes up; */

   void gaussianElim(bool verbose=false);
   // Pre: m >= 1 && n >= 1
   //      No variables/columns exist without at least one coefficient other than 0.
   //      (This should be moved to a post condition)
   // Post:  Matrix is in row echelon form where:
   //        1) All zero rows are below all nonzero rows
   //        2) All leading entries have 0's below them
   //        3) All leading entries are to the right of the
   //           column of the leading entry in the row above.
   //        4) All leading entries are 1.
   //        If varbose==true, intermediate steps are printed.

   void rref(bool verbose=false);
   // Pre: m >= 1 && n >= 1
   //      No variables/columns exist without at least one coefficient other than 0.
   //      (This should be moved to a post condition)
   // Post:  Matrix is in reduced row echelon form where:
   //        1) All zero rows are below all nonzero rows
   //        2) All leading entries have 0's below and above them
   //        3) All leading entries are to the right of the
   //           column of the leading entry in the row above.
   //        4) All leading entries are 1.
   //        If varbose==true, intermediate steps are printed.

   Matrix minorOf(int excludedRow, int excludedCol) const;
   /* Pre: 1 <= excludedRow <= m && 1 <= excludedCol <= n
      Post: Returns a (m-1)x(n-1) matrix identical to this matrix
            except that excludedRow and excludedCol have been deleted.
            */

   RealNumber getDeterminant() const;
   /* Pre:  Matrix is a square matrix (m==n).
      Post: Returns determinant of this matrix.
      */

   void print();
   /* Post: Matrix has been printed to the standard output */

   friend istream& operator >>(istream& ins, Matrix& matrixToFill);
   /* Pre:  Matrix is entered in syntax:
            [[x, y, ..., z], [x, y, ... z], ..., [x, y, ..., z]]
            Matrix that is entered has at least one entry.
            No rows of the matrix have more entries than others.
      Post: mat is now a matrix holding the values entered.
      */

private:
   RealNumber** matrix;
   int m;
   int n;
};

#endif
