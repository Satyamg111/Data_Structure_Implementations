#include<iostream>
#include<queue>
using namespace std;
struct Node {
	int vertex;
	Node *link;
};
class List{
	public:
	Node *head;
	Node *tail;
	
	List(){
		head =NULL;
		tail =NULL;
	}
	void addVertex(int v){
		Node *node = new Node;
		node->vertex = v;
		node->link = NULL;
		if(head==NULL){
			head = node;
			tail = node;
		}
		else{
			tail->link = node;
			tail = node;
		}
	}
	void print(){
		Node *temp = head;
		while(temp!= NULL){
			cout<<temp->vertex<<" -> ";
			temp = temp->link;
		}
	}
};
class Graph{
	List *Edge;
	int V;
	public:
	Graph(int n){
		V=n;
		Edge = new List[V];
		
//		for(int i=0;i<V;i++){
//			Edge[i] = NULL;
//		}
	}
	void createGraph(){
		
		for(int i=0;i<V;i++){
			
			int edge;
			while(true){
				cout<<"Add edge from vertex "<<i<<" -1 if not any : ";
				cin>>edge;
				if(edge != -1){
					if(edge<V){
						Edge[i].addVertex(edge);
						Edge[edge].addVertex(i);
					}
					else cout<<edge << " not in graph "<<endl;
				}
				else{
					break;
				}	
			}	
		}	
	}
	void print(){
		for(int i=0;i<V;i++){
			
			cout<<i<<" -> ";

				Edge[i].print();
		
			cout<<endl;
		}
	}
	void bfs(int v,int visited[]){
		visited[v] = 1;
		queue<int>q;
		q.push(v);
		cout<<v<<" ";
		
		while(!q.empty()){
			v = q.front();
			q.pop();
			
			Node *temp = Edge[v].head;
			
			while(temp!=NULL){
				if(!visited[temp->vertex]){
					cout<<temp->vertex<<" ";
					q.push(temp->vertex);
					visited[temp->vertex] = 1;	
				}
				temp = temp->link;
			}
			
		}
	}
	void dfs(int v,int visited[]){
		visited[v] = 1;
		
		Node *temp = Edge[v].head;
		while(temp!=NULL){
				if(!visited[temp->vertex]){
//					parant[i] = v;
//					bfs[i] = temp->vertex;
//					i++;
					cout<<temp->vertex<<" ";
					dfs(temp->vertex,visited);
					
				}
				temp = temp->link;
			}
	}
};

int main(){
	int V,c,v;
	cout<<"Enter total number of vertices : ";
	cin>>V;
	Graph g(V);
	
	cout<<"Create graph"<<endl;
	int visited[V] = {0};
	
	g.createGraph();
	cout<<"1. DFS\t2.BFS\t3. print graph"<<endl;
	
	while(true){
		cout<<"Enter your choice : ";
		cin>>c;
		switch(c){
			case 1:{
				int visited[V] = {0};
//				cout<<"Enter a node : ";
//				cin>>v;
				for(int i=0;i<V;i++){
					if(visited[i]!=1)
						g.dfs(i,visited);
				}
				break;
			}
			case 2:{
				int visited[V] = {0};
//				cout<<"Enter a node : ";
//				cin>>v;
				for(int i=0;i<V;i++){
					if(visited[i]!=1)
						g.bfs(i,visited);
				}
				
				break;
			}
			case 3:{
				g.print();
				break;
			}
		}
	}

	return 0;
}
