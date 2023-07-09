#include<iostream>
using namespace std;
class Stack{
	int topIndex;
	int cap;
	char arr[100];
	public:
		Stack(int c,int i){
			topIndex = i;
			cap = c;
			arr[cap];
		}
		bool isEmpty(){
			return (topIndex<0);
		}
		bool isFull(){
			return (topIndex==cap-1);
		}
		void push(char ch)
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
		char top()
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
	Stack s(c,-1);
	cout<<"Press 1 check empty.\t\t"
	<<"Press 2 check full.\t\t"
	<<"Press 3 For push.\t\t"
	<<"Press 4 For pop.\t\t"
	<<"Press 5 For top.\t\t"
	<<"Press 6 For size\t\t"
	<<"Press 7 For print.\t\t"
	<<"Press 8 For Exit"<<endl;
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
