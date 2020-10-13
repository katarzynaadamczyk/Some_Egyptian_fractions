#include <iostream>
#include <string>
#include <math.h>
#include "Decomp.h"

using namespace std;

string Decomp::decompose(const string &nrStr, const string &drStr)
{
    return ("[" + to_string(correct_number(nrStr)) + '/' + to_string(correct_number(drStr)) + "]");
}

int Decomp::correct_number(const string &nrStr)
{
    int ret_value = 0;
    for (size_t i = 0, n = nrStr.size(); i < n; i++)
    {
        if (!isdigit(nrStr[i]))
        {
            return 0;
        }
        ret_value += static_cast<int>(nrStr[i] - '0') * pow(10, n - i - 1);
    }
    return ret_value;
}