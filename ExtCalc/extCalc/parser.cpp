#include "parser.hpp"
#include <stdexcept>

//expr -> logical_or_expression
expr* parser::expression()
{
    std::cout << "In expression" << std::endl;
    return logical_or();
}

/*
logical_or_expression-> logical_or_expression '||' logical_and_expression
                        | logical_and_expression
*/
expr* parser::logical_or()
{
    std::cout << "logical_or" << std::endl;
    expr* e1 = logical_and();
    while(!tokens.eof())
    {
        if(match(bar_bar))
        {
            expr* e2 = logical_and();
            e1 = new or_expr(e1, e2);
        }
        else
            break;
    }
    return e1;
}

/*

logical-and-expr -> logical-and-expr '&&' ordering-expr
                  | equality-expr
*/

expr* parser::logical_and()
{
    expr* e1 = equality();
    while(!tokens.eof())
    {
        if(match(amp_amp))
        {
            expr* e2 = equality();
            e1 = new and_expr(e1, e2);
        }
        else
            break;
    }
    return e1;
}

/*
equality-expr -> equality-expr '==' ordering-expr
               | equality-expr '!=' ordering-expr
               | ordering-expr
*/

expr* parser::equality()
{
    expr* e1 = ordering();
    while(!tokens.eof())
    {
        if(match(eq_eq))
        {
            expr * e2 = ordering();
            e1 = new eequ_expr(e1, e2);
        }
        else if(match(bang_eq))
        {
            expr* e2 = ordering();
            e1 = new nequ_expr(e1, e2);
        }
        else
        {
            break;
        }
    }
    return e1;
}

/*
ordering-expr -> ordering-expr '<' additive-expr
               | ordering-expr '>' additive-expr
               | ordering-expr '<=' additive-expr
               | ordering-expr '>=' additive-expr
               | additive-expr
*/

expr* parser::ordering()
{
    expr* e1 = additive();
    while(!tokens.eof())
    {
        if(match(gt))
        {
            expr * e2 = additive();
            e1 = new gt_expr(e1, e2);
        }
        else if(match(lt))
        {
            expr* e2 = additive();
            e1 = new lt_expr(e1, e2);
        }
        else if(match(gt_eq))
        {
            expr* e2 = additive();
            e1 = new gte_expr(e1, e2);
        }
        else if(match(lt_eq))
        {
            expr* e2 = additive();
            e1 = new lte_expr(e1, e2);
        }
        else
        {
            break;
        }
    }
    return e1;
}

/*
additive-expr -> additive-expr + multiplicative-expr
               | additive-expr - multiplicative-expr
               | multiplicative-expr
*/

expr* parser::additive()
{
    expr* e1 = multiplicative();
    while(!tokens.eof())
    {
        if(match(plus))
        {
            expr * e2 = multiplicative();
            e1 = new add_expr(e1, e2);
        }
        else if(match(minus))
        {
            expr * e2 = multiplicative();
            e1 = new mult_expr(e1, e2);
        }
        else
        {
            break;
        }
    }
    return e1;
}

/*
multiplicative-expr -> multiplicative-expr * unary-expr
                     | multiplicative-expr / unary-expr
                     | multiplicative-expr % unary-expr
                     | unary-expr
*/

expr* parser::multiplicative()
{
    expr* e1 = unary();
    while(!tokens.eof())
    {

        if(match(star))
        {
            expr * e2 = unary();
            e1 = new mult_expr(e1, e2);
        }
        else if(match(slash))
        {
            expr * e2 = unary();
            e1 = new div_expr(e1, e2);
        }
        else if(match(percent))
        {
            expr * e2 = unary();
            e1 = new mod_expr(e1, e2);
        }
        else
        {
            break;
        }
    }
    return e1;
}

/*
unary-expr -> - unary-expr
            | + unary-expr
            | ! unary-expr
            | primary-expr
*/
expr* parser::unary()
{
    if(match(minus))
    {
        expr * e = primary();
        return new neg_expr(e);
    }
    else if(match(plus))
    {
        expr * e = primary();
        return new pos_expr(e);
    }
    else if(match(bang))
    {
        expr * e = primary();
        return new not_expr(e);
    }
    else
    {
        return primary();
    }
}

/*
    primary-expr -> literal
                  | ( expr )
*/
expr * parser::primary()
{
    if(match(l_paren))
    {
        expr * e = expression();
        match(r_paren);
        return e;
    }
    int val;
    token i;
    switch (peek())
    {
        case true_true:
            match(true_true);
            return new bool_expr(true);
        case tricksy:
            match(tricksy);
            return new bool_expr(false);
        case integer:
            i = match_and_return(integer);
            val = std::stoi(i.Symbol()->spelling());
            return new int_expr(val);
        default:
            throw std::runtime_error("Expected primary expression");
            break;
    }

}


token_type parser::peek()
{
    return tokens.peek().type;
}

token parser::match_and_return(token_type tok_type)
{
    if(peek() == tok_type)
    {
        return get();
    }
    else
    {
        throw std::logic_error("Match and return failed");
    }
}

bool parser::match(token_type tok_type)
{
    if(peek() == tok_type)
    {
        next();
        return true;
    }
    else
    {
        return false;
    }
}
