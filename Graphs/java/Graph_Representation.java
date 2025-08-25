public class Graph_Representation{
    int adjMatrix[][];

    Graph_Representation(int nodes){
        adjMatrix = new int[nodes][nodes];
    }

    // [[0,1],[1,2],[2,0]]
    public void addEdgesInMatrix(int edges[][], boolean isDirected){
       for(int edge[]: edges){
           int u = edge[0];
           int v = edge[1];

           if(isDirected) {
                // for directed graph, only one side will be marked
                adjMatrix[u][v] = 1;
           }
           else{
                // for undirected graph, both sides will be marked
                adjMatrix[u][v] = 1;
                adjMatrix[v][u] = 1;
           } 
       }
    }

    public void printGraph(){
        for(int i=0; i<adjMatrix.length; i++){
            System.out.print("row " + i + " -> ");
            for(int j=0; j<adjMatrix[i].length; j++){
                System.out.print(adjMatrix[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String args[]){
        int edges[][] = {{0,1},{1,2},{2,0}};
        int nodes = 3;
        Graph_Representation graph = new Graph_Representation(3);
        graph.addEdgesInMatrix(edges, false); // false for undirected graph
        graph.printGraph();
    }
}