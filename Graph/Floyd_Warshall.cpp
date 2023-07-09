//#include<iostream>
//#include<queue>
//#include<vector>
#include <bits/stdc++.h>
using namespace std;
#include<iostream>
using namespace std;
class DisjointSet{
	int *rank,*parant,*size;
	int n;
	public:
		DisjointSet(int n){
			this->n = n;
			rank = new int[n];
			parant = new int[n];
			size = new int[n];
			
			for(int i=0;i<n;i++){
				parant[i] = i;
				size[i] = 1;
			}
			
			
		}
		int find(int x){
			if(x==parant[x]){
				return x;
			}
			return parant[x] = find(parant[x]);
		}
		void unionByRank(int x,int y){
			int xset = find(x);
			int yset = find(y);
			
			if(xset == yset ) return;
			
			if(rank[xset] < rank[yset]){
				parant[xset] = yset;
 			}
 			else if(rank[xset] > rank[yset]){
 				parant[yset] = xset;
			 }
			 else{
			 	parant[xset] = yset;
			 	rank[xset] = rank[xset] + 1;
			 }
		}
		void unionBySize(int x,int y){
			int xset = find(x);
			int yset = find(y);
			
			if(xset == yset ) return;
			
			if(size[xset] < size[yset]){
				parant[xset] = yset;
				size[yset] += size[xset];
			}
			else{
				parant[yset] = xset;
				size[xset] += size[yset];
			}
			
		}
};
struct Node {
	int vertex;
	int weigth;
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
	void addVertex(int v,int w){
		Node *node = new Node;
		node->vertex = v;
		node->weigth=w;
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
	int **spath;
	int V;
	public:
	Graph(int n){
		V=n;
		Edge = new List[V];
		spath = new int[V][V];
		
//		for(int i=0;i<V;i++){
//			Edge[i] = NULL;
//		}
	}
	void createGraph(){
		
		for(int i=0;i<V;i++){
			
			int edge,w;
			while(true){
				cout<<"Add edge from vertex "<<i<<" -1 if not any : ";
				cin>>edge;
				if(edge != -1){
					cout<<"Enter edge weight : ";
					cin>>w;
					if(edge<V){
						Edge[i].addVertex(edge,w);
						Edge[edge].addVertex(i,w);
					}
					else cout<<edge << " not in graph "<<endl;
				}
				else{
					break;
				}	
			}	
		}
	}
	
		void floydMarshal(){
			//vector<vector<int> >matrix (V,vector<int>(V,0));
			int matrix[V][V] = {INT_MAX};
			
			// create matrix from adj list
			for(int i=0;i<V;i++){
				Node *temp = Edge[i].head;
				matrix[i][i]=0;
				while(temp!=NULL){
					int j = temp->vertex;
					matrix[i][j] = temp->weigth;
					temp = temp->link;
				}
			}
			for(int k=0;k<n;k++){
				for(int i=0;i<n;i++){
					for(int j=0;j<n;j++){
					matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
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
	cout<<"1. DFS\t2.BFS\t3. print graph\t4.find shortest path(s to d)"<<endl;
	
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
			case 0:{
				exit(0);
				break;
			}
			
		}
	}

	return 0;
}


void floydWarshall(){
	int matrix;
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
			}
		}
	}
}
