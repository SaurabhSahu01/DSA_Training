#include <iostream>
#include <vector>
using namespace std;

class Graph_Representation {
    vector<vector<int>> adjMatrix;

public:
    // Constructor
    Graph_Representation(int nodes) {
        adjMatrix = vector<vector<int>>(nodes, vector<int>(nodes, 0));
    }

    // Add edges to adjacency matrix
    void addEdgesInMatrix(vector<vector<int>>& edges, bool isDirected) {
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            if (isDirected) {
                // for directed graph, only one side will be marked
                adjMatrix[u][v] = 1;
            } else {
                // for undirected graph, both sides will be marked
                adjMatrix[u][v] = 1;
                adjMatrix[v][u] = 1;
            }
        }
    }

    // Print adjacency matrix
    void printGraph() {
        for (int i = 0; i < adjMatrix.size(); i++) {
            cout << "row " << i << " -> ";
            for (int j = 0; j < adjMatrix[i].size(); j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    vector<vector<int>> edges = {{0,1}, {1,2}, {2,0}};
    int nodes = 3;

    Graph_Representation graph(nodes);
    graph.addEdgesInMatrix(edges, false); // false for undirected graph
    graph.printGraph();

    return 0;
}
