#include<iostream>
#define INVALID_DATA ' '
using namespace std;
template<class T>
class Stack{
	int topIndex;
	int cap;
	T *arr;
	public:
		Stack(int c){
			topIndex = -1;
			cap = c;
			arr = new T[cap];
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
				cout<<"Stack"<<endl;
			}
			else{
				for(int i=topIndex;i>=0;i--)
				{
					cout<<arr[i];
					if(i==topIndex) cout<<" <-top";
					cout<<endl;
				}
				cout<<endl;
			}
		}
		
};
int main()
{
	int cap,choice;
	char ch;
	cout<<"Enter capacity of Stack : ";
	cin>>cap;
	Stack<char>s(cap);
	cout<<"1 isEmpty"
	<<"\t2 isFull"
	<<"\t3 Push"
	<<"\t4 Pop"<<endl
	<<"5 Top"
	<<"\t6 Size"
	<<"\t7 Print"
	<<"\t8 Exit"<<endl;
	
	while(true)
	{
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
				if(!s.isFull())
				{
					cout<<"Enter a character : ";
					cin>>ch;
					if(!s.push(ch)) cout<<"Failed"<<endl;
					else cout<<ch <<" pushed succesful"<<endl;
				}
				else {
					cout<<"Failed"<<endl;
				}
				break;
			}
			case 4:
			{
				(s.isEmpty() ? cout<<"Failed "<<endl : cout<<s.pop()<<" is poped"<<endl);
				break;
			}
			case 5:
			{
				(s.isEmpty() ? cout<<" Failed "<<endl : cout<<s.top()<<" is top of stack"<<endl);
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
	}
	return 0;
}
