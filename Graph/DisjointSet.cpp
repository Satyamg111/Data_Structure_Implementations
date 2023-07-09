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
int main(){
	
}
