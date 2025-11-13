#ifndef STACK_H
#define STACK_H
#define MAX 10
#include <iostream>

template<typename T>
class stack{
   private:
	int top = -1;
	T arr[MAX];
	
   public:
	bool isEmpty(){
   		return (top == -1);
	}
	 
	bool isFull(){
		return(top >= MAX-1);
	}
	
	void peek(){
		if(isEmpty()){
			std::cout << "the stack is empty\n";
		}
	else{
		std::cout<<"the value of the stack is: " << arr [top] << std::endl;
	}
	}
	void push(T value){
		if (isFull()){
			std::cout<< "stack overflow!!"<<std::endl;
		}
		else{
			arr[++top]=value;
			std::cout<<"successfully pushed"<<top<<std::endl;
		}
	}
	void pop(){
		if (isEmpty()){
			std::cout<<"The stack is empty";
		}
		else{
			std::cout<<"successfully popped" <<arr[top--]<<std::endl;
			
		}
	}
	void display(){
		if (isEmpty()){
			std::cout <<"the stack is empty";
		}
		else{
			for(int i =0; i <= MAX; i--){
				std::cout << arr[i] << std::endl;
			}
		}
	}

};

#endif


