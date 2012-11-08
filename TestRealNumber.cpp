/* File:    TestRealNumber.cpp
   Author:  Michael Rivera
   Descrip: A function suite to test the RealNumber class.
   */

#include "RealNumber.h"
#include <iostream>
#include <cassert>

using namespace std;

namespace TEST_REALNUMBER {

bool testClassBasics();

bool testAddition();

bool testSubtraction();

bool testMultiplication();

bool testDivision();

int testRealNumber() {
   cout << "Testing RealNumber... ClassBasics \t- "
      << (testClassBasics() ? "OKAY" : "FAILURE")
      << endl;
   cout << "Testing RealNumber... Addition \t\t- "
      << (testAddition() ? "OKAY" : "FAILURE")
      << endl;
   cout << "Testing RealNumber... Subtraction \t- "
      << (testSubtraction() ? "OKAY" : "FAILURE")
      << endl;
   cout << "Testing RealNumber... Multiplication \t- "
      << (testMultiplication() ? "OKAY" : "FAILURE")
      << endl;
   cout << "Testing RealNumber... Division \t\t- "
      << (testDivision() ? "OKAY" : "FAILURE")
      << endl;

   cout << endl;
   return 0;
}

bool testClassBasics() {
   bool passedTests=true;

   RealNumber a=1,b=-22,c=5+5,d(1),e(2,1),f(-3),g(2,3);

   if(passedTests)
      passedTests = (a == 1);
   if(passedTests)
      passedTests = (b == -22);
   if(passedTests)
      passedTests = (c == 10);
   if(passedTests)
      passedTests = (d == 1);
   if(passedTests)
      passedTests = (e == 2);
   if(passedTests)
      passedTests = (f == -3);
   if(passedTests)
      passedTests = (g != 2 && g != 3);

   RealNumber r1(20,30), r2(30,30), r3(30,20), r4(2,3), r5(3,2);
   RealNumber r6 = r4;
   if(passedTests)
      passedTests = (r1 == r4);
   if(passedTests)
      passedTests = (r5 == r3);
   if(passedTests)
      passedTests = (r2 != r3);
   if(passedTests)
      passedTests = (r1 != r3);
   if(passedTests)
      passedTests = (r6 == r4);

   return passedTests;
}

bool testAddition() {
   RealNumber
      one(1),
      two(2),
      half(1,2),
      twothirds(2,3),
      sevensix(7,6),
      sevensix2(14,12);

   assert(one + two == 3);
   assert(one + one == 2);
   assert(twothirds + half == sevensix);
   assert(twothirds + half == sevensix2);

   return true;
}

bool testSubtraction() {
   RealNumber
      zero = 0,
      one(1),
      half(1,2),
      twothirds(2,3),
      onesix(1,6),
      sevensix(7,6);

   assert(one - one == 0);
   assert(half - zero == half);
   assert(twothirds - half == onesix);
   assert(sevensix - twothirds == half);
   
   return true;
}


bool testMultiplication() {
   RealNumber
      zero = 0,
      one(1),
      two(2),
      half(1,2),
      twothirds(2,3),
      sevensix(7,6),
      onethird(1,3),
      neg(-1),
      seveneighteen(7,18);

   assert(-neg * one == one);
   assert(one * zero == 0);
   assert(one * sevensix == sevensix);
   assert(twothirds * half == onethird);
   assert(onethird * sevensix == seveneighteen);
   assert(half * two == one);
   return true;
}


bool testDivision() {
   RealNumber
      zero = 0,
      one(1),
      two(2),
      twothirds(2,3),
      twothou(2000),
      sevensix(7,6),
      onethird(1,3),
      sevensix2(14,12),
      seveneighteen(7,18);

   assert(zero / one == zero);
   assert(zero / seveneighteen == zero);
   assert(twothirds / onethird == 2);
   assert(two / one == two);
   assert(sevensix2 / sevensix == 1);
   assert(twothou / two == 1000);

   return true;
}

} // End TEST_REALNUMBER
