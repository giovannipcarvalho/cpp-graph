#include <iostream>
#include <cassert>
#include "graph.h"
#include "utils.h"

using namespace std;

int main(){
    Graph g(2);
    g.addEdge(0, 0);
	g.addEdge(0, 1);
	g.addEdge(1, 0);
	
    assert(isSymmetric(g));
    assert(hasLoop(g));

    Graph h(3);
    h.addEdge(0, 1);
    h.addEdge(1, 2);
    h.addEdge(2, 0);

    assert(isCyclic(h));

    cout << "Tests passed." << endl;
}