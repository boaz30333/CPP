#include "token.h"
#include <iostream>
#include "tokenstrings.h"
using namespace std;


    tokenType Token::getType(){
return this->type;
    }
    string Token::getText(){
return this->text;
    }
    void Token::printToken(){
cout<< tokenStrings[this->type-258]<<endl;
    }

    void varToken::add_line(int l){
        this->lines.get()->insert(l);
    }
    shared_ptr<set<int>> varToken::getLines(){
        return this->lines;
    }
    