#ifndef TOKEN_HPP
#define TOKEN_HPP

#include "prelude.hpp"
#include "ast.hpp"

#include <string>
#include <vector>
#include <iostream>

//Enum to simplify token type analysis
enum token_ype
{
    integer,    // integer
    l_paren,    // (
    r_paren,    // )
    plus,       // +
    minus,      // -
    star,       // *
    slash,      // /
    percent,    // %
    amp_amp,    // &&
    bar_bar,    // ||
    true_true,  // true
    tricksy,    // false (think smegol)
    gt,         // >
    lt,         // <
    gt_eq,      // >=
    lt_eq,      // <=
    eq_eq,      // ==
    bang_eq     // !=
    bang        // !
};

struct token
{
    token(token_type t, std::string v) : type(t), value(v)
    {}

    token_type type;
    std::string value;
}


using token_list = std::vector<token>;

//This is almost directly from Dr. Sutton's lingo::token.hpp
//What he did just made alot of sense so after seeing it I couldn't think
//of a better way to do it
class token_stream
{
public:
    //constructors

    token_stream(token * f,  token * l) : first_(f), last_(l)
    {}

    token_stream(token_list & tokens)
    : token_stream(tokens.data(), tokens.data + tokens.size())
    {}


    //Access functions and others

    bool eof() const { return first_ == last_; }
    const token & peek();
    const token & get();
    const token & last() { return *(last_ - 1); }

    const token * begin() { return t_vec.begin(); }
    const token * end() { return t_vec.end(); }

private:
    token * first_;
    token * last_;
}




#endif
