#include <iostream>
#include <vector>

using namespace std;

void add_edge(vector<int> adj[], int v, int e){

	adj[v].push_back(e);
}

void print_adjacency_vector(vector<int> adj[], int n_nodes){

	for(int v = 0; v < n_nodes; v++){

		cout << "Adjacency vector of vertex" << v << ":" << endl;
		cout << "head->";
		for(int e = 0; e < adj[v].size(); e++){
			cout << e << "->";				
		}
		cout << endl;
	}
}

int main(){

	int V = 5;
	vector<int> adj[V];
	
	add_edge(adj, 0, 1);
	add_edge(adj, 0, 2);
	add_edge(adj, 1, 0);
	add_edge(adj, 1, 3);
	add_edge(adj, 1, 4);
	add_edge(adj, 2, 0);
	add_edge(adj, 2, 3);
	add_edge(adj, 2, 4);
	add_edge(adj, 3, 1);
	add_edge(adj, 3, 2);
	add_edge(adj, 3, 4);
	add_edge(adj, 4, 1);
	add_edge(adj, 4, 2);
	add_edge(adj, 4, 3);

	print_adjacency_vector(adj, V);
}