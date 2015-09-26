#include "calc-print.hpp"

////////////////////////////////////////////////////////////////////////////////
//Pre-Order printing////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void pre_order_visitor::visit(digit * d)
{
    output = std::to_string(d->value);
}

void pre_order_visitor::visit(add * a)
{
    output = "( + " + pre_print(a->left) + " " + pre_print(a->right) + ")";
}

void pre_order_visitor::visit(sub * s)
{
    output = "( - " + pre_print(s->left) + " " + pre_print(s->right) + ")";
}

void pre_order_visitor::visit(mult * m)
{
    output = "( * " + pre_print(m->left) + " " + pre_print(m->right) + ")";
}

void pre_order_visitor::visit(divide * d)
{
    output = "( / " + pre_print(d->left) + " " + pre_print(d->right) + ")";

}

void pre_order_visitor::visit(mod * m)
{
    output = "( % " + pre_print(m->left) + " " + pre_print(m->right) + ")";
}

std::string pre_print(expr* e)
{
    pre_order_visitor vis;
    e->accept(vis);
    return vis.output;
}


////////////////////////////////////////////////////////////////////////////////
//Pre-Order printing////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void post_order_visitor::visit(digit * d)
{
    output = std::to_string(d->value);
}

void post_order_visitor::visit(add * a)
{
    output = post_print(a->left) + " " + post_print(a->right) + " + ";
}

void post_order_visitor::visit(sub * s)
{
    output = post_print(s->left) + " " + post_print(s->right) + " - ";
}

void post_order_visitor::visit(mult * m)
{
    output = post_print(m->left) + " " + post_print(m->right) + " * ";
}

void post_order_visitor::visit(divide * d)
{
    output = post_print(d->left) + " "+ post_print(d->right) + " / ";
}

void post_order_visitor::visit(mod * m)
{
    output = post_print(m->left) + " " + post_print(m->right) + " % ";
}

std::string post_print(expr* e)
{
    post_order_visitor vis;
    e->accept(vis);
    return vis.output;
}
