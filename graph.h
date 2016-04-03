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

	Graph(char * filename);

	void addEdge(int a, int b);

	vector<int> successors(int v);

	bool edgeExists(int a, int b);

	~Graph();
};

#endif