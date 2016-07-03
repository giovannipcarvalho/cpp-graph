#ifndef Graph_Utils_H
#define Graph_Utils_H

bool isSymmetric(const Graph g){
    int v = g.getVerticeCount();
    for(int i = 0; i < v; ++i){
        vector<successor> successors = g.successors(i);
        for(int j = 0; j < successors.size(); ++j){
            if(!g.edgeExists(successors[j].index, i))
                return false;
        }
    }
    return true;
}

bool hasLoop(const Graph g){
    int v = g.getVerticeCount();
    for(int i = 0; i < v; ++i)
        if(g.edgeExists(i, i))
            return true;
    return false;
}

enum Color { white, gray, black };

bool isCyclic_DFS_util(const Graph & g, int u, vector<Color> & c){
    c[u] = gray;
    for(auto v : g.successors(u)){
        if(c[v.index] == white){
            return isCyclic_DFS_util(g, v.index, c);
        } else if(c[v.index] == gray){
            return true;
        }
    }
    c[u] = black;
    return false;
}

bool isCyclic(const Graph g){
    vector<Color> c = vector<Color>(g.getVerticeCount(), white);
    for (int i = 0; i < g.getVerticeCount(); ++i){
        if(c[i] == white){
            bool hasCycle = isCyclic_DFS_util(g, i, c);
            if (hasCycle)
                return true;
        }
    }
    return false;
}

int isCycleGraph_DFS_util(const Graph & g, int v, int s = 0){
    if(s < g.getVerticeCount()-1 && g.successors(v).size() > 0)
        return isCycleGraph_DFS_util(g, g.successors(v)[0].index, s+1);
    else
        if(g.successors(v).size() > 0)
            return g.successors(v)[0].index;
        else
            return -1;
}

bool isCycleGraph(const Graph g){
   return isCycleGraph_DFS_util(g, 0) == 0;
}



void print_path(vector<int> paths, int v){
    if (paths[v] == -1)
        cout << v;
    else {
        print_path(paths, paths[v]);
        cout << " -> " << v;
    }
}

void print_all_paths(vector<int> paths){
    for(int i = 0; i < paths.size(); ++i){
        if(paths[i] == -1)
            continue;
        print_path(paths, i);
        cout << endl;
    }
}

//BFS based
vector<int> shortest_path(Graph g, int v){
    vector<Color> c = vector<Color>(g.getVerticeCount(), white);
    vector<int> paths = vector<int>(g.getVerticeCount(), -1);
    
    list<int> queue;
    queue.push_back(v);
    
    while(!queue.empty()){
        int i = queue.front();
        queue.pop_front();
        c[i] = gray;
        
        for(auto s : g.successors(i)){
            if(c[s.index] == white){
                paths[s.index] = i;
                c[s.index] = gray;
                queue.push_back(s.index);
            }
        }
        
        c[i] = black;
    }
    
    return paths;
}


void DFS_visit(const Graph & g, vector<Color> & c, int v){
    c[v] = gray;
    
    for(auto s : g.successors(v)){
        if(c[s.index] == white){
            DFS_visit(g, c, s.index);
        }
    }
    
    c[v] = black;
}

bool isWeaklyConnected(Graph g){
    vector<Color> c = vector<Color>(g.getVerticeCount(), white);
    
    // get underlying graph
    Graph ul = g.underlyingGraph();
    
    // check if ul is connected
    // dfs visit 
    DFS_visit(ul, c, 0);
    
    // doesn't have unvisited (white) vertices
    return find(begin(c), end(c), white) == end(c);
}

#endif
