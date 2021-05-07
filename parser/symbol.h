#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include "enums.h"
using namespace std;

class Symbol
{
    Type type; // TERM or NONTERM

public:
    Symbol(Type t) : type(t) {}
    virtual ~Symbol() = default;
    Type getType() const
    {
        return this->type;
    }
    virtual int getSymbol() const = 0;
    virtual void printSymbol() const = 0;
    friend bool operator==(const Symbol &n, const Symbol &m)
    {
        if (n.getType() == m.getType() && n.getSymbol() == m.getSymbol())
        {
            return true;
        }
        else
            return false;
    }
    friend bool operator==(const Symbol &n, const terminal &m)
    {
        if (n.getType() == Type::TERM && static_cast<terminal>(n.getSymbol()) == m)
        {
            return true;
        }
        else
            return false;
    }
    friend bool operator!=(const Symbol &n, const Symbol &m)
    {
        return !(n == m);
    }
    friend bool operator!=(const Symbol &n, const terminal &m)
    {
        return !(n == m);
    }
};

class Nonterminal : public Symbol
{
    nonTerminal sym;

public:
    Nonterminal(nonTerminal s, Type t) : Symbol(t), sym(s) {}
    void printSymbol() const;
    int getSymbol() const;
};

class Terminal : public Symbol
{
    terminal sym;

public:
    Terminal(terminal s, Type t) : Symbol(t), sym(s) {}
    void printSymbol() const;
    int getSymbol() const;
};