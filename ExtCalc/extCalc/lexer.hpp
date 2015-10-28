#ifndef LEXER_HPP
#define LEXER_HPP

#include <iostream>
#include <string>
#include <vector>


#include "token.hpp"
#include "symbol.hpp"


class lexer
{
public:
    lexer(std::string i, symbol_table & st)
    : input(i), sym_tab(st), iter(i.begin()), lookahead(*iter)
    {}

    token_stream getTokenStream();


private:

    void tokenize();
    void on_token();
    void on_token(std::string);
    void Int();
    void Bool();

    void error();
    void error(std::string);

    void push_token(symbol *);

    bool eof() {
        return lookahead == *input.end();
    }


    token_list tokens;
    std::string input;
    symbol_table & sym_tab;
    std::string::iterator iter;
    char lookahead;

    void next();

};



#endif
