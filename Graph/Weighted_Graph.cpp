//#include<iostream>
//#include<queue>
//#include<vector>
#include <bits/stdc++.h>
using namespace std;
#include<iostream>
using namespace std;
class DisjointSet{
	int *rank,*parant,*size,**spath;
	int n;
	public:
		DisjointSet(int n){
			this->n = n;
			rank = new int[n];
			parant = new int[n];
			spath = new int[V][V];
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
	int kruskalMST(){
			vector<vector<int> >edges;
			int ans=0;
			
			/// create edge set from adjlist
			for(int i=0;i<V;i++){
				Node *temp = Edge[i].head;
				while(temp!=NULL){
					vector<int>v;
					v.push_back(temp->weigth);
					v.push_back(i);
					v.push_back(temp->vertex);
					edges.push_back(v);
					temp=temp->link;
				}
			}
			// sort edgelist based on their weights
			sort(edges.begin(),edges.end());
			
			//disjoint set object
			DisjointSet d(V);
			
			for(int i=0;i<edges.size();i++){
				int w = edges[i][0]; //edge weight
				int x = edges[i][1]; // source
				int y = edges[i][2]; // destination
				
				// if cycle not found
				if(d.find(x) != d.find(y)){
					ans += w;
					d.unionBySize(x,y);  // ad edge in MST
					cout<<x<<" - "<<y<<"  "<<w<<endl;
				}
			}		
			return ans;  // return MST cost
		}
		int minKey(int key[], bool mstSet[]) {
        	int min = INT_MAX, min_index;
        	
			for (int v = 0; v < V; v++)
            	if (mstSet[v] == false && key[v] < min)
                	min = key[v], min_index = v;
        	
			return min_index;
    	}
		int primsMST(){
			int ans = 0;
			//vector<vector<int> >matrix (V,vector<int>(V,0));
			int matrix[V][V] = {0};
			// create matrix from adj list
			for(int i=0;i<V;i++){
				Node *temp = Edge[i].head;
				while(temp!=NULL){
					int j = temp->vertex;
					matrix[i][j] = temp->weigth;
					temp = temp->link;
				}
			}
			
        	int parent[V]; // Array to store constructed MST
        	int key[V]; // Key values used to pick minimum weight edge in cut
        	bool mstSet[V]; // To represent set of vertices not yet included in MST
        
        	for (int i = 0; i < V; i++)
            	key[i] = INT_MAX, mstSet[i] = false;
        
        	key[0] = 0; // Make key 0 so that this vertex is picked as first vertex
        	parent[0] = -1; // First node is always root of MST 
        
        	for (int count = 0; count < V - 1; count++) {
            	int u = minKey(key, mstSet);
            	mstSet[u] = true;
            	for (int v = 0; v < V; v++){
            		if (matrix[u][v] && mstSet[v] == false && matrix[u][v] < key[v]){
                		parent[v] = u;
                		key[v] = matrix[u][v];
					}
				}
                	
      	  	}
      	  	for (int i = 1; i < V; i++){
      	  			int w = matrix[i][parent[i]];
      	  			cout << parent[i] << " - " << i << " \t" << w << " \n";
      	  			ans+=w;
			}
			return ans;
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
	cout<<"1. DFS\t2.BFS\t3. print graph\t4. Kruskal MST\t5.Prims MST"<<endl;
	
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
			case 4:{
				cout<<endl<<"MST cost : "<<g.kruskalMST()<<endl;
				break;
			}
			case 5:{
				cout<<endl<<"MST cost : "<<g.primsMST();
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
