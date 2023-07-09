#include<iostream>
#include<string>
#include<cmath>
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
	if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^' || ch=='%' )
	{
		return 0;
	}
	return 1;
}
int Operation(int a ,int b,char p)
{
	switch(p)
			{
		    	case '+':
				{
					return a+b;
					break;
				}
		   		case '-':
				{
					return a-b;
					break;
				}	
		    	case '*':
				{
					return a*b;
					break;
				}
		    	case '/':
				{
					return a/b;
					break;
				}
				case '%':
				{
					return a%b;
					break;
				}
		    	case '^':
				{
					return pow(a,b);
					break;
				}
			}
}
int main()
{
	Stack<int> s(10);
	
	string infix;
	cout<<"Enter an infix expression "<<endl;
	cin>>infix;
	int len = infix.size();
	
    int i=len-1;
	while(i>=0)
	{
		if(isOperand(infix[i]))
		{
			s.push(infix[i--] - '0');
		}
		else
		{
			int a = s.pop() ;
			int b = s.pop();
			int res = Operation(a , b ,infix[i--]);
			s.push(res);	
		}
	}
	cout<<s.pop();
	
	
	return 0;
}
