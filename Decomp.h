#include <iostream>
#include <string>

class Decomp
{
    public:
    static std::string decompose(const std::string &nrStr, const std::string &drStr);

    private:
    static unsigned long long correct_number(const std::string &nrStr);
    static std::string add_to_string(std::string &s_res, unsigned long long denom, unsigned long long nom = 1);
    static void shorten_fraction(unsigned long long & denom, unsigned long long & nom);
    static void substract_fraction(unsigned long long & denom1, unsigned long long & nom1, unsigned long long denom2, unsigned long long nom2 = 1);

};