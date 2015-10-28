#include "symbol.hpp"

//-------------------symbol-------------------//

std::string const & symbol::spelling() const
{
    return *spell_;
}

token_type symbol::tok() const
{
    return tok_;
}

//-------------------int_symbol-------------------//


int int_symbol::value() const
{
    return value_;
}


//-------------------symbol_table-------------------//


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
