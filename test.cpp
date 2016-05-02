#include <iostream>
#include <cassert>
#include "graph.h"

using namespace std;

int main() {
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(1, 0);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 0);

	assert(g.successors(0)[0] == 1);

	assert(g.edgeExists(0, 1));
	assert(g.edgeExists(1, 0));
	assert(g.edgeExists(1, 2));
	assert(g.edgeExists(2, 0));
	assert(g.edgeExists(2, 3));
	assert(g.edgeExists(3, 0));


	char file[] = "graph-file.txt";
	Graph h(file);

	assert(h.successors(0)[0] == 1);

	assert(h.edgeExists(0, 1));
	assert(h.edgeExists(1, 0));
	assert(h.edgeExists(1, 2));
	assert(h.edgeExists(2, 0));
	assert(h.edgeExists(2, 3));
	assert(h.edgeExists(3, 0));

	h[0][0] = 2;
	assert(h.edgeExists(0, 2));
	h[0][0] = 1;
	assert(h.edgeExists(0, 1));
	
	
	Graph i(3);
	i.addEdge(0, 1);
	i.addEdge(1, 2);
	i.addEdge(2, 0);
	
	Graph ul = i.underlyingGraph();
	
	assert(ul.edgeExists(1, 0));
	assert(ul.edgeExists(2, 1));
	assert(ul.edgeExists(0, 2));

	cout << "Tests passed." << endl;
}