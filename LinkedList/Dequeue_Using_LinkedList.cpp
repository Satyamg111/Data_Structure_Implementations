#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *next;
};
class Queue{
	Node *front,*rear;
	int c;
	public:
		Queue(){
			front= rear=NULL;
			c=0;
		}
		bool isEmpty()
		{
			return (c==0);
		}
		
		int size()
		{
			return c;
		}
		bool enqueueRear(int v)
		{
				Node *nn = new Node;
				nn->data= v;
				nn->next = NULL;
			if(isEmpty())
			{
				front = rear = nn;	
			}
			else{
				rear->next = nn;
				rear = nn;
			}
			c++;
			return true;
		}
		bool enqueueFront(int v)
		{
				Node *nn = new Node;
				nn->data= v;
				nn->next = NULL;
			if(isEmpty())
			{
				front = rear = nn;	
			}
			else{
				nn->next= front;
				front = nn;
			}
			c++;
			return true;
		}
		int dequeueRear()
		{
			if(!isEmpty())
			{
				int rv = rear->data;
				Node *rn = rear;
				if(size() ==1)
				{
					front = rear = NULL;
				}
				else{
					Node *temp =front;
					while(temp->next->next!=NULL)
					{
						temp= temp->next;
					}
					temp->next =NULL;
					delete rn;
				}
				c--;
				return rv;
			}
		}
		int dequeueFront()
		{
			if(!isEmpty())
			{
				int rv = front->data;
				if(size() ==1)
				{
					front = rear = NULL;
				}
				else{
					
					front = front->next;
				}
				c--;
				return rv;
			}
		}
		void print()
		{
			Node *temp= front;
			while(temp!=NULL)
			{
				cout<<temp->data<<" -> ";
				temp = temp->next;
				if(temp==NULL) cout<<" NULL"<<endl;
			}
		}
};
int main()
{
	Queue q;
	q.enqueueRear(10);
	q.print();
	q.enqueueRear(20);
	q.print();
	q.enqueueFront(30);
	q.print();
	q.enqueueFront(40);
	
	q.print();
	
	q.dequeueRear();
	q.dequeueFront();
	q.print();
	
	cout<<q.size()<<endl;
	return 0;
}
