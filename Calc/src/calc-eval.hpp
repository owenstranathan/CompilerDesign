#ifndef CALC_EVAL_HPP
#define CALC_EVAL_HPP

#include "calc-ast.hpp"

struct expr_eval_visitor : visitor
{
    void visit( digit * );
    void visit( add * );
    void visit( sub * );
    void visit( mult *);
    void visit( divide *);
    void visit( mod *);

    int value;
};

int eval(expr *);

#endif
