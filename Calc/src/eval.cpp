#include "calc-parse.hpp"
#include "calc-eval.hpp"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    std::string input;

    while(getline(cin, input))
    {
        try
        {
            calc_parse parser(input);
            expr * ast = parser.parse();
            cout << eval(ast) << endl;;
        }
        catch(std::logic_error error)
        {
            std::cout << "Invalid syntax!" << std::endl;
        }
    }
    return 0;
}
