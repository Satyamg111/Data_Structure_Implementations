#include<iostream>
#include<queue>
using namespace std;
struct Node{
		int data;
		Node *left,*right;
	};
class Tree{
	public:
	Node *root;
	
	Tree(){
		root = NULL;
	}
	Node* creatNode(int val,queue<Node*>&q){
		Node *node = new Node;
		node->data = val;
		node->left =NULL;
		node->right =NULL;
		if(root==NULL){
			root=node;
			q.push(node);
			
		}
		else{
			q.push(node);
		}
		return node;
	}
	void print(){
		
		queue<Node*>q;
		q.push(root);
		Node *temp;
		while(!q.empty()){
			temp = q.front();
			q.pop();
			cout<<temp->data<<" ";
			if(temp->left!=NULL){
				q.push(temp->left);
			}
			if(temp->right!=NULL){
				q.push(temp->right);
			}
		}
		cout<<endl;
		
	}
	void PreOrder(Node *root){
		if(root==NULL){
			return ;
		}
		cout<<root->data<<" ";
		PreOrder(root->left);
		PreOrder(root->right);
	}
	void InOrder(Node *root){
		if(root==NULL){
			return ;
		}
		InOrder(root->left);
		cout<<root->data<<" ";
		InOrder(root->right);
	}
	void PostOrder(Node *root){
		if(root==NULL){
			return ;
		}
		PostOrder(root->left);
		PostOrder(root->right);
		cout<<root->data<<" ";
	}
	
};
int main(){
	Tree t;
	Node *temp ,*newNode;
	queue<Node*>q;
	int x;
	
	cout<<"Create root node "<<endl;
	cout<<"Enter value : ";
	cin>>x;
	t.creatNode(x,q);
	while(!q.empty()){
		temp = q.front();
		q.pop();
		cout<<"Enter Left child Value of "<<temp->data<<" : ";
		cin>>x;
		if(x!=-1){
			newNode = t.creatNode(x,q);
			temp->left = newNode;
		}
		cout<<"Enter right child Value of "<<temp->data<<" : ";
		cin>>x;
		if(x!=-1){
			newNode = t.creatNode(x,q);
			temp->right = newNode;
		}
	}
	cout<<"Leve Order : ";
	t.print();
	cout<<endl;
	cout<<"Preorder : ";
	t.PreOrder(t.root);
	cout<<endl;
	cout<<"Inorder : ";
	t.InOrder(t.root);
	cout<<endl;
	cout<<"Postorder : ";
	t.PostOrder(t.root);
	cout<<endl;
	
	return 0;
}
