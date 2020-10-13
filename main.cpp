#include <iostream>
#include <string>
#include "Decomp.h"

using namespace std;

int main(void)
{
    string nom, denom;

    cout << "Welcome to Some Egyptian fractions program. \n"
         << "I will ask you to give me the nominator and denominator of a fraction. \n"
         << "Then I will return to you Egyptian fraction of it. \n"
         << "If you put 0 in the denominator the program will end. \n\n\n";

    do
    {
        cout << "Nominator: " ;
        getline(cin, nom);
        cout << "Denominator: ";
        getline(cin, denom);
        cout << "Actual return value is: " << Decomp::decompose(nom, denom) << endl << endl;
    } while (denom != "0");
    
    
    
    return 0;
}