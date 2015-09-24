/*
HERE WE HAVE THE PARSER

It parses input from standard input(cin)
and constructs an ast for evaluation

NOTE:

expr -> expr + factor | expr - factor | factor
factor -> factor * term | factor / term | factor % term | term
term -> digit | ( expr )
digit -> 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 “‘

*/


#include <iostream>
#include <string>
#include <cstring>
#include <stdexcept>
#include "calc-ast.hpp"
#include "calc-eval.hpp"


using namespace std;

int main()
{
    char * input = getInput();
    printf("%s",input);
    expr* ast = parse_expr(input);
    cout << eval(ast) << endl;
    return 0;
}




expr * calc_parser::parse_expr(char * input)
{

    expr * e1 = parse_factor(input);

    if(*input == '+')
    {
        ++input;

        expr * e2 = parse_factor(input);
        return new add(e1, e2);
    }
    else if(*input == '-')
    {
        ++input;

        expr * e2 = parse_factor(input);
        return new sub(e1, e2);
    }
    else
    {
        return parse_factor(input);
    }


}

expr * calc_parser::parse_factor(char * input)
{

    expr * e1 = parse_term(input);

    if(*input == '*')
    {
        ++input;

        expr * e2 = parse_term(input);
        return new mult(e1, e2);
    }
    else if(*input == '/')
    {
        ++input;

        expr * e2 = parse_term(input);
        return new divide(e1, e2);
    }
    else if(*input == '%')
    {
        ++input;

        expr * e2 = parse_term(input);
        return new mod(e1, e2);
    }
    else
    {
        return e1;
    }

}

expr * calc_parser::parse_term(char * input)
{
    cout << "In term" << endl;
    if(*input == '(')
    {
        ++input;
        return parse_expr(input);
    }
    else if(isdigit(*input))
    {
        cout << "The input is " << *input << endl;
        expr * dig = new digit(*input);
        input+=1;
        cout << *input << endl;
        return dig;
    }
    else throw logic_error("Invalid syntax! Line 118");

}

void calc_parser::next()
{
    while(lookahead == ' ' || lookahead == '\t')
}
