#ifndef PARSER_HPP
#define PARSER_HPP

#include "prelude.hpp"
#include "lexer.hpp"
#include "symbol.hpp"
#include "ast.hpp"
#include <string>

class parser
{
public:
    //Constructors
    parser(token_stream & ts, symbol_table& st) : tokens(ts), sym_tab(st)
    {}
    parser(token_list & tl) : tokens(token_stream(tl))
    {}

    // To initiate parse recursion and return an the AST
    expr* parse();

private:
    // Parse an expression
    expr* expression();
    // Parse a logical or expression ( || )
    expr* logical_or();
    // Parse a logical and expression ( && )
    expr* logical_and();
    // Parse an equality expression ( == | != )
    expr* equality();
    // Parse an ordering expression ( > | >= | < | <= )
    expr* ordering();
    // Parse and additive expression ( + | -)
    expr* additive();
    // Parse a multiplicative expression ( * | / | % )
    expr* multiplicative();
    // Parse a unary expression ( - | + | ! )
    expr* unary();
    // Parse a primary() expression (int | kw_true | kw_false)
    expr* primary();

    //Token Stream helpers
    token_type peek();
    token match_and_return(token_type);
    bool match(token_type);
    token & get() { return tokens.get(); }
    void next() { tokens.next(); }

    token_stream tokens;
    symbol_table sym_tab;

};

inline
expr * parser::parse()
{
    return expression();
}

#endif
