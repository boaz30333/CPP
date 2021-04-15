#include "symtab.h"
#include <fstream>
#include <string>
#include <cstdlib>

	void SymbolTable::initReserved(){
    ifstream infile("/home/osboxes/Documents/CPP/scanner/reserved.txt");
    string str;
    while (getline(infile, str))
    {
        //
        if(str.empty()) continue;
        string reserved_word= str.substr(0,str.find("\t"));
        int enum_number= atoi((str.substr(str.find("\t")+1)).c_str());
        tokenType type= static_cast<tokenType>(enum_number);
        shared_ptr<Token> ptr= make_shared<Token>(type,reserved_word);
        this->symMap.insert(pair<string,shared_ptr<Token>>(reserved_word,ptr));//use insert token
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
        //https://stackoverflow.com/questions/26281979/c-loop-through-map
        for(auto const& sym: this->symMap){
            auto token = *(sym.second.get());
            if(token.getType()==tokenType::IDENTIFIER){
                cout<< token.getText()<< "\t" ;
                for (auto  line: *(token.getLines().get())){
                    cout<< line<< " ";
                }
                cout<< endl;
            }
        }
        
    }