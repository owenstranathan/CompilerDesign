#include "token.hpp"


const token& token_stream::peek()
{
    assert(!eof());
    return *first_;
}

const token& token_stream::get()
{
    assert(!eof());
    token const & tok = *first_;
    ++first_;
    return tok;
}

const token& token_stream::last()
{
    return *last_;
}
