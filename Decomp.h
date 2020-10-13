#include <iostream>
#include <string>

class Decomp
{
    public:
    static std::string decompose(const std::string &nrStr, const std::string &drStr);

    private:
    static int correct_number(const std::string &nrStr);
};