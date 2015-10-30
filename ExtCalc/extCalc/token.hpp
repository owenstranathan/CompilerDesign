#ifndef TOKEN_HPP
#define TOKEN_HPP

#include "prelude.hpp"



#include <string>
#include <vector>
#include <iostream>

struct symbol;

//Enum to simplify token type analysis
enum token_type
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
    token() : type(integer), sym_(nullptr)
    {}
    token(token_type t, symbol * s) : type(t), sym_(s)
    {}

    symbol const * Symbol() { return sym_; }

    token_type type;
    symbol * sym_;
};


using token_list = std::vector<token>;

//This is almost directly from Dr. Sutton's lingo::token.hpp
//What he did just made alot of sense so after seeing it I couldn't think
//of a better way to do it
class token_stream
{
public:
    //constructors

    //token_stream(token * f,  token * l) : first_(f), last_(l)
    //{}

    // token_stream(token_list & tokens)
    // : token_stream(tokens.data(), tokens.data() + tokens.size())
    // {}

    token_stream(token_list & tokens) : t_vec(tokens), lookahead(t_vec.begin())
    {}
    //Access functions and others

    bool eof() const { return lookahead == t_vec.end(); }
    token & peek() const;
    token & get();
    void next() { ++lookahead; }
    //token * begin() { return &(*t_vec.begin());}
    //token * end() { return &(*t_vec.end()); }
    void reset() { lookahead = t_vec.begin(); }

private:
    //token * first_;
    //token * last_;
    token_list t_vec;
    token_list::iterator lookahead;
};


inline
token & token_stream::peek() const
{
    assert(!eof());
    return *lookahead;
}

inline
token& token_stream::get()
{
    assert(!eof());
    token & tok = *lookahead;
    ++lookahead;
    return tok;
}

#endif
