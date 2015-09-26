//Simple program to demonstrait s_expressions

#include "calc-print.hpp"
#include "calc-parse.hpp"
#include <iostream>
#include <string>

int main()
{
    std::string input;
    while(getline(std::cin, input))
    {
        try
        {
            calc_parse parser(input);
            expr * ast = parser.parse();
            s_expr_print(ast);
        }
        catch(std::logic_error error)
        {
            std::cout << "Invalid syntax!" << std::endl;
        }
    }
    return 0;
}
