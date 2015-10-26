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
        {
            tokenizeBool();
        }
        else if(std::isdigit(lookahead))
        {
            tokenizeInt();
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
                    tokens.push_back(token(plus, "+"));
                break;
                case '-':
                    tokens.push_back(token(minus , "-"));
                break;
                case '*':
                    tokens.push_back(token(star , "*"));
                break;
                case '/':
                    tokens.push_back(token(slash , "/"));
                break;
                case '%':
                    tokens.push_back(token(percent , "%"));
                break;
                case '&':
                    next();
                    if(lookahead == '&')
                    {
                        tokens.push_back(token(amp_amp , "&&"));
                    }
                    else
                    {
                        std::string error = "Unknown identifier ";
                        error += lookahead;
                        error += " in && lex";
                        throw std::invalid_argument(error.c_str());
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
                        std::string error = "Unknown identifier ";
                        error += lookahead;
                        error += " in || lex";
                        throw std::invalid_argument(error.c_str());
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
                        std::string error = "Unknown identifier ";
                        error += lookahead;
                        error += " in == lex";
                        throw std::invalid_argument(error.c_str());
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
                case '\n':
                break;
                case '\0':
                break;
                default:
                    std::string error = "Unknown identifier ";
                    error += lookahead;
                    error += " in default lex";
                    throw std::invalid_argument(error.c_str());
                break;
            }
            next();
        }
    }

}

void lexer::tokenizeBool()
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
    {
        tokens.push_back(token(true_true , s));
    }
    else if(s == "false")
    {
        tokens.push_back(token(tricksy , s));
    }
    else
    {
        std::cout << s << std::endl;
        std::string error = "Unknown identifier " + s;
        error += " in bool lex";
        throw std::invalid_argument(error.c_str());
    }

}

void lexer::tokenizeInt()
{
    assert(std::isdigit(lookahead));
    std::string s = "";
    s+=lookahead;
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
