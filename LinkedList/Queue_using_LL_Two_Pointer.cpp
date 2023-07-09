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
		bool enqueue(int v)
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
		int dequeue()
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
	q.enqueue(10);
	q.print();
	q.enqueue(20);
	q.print();
	q.enqueue(30);
	q.print();
	q.enqueue(40);
	q.print();
	q.dequeue();
	q.print();
	q.enqueue(20);
	q.print();
	q.enqueue(30);
	q.print();
	q.enqueue(40);
	q.print();
	cout<<q.size()<<endl;
	return 0;
}
