#include "elaborate.hpp"
#include <sstream>


// Unary

//type must be int for pos(+)
void elaboration_visitor::visit(const pos_expr * p)
{
    type * t = elaborate(p->only);
    if(get_type_type(t) == "int")
        the_type = t;
    else
        errors.push_back(error("(+bool)"));
}

//also int
void elaboration_visitor::visit(const neg_expr * n)
{
    type * t = elaborate(n->only);
    if(get_type_type(t) == "int")
        the_type = t;
    else
        errors.push_back(error("(-bool)"));
}

//this one's bool
void elaboration_visitor::visit(const not_expr * n)
{
    type * t = elaborate(n->only);
    if(get_type_type(t) == "bool")
        the_type = t;
    else
        errors.push_back(error("(!int)"));
}


//Binary

void elaboration_visitor::on_binary(std::string op, std::string typ, const binary_expr * b)
{
    type * t_first = elaborate(b->first);
    type * t_second = elaborate(b->second);
    std::string first = get_type_type(t_first);
    std::string second = get_type_type(t_second);
    if(first == second && first == typ)
        the_type = t_first;
    else
    {
        std::stringstream ss;
        ss << "("<< first << op << second << ")";
        errors.push_back(ss.str());
    }
}
