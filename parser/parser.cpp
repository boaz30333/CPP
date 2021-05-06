#include "parser.h"
#include <iostream>
#include <stdexcept>

using namespace std;
void Parser::parse()
{
    terminal a = this->nextToken();
    shared_ptr<Symbol> x = make_shared<Nonterminal>(nonTerminal::E, Type::NONTERM);
    while(*(x.get())!=terminal::END){
        if(*(x.get())== a){

        }
        else if (x->getType()==Type::TERM) {
            cout << "syntax error\n" <<endl;
            break;
        }
        else if(table[x->getSymbol()][a]==-1){
            cout << "syntax error\n" <<endl;
            break;
        }
        else{
auto rule = rules[table[x->getSymbol()][a]];
 stack.pop_back();
stack.insert(stack.end(), rule.begin(), rule.end());
   
        }
    x = stack.back(); 

    }
    

}
terminal Parser::nextToken()
{
    char ch;
    this->inputFile.get(ch);
    switch (ch)
    {
    case 'i':
        this->inputFile.get(ch);
        if (ch == 'd')
        {
            return terminal::ID;
        }
        else
        {
            __throw_ios_failure("no legal symbol: i" + ch);
        }
        break;
    case '+':
        return terminal::PLUS;
        break;
    case '*':
        return terminal::ASTERISK;
        break;
    case '(':
        return terminal::LPAREN;
        break;
    case ')':
        return terminal::RPAREN;
        break;
    case 'e':
        return terminal::EPSILON;
        break;

    default:
        if(ch==EOF) return terminal::END;
        else
        __throw_ios_failure("no legal symbol" + ch) ;
        break;
    }
}
void Parser::printLM()
{
}