#include<iostream>
using namespace std;
struct Node{
		int data;
		Node *next;
	};
class LinkedList{
	Node *head;
	int c;
	public :
	LinkedList(){
		head = NULL;
		c=0;
	}
	
	bool isEmpty(){
		return c==0;
	}
	bool insert(int val){
		
		Node *newNode = new Node;
		newNode->data = val;
		newNode->next = NULL;
		
		if(isEmpty()){
			head= newNode;
		}
		else{
			Node *t ,*temp = head;
			
			if(c==1){
				if(head->data >val){
					newNode->next = head;
					head = newNode;
				
				}
				else{
					head->next = newNode;
				}
				c++;
				return true;
			}
			else{
				if(head->data> val){
			newNode->next = head;
			head = newNode;
			c++;
			return true;
		}
				while(temp->data< val && temp!=NULL){
					t = temp;
					temp = temp->next;
				}
				t->next=newNode;
				c++;
				return true;
			}
			
			
		}
		c++;
		return true;
	}
	bool remove(int val){
		int rv;
		if(isEmpty()){
			return false;
		}
		else{
			if(c==1){
				head = NULL;
			}
			else{
				Node* temp=head;
				while(temp->next->data !=val && temp !=NULL){
					temp = temp->next;
				}
				temp->next = temp->next->next;
			}
			c--;
			return true;
		}
	}
	bool search(int val){
		if(isEmpty()){
			return false;
		}
		else{
				Node* temp=head;
				while(temp !=NULL){
					if(temp->data == val)
					    return true;
					temp = temp->next;
				}
		}
		return false;
	}
	void print(){
		Node *temp = head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}	
};
class Hash{
	LinkedList* table[10];
	public:
	Hash(){
		for(int i=0;i<10;i++){
			table[i] = NULL;
		}
	}
		int hashFunction(int val){
			return val%10;
		}
		bool insertHash(int val){
			int index = hashFunction(val);
			if(table[index] == NULL){
				LinkedList *list = new LinkedList;
				table[index] = list;
			}
			table[index]->insert(val);
			return true;
		}
		
		bool removeHash(int val){
			int index = hashFunction(val);
			if(table[index] == NULL){
				return false;
			}
			table[index]->remove(val);
			if(table[index]->isEmpty()){
				table[index]=NULL;
			}
			return true;
		}
	
		bool searchHash(int val){
			int index = hashFunction(val);
			if(table[index] == NULL){
				return false;
			}
			if(table[index]->search(val)){
				return true;
			}
			return false;
		}
		void print (){
			for(int i=0;i<10;i++){
				if(table[i]!=NULL){
					table[i]->print();
				}
			}
		}
	
};
int main(){
	Hash obj;
	obj.insertHash(10);
	obj.insertHash(15);
	obj.insertHash(6);
	obj.insertHash(25);
	obj.insertHash(9);
	obj.print();
	cout<<endl;
	obj.removeHash(25);
	obj.print();
	cout<<endl;
	obj.removeHash(6);
	obj.print();
	cout<<endl;
	
	cout<<obj.searchHash(15)<<endl<<obj.searchHash(6)<<endl;	
	return 0;
}
