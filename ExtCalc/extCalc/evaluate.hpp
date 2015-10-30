#ifndef EVALUATE_HPP
#define EVALUATE_HPP

#include "prelude.hpp"
#include "visitor.hpp"
#include "ast.hpp"

struct eval_visitor : expr_visitor
{
    // Unary
    void visit(const pos_expr *);// + {expr}
    void visit(const neg_expr *); // - {expr}
    void visit(const not_expr *); // ! {expr}

    //Binary
    void visit(const add_expr *); // +
    void visit(const sub_expr *); // -
    void visit(const mult_expr *); // *
    void visit(const div_expr *); // /
    void visit(const mod_expr *); // %
    void visit(const and_expr *); // &&
    void visit(const or_expr *); // ||
    void visit(const gt_expr *); // >
    void visit(const lt_expr *); // <
    void visit(const gte_expr *); // >=
    void visit(const lte_expr *); // <=
    void visit(const eequ_expr *); // ==
    void visit(const nequ_expr *); // !=

    //Literal
    void visit(const int_expr *); // int
    void visit(const bool_expr *); // bool

    int int_value;
    bool bool_value;

};



int int_evaluate(expr * ast);

bool bool_evaluate(expr * ast);


#endif
