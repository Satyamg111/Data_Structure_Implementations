#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *left;
	Node *right;

	Node(int val){
		data = val;
		left = NULL;
		right = NULL;
	}
};
class BST{
	Node *root;
	public:

	BST(){
		root=NULL;
	}
	Node* getRoot(){
		return root;
	}
	Node *search(int val){
		Node *temp = root;
		
		while(temp!=NULL){
			if(temp->data == val){
				return temp;
			}
			if(val<temp->data){
				temp = temp->left;
			}
			else{
				temp=temp->right;
			}
		}
		return NULL;
	}
	bool insert(int val){
		Node *node = new Node(val);
		if(node == NULL)
			return false;
		else{
				if(root==NULL){
					root = node;
					return true;	
				}
				else{
					Node *temp = root,*p=NULL;

					while(temp!=NULL){
					p = temp;
					if(val < temp->data){
						temp = temp->left;
					}
					else{
						temp = temp->right;
					}
				}
				if(val<p->data){
					p->left = node;
				}
				else{
					p->right = node;
				}
			}
			return true;
		}
	}
	Node* recuInsert(Node *root,int key){
	
		Node *temp = NULL;
		
		if(root==NULL){
			temp = new Node(key);
//			temp->data = key;
//			temp->left =NULL;
//			temp->right = NULL;
			return temp;   
		}
		
		if(key < root->data){
			root->left = recuInsert(root->left,key);
		}  
		else if(key > root->data) {
			root->right = recuInsert(root->right,key);
		}
		return root;
		 
	} 
	int remove(int val){
			Node *node = search(val);

			if(node == NULL){
				return INT_MIN;
			}
			Node *temp = root,*par;
			while(val != temp->data){
				if(val<temp->data){
					par = temp;
					temp=temp->left;
				}
				else{
					temp = temp->right;
				}
			}
			
				if(node->left==NULL && node->right==NULL){
					delete node;
				}
				else if(node->left==NULL && node->right!=NULL){
					if(par->left && par->left->data==val){
						par = par->left->left;
					}
				}
				else if(node->left!=NULL && node->right==NULL){
				}
			return val;
			
			
	}
	void remove(Node *root,int key){
		if(root==NULL){
			return NULL;
		}
		if(root->left==NULL && root->right==NULL){
			if(root==this->root){
				this.root=NULL;
			}
			delete root;
		}
		if(key<root->data){
			root->left = remove(root->left,key);
		}
		else if (key>root->data){
			root->right= remove(root->right,key);
		}
		else{
			if(height(root->left)>height(root->right)){
				Node *t =  inPre(root->left);
				root->data = t->data;
				root->left = remove(root->left,t->data);
			}
			else{
				Node *t =  inSucc(root->right);
				root->data = t->data;
				root->right = remove(root->right,t->data);
			}
		}
		return root;
		 
	}	
	void print(Node *root){
		if(root==NULL)  
			return;

		print(root->left);
		cout<<root->data<<" ";
		print(root->right);
	}

};
int main(){
int val;
BST root;
//Node *r = root.createTree();

int c;
while(true){
cout<<"Enter choice : ";
cin>>c;
switch(c){

case 1:{
cout<<"Enter element : ";
cin>>val;
if(root.insert(val)){
cout<<val<<" inserted"<<endl;
}
break;
}
case 2:{
Node *r = root.getRoot();
root.print(r);
cout<<endl;
break;
}
case 0:{
exit(0);
break;
}
}
}
}


