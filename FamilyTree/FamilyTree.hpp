#pragma once
#include <iostream>


namespace family{
    using namespace std;
    struct person{
	string name;
	person *left;
	person *right;
};

class Tree{
public:
	Tree(string name);
	~Tree();
	Tree& addFather(string child,string father);
	Tree& addMother(string child,string mother);
	void remove(string name);
	void display() const;
string relation(string person) const;
string find(string person) const;

private:
	person * search(string, person * root);
void remove(person * person);
	person *root;
};
}

