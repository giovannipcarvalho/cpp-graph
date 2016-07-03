#include "MST.H"

using namespace std;

int main(){
	Graph g("mst-file.txt", true);
	vector<edge> mst = MST_KRUSKAL(g);

	cout << "Pontes a serem reconstruídas:" << endl;

	int totalcost = 0;

	for (auto e : mst) {
		cout << "\t(" << g.getName(e.from) << ", " << g.getName(e.to) << ")" << endl;
		totalcost += e.weight;
	}

	cout << "Custo total: " << totalcost << endl;
}
