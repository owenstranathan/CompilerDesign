#ifndef UTIL_HPP
#define UTIL_HPP

#include "visitor.hpp"
#include "expression.hpp"
#include "type.hpp"
//Get expression types as strings

struct expr_type_visitor : expr_visitor
{
    // Unary
    void visit(const pos_expr *) { the_type = "pos_expr"; } // + {expr}
    void visit(const neg_expr *) { the_type = "neg_expr"; } // - {expr}
    void visit(const not_expr *) { the_type = "not_expr"; } // ! {expr}

    //Binary
    void visit(const add_expr *) { the_type = "add_expr"; } // +
    void visit(const sub_expr *) { the_type = "sub_expr"; } // -
    void visit(const mult_expr *){ the_type = "mult_expr"; } // *
    void visit(const div_expr *) { the_type = "div_expr"; } // /
    void visit(const mod_expr *) { the_type = "mod_expr"; } // %
    void visit(const and_expr *) { the_type = "and_expr"; } // &&
    void visit(const or_expr *)  { the_type = "or_expr"; } // ||
    void visit(const gt_expr *)  { the_type = "gt_expr"; } // >
    void visit(const lt_expr *)  { the_type = "lt_expr"; } // <
    void visit(const gte_expr *) { the_type = "gte_expr"; } // >=
    void visit(const lte_expr *) { the_type = "lte_expr"; } // <=
    void visit(const eequ_expr *){ the_type = "eequ_expr"; } // ==
    void visit(const nequ_expr *){ the_type = "nequ_expr"; } // !=

    //Literal
    void visit(const int_expr *) { the_type = "int_expr"; } // int
    void visit(const bool_expr *){ the_type = "bool_expr"; } // bool

    std::string the_type;

};

std::string get_expr_type(expr* e);


//get type types as strings
struct type_type_visitor : type_visitor
{
    void visit( const bool_type * ) { the_type = "bool"; }
    void visit( const int_type * )  { the_type = "int"; }

    std::string the_type;
};

std::string get_type_type(type * t);

#endif
