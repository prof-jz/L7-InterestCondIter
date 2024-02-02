/***************************************************
*  Alabama A&M University - EE109 - Spring 2024
*  Homework 2 - Loan Calculator++
*  By: Prof J Zehnpfennig, PE
*  Created: Feb. 1, 2024
*  Last Updated: Feb. 1, 2024
*  Tested by:
*  Tested on:
***************************************************/
  
#include <iostream>
#include <math.h>
#include <string.h>
#include<limits>

using namespace std;

int getLoops();
//getLoops() collects the numbers of loans the user wants to calculate.  It returns the number of loans as an integer.

void getLoan(); 
//getLoan() collects the loan information from the user and passes the information to outputs().  getLoan() does not return a value.

void outputs(int P, float r, int n, float t);
//outputs() calculates the monthly payment, total interest, and total payment for each loan.  It displays the information to the user.  outputs() does not return a value.

int getInt();
//getInt() collects an integer from the user.  It returns the integer as an integer.  It also checks for invalid input.

float getFloat();
//getFloat() collects a float from the user.  It returns the float as a float.  It also checks for invalid input.

int main() 
{
  int x = getLoops(); 
  //x is the number of loans the user wants to calculate.
  for (int y = 0; y < x; y++)
  {
    getLoan();
    //getLoan() is called x times, once for each loan the user wants to calculate.
  }
} //end of main()


int getLoops()
{
  int loops = 0;
  //loops is the number of loans the user wants to calculate
  char errorIn = 'Y';
  //errorIn is the error control character

  while (errorIn != 'N' && errorIn != 'n')
    {
      cout << "\n\nHow many loans would you like to calculate? (1, 2, or 3)? ";
      loops = getInt();     
      if (loops > 0 && loops < 4)
        errorIn = 'N';
      //errorIn is set to 'N' to exit the loop only if the user enters a valid number of loans: 1, 2, or 3.
    }
 return(loops); 
}//end of getLoops()


void getLoan()
{
    int number = 0.0, term = 0;
  //number is the number of loan payments per year; term is loan term in years
    float rate = 0, Principal = 0.0;
  //rate is the interest rate per year; Principal is the loan amount
    cout << "\n\n\t\t\tInterest Rate Calculator\n\n";
    cout << "Enter the principal amount: $";
    Principal = getFloat();
    cout << "\nEnter the interest rate in decimal form (eg 5% = 0.05): ";
    rate = getFloat();
    cout << "\nEnter the number of payments per year: ";
    number = getInt();
    cout << "\nEnter the total term in years: ";
    term = getInt();
    outputs(Principal, rate, number, term);
}// end of getLoan()


void outputs(int P, float r, int n, float t)
{
  float A = P * pow( 1 + (r/n),n * t), I = A - P;
  //A is the total amount paid, I is the total interest paid over the life of the loan
  cout << "\n\n\n\n\t\t\t";
  cout << "Your loan information: \n\n";
  cout << "Monthly Payments x " << n * t << ": $" << A/(n*t) << "\n";
  cout << "Total Payback: $" << A << "\n\n";
  cout << "Total Interest: $" << I << "\n\n";
  cout << "Total Effective Interest Rate: " << (I/P) * 100 << "%\n\n";
}//end of outputs()

int getInt()
{
  int x;
  cin >> x;
  while(std::cin.fail() || x < 1) 
  {
      std::cout << "You have entered a non-integer or a number less than 1." << endl;
      cin.clear();
      cin.ignore(256,'\n');
      cin >> x;
  }
  return(x);
}


float getFloat()
{
  float x;
  cin >> x;
  while(std::cin.fail() || x <= 0.0) 
  {
    std::cout << "You have entered a non-number or a number less than or equal to zero." << endl;
    cin.clear();
    cin.ignore(256,'\n');
    cin >> x;
  }
  return(x);
}