// Author: Michael Rivera
// "Matrix.h" implementation

#include "Matrix.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;

void cspc(int num);

void cspc(int num) {
   for(int i=1; i<=num; i++)
      cout << " ";

   return;
}

Matrix::Matrix() {
   matrix = new RealNumber*[1];
   matrix[0] = new RealNumber[1];
   m = n = 1;
   setToZero();
   return;
}

Matrix::Matrix(const Matrix& refToCopy) {
   matrix = new RealNumber*[refToCopy.m];
   for(int i=1; i <= refToCopy.m; i++)
      matrix[i-1] = new RealNumber[refToCopy.n];
   m = refToCopy.m;
   n = refToCopy.n;

   for(int i=1; i<=m; i++)
      for(int j=1; j<=n; j++)
         matrix[i-1][j-1] = refToCopy.matrix[i-1][j-1];
}

void Matrix::operator =(const Matrix& refToCopy) {
   if(&refToCopy == this)
      return;

   // Checking that this Matrix has enough space allocated for matrix
   if(m != refToCopy.m || n != refToCopy.n) {
      // Deleting n cell-pointers (columns) of this matrix
      for(int i=m; i>=1; i--)
         delete [] matrix[i-1];
      // Deleting m pointers (the rows, whose subscripts were columns) of this matrix
      delete [] matrix;

      // Allocating enough space for new dimensions of refToCopy
      m = refToCopy.m;
      n = refToCopy.n;
      matrix = new RealNumber*[refToCopy.m];
      for(int i=1; i <= m; i++)
         matrix[i-1] = new RealNumber[n];
   }

   // Assignment
   for(int i=1; i<=m; i++)
      for(int j=1; j<=n; j++)
         matrix[i-1][j-1] = refToCopy.matrix[i-1][j-1];
}

Matrix::Matrix(int rows, int cols) {
   matrix = new RealNumber*[rows];
   for(int i=1; i<=rows; i++)
      matrix[i-1] = new RealNumber[cols];
   m = rows;
   n = cols;
   setToZero();
}

Matrix::~Matrix() {
   // Deleting n amount of cell in each row (there are m rows total)
   for(int i=m; i>=1; i--)
      delete [] matrix[i-1];

   // Deleting m amount of pointers that used to point to rows
   delete [] matrix;
}

void Matrix::setEntryAt(int i, int j, RealNumber r) {
   matrix[i-1][j-1] = r;
}

void Matrix::setEntryAt(int i, int j, int newNum) {
   RealNumber r(newNum);
   setEntryAt(i,j,r);

   return;
}

RealNumber Matrix::getEntryAt(int i, int j) const {
   return matrix[i-1][j-1];
}

   // STUMP
//   void Matrix::addStaticArray(int row[], int size) {
//      row = row; 
//      return;
//   }

void Matrix::swapRows(int r1, int r2) {
   RealNumber *temp = new RealNumber[n];
   for(int j=1;j<=n;j++) // Backup r1
      temp[j-1] = getEntryAt(r1,j); // refactor with dynamic data

   for(int j=1;j<=n;j++) // Copy r2 into r1
      setEntryAt(r1,j, getEntryAt(r2,j)); // refactor with dynamic data

   for(int j=1;j<=n;j++) // Copy temp into r2
      setEntryAt(r2,j, temp[j-1]); // refactor with dynamic data

   return;
}

void Matrix::multiplyRow(int r1, RealNumber factor) {
  for(int j=1;j<=n;j++)
    setEntryAt(r1,j, factor*getEntryAt(r1,j) );
  return;
}

void Matrix::addRowMultiple(int r1, int r2, RealNumber factor) {
  for(int j=1;j<=n;j++)
    setEntryAt(r2,j, getEntryAt(r2,j) + getEntryAt(r1,j)*factor );

  return;
}

int Matrix::lTermLength() {
   int largest=0;
   // Looping through each entry
   for(int i=1;i<=m;i++)
      for(int j=1;j<=n;j++) {
         int dig = getEntryAt(i,j).getPrintWidth();
      if(dig > largest)
         largest = dig;
      }
   return largest;
}

void Matrix::setToZero() {
   for(int i=1; i<=m; i++) {
      for(int j=1; j<=n; j++) {
         setEntryAt(i,j, RealNumber(0));
      }
   }

   return;
}

void Matrix::gaussianElim(bool verbose) {
  // Todo later: No variables/columns exist without at least one coefficient other than 0.

  int currentRow=1,currentColumn=1;
  while(currentRow<=m && currentColumn<=n) {
      
      // Putting a nonzero leading variable in the currentEntry
      if(getEntryAt(currentRow,currentColumn) == 0) {
         for(int i=currentRow+1; getEntryAt(currentRow,currentColumn) == 0 && i<=m; i++) {
            swapRows(currentRow,i);
            if(verbose) {
               cout << "\tR[" << currentRow << "] --> R[" << i << "]\n";
               cout << "\tR[" << i << "] --> R[" << currentRow << "]\n";
               print();
            }
         }
      }

      if(getEntryAt(currentRow,currentColumn) != 0) { // Don't touch if already 0

         // Reduce leading entry to 1
         RealNumber nonZeroC(RealNumber(1)/getEntryAt(currentColumn,currentRow));
         multiplyRow(currentRow, nonZeroC);
         if(verbose) {
            cout << "\t" << nonZeroC << "R[" << currentRow << "] --> R["
               << currentRow << "]\n";
            print();
         }

         // Adding nonzero multiples to other rows
         bool multipleAdded=false;  // Flag to mark if we make changes
         for(int i=currentRow+1;i<=m;i++) {
            RealNumber opposite(-getEntryAt(i,currentColumn));
            if(opposite != 0) {
               multipleAdded = true;
               addRowMultiple(currentRow,i,opposite);
               if(verbose)
                  cout << "\t" << opposite << "R[" << currentRow << "] + R["
                     << i << "] --> R[" << i << "]\n";
            }
         }
         if(verbose && multipleAdded)
            print();

         currentRow++;
      } // end if. Else, move to next column in this same row.

      currentColumn++;
  }

  return;
}

