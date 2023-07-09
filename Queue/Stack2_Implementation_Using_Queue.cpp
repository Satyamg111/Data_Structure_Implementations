#include<iostream>
#define CAPACITY 5
using namespace std;
template<class T>
class Queue{
	int frontIndex;
	int rearIndex;
	int count;
	T arr[CAPACITY];
	int cap;
	public:
	Queue()
	{
		frontIndex = -1;
		rearIndex = -1;
		count = 0;
		cap= CAPACITY;
	}
	int size()
	{
		return count;
	}
	bool isEmpty()
	{
		return(count == 0);
	}
	bool isFull()
	{
		return(count==cap);
	}
	bool enqueue(T ch)
	{
		if(isFull()) return false;
		else{
			if(isEmpty())
			{
				frontIndex++;
			}
			rearIndex = (rearIndex+1)%cap;
			arr[rearIndex]=ch;
			count++;
			return true;
		}
	}
	T dequeue()
	{
		T ch = arr[frontIndex];
		if(count==1)
		{
			frontIndex = -1;
			rearIndex = -1;
		}
		else{
			frontIndex = (frontIndex+1)%cap;
		}
		count--;
		return ch;
	}
	void print()
	{
		if(!isEmpty())
		{
			int j= frontIndex;
			for(int i=0;i<count;i++)
			{
				cout<<arr[j]<<" ";
				j=(j+1)%cap;
			}
			cout<<endl;
		}
	}	
};
///////////////////////////////////
template<class T>
class Stack{
	Queue<int>q1;
	Queue<int>q2;
	
	public:
		bool isEmpty()
		{
			return(q1.isEmpty());
		}
		bool isFull()
		{
			return(q1.isFull());
		}
		int size()
		{
			return (q1.size());
		}
		bool push(T ch)
		{
			return (q1.enqueue(ch));
			
		}
		T pop()
		{
			T ch ;
			while(q1.size()>1)
			{
				q2.enqueue(q1.dequeue());
			}
			ch = q1.dequeue();
			while(!q2.isEmpty())
			{
				q1.enqueue(q2.dequeue());
			}
			return ch;
		}
		void print()
		{
			q1.print();
		}		
};
int main()
{
	Stack<int>s;
	int c;
	int par;
	cout<<"1.Push   2.Pop   3.Print   4.Size   5.exit\n\n";
	while (true)
	{
		cout<<"Enter your choice : ";
		cin>>c;
		
		switch(c)
		{
			case 1: {
				
				if(!s.isFull())
				{
					cout<<"Enter element : ";
				 	cin>>par;
				 	s.push(par);
				 	cout<<par<<" Entered\n";
				}
				else{
				cout<<"Failed\n";
				}
				
				break;
			}
			case 2:{
				if(!s.isEmpty())
					cout<<s.pop()<<" removed\n";
				else cout<<"Failed"<<endl;
				break;
			}
			case 3:{
				s.print();
				break;
			}
			case 4:{
				cout<<"Size : "<<s.size()<<endl;
				break;
			}
			case 5:{
				exit(0);
				break;
			}
		}	
	}	
}

