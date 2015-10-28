#ifndef PARSER_HPP
#define PARSER_HPP

#include "prelude.hpp"
#include "lexer.hpp"


class parser
{
public:
    //Constructors
    parser(token_stream & ts) : tokens(ts)
    {}
    parser(token_list & tl) : tokens(token_stream(tl))
    {}

    // To initiate parse recursion and return an the AST
    expr* parse();

private:
    // Parse an expression
    expr* expression();
    // Parse a logical or expression
    expr* logical_or();
    // Parse a logical and expression
    expr* logical_and();
    // Parse an equality expression (== | !=)
    expr* equality();
    // Parse an ordering expression
    // > | >= | < | <=
    expr* ordering();
    // Parse and additive expression ( + | -)
    expr* additive();
    // Parse a multiplicative expression ( * | / | %)
    expr* multiplicative();
    // Parse a unary expression ( - | + | !)
    expr* unary();
    // Parse a literal expression (int | kw_true | kw_false)
    expr* literal();

    token & peek() { return tokens.peek(); }
    token & get() { return tokens.get(); }
    token_stream tokens;

};

#endif
