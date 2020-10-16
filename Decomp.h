#include <iostream>
#include <string>

class Decomp
{
    public:
    static std::string decompose(const std::string &nrStr, const std::string &drStr);

    private:
    static int correct_number(const std::string &nrStr);
    static std::string add_to_string(std::string &s_res, int denom, int nom = 1);
    static void shorten_fraction(int & denom, int & nom);
    static void substract_fraction(int & denom1, int & nom1, int denom2, int nom2 = 1);

};