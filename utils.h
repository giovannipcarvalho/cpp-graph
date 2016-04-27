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

bool DFS(const Graph & g, int u, vector<Color> & c){
    c[u] = gray;
    for(auto v : g.successors(u)){
        if(c[v] == white){
            return DFS(g, v, c);
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
            bool hasCycle = DFS(g, i, c);
            if (hasCycle)
                return true;
        }
    }
    return false;
}

#endif