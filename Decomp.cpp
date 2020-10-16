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
        add_to_string(ret_val, 1, nom / denom);
        nom = nom % denom;
    }

    int k = 2;
    while (nom > 1)
    {
        for (int i = k; ; i++)
        {
            if (nom * i > denom)
            {
                k = i;
                break;
            }
        }
        substract_fraction(denom, nom, k);
        add_to_string(ret_val, k);
        k++;
    }    
    if (nom > 0)
    {
        add_to_string(ret_val, denom, nom);
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

string Decomp::add_to_string(string &s_res, int denom, int nom)
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

void Decomp::shorten_fraction(int & denom, int & nom)
{
    for (int k = 2, n = sqrt(nom); k < n; k++)
    {
        while (nom % k == 0 && denom % k == 0)
        {
            nom /= k;
            denom /=k;
        }
    }
    if (denom % nom == 0)
    {
        denom /= nom;
        nom /= nom;
    }
}

void Decomp::substract_fraction(int & denom1, int & nom1, int denom2, int nom2)
{
    nom1 = nom1 * denom2 - nom2 * denom1;
    denom1 *= denom2;
    shorten_fraction(denom1, nom1);
}