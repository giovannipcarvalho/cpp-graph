#include <iostream>
#include <cassert>
#include "graph.h"

using namespace std;

int main() {
	Graph a(2);
	a.addEdge(0, 1, 3);
	a.addEdge(1, 0, 2);

	assert(a.getWeight(0, 1) == 3);
	assert(a.getWeight(1, 0) == 2);
	assert(a[0][0].index == 1);
	assert(a[0][0].weight == 3);

	assert(a.getName(0) == "");
	a.setName(0, "Named");
	assert(a.getName(0) == "Named");

	Graph b("wgraph-file.txt", true);
	assert(b.edgeExists(0, 1));
	assert(b.edgeExists(0, 2));
	assert(b.edgeExists(0, 3));
	assert(b.getWeight(0, 1) == 30);
	assert(b.getWeight(0, 2) == 110);
	assert(b.getWeight(0, 3) == 100);
	//cout << b << endl;

	cout << "Tests passed." << endl;
}
