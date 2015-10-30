#include "lexer.hpp"

#include <algorithm>
#include <stdexcept>

token_stream lexer::getTokenStream()
{
    tokenize();
    return token_stream(tokens);
}


void lexer::tokenize()
{
    while(!eof())
    {
        if(std::isalpha(lookahead))
            Bool();
        else if(std::isdigit(lookahead))
            Int();
        else
        {
            switch (lookahead)
            {
                case '(': on_token(); break;
                case ')': on_token(); break;
                case '+': on_token(); break;
                case '-': on_token(); break;
                case '*': on_token(); break;
                case '/': on_token(); break;
                case '%': on_token(); break;
                case '&':
                    next();
                    ((lookahead == '&') ? on_token("&&") : error());
                    break;
                case '|':
                    next();
                    ((lookahead == '|') ? on_token("||") : error());
                    break;
                case '>':
                    next();
                    ((lookahead == '=') ? on_token(">=") : on_token(">"));
                    break;
                case '<':
                    next();
                    ((lookahead == '=') ? on_token("<=") : on_token("<"));
                    break;
                case '=':
                    next();
                    ((lookahead == '=') ? on_token("==") : error());
                    break;
                case '!':
                    next();
                    ((lookahead == '=') ? on_token("!=") : on_token("!"));
                    break;
                case ' ': break;
                case '\t': break;
                case '\n': break;
                case '\0': break;
                default: error(); break;
            }
            next();
        }
    }

}

void lexer::on_token()
{
    //just look up the symbol in the symbol table and construct a new token
    // in the token list
    std::string t(1, lookahead);
    symbol* sym = sym_tab[t];
    if(sym != nullptr)
        push_token(sym);
    else
    {
        std::string err = "Unknown symbol ";
        err += lookahead;
        throw std::out_of_range(err);
    }
}

//for optional two character tokens called from tokenize in switch statement
void lexer::on_token(std::string t)
{
    symbol* sym = sym_tab[t];
    if(sym != nullptr)
        push_token(sym);
    else
    {
        std::string err = "Unknown symbol ";
        err += t;
        throw std::out_of_range(err);
    }
}

void lexer::push_token(symbol* sym)
{
    tokens.push_back(token(sym->tok(), sym));
}
void lexer::Bool()
{
    assert(std::isalpha(lookahead));
    std::string s = "";
    s += lookahead;
    next();
    while(std::isalpha(lookahead))
    {
        s += lookahead;
        next();
    }
    if(s == "true")
        on_token("true");
    else if(s == "false")
        on_token("false");
    else
        error(s);
}

void lexer::Int()
{
    assert(std::isdigit(lookahead));
    std::string s = "";
    s+=lookahead;
    next();
    while(std::isdigit(lookahead))
    {

        s+=lookahead;
        next();
    }
    symbol * sym = sym_tab.insert(s, integer);
    push_token(sym);
}

void lexer::error()
{
    std::string error = "Unknown identifier ";
    error += lookahead;
    throw std::invalid_argument(error.c_str());

}
void lexer::error(std::string s)
{
    std::string error = "Unknown identifier ";
    error += s;
    throw std::invalid_argument(error.c_str());
}

void lexer::next()
{
    ++iter;
    lookahead = *iter;
}
