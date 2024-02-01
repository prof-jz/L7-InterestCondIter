#include <iostream>
#include <math.h>

using namespace std;

int main() 
{
  int x = 0, n = 0, t = 0; 
  //x is a counter, n is the number of payments per year, t is the total term in years
  float P = 0.0, r = 0.0, A = 0.0, I =0.0;
  //P is principal, r is interest rate, A is the total amount paid, I is the total interest paid 
  char cont = 'Y';
  //cont is the error control character

  while (cont != 'N' && cont != 'n')
    {
      cout << "\n\nHow many loans would you like to calculate? (1, 2, or 3)? ";
      cin >> x;
      if (x > 0 && x < 4)
        cont = 'N';
    }
  for (int y = 0; y < x; y++)
    {
      cout << "\n\n\t\t\tInterest Rate Calculator\n\n";
      cout << "Enter the principal amount: $";
      cin >> P;
      cout << "\nEnter the interest rate in decimal form (eg 5% = 0.05): ";
      cin >> r;
      cout << "\nEnter the number of payments per year: ";
      cin >> n;
      cout << "\nEnter the total term in years: ";
      cin >> t;
      A = P * pow( 1 + (r/n),n * t);
      I = A - P;
      cout << "\n\n\n\n";
      cout << "Your loan information: \n\n";
      cout << "Total Payback: $" << A << "\n\n";
      cout << "Total Interest: $" << I << "\n\n";
      cout << "Total Effective Interest Rate: " << (I/P) * 100 << "%\n\n";
    }
}