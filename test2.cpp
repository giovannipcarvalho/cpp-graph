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

	cout << "Tests passed." << endl;
}
