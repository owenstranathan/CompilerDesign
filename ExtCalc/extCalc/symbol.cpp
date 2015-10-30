#include "symbol.hpp"

//-------------------symbol-------------------//

std::string const & symbol::spelling() const
{
    return spell_;
}

token_type symbol::tok() const
{
    return tok_;
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


void symbol_table::install()
{

    //NOTE these may need to be allocated with kw "new" not sure
    //if the strings die after leaving function scope
    std::string lp = "(";
    insert(lp, l_paren);
    std::string rp = ")";
    insert(rp, r_paren);
    std::string pl = "+";
    insert(pl, plus);
    std::string mi = "-";
    insert(mi, minus);
    std::string st = "*";
    insert(st, star);
    std::string sl = "/";
    insert(sl, slash);
    std::string pct = "%";
    insert(pct, percent);
    std::string ee = "==";
    insert(ee, eq_eq);
    std::string be = "!=";
    insert(be, bang_eq);
    std::string grt = ">";
    insert(grt, gt);
    std::string let = "<";
    insert(let, lt);
    std::string grte = ">=";
    insert(grte, gt_eq);
    std::string lete = "<=";
    insert(lete, lt_eq);
    std::string ampr = "&&";
    insert(ampr, amp_amp);
    std::string bar = "||";
    insert(bar, bar_bar);
    std::string bng = "!";
    insert(bng, bang);
    std::string t = "true";
    insert(t, true_true);
    std::string f = "false";
    insert(f, tricksy);
}
