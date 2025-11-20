// Cycle Detection in unirected Graph

#include <bits/stdc++.h>
using namespace std;

// DFS

class SolutionDFS {
public:
    bool dfsCycle(int node, int parent, vector<int> adj[], vector<bool>& visited) {
        visited[node] = true;
        for (int neigh : adj[node]) {
            if (!visited[neigh]) {
                if (dfsCycle(neigh, node, adj, visited)) 
                return true;
            } 
            else if (neigh != parent) {
                return true;
            }
        }
        return false;
    }

    bool hasCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfsCycle(i, -1, adj, visited)) 
                return true;
            }
        }
        return false;
    }
};

// DFS

class SolutionBFS {
public:
    bool bfsCycle(int src, vector<int> adj[], vector<bool>& visited) {
        queue<pair<int,int>> q;
        visited[src] = true;
        q.push({src, -1});

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (int neigh : adj[node]) {
                if (!visited[neigh]) {
                    visited[neigh] = true;
                    q.push({neigh, node});
                } 
                else if (neigh != parent) {
                    return true;
                }
            }
        }
        return false;
    }

    bool hasCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (bfsCycle(i, adj, visited)) 
                return true;
            }
        }
        return false;
    }
};

// DSU
class SolutionUF {
    struct DSU {
        vector<int> parent, rank;
        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; i++) parent[i] = i;
        }
        int find(int x) {
            if (x == parent[x]) return x;
            return parent[x] = find(parent[x]);
        }
        bool unionSet(int u, int v) {
            int pu = find(u), pv = find(v);

            if(pu == pv) 
            return false; // cycle detected

            if (rank[pu] < rank[pv]) 
            swap(pu, pv);

            parent[pv] = pu;

            if (rank[pu] == rank[pv]) 
            rank[pu]++;
            
            return true;
        }
    };

public:
    bool hasCycle(int V, vector<pair<int,int>>& edges) {
        DSU dsu(V);
        for (auto &e : edges) {
            if (!dsu.unionSet(e.first, e.second)) {
                return true;
            }
        }
        return false;
    }
};