void Matrix::rref(bool verbose) {
   gaussianElim(verbose);

   // Scan each row, bottom to top...
   for(int i=m; i>=1; i--) {

      // for leading entries, or pivot columns
      int pivotColumn = 1;    // Potential pivot column.
      while(pivotColumn<=n && getEntryAt(i,pivotColumn) == 0)
         pivotColumn++;
      
      // If pivot column was found (other than (1,1) position)
      if(pivotColumn <=n && pivotColumn > 1) {
         for(int rowToDestroy=i-1;rowToDestroy>=1;rowToDestroy--) {
            RealNumber opposite(-getEntryAt(rowToDestroy,pivotColumn));
            addRowMultiple(i,rowToDestroy,opposite);
            if(verbose)
               cout << "\t" << opposite << "R[" << i << "] + R["
                  << rowToDestroy << "] --> R[" << rowToDestroy << "]\n";
         }
         if(verbose)
            print();
      }
   }
   
   return;
}

Matrix Matrix::minorOf(int excludedRow, int excludedCol) const {
   Matrix mminor(m-1, n-1);

   for(int i=1, iMinor=1; i<=m; i++) {
      if(i != excludedRow) {
         for(int j=1, jMinor=1; j<=n; j++) {
            if(j != excludedCol) {
               mminor.matrix[iMinor-1][jMinor-1] = matrix[i-1][j-1];
               jMinor++;
            }
         }
         iMinor++;
      }
   }

   return mminor;
}

RealNumber Matrix::getDeterminant() const {
   if(m==1 && n==1)
      return getEntryAt(1,1);
   else if(m==2 && n==2)
      return (getEntryAt(1,1)*getEntryAt(2,2) - getEntryAt(1,2)*getEntryAt(2,1));
   else {
      RealNumber determinant=0;
      for(int j=1; j<=n; j++) {
         determinant = determinant +
         (getEntryAt(1,j) *
         (((1+j)%2 == 0) ? 1 : -1) * 
         minorOf(1,j).getDeterminant());
      }

      return determinant;
   }

   return 0;
}

void Matrix::print() {
   int width = lTermLength()+1;

  // Printing top closing brackets
  cout << "--"; cspc((n*width)-1); cout << "--\n";

  // Printing
  for(int i=1; i<=m; i++) {
    cout << "|"; // leading side of this row
 
    for(int j=1; j<=n; j++) {
       cspc(width - getEntryAt(i,j).getPrintWidth());
       cout << getEntryAt(i,j);
    }
    cout << " |\n";  // closing side of this row
  }

  // Printing bottom closing brackets
  cout << "--"; cspc((n*width)-1); cout << "--\n";

  return;
}

istream& operator >>(istream& ins, Matrix& matrixToFill) {
   while(ins.get() != '['); // Eating leading '[' of whole matrix

   // Using fresh matrix; will assign its values to matrixToFill before returning.
   Matrix newM(1,1);

   // Reading first row and eshtablish set columns
   while(ins.get() != '['); // Eating leading '[' of row
   RealNumber nextNum;
   ins >> nextNum;
   newM.setEntryAt(1,1, nextNum);
   char charAfterEntry = ins.get(); // ',' ==> another column, or ']' ==> row is done
   while(charAfterEntry != ']') {   // repeating until closing ']' of row is found.

      Matrix matrixWithNewColumn = Matrix(1, newM.n+1);
      for(int j=1; j<=newM.n; j++)
         matrixWithNewColumn.setEntryAt(1,j,newM.getEntryAt(1,j));
      newM = matrixWithNewColumn;
      ins >> nextNum;
      newM.setEntryAt(1,newM.n, nextNum);
      charAfterEntry = ins.get();// ',' ==> another column, or ']' ==> done with row
   }

   charAfterEntry = ins.get();   // ',' ==> another row, or ']' ==> done with matrix
   while(charAfterEntry != ']') {   // While there are more ROWS in this matrix
      Matrix matrixWithNewColumn = Matrix(newM.m+1, newM.n);
      for(int i=1; i<=newM.m; i++)
         for(int j=1; j<=newM.n; j++)
            matrixWithNewColumn.setEntryAt(i,j,newM.getEntryAt(i,j));
      newM = matrixWithNewColumn;

      // Filling each column
      while(ins.get() != '['); // '['
      for(int j=1; j<=newM.n; j++) {
         ins >> nextNum;
         newM.setEntryAt(newM.m,j, nextNum);
         ins.get();  // ',' or ']' after last column
      }

      charAfterEntry = ins.get();   // ',' ==> another row, or ']' ==> done with matrix
   }

   matrixToFill = newM;
   return ins;
}
