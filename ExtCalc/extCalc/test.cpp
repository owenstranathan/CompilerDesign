#include "lexer.hpp"
#include "symbol.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;


int main()
{
    try{
        string input;
        while(getline(cin, input))
        {
            symbol_table sym_tab;
            sym_tab.install();
            lexer lex(input, sym_tab);
            cout << "calling getTokenStream" << endl;
            token_stream ts = lex.getTokenStream();
            cout << "PRINTING TOKEN STREAM" << endl;
            while(!ts.eof())
            {
                cout << ts.get().Symbol()->spelling() << " ";
            }
            cout << endl;
        }
    }
    catch(exception& error)
    {
        cout <<"Error: " << error.what() << endl;
    }
    return 0;
}
