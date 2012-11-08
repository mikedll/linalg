/* File:    RealNumber.h
   Author:  Michael Rivera
   Descrip: RealNumber class encapsulates the idea of a real number in mathmatics.
   Val Sem: Static Memory, N/A
   */

#ifndef MATH_REALNUMBER
#define MATH_REALNUMBER

#include <iostream>
#include <string>

using namespace std;

class RealNumber {

/* Invariant: denom != 0
   Invariant: GCD(num, denom) == 1
   */

public:
/* Constructors, Destructors; */

   RealNumber();
   /* Post: num == 0 && denom == 1; */
   RealNumber(int n);
   /* Post: num == n && denom == 1 */
   RealNumber(int n, int d);
   /* Pre:  d != 0
      Post: num == n && denom == d;
      */

/* Mutators, Accessors; */

   int getNum() const { return num; }
   /* Post: Returns num; */
   int getDenom() const { return denom; }
   /* Post: Returns denom; */
   void setNum(int n);
   /* Post: num == n;  */
   void setDenom(int d);
   /* Pre:  d != 0
      Post: denom == d; */

/* Member Methods */ 

   void print() const;
   /* Post: RealNumber has been printed to the screen in form "num/denom";
            If denum == 1, denom & "/" is omited;
            */

   int getPrintWidth();
   /* Post: Returns number of characters print() will print; */

   void reduce();
   /* Post: GCD(num,denom) == 1 (no changes if num == 0);
            denom > 0
            */

   void resolveNegative();
   /* Post: denom is not negative. */

/* Overloaded Operators */

   RealNumber operator-();

   RealNumber operator+(RealNumber r2);
   RealNumber operator-(RealNumber r2);
   RealNumber operator*(RealNumber r2);
   RealNumber operator/(RealNumber r2);
   RealNumber operator=(int n);

   bool operator==(RealNumber r2);
   bool operator==(int n);
   bool operator!=(RealNumber r2);
   bool operator!=(int n);

   bool operator>=(RealNumber r2);
   bool operator<=(RealNumber r2);
   bool operator>(RealNumber r2);
   bool operator<(RealNumber r2);

   friend ostream& operator <<(ostream& outs, const RealNumber r2);
   friend istream& operator >>(istream& ins, RealNumber& r2);

private:
   int num;
   int denom;

};

#endif
