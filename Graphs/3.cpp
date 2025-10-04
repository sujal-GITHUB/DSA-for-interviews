// Disjoint Set Union

#include<bits/stdc++.h>
using namespace std;

/*
# Time Complexity:

Each edge requires 2 find() + 1 union() operation.

With path compression + union by rank, each operation is O(α(V)), where α is the inverse Ackermann function (almost constant).

Total = O(E · 4α(V)) ≈ O(E)

// 4 α(V) per edge, but since α(V) is tiny (≤ 4) in practice, it’s treated as O(1).

Space Complexity:

parent[] + rank[] arrays → O(V)

Total = O(V)
*/

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