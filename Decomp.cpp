#include <iostream>
#include <string>
#include <math.h>
#include "Decomp.h"

using namespace std;

string Decomp::decompose(const string &nrStr, const string &drStr)
{
    int nom {correct_number(nrStr)}, denom {correct_number(drStr)};
    if (nom == 0 || denom == 0)
    {
        return "[]";
    }
    string ret_val {"["};
    if (nom > denom)
    {
        add_to_string(ret_val, nom / denom);
        nom = nom % denom;
    }

    while (nom > 1)
    {
        
        /* code here */
        break;
    }    

    ret_val += "]";
    
    return ret_val;
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

string Decomp::add_to_string(string &s_res, int nom, int denom)
{
    if (s_res.size() > 1)
    {
        s_res += ", ";
    }
    s_res += to_string(nom);
    if (denom > 1)
    {
        s_res += "/" + to_string(denom);
    }
    return s_res;
}