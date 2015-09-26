#ifndef CALC_PRINT_HPP
#define CALC_PRINT_HPP

#include <string>
#include <iostream>

#include "calc-ast.hpp"


////////////////////////////////////////////////////////////////////////////////
//PRE-Order printing////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

struct pre_order_visitor : visitor
{
    void visit( digit * ) override;
    void visit( add * ) override;
    void visit( sub * ) override;
    void visit( mult *) override;
    void visit( divide *) override;
    void visit( mod *) override;

    std::string output;
};

std::string pre_print(expr *);

inline void s_expr_print(expr * e)
{
    std::cout << pre_print(e) << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
//POST-Order printing///////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

struct post_order_visitor : visitor
{
    void visit( digit * ) override;
    void visit( add * ) override;
    void visit( sub * ) override;
    void visit( mult *) override;
    void visit( divide *) override;
    void visit( mod *) override;

    std::string output;
};

std::string post_print(expr *);

inline void post_fix_print(expr * e)
{
    std::cout << post_print(e) << std::endl;
}

#endif
