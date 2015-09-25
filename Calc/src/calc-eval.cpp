#include <iostream>
#include "calc-ast.hpp"
#include "calc-eval.hpp"



void expr_eval_visitor::visit( digit * d)
{
    // std::cout << "visiting a digit " << d->value << "\n";
    value = d->value;
}

void expr_eval_visitor::visit( add * a)
{
    // std::cout << "visiting add\n";
    value = eval(a->left) + eval(a->right);
}

void expr_eval_visitor::visit(sub * s)
{
    // std::cout << "visiting sub\n";
    value = eval(s->left) - eval(s->right);
}

void expr_eval_visitor::visit(mult * m)
{
    // std::cout << "visiting mult\n";
    value = eval(m->left) * eval(m->right);
}

void expr_eval_visitor::visit(divide * d)
{
    // std::cout << "visiting div\n";
    value = eval(d->left) / eval(d->right);
}

void expr_eval_visitor::visit(mod * m)
{
    // std::cout << "visiting mod\n";
    value = eval(m->left) % eval(m->right);
}

int eval(expr* e)
{
    expr_eval_visitor vis;
    e->accept(vis);
    return vis.value;
}
