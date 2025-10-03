// Number of Provinces

// Link: https://leetcode.com/problems/number-of-provinces/description/

#include <bits/stdc++.h>
using namespace std;

// BFS

class Solution {
private:
    void dfs(int node,vector<int>&vis,vector<int>adj[]){
        vis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it])
            dfs(it,vis,adj);
        }
    } 
public:
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>vis(n,0);
        int count = 0;
        vector<int>adj[n];

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                } 
            }
        }

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,adj);
                count++;
            }
        }
        return count;
    }    
};

// DSU

class DSU {
    vector<int> parent, size;

public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int findPar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findPar(parent[node]); // path compression
    }

    void unionS(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);
        if (pu == pv) return; // already same component

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU dsu(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) { 
                if (isConnected[i][j] == 1) {
                    dsu.unionS(i, j);
                }
            }
        }

        unordered_set<int> provinces;
        for (int i = 0; i < n; i++) {
            provinces.insert(dsu.findPar(i));
        }
        return provinces.size();
    }
};
