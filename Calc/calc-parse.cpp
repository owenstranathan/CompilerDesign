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
#include "calc_ast.hpp"


void eat_whitespace(char *);
expr * parse_expr(char * );
expr * parse_factor(char *);
expr * parse_term(char *);

string getInput();

using namespace std;

int main()
{
    string input = getInput();
    expr* ast = parse_expr(input.c_str());
    cout << "FUCKING COOL" << endl;
}

void eat_whitespace(char * input)
{
    while(*input == ' ' || *input == '  ')
    {
        ++input;
    }
    return;
}

expr * parse_expr(char * input)
{
    eat_whitespace(input);
    expr * e1 = parse_factor(input);
    eat_whitespace(input);
    if(*input == '+')
    {
        ++input;
        eat_whitespace(input);
        expr * e2 = parse_factor(input);
        return new add(e1, e2);
    }
    else if(*input == '-')
    {
        ++input;
        eat_whitespace(input);
        expr * e2 = parse_factor(input);
        return new sub(e1, e2);
    }

}

expr * parse_factor(char * input)
{
    eat_whitespace(input);
    expr * term1 = parse_term(input);
    eat_whitespace(input);
    if(*input == '*')
    {
        ++input;
        eat_whitespace(input);
        expr * e2 = parse_term(input);
        return new mult(e1, e2);
    }
    else if(*input == '/')
    {
        ++input;
        eat_whitespace(input);
        expr * e2 = parse_term(input);
        return new div(e1, e2);
    }
    else if(*input == '%')
    {
        ++input;
        eat_whitespace(input);
        expr * e2 = parse_term(input);
        return new mod(e1, e2);
    }
}

exr * parse_term(char * input)
{
    if(*input == '(')
    {
        ++input;
        eat_whitespace(input);
        return parse_expr(input);
    }
    else if(isdigit(*input))
    {
        expr * dig = new digit(*input);
        i++;
        return dig;
    }
}


string getInput()
{
    string input;
    getline(cin, input);
    return input;
}
