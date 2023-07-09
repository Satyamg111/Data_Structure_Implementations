#include<iostream>
using namespace std;
struct Node {
	int data ;
	Node *next;
};
Node *head = NULL;
Node *tail = NULL;
int c=0;
bool isEmpty()
{
	return (c==0);
}
int size()
{
	return c;
}
bool insertBegin(int v)
{
	Node *node = new Node;
	node->data= v;
	node->next=NULL;
	if(node == NULL)
	{
		return false;
	}
	else{
		if(isEmpty())
		{
			head = node;
			tail = node;	
		}
		else{
			node->next=head;
			head=node;
			tail->next = head;
		}
		c++;
		return true;
	}
}
bool insertEnd(int v)
{
	Node *node = new Node;
	node->data = v;
	node->next = NULL;
	if(node == NULL)
	{
		return false;	
	}	
	else{
		if(isEmpty())
		{
			head = node;
			tail = node;
		}
		else{
			tail->next = node;
			tail = node;
			tail->next = head;
		}
		c++;
		return true;
	}
}
int deleteBegin()
{
	Node *rnode;
	int rv;
	if(!isEmpty())
	{
		rnode = head;
		rv = head->data;
		if(size()==1)
		{
			head = NULL;
			tail = NULL;
		}
		else{
			head = head->next;
		}
		c--;
		delete rnode;
		return rv;
	}
	return INT_MIN;
}
int deleteEnd()
{
	Node *rnode,*temp;
	int rv;
	if(!isEmpty())
	{
		rnode = head;
		rv = head->data;
		if(size()==1)
		{
			head = NULL;
			tail = NULL;
		}
		else
		{
			temp = head;
			while(temp->next!=tail)
			{
				temp = temp->next;
			}
			rnode = temp->next;
			tail = temp;
			tail->next = head;
			c--;
			delete rnode;
			return rv;
		}
	}
	return INT_MIN;
}
void print()
{
	Node *temp=head;
	while(temp!=tail)
	{
		cout<<temp->data<<" -> ";
		temp = temp->next;
	}
	cout<<temp->data;
	cout<<endl;
}
int main()
{
//	insertBegin(10);
//	print();
	insertEnd(5);
	print();
	//cout<<tail->next->data<<endl;
	insertBegin(15);
	print();
	cout<<tail->next->data<<endl;
	insertBegin(10);
	print();
	cout<<tail->next->data<<endl;
	insertEnd(20);
	print();
	cout<<tail->next->data<<endl;
//	deleteBegin();
//	print();
//	deleteEnd();
//	print();
	
	
	return 0;
}
