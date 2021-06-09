#include "scanner.h"
#include "symtab.h"
// globals
Token_stream ts;
Symbol_table st;
//map<string, int> names;

int statement()
{
    Token t = ts.get(); // get the next token from token stream
    switch (t.kind)
    {
    case INT:
        return declaration();
    case IF:
    {
       int cond= boolean();
       int ifTrue= boolean();
       t = ts.get(); //suppose to be else
       if(t.kind!= ELSE){
           throw runtime_error("'else' expected");
       }
        int ifFalse= boolean();
        if(cond) {
            return ifTrue;
        }
        else return ifFalse;
    }
    default:
        ts.putback(t); // put t back into the token stream
        return boolean();
    }
}

int declaration()
{
    Token t = ts.get();
    if (t.kind != ID)
        throw runtime_error("name expected in declaration");
    string name = t.name;
    st.declare(name, 0);
    return 0;
}
int boolean()
{
    int left = join();
    int findTrue = 0;
    if (left != 0)
    {
        findTrue = 1;
    }
    Token t = ts.get();

    switch (t.kind)
    {
    case '|':
        while (true)
        {

            left = join();
            if (left != 0)
            {
                findTrue = 1;
            }
            t = ts.get();
            if (t.kind != '|')
            {
                ts.putback(t);
                break;
            }
        }
        return findTrue;
        break;
    default:
        ts.putback(t); // put t back into the token stream
                       // return left;   // finally: no more + or -: return the answer
        return left;
        break;
    }
}
int join()
{
    int left = rel();
    int findFalse = 0;
    Token t = ts.get();
    if (left == 0)
    {
        findFalse = 1;
    }
    switch (t.kind)
    {
    case '&':
        while (true)
        {

            left = rel();
            if (left == 0)
            {
                findFalse = 1;
            }
            t = ts.get();
            if (t.kind != '&')
            {
                ts.putback(t);
                break;
            }
        }
        return !findFalse;
        break;
    default:
        ts.putback(t); // put t back into the token stream
                       // return left;   // finally: no more + or -: return the answer
        return left;
        break;
    }
}
// int equality()
// {
//     int left = expression();
//     Token t = ts.get();
//     switch (t.kind)
//     {
//     case '<':
//         break;
//     case '>':
//         break;
//     default:
//         ts.putback(t); // put t back into the token stream
//         return left;   // finally: no more + or -: return the answer
//         break;
//     }
// }

int rel()
{
    int left = expression();
    Token t = ts.get();
    int right;
    switch (t.kind)
    {
    case '<':
        right = expression();
        if (left < right)
            return 1;
        else
            return 0;
        break;
    case '>':
        right = expression();
        if (left > right)
            return 1;
        else
            return 0;
        break;
    default:
        ts.putback(t); // put t back into the token stream
        return left;   // finally: no more + or -: return the answer
        break;
    }
}
// + and -
int expression()
{
    int left = term();  // read and evaluate a Term
    Token t = ts.get(); // get the next token from token stream

    while (true)
    {
        switch (t.kind)
        {
        case '+':
            left += term(); // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term(); // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t); // put t back into the token stream
            return left;   // finally: no more + or -: return the answer
        }
    }
}

// * and /
int term()
{
    int left = primary();
    Token t = ts.get();

    while (true)
    {
        switch (t.kind)
        {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
        {
            int d = primary();
            if (d == 0)
                throw runtime_error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);
            return left;
        }
    }
}

int primary()
{
    Token t = ts.get();
    int result;
    switch (t.kind)
    {
    case '(': // handle '(' expression ')'
    {
        int d = boolean();
        t = ts.get();
        if (t.kind != ')')
            throw runtime_error("')' expected");
        return d;
    }
    case '-':
        return -1 * primary();
    case '+':
        return primary();
    case '!':
        if (primary() != 0)
            return 0;
        else
            return 1;
    case NUM:
        return t.value; // return the number value
    case ID:
    {
        string n = t.name;
        Token next = ts.get();
        if (next.kind == '=')
        { // name = expression
            int d = boolean();
            st.set(n, d);
            return d; // return the assignment value
        }
        else
        {
            ts.putback(next);            // not an assignment
            return st.get(t.name).value; // return the id value
        }
    }
    default:
        throw runtime_error("primary expected");
    }
}
