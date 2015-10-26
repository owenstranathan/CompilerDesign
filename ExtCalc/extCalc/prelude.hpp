// Prelude includes declarations that are used throughout the
// compiler

#ifndef PRELUDE_HPP
#define PRELUDE_HPP

#include <cassert>


//---------------------// Visitors //---------------------//

struct type_visitor;
struct expr_visitor;

//---------------------// Types //---------------------//

struct type;
struct bool_type;
struct int_type;


//---------------------// Expressions //---------------------//

// Papa Expression
struct expr;

// Unary Expressions
struct unary_expr; // {op} {expr}
//Arithmetic
struct pos_expr; // + {expr}
struct neg_expr; // - {expr}
//Logical
struct not_expr; // ! {expr}


// Binary Expressions
struct binary_expr; // {expr} {op} {expr}
//Arithmetic
struct add_expr; // {expr} + {expr}
struct sub_expr; // {expr} - {expr}
struct mult_expr; // {expr} * {expr}
struct div_expr; // {expr} / {expr}
struct mod_expr; // {expr} % {expr}
//Logical
struct and_expr; // {expr} && {expr}
struct or_expr; // {expr} || {expr}
struct gt_expr; // {expr} > {expr}
struct lt_expr; // {expr} < {expr}
struct gte_expr; // {expr} >= {expr}
struct lte_expr; // {expr} <= {expr}
struct eequ_expr; // {expr} == {expr}
struct nequ_expr; // {expr} != {expr}


#endif
