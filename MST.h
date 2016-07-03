#include <iostream>
#include <vector>
#include <set>

#include "graph.h"

using namespace std;

struct edge {
	int from;
	int to;
	int weight;
};

struct edgecmp {
	bool operator () (const edge & a, const edge & b) {
		return a.weight < b.weight;
	}
};

int find_set(int v, vector<int> & sets){
	if(sets[v] == -1)
		return v;
	else
		return find_set(sets[v], sets);
}

void set_union(int s1, int s2, vector<int> & sets) {
	sets[s2] = s1;
}

ostream & operator << (ostream & out, const edge & e){
	out << e.from << "->" << e.to << ": " << e.weight;
	return out;
}

//KRUSKAL
vector< edge > MST_KRUSKAL(const Graph & g){
	set< edge, edgecmp > edges;
	vector< edge > result;

	//every edge in graph G, automatically ordered by weight
	for (int i = 0; i < g.getVerticeCount(); ++i){
		for (auto s : g.successors(i)){
			edges.insert({i, s.index, s.weight});
		}
	}

	//init sets to -1
	vector< int > sets = vector<int>(g.getVerticeCount(), -1);

	for(auto e : edges)
		if(find_set(e.from, sets) != find_set(e.to, sets)){
			set_union(e.from, e.to, sets);
			result.push_back(e);
		}

	return result;
}

