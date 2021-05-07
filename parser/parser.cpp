#include "parser.h"
#include <iostream>
#include <stdexcept>

using namespace std;
void Parser::parse()
{
    terminal a = this->nextToken();
    shared_ptr<Symbol> end = make_shared<Terminal>(terminal::END, Type::TERM);
    shared_ptr<Symbol> x = make_shared<Nonterminal>(nonTerminal::E, Type::NONTERM);
    stack.push_back(end);
    stack.push_back(x);
    printLM();
    while (*(x.get()) != terminal::END)
    {
        if (*(x.get()) == a)
        {
            accepted.push_back(x);
            stack.pop_back();
            printLM();
            a = this->nextToken();
        }
        else if (x->getType() == Type::TERM)
        {
            cout << "syntax error\n"
                 << endl;
            break;
        }
        else if (table[x->getSymbol()][a] == -1)
        {
            cout << "syntax error\n"
                 << endl;
            break;
        }
        else
        {
            auto rule = rules[table[x->getSymbol()][a]];
            stack.pop_back();
            stack.insert(stack.end(), rule.begin(), rule.end());
            if (*stack.back() == terminal::EPSILON)
                stack.pop_back();
            printLM();
        }

        x = stack.back();
    }
}
terminal Parser::nextToken()
{

    char ch;
    this->inputFile.get(ch);
    if (inputFile.eof())
        return terminal::END;
    switch (ch)
    {
    case ' ':
        return nextToken();
        break;
    case '\r':
        return nextToken();
        break;
    case '\n':
        return nextToken();
        break;
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

        __throw_ios_failure("no legal symbol" + ch);
        break;
    }
}
void Parser::printLM()
{
    for (auto i = accepted.begin(); i != accepted.end(); i++)
    {
        (*i)->printSymbol();
        cout << " ";
    }
    cout << "|";
    for (auto i = stack.rbegin(); i != stack.rend() - 1; i++)
    {
        cout << " ";
        (*i)->printSymbol();
    }
    cout << endl;
}