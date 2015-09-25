/*
Welcome to calc-ast.hpp

This defines the tyoes of the abstract syntax tree
for the grammar of the calc language,
 described in the brief for assignment one
for Dr. Sutton's Compiler Design class.

Here it is:

expr -> expr + factor | expr - factor | factor
factor -> factor * term | factor / term | factor % term | term
term -> digit | ( expr )
digit -> 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 “‘

Horizontal white space is allowed between terminals but ignored. A newline
shall not appear within an expression.

*/

#ifndef CALC_AST_HPP
#define CALC_AST_HPP

struct visitor;
struct expr;
struct digit;
struct sub;
struct add;
struct mod;
struct divide;
struct mult;
struct term;


struct visitor{
    virtual void visit(digit *) = 0;
    virtual void visit(add *) = 0;
    virtual void visit(sub *) = 0;
    virtual void visit(mult *) = 0;
    virtual void visit(divide *) = 0;
    virtual void visit(mod *) = 0;


};

struct expr{
    virtual void accept(visitor & v) = 0;
};

struct digit : expr
{
    digit(int v): value(v)
    {}

    void accept(visitor & v) { v.visit(this); }

    int value;
};

struct add : expr
{
    add(expr * l, expr * r) : left(l), right(r)
    {}

    void accept(visitor & v) { v.visit(this); }

    expr * left;
    expr * right;
};

struct sub : expr
{
    sub(expr * l, expr * r) : left(l), right(r)
    {}

    void accept(visitor & v) { v.visit(this); }

    expr * left;
    expr * right;
};

struct mult : expr
{
    mult(expr * l, expr * r) : left(l), right(r)
    {}

    void accept(visitor & v) { v.visit(this); }

    expr * left;
    expr * right;
};

struct divide : expr
{
    divide(expr * l, expr * r) : left(l), right(r)
    {}

    void accept(visitor & v) { v.visit(this); }

    expr * left;
    expr * right;
};

struct mod : expr
{
    mod(expr * l, expr * r) : left(l), right(r)
    {}

    void accept(visitor & v) { v.visit(this); }

    expr * left;
    expr * right;
};


#endif
