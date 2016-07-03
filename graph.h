#include <vector>
#include <list>
#include <algorithm>
#include <utility>

using namespace std;

#ifndef Graph_H
#define Graph_H

//typedef pair<int, int> successor;

struct successor {
	int index;
	int weight;
};

class Graph
{
private:
	int vertices;
	vector< vector<successor> > adj;

public:
	Graph(int n);

	Graph(const char * filename);
	
	int getVerticeCount() const;

	void addEdge(int a, int b);

	void addEdge(int a, int b, int w);

	void addEdge(int a, successor b);

	vector<successor> successors(int v) const;

	bool edgeExists(int a, int b) const;
	
	bool edgeExists(int a, successor b) const;

	vector<successor> & operator[] (int v);
	
	Graph underlyingGraph() const;

	void print (ostream & out);

	~Graph();
};

ostream & operator << (ostream & out, Graph g);

ostream & operator << (ostream & out, successor s);

//bool operator == (const successor & a, const int & b);

#endif
