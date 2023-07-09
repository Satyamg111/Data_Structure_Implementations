#include<iostream>
#define INVALID_DATA ' '
using namespace std;
template<class T>
class Stack{
	int topIndex;
	int cap;
	T arr[100];
	public:
		Stack(){
			topIndex = -1;
			cap=100;
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
				for(int i=0;i<=topIndex;i++)
				{
					cout<<arr[i]<<" ";
				}
			}
		}
		
};
class Queue{
	
	        Stack<int>s1;
		    Stack<int>s2; 
	public:
		
		bool nqueue(int v)
		{
			if(s1.push(v))
			{
				return true;
			}
			return false;
		}
		int dqueue()
		{
			int p;
			while(!s1.isEmpty())
			{
				s2.push(s1.pop());
			}
			p = s2.pop();
			while(!s2.isEmpty())
			{
				s1.push(s2.pop());
			}
			return p;
		}
		void print()
		{
			s1.print();
		}
};
int main()
{
	Queue q;
	int choice=1;
	int n;
	cout<<"Press 1. Enter	2. remove 3.Print 4. Exit"<<endl;
	
	while(choice)
	{
		cout<<"Enter your choice : ";
	    cin>>choice;
		switch(choice)
		{
			case 1: {
				cout<<"Enter element : ";
				cin>>n;
				q.nqueue(n)?cout<<n<<" Entered\n":cout<<"Failed\n";
				break;
			}
			case 2:{
				cout<<q.dqueue()<<" removed\n";
				break;
			}
			case 3:{
				q.print();
				break;
			}
			case 4:{
				exit(0);
				break;
			}
		}
	}
	
}
