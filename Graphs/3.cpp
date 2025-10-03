// Disjoint Set Union

#include<bits/stdc++.h>
using namespace std;

class DSU{
    vector<int>size;
    vector<int>parent;

    public:

    DSU(int n){
        size.resize(n, 0);
        parent.resize(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }

    int findUpar(int node){
        if(node == parent[node])
        return node;

        return parent[node] = findUpar(parent[node]);
    }

    void unionS(int u, int v){
        int uu = findUpar(u);
        int vv = findUpar(v);

        if(uu == vv)
        return;

        if(size[uu] < size[vv]){
            size[vv] += size[uu];
            parent[uu] = vv;
        }
        else{
            size[uu] += size[vv];
            parent[vv] = uu;
        }
    }
};