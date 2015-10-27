#ifndef TOKEN_HPP
#define TOKEN_HPP

#include "prelude.hpp"
#include "ast.hpp"
//#include "symbol.hpp"

#include <string>
#include <vector>
#include <iostream>

//Enum to simplify token type analysis
enum token_type : short
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
    bang_eq,    // !=
    bang        // !
};

struct token
{
    token(token_type t, std::string v) : type(t), value(v)
    {}

    token_type type;
    std::string value;
};


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
    : token_stream(tokens.data(), tokens.data() + tokens.size())
    {}


    //Access functions and others

    bool eof() const { return first_ == last_; }
    token & peek() const;
    token & get();
    token & last() { return *(last_ - 1); }

    token * begin() { return &(*t_vec.begin());}
    token * end() { return &(*t_vec.end()); }

private:
    token * first_;
    token * last_;
    token_list t_vec;
};



token & token_stream::peek() const
{
    assert(!eof());
    return *first_;
}

token& token_stream::get()
{
    assert(!eof());
    token & tok = *first_;
    ++first_;
    return tok;
}
#endif
