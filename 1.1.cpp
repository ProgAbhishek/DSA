#include<iostream>
using namespace std;
#define MAX 100
int stack[MAX], top=-1;

void push(int value)
{
	if(top==MAX-1){
		cout<<" stack overflow\n";
	}
	else
	{
		top++;
		stack[top]=value;
		cout<<value<<" pushe into the stack\n";
		
	}
	}
	
	//pop operation
	void pop(){
		if(top==-1)
		{
			cout<<" stack underflow\n";
		}
		else{
			cout<<stack[top]<<" popped from stack.\n";
			top--;
		}
	}
	
	void display()
	{
		if(top==-1){
			cout<<" stack is emmpty\n";
		}
		else
		{
			cout<<"  stack elements:\n";
			for(int i=top;i>=0;i--){
				cout<<stack[i]<<"";
			}
			cout<<"\n";
			}
		}
		
		int main(){
			push(10);
			push(20);
			push(30);
			display();
			pop();
			display();
			return 0;
		}
		

