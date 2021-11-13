#include <iostream>

using namespace std;


// A utility function to find the vertex with
// minimum key value, from the set of vertices
// not yet included in MST
int maxKey(int V, int key[], bool mstSet[])
{
    // Initialize min value
    int max = INT_MIN, max_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] > max)
            max = key[v], max_index = v;

    return max_index;
}

// A utility function to print the
// constructed MST stored in parent[]
int printMST(int V, int parent[], int **graph)
{
    int w=0;
    for (int i = 1; i < V; i++)
        w+=graph[i][parent[i]];
    return w;
}

// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation
int primMST_mod(int V, int **graph)
{
    // Array to store constructed MST
    int parent[V];

    // Key values used to pick minimum weight edge in cut
    int key[V];

    // To represent set of vertices included in MST
    bool mstSet[V];

    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++)
        key[i] = INT_MIN, mstSet[i] = false;

    // Always include first 1st vertex in MST.
    // Make key 0 so that this vertex is picked as first vertex.
    key[0] = 0;
    parent[0] = -1; // First node is always root of MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++)
    {
        // Pick the minimum key vertex from the
        // set of vertices not yet included in MST
        int u = maxKey(V, key, mstSet);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of
        // the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not
        // yet included in MST
        for (int v = 0; v < V; v++)

            // graph[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == false && graph[u][v] > key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    // print the constructed MST
    return printMST(V, parent, graph);
}

// Driver code
int main()
{
    int V;
    cin>>V;
    int **g = new int *[V];
    for(int i = 0; i <V; i++)
        g[i] = new int[V];
    int i,j;
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
            cin>>g[i][j];
    }

    // Print the solution
    cout<<"Minimum Spanning Weight : "<<primMST_mod(V, g)<<endl;

    return 0;
}
