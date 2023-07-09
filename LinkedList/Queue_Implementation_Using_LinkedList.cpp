//////  Queue Implementtation using Linked List

#include<iostream>
using namespace std;
class Queue{
	struct Node{
		int data;
		Node *next;
	};
	int c;
	Node *head = NULL;
	public:
		Queue()
		{
			c=0;
		}
		bool isEmpty()
		{
			return (head == NULL);
		}
		bool enqueue(int v)
		{
			Node *newNode = new Node;
			newNode->data = v;
			newNode->next = NULL;
			if(isEmpty())
			{
				head = newNode;
			}
			else
			{
				Node *temp = head;
				while (temp->next !=NULL)
				{
					temp = temp->next;
				}
				temp->next = newNode;
			}
			if(newNode == NULL)
					return false;
			c++;
			return true;
		}
		int dequeue()
		{
			if(isEmpty())
			{
				return INT_MIN;
			}
			Node *rnode;
			int v = head->data;
			rnode = head;
			head = head->next;
			delete rnode;
			c--;
			return v;
		}
		int size()
		{
			return c;
		}
		void print()
		{
			Node *temp = head;
				while (temp!=NULL)
				{
					cout<<temp->data<<" ";
					temp = temp->next;
				}
				cout<<endl;
		}
};
int main()
{
	Queue q;
	char par;
	int choice;
	cout<<"1.isEmpty 2.enqueue 3.dequeue \n4.size 5.print 6.exit\n";
		
	while (true)
	{
		cout<<"Enter your choice : ";
		cin>>choice;
		
		switch(choice)
		{
			
			case 1: {
				if(q.isEmpty()) cout<<"Queue is Empty"<<endl;
				else cout<<"Queue is not Empty"<<endl;
				break;
			}
			case 2: {
				if(!q.isFull()) {
					cout<<"Enter value : ";
					cin>>par;
					if(q.enqueue(par)) cout<<"Succsess"<<endl;
				}
				else cout<<"Queue is Full"<<endl;
				break;
			}
			case 3: {
				if(!q.isEmpty()){
					par = q.dequeue();
					cout<<par<<" is removed"<<endl;
				}
				else cout<<"Queue is Empty"<<endl;
				break;
			}
			case 4: {
				cout<<"Size of queue : "<<q.size();
				break;
			}
			case 5: {
				if(!q.isEmpty()){
					q.print();
				}
				else cout<<"Queue is Empty"<<endl;
				break;
			}
			case 6:{
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
