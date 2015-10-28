#include "parser.hpp"

//expr -> logical_or_expression
expr* parser::expression()
{
    return logical_or();
}

/*
logical_or_expression-> logical_or_expression '||' logical_and_expression
                        | logical_and_expression
*/


expr* parser::logical_or()
{
    expr* expr1 = logical_and();
    expr* expr2;
    while(!tokens.eof())
    {

        assert(peek().type == bar_bar);
        expr2 = logical_and();
    }
}
