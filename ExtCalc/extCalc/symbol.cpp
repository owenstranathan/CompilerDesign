#include "symbol.hpp"



//-------------------symbol-------------------//

inline
std::string const & symbol::spelling() const
{
    return *spell_;
}

inline
token_type symbol::tok() const
{
    return tok_;
}

//-------------------int_symbol-------------------//


inline
int int_symbol::value() const
{
    return value_;
}


//-------------------symbol_table-------------------//

inline
symbol_table::~symbol_table()
{
    for(auto pair : *this)
        delete pair.second;
}


inline
symbol * symbol_table::operator[](std::string str)
{
    auto iter = find(str);
    if(iter != end())
    {
        return iter->second;
    }
    else
    {
        return nullptr;
    }
}
