#include<iostream>
using namespace std;
template<class T>
class Stack{
	int topIndex;
	int cap;
	T *arr;
	public:
		Stack(int c,int i){
			topIndex = i;
			cap = c;
			arr = new int[cap];
		}
		bool isEmpty(){
			return (topIndex<0);
		}
		bool isFull(){
			return (topIndex==cap-1);
		}
		void push(T ch)
		{
			if(isFull()){
				cout<<"Stack is already full"<<endl;
			}
			else{
				arr[++topIndex]=ch;
				cout<<ch<<" is pushed succesfuly"<<endl;
			}
		}
		void pop()
		{
			if(isEmpty()){
				cout<<"Stack is already Empty"<<endl;
			}
			else{
				
				cout<<arr[topIndex--]<<" is poped succesfuly"<<endl;
			}
		}
		T top()
		{
			if(isEmpty()){
				cout<<"Stack is Empty" <<endl;
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
				cout<<"Stack is Empty"<<endl;
			}
			else{
				for(int i=0;i<=topIndex;i++)
				{
					cout<<endl<<arr[i];
					if(i==topIndex) cout<<" <-top"<<endl;
				}
			}
		}
		
};
int main()
{
	int c;
	cout<<"Enter capacity of Stack : ";
	cin>>c;
	Stack<char>s(c,-1);
	cout<<"\tPress 1 check empty"<<endl
	<<"\tPress 2 check full"<<endl
	<<"\tPress 3 For push"<<endl
	<<"\tPress 4 For pop"<<endl
	<<"\tPress 5 For top"<<endl
	<<"\tPress 6 For size"<<endl
	<<"\tPress 7 For print"<<endl
	<<"\tPress 8 For Exit"<<endl;
	l:
	int choice;
	cout<<"Enter your Choice : ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			{
				s.isEmpty()?cout<<"Stack is empty"<<endl : cout<<"Stack is not empty"<<endl;
				break;
			}
		case 2:
			{
				s.isFull()?cout<<"Stack is full"<<endl : cout<<"Stack is not full"<<endl;
				break;
			}
		case 3:
			{
				char ch;
				cout<<"Enter a character : ";
				cin>>ch;
				s.push(ch);
				break;
			}
		case 4:
			{
				s.pop();
				break;
			}
		case 5:
			{
				cout<<"Top of Stack : "<<s.top()<<endl;
				break;
			}
		case 6:
			{
				cout<<"Size of Stack : "<<s.size()<<endl;
				break;
			}
		case 7:
			{
				cout<<"Stack Elements : "<<endl;
				s.print(); 
				break;
			}
		case 8:
			{
				exit(0);
			}
		default :
			{
				cout<<"Enter correct choice "<<endl;
				break;
			}
	}
	goto l;
}
