// Minimum Cost Paths
#include <algorithm>
#include <vector>
#include <list>
#include "graph.h"

using namespace std;

#define INFINITY 99999

/*
 * Source:
 * http://stackoverflow.com/a/25524075
 * */
template< typename T >
typename std::list<T>::iterator 
   insert_sorted( std::list<T> & l, T const& item )
{
    return l.insert
        ( 
            std::upper_bound( l.begin(), l.end(), item ),
            item 
        );
}

bool operator < (const successor & lhs, const successor & rhs){
	return lhs.weight < rhs.weight;
}

void relax(const int v, const int x, const int p, vector<int> & cost, vector<int> & ante){
	if ( (cost[v] + p) < cost[x] ){
		cost[x] = cost[v] + p;
		ante[x] = v;
	}
}

//Dijkstra MCP
// returns vector of costs
void dijkstra_mcp(int startingPoint, const Graph & g, vector<int> & cost, vector<int> & ante){
	//init costs to infinity
	//vector<int> cost = vector<int>(g.getVerticeCount(), INFINITY);
	cost = vector<int>(g.getVerticeCount(), INFINITY);
	//vector<int> ante = vector<int>(g.getVerticeCount(), -1);
	ante = vector<int>(g.getVerticeCount(), -1);
	cost[startingPoint] = 0; // 0-cost to self

	// priority queue
	list<successor> queue;

	// fill up costs
	for (int v = 0; v < g.getVerticeCount(); ++v)
		insert_sorted(queue, {v, cost[v]});

	int c = 0;

	// while not empty
	while(!queue.empty()){
		// get lowest cost v
		successor v = queue.front();
		queue.pop_front();
		
		// foreach successor of v
		for(auto x : g.successors(v.index)){
			// relax successor
			relax(v.index, x.index, x.weight, cost, ante);

			// update key
			for(auto & i : queue){
				if (i.index == x.index)
					i.weight = cost[x.index];
			}
		}

	}
}
