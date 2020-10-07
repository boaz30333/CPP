#include "FamilyTree.hpp"
#include <iostream>
#include <string>

#define COUNT 10 

namespace family{
using namespace std;
Tree::Tree(string name){
	root = new person();
	if(root==NULL) {
		cout<<"error"<<endl;
		return;
	}
	root->rltd="me";
	root->name = name;
	root->father=NULL;
	root->mother=NULL;

}

Tree::~Tree(){
	remove(&(this->root));
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
	  __throw_invalid_argument("try to add father to son not exist");
		if(son->father!=NULL)
		  __throw_logic_error("try to add father to son already has ons");
	son->father = new person();
	if(son->father==nullptr) __throw_bad_alloc;
	(son->father)->name=father;
	if(son->rltd==string("me")) 
	(son->father)->rltd="father";
	else if (son->rltd==string("father")||son->rltd==string("mother")) 
	(son->father)->rltd="grandfather";
	else {(son->father)->rltd="great-"+son->rltd;
		size_t found =(son->father)->rltd.find("mother");
	if(found!=  string::npos) (son->father)->rltd.replace(found,6,"father");
	}
	return *this;	
}

Tree& Tree:: addMother(string child,string mother){
		person *son = search(child,this->root);
	if(son==NULL)
	  __throw_invalid_argument("try to add mother to son not exist");
		if(son->mother!=NULL)
		  __throw_logic_error("try to add mother to son already has ons");
	son->mother = new person();
	if(son->mother==nullptr) __throw_bad_alloc;
	(son->mother)->name=mother;
	if(son->rltd==string("me")) 
	(son->mother)->rltd="mother";
	else if (son->rltd==string("mother")||son->rltd==string("father")) 
	(son->mother)->rltd="grandmother";
	else {(son->mother)->rltd="great-"+son->rltd;
	size_t found =(son->mother)->rltd.find("father");
	if(found!= string::npos) (son->mother)->rltd.replace(found,6,"mother");
	}
	return *this;
}

void Tree:: remove(string name){
	if((this->root)->name==string (name))
		__throw_invalid_argument("cannot remove the root!");
person **son = searchRemove(name,&this->root);
	if(son==NULL)
	  __throw_invalid_argument("Did not find the person in family tree");
	remove(son);
	*son=NULL;
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

string Tree::relation(string person){
family::person * son = search(person,this->root);
if(son==nullptr) return "unrelated";
return son->rltd;

}

string Tree::find(string rltd){
person * son =find(rltd, this->root);
if(son==nullptr)
__throw_invalid_argument("try find related not exist");
return son->name;
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
	if(root->mother!=NULL){
	person * left = search(name,root->mother);
	if(left!=NULL) return left;
	}
	return NULL;
	
}
person * Tree:: find(string rltd, person * root){
	if(root->rltd==rltd) return root;
	if(root->father!=NULL){
	person * right = find(rltd,root->father);
	if (right!=NULL) return right;
	}
	
	if(root->mother!=NULL){
	person * left = find(rltd,root->mother);
	if(left!=NULL) return left;
	}
	return NULL;
	
}
person ** Tree:: searchRemove(string name, person ** root){
	if((*root)->name==name) 
		  return root;
	if((*root)->father!=NULL){
		person ** right = searchRemove(name,&(*root)->father);
		if (right!=NULL) return right;
	}
	
	if((*root)->mother!=NULL){
		person ** left = searchRemove(name,&(*root)->mother);
		if(left!=NULL) return left;
	}
	return NULL;
	
}
person * Tree::get_root(){
	return root;
}


}
