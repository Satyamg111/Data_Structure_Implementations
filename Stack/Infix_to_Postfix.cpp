#include<iostream>
#define INVALID_DATA ' '
using namespace std;
template<class T>
class Stack{
	int topIndex;
	int cap;
	T arr[100];
	public:
		Stack(int c){
			topIndex = -1;
			cap = c;
			arr[cap];
		}
		bool isEmpty(){
			return (topIndex<0);
		}
		bool isFull(){
			return (topIndex==cap-1);
		}
		bool push(T ch)
		{
			if(isFull()){
				return false;
			}
			else{
				arr[++topIndex]=ch;
				return true;
			}
		}
		T pop()
		{
			if(isEmpty()){
				return INVALID_DATA;
			}
			else{
				
				T r=arr[topIndex--];
				return r;
			}
		}
		T top()
		{
			if(isEmpty()){
				return INVALID_DATA;
			}
			else {
				return (arr[topIndex]);
			}
		}
		int size()
		{
			return topIndex+1;
		}
		void print()
		{
			if(isEmpty())
			{
				return;
			}
			else{
				for(int i=topIndex;i>=0;i--)
				{
					cout<<arr[i];
				}
			}
		}
		
};
bool isOperand(char ch){
	if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='%' || ch =='^')
	{
		return 0;
	}
	return 1;
}
int pre(char p)
{
	switch(p){
		case '+':
			{
				return 1;
				break;
			}
		case '-':
			{
				return 1;
				break;
			}
		case '*':
			{
				return 2;
				break;
			}
		case '/':
			{
				return 2;
				break;
			}
		case '%':
			{
				return 2;
				break;
			}
		case '^':
			{
				return 3;
				break;
			}
	}
}
bool isOpen(char ch)
{
	if(ch=='(')
	{
		return 1;
	}
	return 0;
}
bool isClose(char ch)
{
	if(ch==')')
	{
		return 1;
	}
	return 0;
}


int main()
{
	char infix[100],c;
	cout<<"Enter an infix expression "<<endl;
	cin>>infix;
	
	Stack<char>s(100);
    int i=0;
	while(infix[i] != '\0')
	{
		
		if(isOperand(infix[i]))
		{
			if(!isOpen(infix[i]) && !isClose(infix[i]))
			{
				cout<<infix[i++];
			}
			else
			{
				if(isOpen(infix[i]))
				{
					s.push(infix[i++]);
				}
				else if(isClose(infix[i]))
				{
					c = s.pop();
					while(s.top()!=c)
					{
						cout<<c;
						c = s.pop();
					}
					s.pop();
					i++;	
				}
			}
		}
		else 
		{
			if(pre(infix[i])>pre(s.top()) || s.isEmpty())
			{
				s.push(infix[i++]);
			}
			else
			{
				c = s.pop();
				if(!isOpen(c))
				{
					cout<<c;
				}		
			}
			
		}
	}
	while(!s.isEmpty())
	{
		c=s.pop();
		cout<<c;
	}
	
	
	return 0;
}
