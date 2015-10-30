#include "lexer.hpp"
#include "symbol.hpp"
#include "parser.hpp"
//#include "elaborate.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;


int main()
{
    try{
        std::string input;
        std::vector<std::string> inputs;
        symbol_table sym_tab;
        sym_tab.install();
        while(getline(cin, input))
        {
            lexer lex(input, sym_tab);
            token_stream ts = lex.getTokenStream();
            //parser par(ts, sym_tab);
            //par.parse();
            while(!ts.eof())
            {
                cout << ts.get().Symbol()->spelling() << " ";
            }
            cout << endl;
        }
    }
    catch(exception& err)
    {
        cout <<"Error: " << err.what() << endl;
    }
    return 0;
}
