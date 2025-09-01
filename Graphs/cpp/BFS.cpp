// 1.) using DFS
// 2.) using BFS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// complete this function using 1.) DFS 2.) BFS
vector<vector<int>> allPathsTopToBottom(int n, 
    vector<vector<int>>& list, 
    int source, 
    int destination, vector<bool>& visited){

    if(source == destination){
        vector<vector<int>> base;
        base.push_back({source});
        return base;
    }
    
    vector<vector<int>> answer;
    visited[source] = 1;

    for(auto neighbour : list[source]){
        if(!visited[neighbour]){
            vector<vector<int>> tempPath = allPathsTopToBottom(n, list, neighbour, destination, visited);
            if(tempPath.size()){
                for(auto path : tempPath){
                    path.insert(path.begin(), source);
                }
                answer = tempPath;
            }
        }
    }
    return answer;
}

void allPathsBottomToTop(int n, 
    vector<vector<int>>& edges, 
    int source, 
    int destination, vector<int> tempPath, vector<vector<int>>& answer) {}

vector<vector<int>> edgeToList(int nodes, vector<vector<int>>& edges){
        // make a 2D list of list - adj. list
        vector<vector<int>> list(nodes);

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            // undirected graph
            list[u].push_back(v);
            list[v].push_back(u);
        }

        return list;
}

int main(){
    return 0;
}