#include <iostream>
#include <string>

class Decomp
{
    public:
    static std::string decompose(const std::string &nrStr, const std::string &drStr);

    private:
    static int correct_number(const std::string &nrStr);
    static std::string add_to_string(std::string &s_res, int nom, int denom = 1);
};