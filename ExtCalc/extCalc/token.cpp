#include "token.hpp"


token& token_stream::peek()
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
