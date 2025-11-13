#include <iostream>
#include "stack.h"

int main(){
	stack <int> s1;
	stack<std::string> s2;
	s1.peek();
    s1.push(10);
    s1.push(9);
    s1.push(8);
    s1.push(7);
    s1.push(6);
    s1.push(5);
    s1.push(4);
    s1.push(3); 
    s1.push(2);
    s1.pop();
    s1.push(1);
	s1.peek();
	s1.pop();
	s1.display();
	return 0;
};
