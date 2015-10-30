#include "elaborate.hpp"

#include "expression.hpp"
#include "type.hpp"
#include "util.hpp"

#include <sstream>


// Unary

//type must be int for pos(+)
void elaboration_visitor::visit(const pos_expr * p)
{
    type * t = elaborate(p->only);
    if(get_type_type(t) == "int")
        the_type = t;
    else
        errors.push_back(error_message("(+bool)"));
}

//also int
void elaboration_visitor::visit(const neg_expr * n)
{
    type * t = elaborate(n->only);
    if(get_type_type(t) == "int")
        the_type = t;
    else
        errors.push_back(error_message("(-bool)"));
}

//this one's bool
void elaboration_visitor::visit(const not_expr * n)
{
    type * t = elaborate(n->only);
    if(get_type_type(t) == "bool")
        the_type = t;
    else
        errors.push_back(error_message("(!int)"));
}

void elaboration_visitor::visit(const int_expr *)
{ the_type = new int_type(); }

void elaboration_visitor::visit(const bool_expr *)
{ the_type = new bool_type(); }

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
        errors.push_back(error_message(ss.str()));
    }
}

std::string elaboration_visitor::error_message(std::string message)
{

    std::string err = "Malformed syntax: no known elaboration of expression with type : ";
    err += message;
    err += " stopping translatlation!";
    return err;
}


type * elaborate(expr* ast)
{
    elaboration_visitor v;
    ast->accept(v);
    if(v.errors.size() > 0)
    {
        for(auto err : v.errors)
        {
            std::cout << err << std::endl;
        }
        return nullptr;
    }
    return v.the_type;
}
