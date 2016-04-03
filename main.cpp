#include <iostream>
#include "graph.h"
 
using namespace std;

int main(int argc, char const *argv[])
{
	// cout << "Hello!" << endl;
	Graph g(4);
	g.addEdge(0, 0);
	g.addEdge(0, 1);
	g.addEdge(0, 2);

	vector<int> s = g.successors(0);
	
	// print successors
	// for (std::vector<int>::iterator i = s.begin(); i != s.end(); ++i)
	// {
	// 	cout << *i << endl;
	// }

	// cout << g.edgeExists(0, 0) << endl;
	// cout << g.edgeExists(0, 1) << endl;
	// cout << g.edgeExists(0, 2) << endl;
	// cout << g.edgeExists(0, 3) << endl;

	char str[] = "my file";

	Graph h(str);

	return 0;
}