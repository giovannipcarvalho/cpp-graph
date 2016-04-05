#include <vector>
#include <algorithm>

using namespace std;

#ifndef Graph_H
#define Graph_H

class Graph
{
private:
	int vertices;
	vector< vector<int> > adj;

public:
	Graph(int n);

	Graph(const char * filename);

	void addEdge(int a, int b);

	vector<int> successors(int v);

	bool edgeExists(int a, int b);

	vector<int> & operator[] (int v);

	void print (ostream & out);

	~Graph();
};

ostream & operator << (ostream & out, Graph g);

#endif