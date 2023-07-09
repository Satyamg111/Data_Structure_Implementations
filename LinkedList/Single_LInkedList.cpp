#include<iostream>
using namespace std;
int size=0;
class Node{
	int data;
	Node *next;
	public:
		Node(){}
		Node(int data)
		{
			this->data= data;
			this->next=NULL;
		}
		bool isEmpty()
		{
			return (size==0);
		}
		void insertAtBegin(Node* &head,int data)
		{
			Node *temp = new Node(data);
			temp->next=head;
			temp=head;
		}
		void addLast(Node* &head,int data)
		{
			Node* temp=new Node(data);
			Node* first = head;
			Node* sec = head->next;
			while(sec!=NULL)
			{
				if(sec->next==NULL)
				{
					sec->next=temp;
					return ;
				}
				first=first->next;
				sec=sec->next;
				
			}
		}
		void print(Node* &head)
		{
			Node *temp=head;
			
			while(temp!=NULL)
			{
				cout<<temp->data<<endl;
				temp=temp->next;
			}
		}
};
int main()
{
	int choice,data;
	Node *node1= new Node(10);
	
	Node *head = node1;
	
	cout<<"1.insterAtBegin\t2.insertAtEnd\t3.insertAtPosition\t4.insertAfterValue\n5.deleteAtBegin\t6.deleteAtEnd\t7.deleteAtPosition\t8.deleteAfterValue\n9.Size\t10.Search\t11.Print\t12.Exit\n\n";
	
	while(true)
	{
		cout<<"Enter your Choice : ";
	    cin>>choice;
		switch(choice){
		case 1:{
			cout<<"Enter element data : ";
			cin>>data;
			head->insertAtBegin(head,data);
			break;
		}
		case 2:{
			cout<<"Enter element data : ";
			cin>>data;
			head->insertAtLast(tail,data);
			break;
		}
		case 1:{
			cout<<"Enter element data : ";
			cin>>data;
			head->insertAtBegin(head,data);
			break;
		}
		case 1:{
			cout<<"Enter element data : ";
			cin>>data;
			head->insertAtBegin(head,data);
			break;
		}
		case 2:{
				cout<<"Enter element data : ";
				cin>>data;
				head->addLast(head,data);
			break;
		}
		case 3:{
			
			break;
		}
		case 4:{
			
			break;
		}
		case 5:{
			
			break;
		}
		case 6:{
			head->print(head);
			
			break;
		}
		case 7:{
			exit(0);
			break;
		}
		
	}
	}
	
	return 0;
}
