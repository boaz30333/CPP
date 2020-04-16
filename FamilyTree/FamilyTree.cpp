






#include "FamilyTree.hpp"
#include <iostream>
namespace family{
using namespace std;
Tree::Tree(string name){
	root=(person *) malloc(sizeof(person));
	if(root==NULL) {
		cout<<"error"<<endl;
		return;
	}
	root->name = name;
	root->father=NULL;
	root->mother=NULL;
}

Tree::~Tree(){
	remove(root);
}

void Tree::remove(person * person){
	if(person != NULL){
		remove(person->father);
		remove(person->mother);
		delete person;
	}
}

Tree& Tree:: addFather(string child,string father){
	return *this;
}

Tree& Tree:: addMother(string child,string mother){
	return *this;
}

void Tree:: remove(string name){

}

void Tree::  display() const{
	return;
}

string Tree::relation(string person) const{
	return person;
}

string Tree::find(string person) const{
	return person;
}

person * Tree::search(string, person * root){
	return root;
}

person * Tree::get_root(){
	return root;
}


}