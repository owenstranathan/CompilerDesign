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

#ifndef CALC-AST_HPP
#define CALC-AST_HPP

struct visitor;
struct expr;
struct mod;
struct div;
struct mult;
struct sub;
struct add;
struct digit;

struct visitor{
    virtual void visit(expr *);

};

struct expr{
    virtual void accept(visitor & v) = 0;
};

struct mod : expr
{
    void accept(visitor & v) { v.visit(this); }

    expr * left;
    expr * right;
};

struct div : expr
{
    void accept(visitor & v) { v.visit(this); }

    expr * left;
    expr * right;
};

struct mult : expr
{
    void accept(visitor & v) { v.visit(this); }

    expr * left;
    expr * right;
};

struct sub : expr
{
    void accept(visitor & v) { v.visit(this); }

    expr * left;
    expr * right;
};

struct add : expr
{
    void accept(visitor & v) { v.visit(this); }

    expr * left;
    expr * right;
};

struct digit : expr
{
    void accept(visitor & v) { v.visit(this); }

    int value;
};


#endif
