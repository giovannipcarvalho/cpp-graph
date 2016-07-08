#include <iostream>
#include "graph.h"
#include "utils.h" 
 
using namespace std;

int main(int argc, char const *argv[])
{
	if (argc > 1){
		Graph g(argv[1]);
		cout << "Ciclico: "<< isCyclic(g) << endl;
		cout << "Simetrico: " <<isSymmetric(g) << endl;
		cout << "Loop: " << hasLoop(g) << endl;
		cout << "Ciclo: " << isCycleGraph(g) << endl;
		cout << "Fracamente: " << isWeaklyConnected(g) << endl;
		//cout << g << endl;
	}
	return 0;
}
