// Implementation of Singly Linked List

#include<iostream>
using namespace std;
struct Node{         	// Node Structure ----------------
	int data;
	Node *next;
};
class LinkedList{
	Node *head;
	LinkedList(){
		head = NULL;
	}
bool isEmpty(){         //return true if Linked List not Created / Empty . ----------
	return (head==NULL);
}
int size(){				// return size of Linked List
	int c=0;
	Node *temp= head;
	while(temp!=NULL)
	{
		c++;
		temp=temp->next;
	}
	return c;
}
bool insertAtBegin(int v)  // Insert new node at begining of Linked List
{
	Node *node = new Node;
	node->data = v;      // data inserted in new node.
	node->next=NULL;
	if(isEmpty())
	{
		head = node;   // if List is empty ,new node is head of LL.
	}
	else{
		node->next =head;   // now new node is head of LL.
		head = node;
	}
	if(node==NULL)
		return false;
	else
		return true;      //return true id node inserted.
}
bool insertAtEnd(int v)   // Insert new node at Ending of Linked List
{
	Node *node,*temp;
	node = new Node;
	node->data = v;
	node->next=NULL;		 // set data in new node.
	if(node==NULL)       // return false if node not inserted.
	   return false;
	else{
		node->next=NULL;  //  next of node pointing NULL
		if(isEmpty())	  // if LL is Empty , new node become head.
		{
			head=node;
		}
		else{
			temp=head;    // temp pointing first node of LL.
			while(temp->next!=NULL)   
			{
				temp=temp->next;
			}
			temp->next=node;     // node inserted.
			return true;
		}
	}
}
bool insertAtPosition(int i,int v)
{
	Node *temp=head;
	Node *node = new Node;
	node->data = v;
	int a=1;
	if(!isEmpty())
	{
		while(temp!=NULL)
		{
			if(a==i)
			{
				node->next=temp->next;
				temp->next = node;
				return true;
			}
			temp = temp->next;
			a++;
		}
	}
	return false;
}
bool insertAfterValue(int val,int data)
{
	Node *temp=head;
	Node *node = new Node;
	node->data = data;
	if(!isEmpty())
	{
		while(temp!=NULL)
		{
			if(temp->data==val)
			{
				node->next=temp->next;
				temp->next = node;
				return true;
			}
			temp = temp->next;
		}
	}
	return false;
}
int deleteBegin()       /// delete node from begining.
{
	Node *node;
	int v;
	if(isEmpty())     //  if LL is Empty retuen min value of int
	{
		return INT_MIN;
	}
	else{                       
		v=head->data;    //  v store data .to be deleted
		node = head;     //  node store the node , to be deleted
		head=head->next; //  first node removed. 
		delete node;     // removed node delete
		return v;		 // return deleted data.
	}
}
int deleteEnd()     // delete node from end.
{
	Node *rnode,*temp;    
	int rv;
	if(isEmpty())  // if LL isEmpty return min value of int.
	{
		return INT_MIN; 
	}
	else{
		if(size()==1)    // if LL contains i=only one node (head node)
		{
			rv=head->data;    // rv stores data to be removed
			delete head;      //delete head node.
			head=NULL;        
			return rv;		  // return deleted data.
		}
		else{
			temp=head;        // temp pointed first node
			while(temp->next!=NULL)   
			{
				rnode=temp;
				temp=temp->next;
			}
			rv=temp->data;   
			rnode->next=NULL;
			delete temp;
			return rv;
		}
		
	}
}
int deleteAtPosition(int p)
{
		Node *temp=head;
		Node *rnode;
		int rv;
		int i=1;
		if(isEmpty() || p>size())
		{
			return INT_MIN;			
		}
		else {
			while(i-1!=p)
			{
				temp = temp->next ;
				i++;
			}
			rnode = temp->next;
			temp->next = rnode->next;
			rv = rnode->data;

			delete(rnode);
			return rv;		
		}
}
int deleteAfterValue(int val)
{
	    Node *temp=head;
		Node *rnode;
		int rv;
		if(isEmpty())
		{
			return INT_MIN;			
		}
		else
		{
			while(temp->data!=val)
			{
				temp = temp->next ;
			}
			rnode = temp->next;
			rv = rnode->data;
			delete(rnode);
			return rv;		
		}
}
void print()
{
	Node *temp = head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" -> ";
		temp = temp->next;
	}
	cout<<"null"<<endl;
}
};


/// Main Function Starded ------------------------------------------
int main()
{
	
	int choice,data,i;
	
	cout<<"1.insterAtBegin\t2.insertAtEnd\t3.insertAtPosition\t4.insertAfterValue\n5.deleteAtBegin\t6.deleteAtEnd\t7.deleteAtPosition\t8.deleteAfterValue\n9.Size\t10.Search\t11.Print\t0.Exit\n\n";
	
	while(true)
	{
		cout<<"Enter your Choice : ";
	    cin>>choice;
		switch(choice){
		case 1:{
			cout<<"Enter element data : ";
			cin>>data;
			if(insertAtBegin(data))
				cout<<data+" inserted at Begin" <<endl;
			else
			   cout<<"Failed "<<endl;
			break;
		}
		case 2:{
			cout<<"Enter element data : ";
			cin>>data;
			if(insertAtEnd(data))
			    cout<<data+ " inserted at Last"<<endl;
			break;
		}
		case 3:{
			cout<<"Enter element data : ";
			cin>>data;
			cout<<"Enter Position : ";
			cin>>i;
			if(insertAtPosition(i,data))
			{
				cout<<data<<" inserted"<<endl;
			}
			else cout<<"Failed"<<endl;
			break;
		}
		case 4:{
			cout<<"Enter Element data : ";
			cin>>data;
			cout<<"Enter value after you want to add new ele. : ";
			cin>>i;
			if(insertAfterValue(i,data))
			{
				cout<<data<<" inserted "<<endl;
			}
			else cout<<"Failed"<<endl;	
			break;
		}
		case 5:{
			data = deleteBegin();
			cout<<data+" deleted from Begin"<<endl;
			break;
		}
		case 6:{
			data = deleteEnd();
			cout<<data+" deleted from End"<<endl;
			break;
		}
		case 7:{
			cout<<"Enter Position which you want to remove : ";
			cin>>i;
			data = deleteAtPosition(i);
			cout<<data+" deleted"<<endl;
			break;
		}
		case 8:{
			cout<<"Enter value after which you want to remove : ";
			cin>>data;
			data = deleteAfterValue(data);
			cout<<data+" deleted"<<endl;
			break;
		}
		case 9:{
			cout<<"Size = "<<size()<<endl;
			break;
		}
		case 11:{
			print();
			break;
		}
		case 0:{
			exit(0);
			break;
		}
		
	}
	}
	
	return 0;
}
