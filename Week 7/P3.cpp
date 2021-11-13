#include <iostream>
#include <limits.h>

using namespace std;

// Define number of vertices in the graph and infinite value
int t[10][10][50];
#define INF INT_MAX

// A naive recursive function to count walks from u to v with k edges
int shortestPath(int V, int **graph, int u, int v, int k)
{
    // Base cases
    if (k == 0 && u == v)             return 0;
    if (k == 1 && graph[u][v] != INF) return graph[u][v];
    if (k <= 0)                       return INF;

    // Initialize result
    int res = INF;

    if(t[u][v][k]!=-1)
        return t[u][v][k];
    // Go to all adjacents of u and recur
    for (int i = 0; i < V; i++)
    {
        if (graph[u][i] != INF && u != i && v != i)
        {
            int rec_res = shortestPath(V, graph, i, v, k-1);
            if (rec_res != INF)
                res = min(res, graph[u][i] + rec_res);
        }
    }
    t[u][v][k] = res;
    return res;
}


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
     int u,v,k;
     cin>>u>>v>>k;

     memset(t,-1,sizeof(t));

     cout << "Weight of the shortest path from("<<u<<","<<v<<") with "<<k<<" edges : "<< shortestPath(V, g, u, v, k);
     free(g);
     return 0;
}
