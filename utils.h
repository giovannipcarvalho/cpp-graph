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

#endif