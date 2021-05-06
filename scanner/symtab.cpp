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
        if(str.empty()) continue;
        string reserved_word= str.substr(0,str.find("\t"));
        int enum_number= atoi((str.substr(str.find("\t")+1)).c_str());
        tokenType type= static_cast<tokenType>(enum_number);
        this->insertToken(reserved_word,make_shared<Token>(type,reserved_word)) ;
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
            auto token = sym.second.get();
            if(token->getType()==tokenType::IDENTIFIER){
                cout<< token->getText().c_str()<< "\t" ;
                set<int> lines= *(token->getLines()).get();
                for (auto  line: lines ){
                    cout<< line<< " ";
                }
                cout<< endl;
            }
        }
        
    }