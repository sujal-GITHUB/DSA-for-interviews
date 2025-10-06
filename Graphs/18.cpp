// Shortest path in Directed Acyclic Graph

// Link: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string findOrder(vector<string> &words) {
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indegree;

        // Initialize indegree for all unique characters
        for(auto &w: words){
            for(char c: w){
                indegree[c] = 0;
            }
        }

        int n = words.size();
        for(int i=0; i<n-1; i++){
            string w1 = words[i];
            string w2 = words[i+1];

            int len = min(w1.size(), w2.size());
            bool found = false;

            for(int j=0; j<len; j++){
                if(w1[j] != w2[j]){
                    adj[w1[j]].push_back(w2[j]);
                    indegree[w2[j]]++;
                    found = true;
                    break;
                }
            }

            // invalid case: prefix issue
            if(!found && w1.size() > w2.size()){
                return "";
            }
        }

        // Topological Sort (Kahn’s BFS)
        queue<char> q;
        for(auto &p: indegree){
            if(p.second == 0) 
            q.push(p.first);
        }

        string order;
        while(!q.empty()){
            char u = q.front();
            q.pop();
            
            order.push_back(u);

            for(char v : adj[u]){
                indegree[v]--;
                if(indegree[v] == 0) 
                q.push(v);
            }
        }

        if(order.size() < indegree.size()) 
        return ""; // cycle exists

        return order;
    }
};
