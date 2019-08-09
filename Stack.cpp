/* it will work on static memory */

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#define CAPACITY 5

class Stack {
	int stck[CAPACITY];
	int top;
 public:
 	Stack() { //constructor 
 	 top = -1; //top value not pointing any stack value
	 }
 	void push(int ele);
 	bool isFull();
 	bool isEmpty();
 	int pop();
 	void traverse();
 	void pick(int tos);
};

void Stack::push(int ele) { //inserting elements on the stack
	 
	
	if(isFull()){
		cout << "Stack is full." << endl;
	}else{
		top++;
		stck[top] = ele;
	}
}
bool Stack::isFull() { //checking stack is full or not
	if((top+1) == CAPACITY)
	return true;
	else return false;
}
bool Stack::isEmpty() { //checking stack is empty or not
	if(top == -1)
	return true;
	else return false;
}
int Stack::pop() { //deleting elements from the stack
   if(isEmpty()) {
   	cout << "There are no elements available to delete." << endl;
   }else {
   	top --;
   	return stck[top];
   }
}
void Stack::pick(int tos) { //extracting elements according to top value
      
	  if(isEmpty()) {
      	cout << "No elements available." << endl;
	  }else {
	  	cout << "In position " << tos << " the integer: " << stck[tos-1] << " is found." << endl; 
	  }
}
void Stack::traverse() { //traversing all the elements inside the stack
 if(isEmpty()) { 
  cout << "No element is found." << endl;
 } 
 else {
 	cout << "\nElement/\'s inside the stack: " << endl;
 	for(int i = 0; i <= top; i++) {
 		cout << stck[i] << ", ";
	 } // end of for
 } //end of else
}
int main(){
	
	Stack stack;
	int nopush;
	int pushvalue;
	
	cout << "How many element you want to push? MAX VALUE IS 5"  << "\n: ";
	cin >> nopush;
	cout << "Enter the elements one by one: " << endl;
	for(int i = 0; i < nopush; i++) { //pushing the elements on the stack
	    	cin >> pushvalue;
	    	stack.push(pushvalue);
	    	if(stack.isFull()) break;
	}
	cout << "All value\'s are pushed" << endl;
	
	stack.traverse(); //print the list before deleting  
	stack.pop(); // deleting one element
	stack.traverse(); //print the list after deleting
	
	int pickvalue;
	
	cout << "\nEnter index number of stack which elements you want to pick: ";
	cin >> pickvalue;
	stack.pick(pickvalue);
    //elements after picking one element
    stack.traverse();
    stack.push(60); //pushing new elements to overwritten on previos elements
    stack.traverse(); //traversing after pushing new elements;
    stack.pop(); //deleting one elements at the top
    stack.traverse(); //printing all the elements inside stack after deleting one
	
	
	cin.get();
	return 0;
}

