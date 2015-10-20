#include "lexer.hpp"

#include <algorithm>
#include <stdexcept>

void lexer::tokenize()
{
    while(!eof())
    {
        if(std::isalpha(lookahead))
        {
            tokenize_bool();
        }
        else if(std::isdigit(lookahead))
        {
            tokenize_int(lookahead);
        }
        else
        {
            switch (lookahead)
            {
                case '(':
                    tokens.push_back(token(l_paren, "("));
                break;
                case ')':
                    tokens.push_back(token(r_paren, ")"));
                break;
                case '+':
                    tokens.push_back(token(plus, ));
                break;
                case '-':
                    tokens.push_back(token(minus , "-");
                break;
                case '*':
                    tokens.push_back(token(star , "*"));
                break;
                case '/':
                    tokens.push_back(token(slash , "/"));
                break;
                case '%':
                    tokens.push_back(token(percent , "%");
                break;
                case '&':
                    next();
                    if(lookahead == '&')
                    {
                        tokens.push_back(token(amp_amp , "&&"));
                    }
                    else
                    {
                        throw std::invalid_input();
                    }
                break;
                case '|':
                    next();
                    if(lookahead == '|')
                    {
                        tokens.push_back(token(bar_bar , "||"));
                    }
                    else
                    {
                        throw std::invalid_input();
                    }
                break;
                case '>':
                    next();
                    if(lookahead == '=')
                    {
                        tokens.push_back(token(gt_eq, ">="));
                    }
                    else
                    {
                        tokens.push_back(token(gt, ">"));
                    }
                break;
                case '<':
                    next();
                    if(lookahead == '=')
                    {
                        tokens.push_back(token(lt_eq, "<="));
                    }
                    else
                    {
                        tokens.push_back(token(lt, "<"));
                    }
                break;
                case '=':
                    next();
                    if(lookahead == '=')
                    {
                        tokens.push_back(token(eq_eq, "=="));
                    }
                    else
                    {
                        throw std::invalid_input();
                    }
                break;
                case '!':
                    next();
                    if(lookahead == '=')
                    {
                        tokens.push_back(token(bang_eq, "!="));
                    }
                    else
                    {
                        tokens.push_back(token(bang, "!"));
                    }
                break;
                case ' ':
                break;
                case '\t':
                break;
                default:
                    throw std::invalid_input();
                break;
            }
            next();
        }
    }

}

void tokenize_bool()
{
    assert(std::isalpha(lookahead));
    std::string s(lookahead);
    next();
    while(std::isalpha(lookahead))
    {
        s += lookahead;
        next();
    }
    if(s == "true")
    {
        tokens.push_back(token(true_true , s));
    }
    else if(s == "false")
    {
        tokens.push_back(token(tricksy , s));
    }
    else
    {
        throw std::invalid_input();
    }

}

void lexer::tokenize_int()
{
    assert(std::isdigit(lookahead));
    std::string s(lookahead);
    next();
    while(std::isdigit(lookahead))
    {
        s += lookahead;
        next();
    }
    tokens.push_back(token(integer, s));
}

void lexer::next()
{
    assert(!eof());
    ++iter;
    lookahead = *iter;
}
