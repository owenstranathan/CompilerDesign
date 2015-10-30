#include "util.hpp"

std::string get_expr_type(expr* e)
{
    expr_type_visitor v;
    e->accept(v);
    return v.the_type;
}




std::string get_type_type(type * t)
{
    type_type_visitor v;
    t->accept(v);
    return v.the_type;
}
