#include <iostream>
#include "graph.h"
 
using namespace std;

int main(int argc, char const *argv[])
{
	if (argc > 1){
		Graph g(argv[1]);
		cout << "Checking edge 0->0: " << g.edgeExists(0, 0) << endl;
		cout << "Checking edge 0->1: " << g.edgeExists(0, 1) << endl;
		cout << g << endl;
	}
	return 0;
}
