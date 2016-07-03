#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include "graph.h"

using namespace std;

void edge_adder(Graph & g, int v, string line){
	char * str = (char*) line.c_str();
	char * cp = strtok(str, " ");
	while (cp != nullptr){
		g.addEdge(v, atoi(cp));
		cp = strtok(nullptr, " ");
	}
}

Graph::Graph(int n) {
	vertices = n;
	adj = vector< vector<successor> >(n);
}

Graph::Graph(const char * filename){
	ifstream file(filename);

	int c = 0;

	Graph * g;

	for (string line; getline(file, line); ){
		if(c == 0)
			g = new Graph(atoi(line.c_str())); // init graph
		else
			edge_adder(*g, c-1, line);
		++c;
	}

	*this = *g;
	delete g;
}

int Graph::getVerticeCount() const{
	return vertices;
}

void Graph::addEdge(int a, int b){
	if(b < vertices)
		adj[a].push_back({b, 1});
}

void Graph::addEdge(int a, int b, int w){
	if(b < vertices)
		adj[a].push_back({b, w});
}

void Graph::addEdge(int a, successor b){
	if(b.succIndex < vertices)
		adj[a].push_back(b);
}

vector<successor> Graph::successors(int v) const{
	vector<successor> r = adj[v]; // deep copy
	return r;
}

bool Graph::edgeExists(int a, int b) const{
	return find(adj[a].begin(), adj[a].end(), b) != adj[a].end();
}

bool Graph::edgeExists(int a, successor b) const{
	return find(adj[a].begin(), adj[a].end(), b) != adj[a].end();
}

vector<successor> & Graph::operator [] (int v) {
	return adj[v];
}

Graph Graph::underlyingGraph() const{
	Graph g(getVerticeCount());
	
	for(int i = 0; i < getVerticeCount(); ++i){
		for(int j = 0; j < successors(i).size(); ++j){
			g.addEdge(i, successors(i)[j]);
			g.addEdge(successors(i)[j].succIndex, i);
		}
	}
	
	return g;
}

void Graph::print (ostream & out){
	out << vertices << endl;
	for (int i = 0; i < adj.size(); ++i){
		for (int j = 0; j < adj[i].size(); ++j){
			out << adj[i][j];
			if(j < adj[i].size() - 1)
				out << ' ';
		}
		if(i < adj.size() - 1)
			out << endl;
	}
}

Graph::~Graph() {
	// do nothing
}

ostream & operator << (ostream & out, Graph g){
	g.print(out);
	return out;
}

ostream & operator << (ostream & out, successor s){
	out << s.succIndex << ' ' << s.succWeight;
	return out;
}

bool operator == (const successor & a, const int & b){
	return a.succIndex == b;
}

bool operator == (const successor & a, const successor & b){
	return a.succIndex == b.succIndex;
}
