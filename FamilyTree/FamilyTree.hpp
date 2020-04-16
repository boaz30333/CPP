#pragma once
#include <iostream>


namespace family{
    using namespace std;
    struct person{
		string name;
		person * father;
		person * mother;
	};
class Trunk
{
	public:
    Trunk *prev;
    string str;

    Trunk(Trunk *prev, string str)
    {
        this->prev = prev;
        this->str = str;
    }
};
	class Tree{
	public:
		Tree(string name);
		~Tree();
		Tree& addFather(string child,string father);
		Tree& addMother(string child,string mother);
		void remove(string name);
		void display() ;
		string relation(string person) const;
		string find(string person) const;
		//string get_name();
		person * get_root();
		//person * get_left();
		void set_father(string name);
		//person * get_right();
		void set_mother(string name);


	private:
		person * search(string, person * root);
		void remove(person ** person);
		person *root;
		void printTree(person *root, Trunk *prev, bool isLeft);
		void showTrunks(Trunk *p);

	};
}

