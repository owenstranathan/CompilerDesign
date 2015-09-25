#include "calc-parse.hpp"
#include "calc-eval.hpp"
#include "calc-ast.hpp"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    std::string input;

    while(getline(cin, input))
    {
        calc_parse parser(input);
        expr * ast = parser.parse();
        cout << eval(ast) << endl;;
    }
    return 0;
}
