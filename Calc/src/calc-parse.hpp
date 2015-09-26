#ifndef CALC_PARSE_HPP
#define CALC_PARSE_HPP

#include "calc-ast.hpp"

#include <iostream>
#include <string>

struct calc_parse
{

    expr * parse() { return parse_expr(); }
    expr * parse_expr();
    expr * parse_factor(expr * e1);
    expr * parse_term();
    void next();

    std::string input;
    std::string::iterator iter;
    char lookahead;

    calc_parse(std::string i) :  input(i), iter(input.begin()), lookahead(*iter)
    {}


};

#endif
