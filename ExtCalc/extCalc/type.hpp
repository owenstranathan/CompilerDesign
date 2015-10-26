#ifndef TYPE_HPP
#define TYPE_HPP

#include "visitor.hpp"


struct type
{
    virtual ~type()
    { }
    virtual void accept( type_visitor & ) const = 0;
};

struct bool_type : type
{
    void accept( type_visitor & v ) const { v.visit(this); }
};

struct int_type : type
{
    void accept( type_visitor & v ) const { v.visit(this); }
};


#endif
