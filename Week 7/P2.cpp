#include<limits.h>
#include<iostream>
using namespace std;

void printSolution(int v, int dist[])
{
    cout <<"Vertex \t Distance from Source" << endl;
    for (int i = 0; i < v; i++)
        cout  << i+1 << " : "<<dist[i]<< endl;
}
void BellmanFord(int v, int e, int **graph, int src)
{
    int V = v;
    int E = e;
    int dist[V];

    int edge[e][2];
    int c=0;
    int i,j;
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            if(graph[i][j]!=0)
            {
                edge[c][0] = i;
                edge[c][1] = j;
                c++;
            }
        }
    }

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edge[j][0];
            int v = edge[j][1];;
            int weight = graph[u][v];
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    for (int i = 0; i < E; i++) {
        int u = edge[i][0];
        int v = edge[i][1];;
        int weight = graph[u][v];
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle");
            return; // If negative cycle is detected, simply return
        }
    }

    printSolution(v, dist);
    return;
}
int main()
{
    int v,e=0;
    cin>>v;
    int **g = new int *[v];
    for(int i = 0; i <v; i++)
        g[i] = new int[v];
    int i,j;
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            cin>>g[i][j];
            if(g[i][j]!=0)
                e++;
        }
    }

    int s;
    cin>>s;

    BellmanFord(v, e, g, s-1);
    free(g);
    return 0;
}
