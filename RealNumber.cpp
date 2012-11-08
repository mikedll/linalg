/* File:    RealNumber.cpp
   Author:  Michael Rivera
   Descrip: Implements RealNumber.h
   Val Sem: Assignment Operator OK
   */

#include "RealNumber.h"

using namespace std;

int GCD(int a, int b);
/* Pre:  a != 0 && b != 0
   Post: Returns greatest common divisor of a and b.
   */

int GCD(int a, int b) {
   a = (a < 0 ? -a : a);
   b = (b < 0 ? -b : b);
   int gcd = a;
   if(b < a) gcd = b;

   // Not optimized
   while(gcd > 0 && !(a%gcd == 0 && b%gcd == 0))
      gcd--;
   
   return gcd;
}

RealNumber::RealNumber() {
   num = 0;
   denom = 1;
}

RealNumber::RealNumber(int n) {
   num = n;
   denom = 1;
}

RealNumber::RealNumber(int n, int d) {
   if(d == 0)
      d = 1;

   num = n;
   denom = d;

   reduce();
   return;
}


void RealNumber::setNum(int n) {
   num = n;

   return;
}

void RealNumber::setDenom(int d) {
   denom = d;

   return;
}

void RealNumber::print() const  {
   cout << num;
   if(denom != 1)
      cout << "/" << denom;

   return;
}

int RealNumber::getPrintWidth() {
   int n = num;
   int d = denom;
   int width = 1;         // 1's digit of numberator
   if(num < 0)
      width++;            // Account for negative sign

   while((n / 10) != 0) {  // Add digits in numerator beyond 1's place
      width++;
      n /= 10;
   }

   if(d > 1)           // Add character for "/" of fraction
      width += 2;      // and 1's digit of denominator

      while((d / 10) != 0) {// Add digits in denominator beyond 1's place
      width++;
      d /= 10;
   }

   return width;
}
void RealNumber::reduce()  {
   if(num == 0) {
      denom = 1;
      return;
   }

   int gcd = GCD(num, denom);
   num /= gcd;
   denom /= gcd;

   resolveNegative();
   return;
}
void RealNumber::resolveNegative() {
   if(denom < 0) {
      denom = -denom;
      num = -num;
   }

   return;
}

RealNumber RealNumber::operator-() {
   return RealNumber(-num, denom);
}

RealNumber RealNumber::operator +(RealNumber r2) {
   RealNumber sum(num,denom);

   if(sum.denom != r2.denom) {// Using denom*r2.denom for common denominator
      sum.denom *= r2.denom;
      sum.num *= r2.denom;
   
      r2.num *= (sum.denom/r2.denom);   
   }
   sum.num += r2.num;         // Denoms are equal, adding numerators

   sum.reduce();
   return sum;
}

RealNumber RealNumber::operator -(RealNumber r2) {
   RealNumber sum(num,denom);

   if(sum.denom != r2.denom) {
      sum.denom *= r2.denom;  // Using denom*r2.denom for common denominator
      sum.num *= r2.denom;

      r2.num *= (sum.denom/r2.denom);
   }
   sum.num -= r2.num;         // Denoms are equal, adding numerators
   
   sum.reduce();
   return sum;   
}

RealNumber RealNumber::operator *(RealNumber r2) {
   RealNumber product(num,denom);

   product.num *= r2.num;
   product.denom *= r2.denom;

   product.reduce();
   return product;
}

RealNumber RealNumber::operator /(RealNumber r2) {
   RealNumber dividend(num,denom);

   dividend.num *= r2.denom;
   dividend.denom *= r2.num;

   dividend.reduce();
   return dividend;
}

RealNumber RealNumber::operator =(int n) {
   num = n;
   denom = 1;

   return *this;
}

bool RealNumber::operator ==(RealNumber r2) {
   return (num == r2.num && denom == r2.denom);
}
bool RealNumber::operator ==(int n) {
   return (denom == 1 && num == n);
}
bool RealNumber::operator !=(RealNumber r2) {
   return !(num == r2.num && denom == r2.denom);
}
bool RealNumber::operator !=(int n) {
   return !(denom == 1 && num == n);
}

ostream& operator <<(ostream& outs, const RealNumber r2) {
   outs << r2.num;
   if(r2.denom != 1)
      outs << "/" << r2.denom;

   return outs;
}
istream& operator >>(istream& ins, RealNumber& r2) {
   ins >> r2.num;
   if(ins.peek() == '/') {
      ins.get();
      ins >> r2.denom;
   }
   else
      r2.denom = 1;

   r2.reduce();
   return ins;
}
