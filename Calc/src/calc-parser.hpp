#ifndef CALC_PARSER_HPP
#define CALC_PARSER_HPP

#include <iostream>

struct calc_parser
{
    expr * parse_expr(char * );
    expr * parse_factor(char *);
    expr * parse_term(char *);
    void next();

    char lookahead;
    std::istream & inStream;

    calc_parser(std::istream & i) : inStream(i), lookahead(inStream.get())
    {}


}

#endif
