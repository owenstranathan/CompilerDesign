#ifndef TYPE_HPP
#define TYPE_HPP

#include "prelude.hpp"


struct type
{
    virtual ~type()
    { }
    virtual void accept( type_visitor & ) const = 0;
};

struct bool_type : type
{
    void accept( type_visitor & v ) { v.visit(this) }
};

struct int_type : type
{
    void accept( type_visitor & v ) { v.visit(this) }
};


#endif
