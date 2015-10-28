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
    symbol(std::string* s, token_type t): spell_(s), tok_(t)
    {}

    virtual ~symbol()
    { }

    std::string const& spelling() const;
    token_type tok() const;

protected:
    std::string const* spell_; //The text of the symbol
    token_type tok_;//The type of the symbol
};


//-------------------int_symbol-------------------//

//Easier to make a separate integer symbol so that you cant convert from string
//to int in lexing
struct int_symbol : symbol
{
public:
    int_symbol(std::string* s, token_type t)
    : symbol(s, t), value_(std::stoi(*spell_))
    {}

    int value() const;

private:
    int value_; //the integer value of the symbol

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
    template<typename T, typename...Args>
    symbol * insert(std::string& , Args&& ...); //put a new symbol in the table

    symbol * operator[](std::string); //get a symbole from the table
};

inline
void symbol_table::install()
{

    //NOTE these may need to be allocated with kw "new" not sure
    //if the strings die after leaving function scope
    std::string lp = "(";
    insert<symbol>(lp, &lp, l_paren);
    std::string rp = ")";
    insert<symbol>(rp, &rp, r_paren);
    std::string pl = "+";
    insert<symbol>(pl, &pl, plus);
    std::string mi = "-";
    insert<symbol>(mi, &mi, minus);
    std::string st = "*";
    insert<symbol>(st, &st, star);
    std::string sl = "/";
    insert<symbol>(sl, &sl, slash);
    std::string pct = "%";
    insert<symbol>(pct, &pct, percent);
    std::string ee = "==";
    insert<symbol>(ee, &ee, eq_eq);
    std::string be = "!=";
    insert<symbol>(be, &be, bang_eq);
    std::string grt = ">";
    insert<symbol>(grt, &grt, gt);
    std::string let = "<";
    insert<symbol>(let, &let, lt);
    std::string grte = ">=";
    insert<symbol>(grte, &grte, gt_eq);
    std::string lete = "<=";
    insert<symbol>(lete, &lete, lt_eq);
    std::string ampr = "&&";
    insert<symbol>(ampr, &ampr, amp_amp);
    std::string bar = "||";
    insert<symbol>(bar, &bar, bar_bar);
    std::string bng = "!";
    insert<symbol>(bng, &bng, bang);
    std::string t = "true";
    insert<symbol>(t, &t, true_true);
    std::string f = "false";
    insert<symbol>(f, &f, tricksy);
}


//Basically all of this is from Dr. Sutton I give him full credit
//I could have done it my own way but this much cooler.
//So this is some cool ass shit I found in Dr.Sutton's calc
//implementation, the template function takes the symbol typename as T
//and it takes a vairable number of parameters ...args of generic type Args
//and it passes their intialization to the std::forward for determination
//at compiletime. How cool is that?
template<typename T, typename...Args>
inline symbol *
symbol_table::insert(std::string& text, Args&& ...args)
{
    auto pair = emplace(text, nullptr);
    auto iter = pair.first;
    if(pair.second)
    {
        //Insertion successful
        //create a new symbol and bind to symbol entry
        //Here's that std::forward I was talking about
        iter->second = new T(std::forward<Args>(args)...);
        iter->second->spell_ = &iter->first;
    }
    //the insertion was unsuccessful because the symbol already exists
    // else
    // {
    //     ////if the symbol is redefined then that's bad.
    //     //if(typeid(T*) != typeid(iter->second))
    //     //    throw std::runtime_error("invalid symbol redefinition");
    // }

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
