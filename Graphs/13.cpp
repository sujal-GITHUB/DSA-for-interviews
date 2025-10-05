// Topo Sort

#include<bits/stdc++.h>
using namespace std;

// DFS

void dfs(int node, vector<int> adj[], vector<bool> &visited, stack<int> &st) {
    visited[node] = true;
    for (auto neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, st);
        }
    }
    st.push(node);
}

vector<int> topoSortDFS(int n, vector<int> adj[]) {
    vector<bool> visited(n, false);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, st);
        }
    }

    vector<int> topo;
    while (!st.empty()) {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}

// Kahn's Algorithm

vector<int> topoSortBFS(int n, vector<int> adj[]) {
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++) {
        for (auto v : adj[i]) 
        indegree[v]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) 
        q.push(i);
    }

    vector<int> topo;
    while (!q.empty()) {
        int u = q.front(); 
        q.pop();

        topo.push_back(u);
        for (auto v : adj[u]) {
            indegree[v]--;
            
            if (indegree[v] == 0) 
            q.push(v);
        }
    }

    // If topo.size() != n, there is a cycle
    if (topo.size() != n) {
        cout << "Graph has a cycle!\n";
        return {};
    }
    return topo;
}