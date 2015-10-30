#ifndef ELABORATE_HPP
#define ELABORATE_HPP

#include <string>
#include <vector>

#include "prelude.hpp"
#include "visitor.hpp"
#include "ast.hpp"


struct elaboration_visitor : expr_visitor
{
    elaboration_visitor() : the_type(nullptr)
    {}

    // Unary
    void visit(const pos_expr *);
    void visit(const neg_expr *);
    void visit(const not_expr *);

    //Binary
    void visit(const add_expr * e) { on_binary("+", "int", e); }
    void visit(const sub_expr * e) { on_binary("-", "int", e); }
    void visit(const mult_expr * e){ on_binary("*", "int", e); }
    void visit(const div_expr * e) { on_binary("/", "int", e); }
    void visit(const mod_expr * e) { on_binary("%", "int", e); }
    void visit(const and_expr * e) { on_binary("&&", "bool", e); }
    void visit(const or_expr * e)  { on_binary("||", "bool", e); }
    void visit(const gt_expr * e)  { on_binary(">", "bool", e); }
    void visit(const lt_expr * e)  { on_binary("<", "bool", e); }
    void visit(const gte_expr * e) { on_binary(">=", "bool", e); }
    void visit(const lte_expr * e) { on_binary("<=", "bool", e); }
    void visit(const eequ_expr * e){ on_binary("==", "bool", e); }
    void visit(const nequ_expr * e){ on_binary("!=", "bool", e); }

    //Literal
    void visit(const int_expr *);
    void visit(const bool_expr *);

    void on_binary(std::string op, std::string typ, const binary_expr * b);

    std::string error_message(std::string message);


    type * the_type;
    std::vector<std::string> errors;


};




type * elaborate(expr * ast);


#endif
