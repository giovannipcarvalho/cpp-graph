#include <iostream>
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

void weighted_edge_adder(Graph & g, int v, string line){
	char * str = (char*) line.c_str();
	char * cp = strtok(str, " ");

	//set vertice v name
	g.setName(v, cp);
	cp = strtok(nullptr, " ");

	while(cp != nullptr){
		int succIndex = atoi(cp);
		cp = strtok(nullptr, " ");
		int succWeight = atoi(cp);

		g.addEdge(v, succIndex, succWeight);
		cp = strtok(nullptr, " ");
	}
}

Graph::Graph(int n) {
	vertices = n;
	adj = vector< vector<successor> >(n);
	name = vector< string >(n);
}

Graph::Graph(const char * filename, bool isWeighted){
	weighted = isWeighted;

	ifstream file(filename);

	int c = 0;

	Graph * g;

	for (string line; getline(file, line); ){
		if(c == 0)
			g = new Graph(atoi(line.c_str())); // init graph
		else {
			//unweighted
			if(!weighted)
				edge_adder(*g, c-1, line);
			//weighted
			else
				weighted_edge_adder(*g, c-1, line);
		}
		++c;
	}

	*this = *g;
	delete g;
}

int Graph::getVerticeCount() const{
	return vertices;
}

void Graph::setName(int v, string newName){
	if (v < vertices)
		name[v] = newName;
}

string Graph::getName(int v) const{
	return name[v];
}

void Graph::addEdge(int a, int b){
	successor s = {b, 1};
	if(b < vertices)
		adj[a].push_back(s);
}

void Graph::addEdge(int a, int b, int w){
	successor s = {b, w};
	if(b < vertices)
		adj[a].push_back(s);
}

void Graph::addEdge(int a, successor b){
	if(b.index < vertices)
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

int Graph::getWeight(int a, int b) const{
	if(!edgeExists(a, b))
		return -1;
	else
		return find(adj[a].begin(), adj[a].end(), b)->weight;
}

vector<successor> & Graph::operator [] (int v) {
	return adj[v];
}

Graph Graph::underlyingGraph() const{
	Graph g(getVerticeCount());
	
	for(int i = 0; i < getVerticeCount(); ++i){
		for(int j = 0; j < successors(i).size(); ++j){
			g.addEdge(i, successors(i)[j]);
			g.addEdge(successors(i)[j].index, i);
		}
	}
	
	return g;
}

void Graph::print (ostream & out){
	out << vertices << endl;
	for (int i = 0; i < adj.size(); ++i){
		if(getName(i) != "")
			out << getName(i) << " ";
		for (int j = 0; j < adj[i].size(); ++j){
			if(weighted)
				out << adj[i][j];
			else
				cout << adj[i][j].index;
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
	out << s.index << ' ' << s.weight;
	return out;
}

bool operator == (const successor & a, const int & b){
	return a.index == b;
}

bool operator == (const successor & a, const successor & b){
	return a.index == b.index;
}
