#ifndef LEXER_HPP
#define LEXER_HPP

#include <iostream>
#include <string>
#include <vector>


#include "token.hpp"


class lexer
{
public:
    lexer(std::string i) : input(i), iter(i.begin()), lookahead(*iter)
    {}

    token_stream getTokenStream();


private:

    void tokenize();

    void tokenizeInt();
    void tokenizeBool();

    bool eof() {
        return lookahead == *input.end();
    }

    token_list tokens;
    std::string input;
    std::string::iterator iter;
    char lookahead;

    void next();

};



#endif
