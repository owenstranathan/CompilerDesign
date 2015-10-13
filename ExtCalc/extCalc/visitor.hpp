//---------------------// Expression Visitor //---------------------//
struct expr_visitor
{
    // Unary
    virtual void visit(const pos_expr *) {} // + {expr}
    virtual void visit(const neg_expr *) {} // - {expr}
    virtual void  visit(const neg_expr *) {} // ! {expr}

    //Binary
    virtual void visit(const add_expr *) {} // +
    virtual void visit(const sub_expr *) {} // -
    virtual void visit(const mult_expr *) {} // *
    virtual void visit(const div_expr *) {} // /
    virtual void visit(const mod_expr *) {} // %
    virtual void visit(const add_expr *) {} // &&
    virtual void visit(const or_expr *) {} // ||
    virtual void visit(const gt_expr *) {} // >
    virtual void visit(const lt_expr *) {} // <
    virtual void visit(const gte_expr *) {} // >=
    virtual void visit(const lte_expr *) {} // <=
    virtual void visit(const eequ_expr *) {} // ==
    virtual void visit(const nequ_expr *) {} // !=

}

//---------------------// Type Visitor //---------------------//


struct type_visitor
{
    virtual void visit( const bool_type * ) = 0;
    virtual void visit( const int_type * ) = 0;
};
