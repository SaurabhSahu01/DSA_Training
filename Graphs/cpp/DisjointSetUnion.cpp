#include<iostream>
#include<vector>
using namespace std;

class DisjointSetUnion {
    int components; 
    vector<int> parent;
    vector<int> rank;

    public:
        DisjointSetUnion(int nodes): parent(nodes), rank(nodes), components(nodes){
            for(int i = 0; i < nodes; i++){
                parent[i] = i;
                rank[i] = 0;
            }
        }
        
        ~DisjointSetUnion(){
            cout<< "Class destroyed!";
        }

        int findRootParent(int node){
            if(parent[node] == node)
                return node;
            parent[node] = findRootParent(parent[node]);
            return parent[node];
        }

        void unionByRank(int u, int v){
            // 1. find the root parents
            int rootParent1 = findRootParent(u);
            int rootParent2 = findRootParent(v);

            // already in the same component
            if(rootParent1 == rootParent2)
                return;

            if(rank[rootParent1] > rank[rootParent2]){
                parent[rootParent2] = rootParent1;
                cout<< v << " is attached to " << u << endl;
            }
            else if(rank[rootParent2] > rank[rootParent2]){
                parent[rootParent1] = rootParent2;
                cout<< u << " is attached to " << v << endl;
            }
            else{
                // add the second root parent to the first and increment the rank of first
                parent[rootParent2] = rootParent1;
                rank[rootParent1]++;
                cout<< v << " is attached to " << u << endl;
            }
            components--;
        }

        int totalComponents(){
            return components;
        }
};

int main(){
    vector<vector<int>> edges = {{3,4}, {1,2}, {5,2}, {4,2}, {0,5}};
    int nodes = 6;
    DisjointSetUnion ds(nodes);
    for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        ds.unionByRank(u, v);
    }
    cout << ds.findRootParent(1) << endl;
    cout << "Total Components : "<< ds.totalComponents() << endl;
    return 0;
}

