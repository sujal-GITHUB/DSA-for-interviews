// Rat in a Maze

// Link: https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isValid(int i, int j, vector<vector<int>>& maze){
        int n = maze.size();
        
        if(i<n && j<n && i>=0 && j>=0 && maze[i][j] == 1)
        return true;
        
        return false;
    }
  
    void f(int i, int j, vector<vector<int>>& maze, string temp, vector<string>&ans){
        int n = maze.size();
        
        if(i==n-1 && j==n-1){
            ans.push_back(temp);
            return;
        };
        
        // mark Visited
        maze[i][j] = 0;
        
        // Up
        if(isValid(i-1, j, maze))
        f(i-1, j, maze, temp+'U' ,ans);
        
        // Down
        if(isValid(i+1, j, maze))
        f(i+1, j, maze, temp+'D', ans);
        
        // Left
        if(isValid(i, j-1, maze))
        f(i, j-1, maze, temp+'L', ans);
        
        // Right
        if(isValid(i, j+1, maze))
        f(i, j+1, maze, temp+'R', ans);
        
        // unmark
        maze[i][j] = 1;
    }
  
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string>ans;
        
        if(maze[0][0] == 0) 
        return ans;
        
        string temp = "";
        f(0, 0, maze, temp, ans);
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};