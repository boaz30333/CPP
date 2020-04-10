#include <iostream>

#ifndef DATE_H
#define DATE_H
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
	void display;
string relation(string person);
string find(string person);

private:
	void destroy_tree(node *root);
	person *search(string, node * root);

	person *root;
};









