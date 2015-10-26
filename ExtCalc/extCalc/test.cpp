#include "lexer.hpp"
#include "token.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;


int main()
{
    try{
        string input;
        while(getline(cin, input))
        {
            cout << input << endl;
            lexer lex(input);
            cout << "calling getTokenStream" << endl;
            token_stream ts = lex.getTokenStream();
            cout << "PRINTING TOKEN STREAM" << endl;
            while(!ts.eof())
            {
                cout << ts.get().value << " ";
            }
            cout << endl;
        }
    }
    catch(invalid_argument& error)
    {
        cout << error.what() << endl;
    }
    return 0;
}
