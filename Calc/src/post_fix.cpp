#include "calc-print.hpp"
#include "calc-parse.hpp"

#include <iostream>
#include <string>
#include <stdexcept>

int main()
{
    std::string input;
    while(getline(std::cin, input))
    {
        try
        {
            calc_parse parser(input);
            expr * ast = parser.parse();
            post_fix_print(ast);
        }
        catch(std::logic_error error)
        {
            std::cout << "Invalid syntax!" << std::endl;
        }
    }
    return 0;
}
