#include "symtab.h"
#include <fstream>
#include <string>
#include <cstdlib>

	void SymbolTable::initReserved(){
    ifstream infile("reserved.txt");
    string str;
    while (getline(infile, str))
    {
        //
        string reserved_word= str.substr(0,str.find("\t"));
        int enum_number= atoi((str.substr(str.find("\t")+1)).c_str());
        tokenType type= static_cast<tokenType>(enum_number);
        shared_ptr<Token> ptr= make_shared<Token>(type,reserved_word);
        this->symMap.insert(pair<string,shared_ptr<Token>>(reserved_word,ptr));
    }
    }

	shared_ptr<Token> SymbolTable::lookupToken(string text){
       auto iter= symMap.find( text);
       return (iter != symMap.end()) ? symMap.at(text) : nullptr ;
    }
	void SymbolTable::insertToken(string text, shared_ptr<Token> tokenp){
        this->symMap.insert(pair<string,shared_ptr<Token>>(text,tokenp));
    }
	void SymbolTable::xref(){
        
    }