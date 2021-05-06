#include "symbol.h"
#include "strings.h"
#include <iostream>


using namespace std;


void Terminal::printSymbol() const{
cout << terminalStrings[this->getSymbol()] <<endl;
}
void Nonterminal::printSymbol() const{
cout << tokenStrings[this->getSymbol()] <<endl;

}
int Terminal::getSymbol()const {
    return this->sym;
}
int Nonterminal::getSymbol() const{
        return this->sym;

}
