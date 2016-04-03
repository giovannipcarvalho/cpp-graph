#include <iostream>
#include <string>
#include <fstream>
#include "graph.h"

using namespace std;

void edge_adder(Graph & g, int v, string line){
	char * cp;
	cp = strtok(strdup(line.c_str()), " ");
	while (cp != nullptr){
		g.addEdge(v, atoi(cp));
		cp = strtok(nullptr, " ");
	}
}

Graph::Graph(int n) {
	vertices = n;
	adj = vector< vector<int> >(n);
	cout << "Initializing graph" << endl;
}

Graph::Graph(char * filename){
	cout << filename << endl;
}

void Graph::addEdge(int a, int b){
	if(b < vertices)
		adj[a].push_back(b);
}

vector<int> Graph::successors(int v){
	vector<int> r = adj[v]; // deep copy
	return r;
}

bool Graph::edgeExists(int a, int b){
	return find(adj[a].begin(), adj[a].end(), b) != adj[a].end();
}

Graph::~Graph() {
	// do nothing
}