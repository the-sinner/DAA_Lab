#include <iostream>
#include <sstream>

using namespace std;

/* Define Infinite as a large enough
value.This value will be used for
vertices not connected to each other */
#define INF 99999

// A function to print the solution matrix
void printSolution(int V, int **dist);

// Solves the all-pairs shortest path
// problem using Floyd Warshall algorithm
void floydWarshall(int V, int **graph)
{
    /* dist[][] will be the output matrix
    that will finally have the shortest
    distances between every pair of vertices */
    int **dist = new int *[V];
    for(int i = 0; i <V; i++)
        dist[i] = new int[V];
    int i, j, k;

    /* Initialize the solution matrix same
    as input graph matrix. Or we can say
    the initial values of shortest distances
    are based on shortest paths considering
    no intermediate vertex. */
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    /* Add all vertices one by one to
    the set of intermediate vertices.
    ---> Before start of an iteration,
    we have shortest distances between all
    pairs of vertices such that the
    shortest distances consider only the
    vertices in set {0, 1, 2, .. k-1} as
    intermediate vertices.
    ----> After the end of an iteration,
    vertex no. k is added to the set of
    intermediate vertices and the set becomes {0, 1, 2, ..
    k} */
    for (k = 0; k < V; k++) {
        // Pick all vertices as source one by one
        for (i = 0; i < V; i++) {
            // Pick all vertices as destination for the
            // above picked source
            for (j = 0; j < V; j++) {
                // If vertex k is on the shortest path from
                // i to j, then update the value of
                // dist[i][j]
                if (dist[i][j] > (dist[i][k] + dist[k][j])
                    && (dist[k][j] != INF
                        && dist[i][k] != INF))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the shortest distance matrix
    printSolution(V, dist);
}

/* A utility function to print solution */
void printSolution(int V, int **dist)
{
    cout << "Shortest Distance Matrix : \n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF"
                     << "     ";
            else
                cout << dist[i][j] << "     ";
        }
        cout << endl;
    }
}

// Driver code
int main()
{
    int V;
    string x;
    cin>>V;
    int **g = new int *[V];
    for(int i = 0; i <V; i++)
        g[i] = new int[V];
    int i,j;
    for(i=0;i<V;i++)
    {
        for(j=0;j<V;j++)
        {
            cin>>x;
            if(x[0]!='I')
            {
                stringstream temp(x);
                temp >> g[i][j];
            }
            else
                g[i][j] = INF;

        }

    }

    // Print the solution
    floydWarshall(V, g);
    free(g);
    return 0;
}
