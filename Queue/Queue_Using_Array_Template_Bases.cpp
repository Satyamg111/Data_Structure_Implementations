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
int main()
{
	Queue<char>q;
	char par;
	int choice;
	cout<<"1.isFull   2.isEmpty   3.enqueue   4.dequeue 5.size   6.print   7.exit\n\n";
		
	while (true)
	{
		cout<<"Enter your choice : ";
		cin>>choice;
		
		switch(choice)
		{
			case 1: {
				if(q.isFull()) cout<<"Queue is Full"<<endl;
				else cout<<"Queue is not Full"<<endl;
				break;
			}
			case 2: {
				if(q.isEmpty()) cout<<"Queue is Empty"<<endl;
				else cout<<"Queue is not Empty"<<endl;
				break;
			}
			case 3: {
				if(!q.isFull()) {
					cout<<"Enter value : ";
					cin>>par;
					if(q.enqueue(par)) cout<<"Succsess"<<endl;
				}
				else cout<<"Queue is Full"<<endl;
				break;
			}
			case 4: {
				if(!q.isEmpty()){
					par = q.dequeue();
					cout<<par<<" is removed"<<endl;
				}
				else cout<<"Queue is Empty"<<endl;
				break;
			}
			case 5: {
				cout<<"Size of queue : "<<q.size();
				break;
			}
			case 6: {
				if(!q.isEmpty()){
					q.print();
				}
				else cout<<"Queue is Empty"<<endl;
				break;
			}
			case 7:{
				exit(0);
			}
			default:{
				cout<<"Enter correct choice"<<endl;
				break;
			}
		}
	}
	
	return 0;
}
