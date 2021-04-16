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
       string tokenstrings;
        if(type>=258)
            tokenstrings=tokenStrings[this->type-258];
            else
           tokenstrings+=type;
cout<< tokenstrings << " "+ this->getText()<<endl;
    }

    void varToken::add_line(int l){
        this->lines.get()->insert(l);
    }
    shared_ptr<set<int>> varToken::getLines(){
        return this->lines;
    }
    