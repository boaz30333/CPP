






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
	remove(&root);
}

void Tree::remove(person ** person){
	if(*person != NULL){
		remove(&((*person)->father));
		remove(&((*person)->mother));
		delete *person;
	}
}

Tree& Tree:: addFather(string child,string father){
	person *son = search(child,this->root);
	if(son==NULL)
	  __throw_invalid_argument("Did not find the person in family tree");
	son->father=(person *) malloc(sizeof(person));
	(son->father)->name=father;
	return *this;

	
}

Tree& Tree:: addMother(string child,string mother){
		person *son = search(child,this->root);
	if(son==NULL)
	  __throw_invalid_argument("Did not find the person in family tree");
	son->mother=(person *) malloc(sizeof(person));
	(son->mother)->name=mother;
	return *this;
}

void Tree:: remove(string name){
person *son = search(name,this->root);
	if(son==NULL)
	  __throw_invalid_argument("Did not find the person in family tree");
	remove(&son);
}

void Tree::  display(){
	
	printTree(this->root, nullptr, false);

}
void showTrunks(family::Trunk *p)
{
    if (p == nullptr)
        return;
    showTrunks(p->prev);

    cout << p->str;
}
// Recursive function to print binary tree
// It uses inorder traversal
void Tree::printTree(person *root, family::Trunk *prev, bool isLeft)
{
    if (root == nullptr)
        return;
    
    string prev_str = "    ";
    family::Trunk *trunk = new family::Trunk(prev, prev_str);

    printTree(root->mother, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isLeft)
    {
        trunk->str = ".---";
        prev_str = "   |";
    }
    else
    {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->name << endl;
    if (prev)
        prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->father, trunk, false);

}

string Tree::relation(string person) const{
	return person;
}

string Tree::find(string person) const{
	return person;
}


/**
                  a
			b  		 g
		c    f          h
      d   e
		**/
person * Tree:: search(string name, person * root){
	if(root->name==name) return root;
	if(root->father!=NULL){
	person * right = search(name,root->father);
	if (right!=NULL) return right;
	}
	
	if(root->father!=NULL){
	person * left = search(name,root->mother);
	if(left!=NULL) return left;
	}
	return NULL;
	
}

person * Tree::get_root(){
	return root;
}


}