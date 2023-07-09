////  Stack Implementation using Linked List

#include<iostream>
using namespace std;

class Stack{
	struct Node{
	int data;
	Node *next;
	};
	Node *head = NULL;
	int c;
		public :
			Stack()
			{
				c=0;
			}
		bool isEmpty()
		{
			return (head == NULL);
		}
		bool push(int v)
		{
			Node *newNode = new Node;
			newNode->data = v;
			newNode->next = NULL;
			if(isEmpty())
			{
				head = newNode;
			}
			else{
				newNode->next = head;
			    head = newNode;
			}
			if(newNode==NULL)
			{
				return false;
			}
			c++;
			return true;
		}
		int pop()
		{
			Node *rnode;
			int rv;
			
			if(isEmpty())
			{
				return INT_MIN;
			}
			rv = head->data;
			rnode=head;
			head = head->next;
			delete rnode;
			c--;
			return rv;;
		}
		int top()
		{
			if(!isEmpty())
		 	  return (head->data);
		}
		int size()
		{
			return c;
		}
		void print()
		{
			Node *temp=head;
			
			
			while(temp!=NULL)
			{
				cout<<temp->data;
				if(temp==head)
				{
					cout<<" <- Top";
				}
				cout<<endl;
				temp=temp->next;
			}
			cout<<endl;
		}
};
int main()
{
	Stack s;
	int choice, par;
	cout<<"1.isEmpty\t2.Push\t3.Pop\n4.Top\t5.Size\t6.Print\t7.Exit"<<endl;
	
	while(true)
	{
		cout<<"Enter Your choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1:{
				if(s.isEmpty()) cout<<"Stack is Empty "<<endl;
				else cout<<"Stack is not Empty"<<endl;
				break;
			}
			case 2:{
				
					cout<<"Enter new element : ";
					cin>>par;
					if(s.push(par))
					{
						cout<<par<<" pushed "<<endl;
					}
					else cout<<"Failed"<<endl;
				break;
			}
			case 3:{
				if(!s.isEmpty()){
					par = s.pop();
					cout<<par<<" popped"<<endl;
				}
				else cout<<"Failed"<<endl;
				break;
			}
			case 4:{
				if(!s.isEmpty()){
					par = s.top();
					cout<<par<<" is top of stack"<<endl;
				}
				else cout<<"Stack is Empty"<<endl;
				break;
			}
			case 5:{
				cout<<"Size of Stack : "<<s.size()<<endl;
				break;
			}
			case 6:{
				if(!s.isEmpty())
					s.print();
				else cout<<"Stack is Empty"<<endl;
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
