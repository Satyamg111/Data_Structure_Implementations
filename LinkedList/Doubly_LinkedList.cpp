#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *prev ,*next;
};
Node *head = NULL;
Node *tail = NULL;
int c=0;
bool isEmpty()
{
	return c==0;
}
int size()
{
	return c;
}
bool insertBegin(int v)
{
	Node *node = new Node;
	node->data = v;
	node->prev = NULL;
	node->next = NULL;
	if(node==NULL)
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
			head->prev = node;
			node->next = head;
			head = node;
		}
		c++;
		return true;
	}
}
bool insertEnd(int v)
{
	Node *node = new Node;
	node->data = v;
	node->prev = NULL;
	node->next = NULL;
	if(node==NULL)
	{
		return false;
	}
	else{
		if(isEmpty())
		{
			head = node;
		}
		else{
			tail->next = node;
			node->prev = tail;
			tail = node;
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
			head->prev = NULL;
		}
		delete rnode;
		return rv;
	}
	return INT_MIN;
}
int deleteEnd()
{
	Node *rnode;
	int rv;
	if(!isEmpty())
	{
		rnode = tail;
		rv = tail->data;
		if(size()==1)
		{
			head = NULL;
			tail = NULL;
		}
		else{
			tail = tail->prev;
			tail->next = NULL;
		}
		delete rnode;
		return rv;
	}
	return INT_MIN;
}
void print()
{
	Node *temp = head;
	while(temp!=NULL)
	{
		if(temp==head)
		{
			cout<<"NULL -><- ";
		}
		cout<<temp->data<<" -><- ";
		temp=temp->next;
		if(temp==NULL)
		{
			cout<<"NULL";
		}
	}
	cout<<endl;
}
int main()
{
	insertBegin(10);
	print();
	insertBegin(20);
	print();
	insertBegin(30);
	print();
	insertEnd(40);
	print();
	insertEnd(50);
	print();
	insertEnd(60);
	print();
	deleteEnd();
	print();
	deleteBegin();
	print();
	return 0;
}
