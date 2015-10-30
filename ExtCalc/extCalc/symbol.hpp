#ifndef SYMBOL_HPP
#define SYMBOL_HPP

#include <string>
#include <vector>
#include <unordered_map>

#include "prelude.hpp"

#include "token.hpp"

//-------------------symbol-------------------//

struct symbol
{
    friend class symbol_table;
public:
    //initialize with token kind and text
    symbol(std::string s, token_type t) : spell_(s), tok_(t)
    {}

    virtual ~symbol()
    {}

    std::string const & spelling() const;
    token_type tok() const;

protected:
    std::string spell_; //The text of the symbol
    token_type tok_;//The type of the symbol
};


//-------------------symbol_table-------------------//

//The symbol table
class symbol_table: std::unordered_map<std::string, symbol*>
{
public:
    //Destructor
    ~symbol_table();

    //preinstalls symbols in the lexical grammar
    void install();


    //The insertion function
    symbol * insert(std::string& , token_type); //put a new symbol in the table

    symbol * operator[](std::string); //get a symbole from the table
};


inline symbol *
symbol_table::insert(std::string& text, token_type tok)
{
    auto pair = emplace(text, nullptr);
    auto iter = pair.first;
    if(pair.second)
    {
        //Insertion successful
        iter->second = new symbol(text, tok);
    }

    //return the symbol ptr
    return iter->second;
}

inline
symbol_table::~symbol_table()
{
    for(auto pair : *this)
        delete pair.second;
}


#endif
