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

	cout << "Tests passed" << endl;
}