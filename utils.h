#ifndef Graph_Utils_H
#define Graph_Utils_H

bool isSymmetric(const Graph g){
    int v = g.getVerticeCount();
    for(int i = 0; i < v; ++i){
        vector<int> successors = g.successors(i);
        for(int j = 0; j < successors.size(); ++j){
            if(!g.edgeExists(successors[j], i))
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
        if(c[v] == white){
            return isCyclic_DFS_util(g, v, c);
        } else if(c[v] == gray){
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
        return isCycleGraph_DFS_util(g, g.successors(v)[0], s+1);
    else
        if(g.successors(v).size() > 0)
            return g.successors(v)[0];
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
    for(int i = 1; i < paths.size(); ++i){
        print_path(paths, i);
        cout << endl;
    }
}


//BFS based
vector<int> shortest_path(Graph g){
    vector<Color> c = vector<Color>(g.getVerticeCount(), white);
    vector<int> paths = vector<int>(g.getVerticeCount(), -1);
    
    for(int i = 0; i < g.getVerticeCount(); ++i){
        c[i] = gray;
        
        for(int j = 0; j < g.successors(i).size(); ++j){
            if(c[g.successors(i)[j]] == white){
                paths[g.successors(i)[j]] = i;
                c[g.successors(i)[j]] = gray;
            }
        }
        
        c[i] = black;
    }
    
    return paths;
}


void DFS_visit(const Graph & g, vector<Color> & c, int v){
    c[v] = gray;
    
    for(auto s : g.successors(v)){
        if(c[s] == white){
            DFS_visit(g, c, s);
        }
    }
    
    c[v] = black;
}

#endif