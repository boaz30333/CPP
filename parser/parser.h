#include "symbol.h"
class Parser {
	ifstream& inputFile;
	vector<vector<shared_ptr<Symbol>>> rules = {
		{ make_shared<Nonterminal>(Nonterminal(E_, NONTERM) ), make_shared<Nonterminal>(Nonterminal(T, NONTERM) )},
		{ make_shared<Nonterminal>(Nonterminal(E_, NONTERM)) , make_shared<Nonterminal>(Nonterminal(T, NONTERM) ), make_shared<Terminal>(Terminal(PLUS, TERM)) },
		{ make_shared<Terminal>(Terminal(EPSILON, TERM)) },
		{ make_shared<Nonterminal>(Nonterminal(T_, NONTERM) ), make_shared<Nonterminal>(Nonterminal(F, NONTERM) )},
		{ make_shared<Nonterminal>(Nonterminal(T_, NONTERM)) , make_shared<Nonterminal>(Nonterminal(F, NONTERM) ), make_shared<Terminal>(Terminal(ASTERISK, TERM)) },
		{ make_shared<Terminal>(Terminal(EPSILON, TERM) )},
		{make_shared<Terminal>( Terminal(RPAREN, TERM)) , make_shared<Nonterminal>(Nonterminal(E, NONTERM)) , make_shared<Terminal>(Terminal(LPAREN, TERM)) },
		{ make_shared<Terminal>(Terminal(ID, TERM)) }
	};
	vector<vector<int>> table {
		{ 0 , -1 , -1 , 0 , -1 , -1 },
		{ -1 , 1 , -1 , -1 , 2 , 2 },
		{ 3 , -1 , -1 , 3 , -1 , -1 },
		{ -1 , 5 , 4 , -1 , 5 , 5 },
		{ 7 , -1 , -1 , 6 , -1 , -1 }
	};
	vector<std::shared_ptr<Symbol>> stack;
	vector<std::shared_ptr<Symbol>> accepted;
	
public:
	Parser(ifstream& file) : inputFile(file) {}
	void parse();
	terminal nextToken ();
	void printLM();
};
