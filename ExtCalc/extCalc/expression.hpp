#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include "prelude.hpp"
#include "visitor.hpp"

//---------------------// Papa Expression //---------------------//

struct expr
{
    virtual ~expr()
    { }
    virtual void accept(expr_visitor&)  = 0;
};

//---------------------// Unary Expressions //---------------------//

struct unary_expr : expr
{
    virtual ~unary_expr()
    { }
    unary_expr(expr * e)
    : only(e)
    { }
    expr * only;
};

//----// Arithmetic //----//

struct pos_expr : unary_expr
{
    pos_expr(expr * e)
    : unary_expr(e)
    {}

    void accept(expr_visitor & v)
    { v.visit(this); }
};

struct neg_expr : unary_expr
{
    neg_expr(expr * e)
    : unary_expr(e)
    {}

    void accept(expr_visitor & v)
    { v.visit(this); }
};

//----// Logical //----//

struct not_expr : unary_expr
{
    not_expr(expr * e)
    : unary_expr(e)
    {}

    void accept(expr_visitor & v)
    { v.visit(this); }
};

//---------------------// Binary Expressions //---------------------//

struct binary_expr : expr
{
    binary_expr(expr * e1, expr * e2)
    : first(e1), second(e2)
    {}

    expr * first;
    expr * second;

};

//----// Arithmetic //----//


struct add_expr : binary_expr
{
    add_expr( expr * e1, expr * e2 ) : binary_expr(e1, e2)
    {}

    void accept(expr_visitor & v)
    { v.visit(this); }
};

struct sub_expr : binary_expr
{
    sub_expr( expr * e1, expr * e2 ) : binary_expr(e1, e2)
    {}

    void accept(expr_visitor & v)
    { v.visit(this); }
};


struct mult_expr : binary_expr
{
    mult_expr( expr * e1, expr * e2 ) : binary_expr(e1, e2)
    {}

    void accept(expr_visitor & v)
    { v.visit(this); }
};

struct div_expr : binary_expr
{
    div_expr( expr * e1, expr * e2 ) : binary_expr(e1, e2)
    {}

    void accept(expr_visitor & v)
    { v.visit(this); }
};

struct mod_expr : binary_expr
{
    mod_expr( expr * e1, expr * e2 ) : binary_expr(e1, e2)
    {}

    void accept(expr_visitor & v)
    { v.visit(this); }
};

//----// Logical //----//

struct and_expr : binary_expr
{
    and_expr( expr * e1, expr * e2 ) : binary_expr(e1, e2)
    {}

    void accept(expr_visitor & v)
    { v.visit(this); }
};

struct or_expr : binary_expr
{
    or_expr( expr * e1, expr * e2 ) : binary_expr(e1, e2)
    {}

    void accept(expr_visitor & v)
    { v.visit(this); }
};

struct gt_expr : binary_expr
{
    gt_expr( expr * e1, expr * e2 ) : binary_expr(e1, e2)
    {}

    void accept(expr_visitor & v)
    { v.visit(this); }
};

struct lt_expr : binary_expr
{
    lt_expr( expr * e1, expr * e2 ) : binary_expr(e1, e2)
    {}

    void accept(expr_visitor & v)
    { v.visit(this); }
};

struct gte_expr : binary_expr
{
    gte_expr( expr * e1, expr * e2 ) : binary_expr(e1, e2)
    {}

    void accept(expr_visitor & v)
    { v.visit(this); }
};

struct lte_expr : binary_expr
{
    lte_expr( expr * e1, expr * e2 ) : binary_expr(e1, e2)
    {}

    void accept(expr_visitor & v)
    { v.visit(this); }
};

struct eequ_expr : binary_expr
{
    eequ_expr( expr * e1, expr * e2 ) : binary_expr(e1, e2)
    {}

    void accept(expr_visitor & v)
    { v.visit(this); }
};

struct nequ_expr : binary_expr
{
    nequ_expr( expr * e1, expr * e2 ) : binary_expr(e1, e2)
    {}

    void accept(expr_visitor & v)
    { v.visit(this); }
};

//---------------------// Literal Expressions //---------------------//

struct int_expr :expr
{
public:
    int_expr(int value) : value_(value)
    {}

    int value() const { return value_; }

    void accept(expr_visitor & v) { v.visit(this); }

private:
    int value_;
};

struct bool_expr :expr
{
public:
    bool_expr(bool value) : value_(value)
    {}

    bool value() const { return value_; }

    void accept(expr_visitor & v) { v.visit(this); }

private:
    bool value_;
};

#endif
