#include <iostream>
#include "MCP.h"

using namespace std;

void print_path(int v, Graph & g, vector<int> ante){
    if (ante[v] == -1)
        cout << g.getName(v);
    else {
        print_path(ante[v], g, ante);
        cout << " -> " << g.getName(v);
    }
}

void print_mcp(int v, Graph & g, vector<int> & cost, vector<int> & ante){
	cout << "Menores caminhos saindo de " << g.getName(v) << ": " << endl;
	for(int i = 1; i < g.getVerticeCount(); ++i){
		cout << "\t";
		print_path(i, g, ante);
		cout << " (custo: " << cost[i] << ")" << endl;
	}
}

int main(){
	Graph g("wgraph-file.txt", true);
	vector<int> ante;
	vector<int> cost;

	dijkstra_mcp(0, g, cost, ante);

	print_mcp(0, g, cost, ante);
}
