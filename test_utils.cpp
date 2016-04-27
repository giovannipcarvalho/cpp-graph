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


    Graph j(8);
    j.addEdge(0, 1);
    j.addEdge(1, 2);
    j.addEdge(2, 3);
    j.addEdge(3, 4);
    j.addEdge(4, 5);
    j.addEdge(5, 6);
    j.addEdge(6, 7);
    j.addEdge(7, 0);
    assert(isCycleGraph(j));

    cout << "Tests passed." << endl;
}