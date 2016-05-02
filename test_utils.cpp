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
    j.addEdge(0, 4);
    j.addEdge(1, 5);
    j.addEdge(2, 7);
    j.addEdge(3, 6);
    j.addEdge(4, 1);
    j.addEdge(5, 3);
    j.addEdge(6, 2);
    j.addEdge(7, 0);
    assert(isCycleGraph(j));
   
    Graph i(6);
    i.addEdge(0, 1);
    i.addEdge(0, 2);
    i.addEdge(0, 4);
    i.addEdge(1, 2);
    i.addEdge(1, 0);
    i.addEdge(2, 0);
    i.addEdge(2, 1);
    i.addEdge(2, 3);
    i.addEdge(3, 2);
    i.addEdge(3, 4);
    i.addEdge(3, 5);
    i.addEdge(4, 0);
    i.addEdge(4, 3);
    i.addEdge(5, 3);
    
    vector<int> paths = shortest_path(i);
    vector<int> v = {-1,0,0,2,0,3};
    assert(paths == v);
    //   print each shortest path
    //   print_all_paths(paths);
    
    
    Graph k(3);
    k.addEdge(0,1);
    k.addEdge(1,2);
    k.addEdge(2,0);
    
    vector<Color> c = vector<Color>(k.getVerticeCount(), white);
    DFS_visit(k, c, 0);
    for (auto i : c)
        assert(i == black);
        
        
    Graph l(3);
    l.addEdge(0, 1);
    l.addEdge(0, 2);
    assert(isWeaklyConnected(l));
    
    cout << "Tests passed." << endl;
}