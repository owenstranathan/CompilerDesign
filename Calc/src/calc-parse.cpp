/*
HERE WE HAVE THE PARSER

It parses input from standard input(cin)
and constructs an ast for evaluation

NOTE:

The concrete grammar:

expr -> expr + factor | expr - factor | factor
factor -> factor * term | factor / term | factor % term | term
term -> digit | ( expr )
digit -> 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 “‘


The abstract grammar:

expression ->   expr + expr
                expr - expr
                expr * expr
                expr / expr
                expr % expr
                digit -> 0|1|2|3|4|5|6|7|8|9


BAD SYNTAX will cause the parser to throw a std::logic_error deal with it!

*/


#include <iostream>
#include <string>
#include <cstring>
#include <stdexcept>
#include "calc-ast.hpp"
#include "calc-eval.hpp"
#include "calc-parse.hpp"


using namespace std;


expr * calc_parse::parse_expr()
{
    expr * e1 = parse_factor(NULL);
    expr * e2;
    while(iter != input.end())
    {
        if(lookahead == '+')
        {
            next();
            e2 = parse_factor(NULL);
            e1 = new add(e1, e2);
        }
        else if(lookahead == '-')
        {
            next();
            e2 = parse_factor(NULL);
            e1 = new sub(e1, e2);
        }
        else if(lookahead == ')')
        {
            next();
        }
        else
        {
            // cout << ((iter == input.end()) ? "true" : "false")  << endl;
            e1 = parse_factor(e1);
        }
    }
    return e1;


}

expr * calc_parse::parse_factor( expr * e1 = NULL)
{


    // cout << "We got in parse_factor the value of lookahead is : '" << lookahead <<"'"<<endl;
    if(e1 == NULL)
    {
        e1 = parse_term();
    }
    // cout << lookahead << endl;
    // cout << "lookahead == '/' --> " << ((lookahead == '/') ? "true" : "false") << endl;
    if(lookahead == '*')
    {
        next();
        expr * e2 = parse_term();
        return new mult(e1, e2);
    }
    else if(lookahead == '/' || lookahead == 47)
    {
        next();
        expr * e2 = parse_term();
        return new divide(e1, e2);
    }
    else if(lookahead == '%')
    {
        next();
        expr * e2 = parse_term();
        return new mod(e1, e2);
    }
    else
    {
        return e1;
    }

}

expr * calc_parse::parse_term()
{
    // cout << "We got in parse_term the value of lookahead is : " << lookahead << endl;
    if(lookahead == '(')
    {
        next();
        return parse_expr();
    }
    else if(isdigit(lookahead))
    {
        //atoi() is being a dick so I just did a straight ascii conversion
        expr * dig = new digit(lookahead-48);
        next();
        return dig;
    }
    else throw logic_error("Invalid syntax!");

}

void calc_parse::next()
{
    do
    {
        ++iter;
        lookahead = *iter;
    }while((lookahead == ' ' || lookahead == '\t') && iter != input.end());

}
