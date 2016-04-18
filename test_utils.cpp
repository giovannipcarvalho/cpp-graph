#include <iostream>
#include "graph.h"
#include "utils.h"

using namespace std;

int main(){
    Graph g(2);
	g.addEdge(0, 1);
	g.addEdge(1, 0);
	
    cout << isSymmetric(g) << endl;
}