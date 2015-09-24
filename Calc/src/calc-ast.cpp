// #include <iostream>
// #include <string>
// #include "calc-ast.hpp"
//
//
// struct print_vis : visitor
// {
//     void visit( digit * ) { output = "digit"; }
//     void visit( add * ) { output = "add"; }
//     void visit( sub * ) { output = "sub"; }
//     void visit( mult * ) { output = "mult"; }
//     void visit( divide * ) { output = "divide"; }
//     void visit( mod * ) { output = "mod"; }
//
//     std::string output;
// };
//
// void print_expr(expr * e)
// {
//     print_vis vis;
//     e->accept(vis);
//     std::cout << vis.output;
// }
