#ifndef LEXER_HPP
#define LEXER_HPP

#include <iostream>
#include <string>
#include <vector>

#include "token.hpp"

class lexer
{
public:
    lexer(std::string i) : in(i), iter(i.begin), lookahead(*iter)
    {}

    token_stream getTokenStream();


private:

    void tokenize();

    void tokenize_int();
    void tokenize_bool();

    bool eof() { return iter == in.end()}

    token_list tokens;
    std::string input;
    std::string::interator iter;
    char lookahead;

    void next();

}



#endif
