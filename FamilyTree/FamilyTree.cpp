






#include "FamilyTree.hpp"
#include <iostream>
#define COUNT 10 
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

void Tree::  display() {
	
print2D(this->root);

}
// Function to print binary tree in 2D  
// It does reverse inorder traversal  
void Tree::print2DUtil(person *root, int space)  
{  
    // Base case  
    if (root == NULL)  
        return;  
  
    // Increase distance between levels  
    space += COUNT;  
  
    // Process right child first  
    print2DUtil(root->father, space);  
  
    // Print current node after space  
    // count  
    cout<<endl;  
    for (int i = COUNT; i < space; i++)  
        cout<<" ";  
    cout<<root->name<<"\n";  
  
    // Process left child  
    print2DUtil(root->mother, space);  
}  
  
// Wrapper over print2DUtil()  
void Tree::print2D(person *root)  
{  
    // Pass initial space count as 0  
    print2DUtil(root, 0);  
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