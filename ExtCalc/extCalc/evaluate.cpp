#include "evaluate.hpp"
#include "ast.hpp"

using namespace std;


void eval_visitor::visit(const pos_expr * e)
{
    int_value = int_evaluate(e->only);
}


void eval_visitor::visit(const neg_expr * e)
{
    int_value = -1 * int_evaluate(e->only);
}


void eval_visitor::visit(const not_expr * e)
{
    bool_value = !bool_evaluate(e->only);
}


void eval_visitor::visit(const add_expr * e)
{
    int_value = int_evaluate(e->first) + int_evaluate(e->second);
}



void eval_visitor::visit(const sub_expr * e)
{
    int_value = int_evaluate(e->first) - int_evaluate(e->second);
}


void eval_visitor::visit(const mult_expr * e)
{
    int_value = int_evaluate(e->first) * int_evaluate(e->second);
}


void eval_visitor::visit(const div_expr * e)
{
    int_value = int_evaluate(e->first) / int_evaluate(e->second);
}


void eval_visitor::visit(const mod_expr * e)
{
    int_value = int_evaluate(e->first) % int_evaluate(e->second);
}


void eval_visitor::visit(const and_expr * e)
{
    bool_value = bool_evaluate(e->first) && bool_evaluate(e->second);
}


void eval_visitor::visit(const or_expr * e)
{
    bool_value = bool_evaluate(e->first) || bool_evaluate(e->second);
}


void eval_visitor::visit(const gt_expr * e)
{
    bool_value = int_evaluate(e->first) > int_evaluate(e->second);
}



void eval_visitor::visit(const lt_expr * e)
{
    bool_value = int_evaluate(e->first) < int_evaluate(e->second);
}


void eval_visitor::visit(const gte_expr * e)
{
    bool_value = int_evaluate(e->first) >= int_evaluate(e->second);
}


void eval_visitor::visit(const lte_expr * e)
{
    bool_value = int_evaluate(e->first) <= int_evaluate(e->second);
}


void eval_visitor::visit(const eequ_expr * e)
{
    bool_value = bool_evaluate(e->first) == bool_evaluate(e->second);
}


void eval_visitor::visit(const nequ_expr * e)
{
    bool_value = bool_evaluate(e->first) == bool_evaluate(e->second);
}


void eval_visitor::visit(const int_expr * e)
{
    int_value = e->value();
}



void eval_visitor::visit(const bool_expr * e)
{
    bool_value = e->value();
}



int int_evaluate(expr * ast)
{
    eval_visitor v;
    ast->accept(v);
    return v.int_value;
}

bool bool_evaluate(expr * ast)
{
    eval_visitor v;
    ast->accept(v);
    return v.bool_value;
}
