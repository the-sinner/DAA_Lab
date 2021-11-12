#include<limits.h>
#include<iostream>
using namespace std;

int minDistance(int v, int dist[], bool sptSet[])
{

    int min = INT_MAX, min_index;

    for (int i = 0; i < v; i++)
        if (sptSet[i] == false && dist[i] <= min)
            min = dist[i], min_index = i;

    return min_index;
}
void printSolution(int v, int dist[])
{
    cout <<"Vertex \t Distance from Source" << endl;
    for (int i = 0; i < v; i++)
        cout  << i+1 << " : "<<dist[i]<< endl;
}
void dijkstra(int v, int **graph, int src)
{
    int dist[v];

    bool sptSet[v];

    for (int i = 0; i < v; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;

    for (int count = 0; count < v - 1; count++) {

        int u = minDistance(v, dist, sptSet);

        sptSet[u] = true;

        for (int i = 0; i < v; i++)
            if (!sptSet[i] && graph[u][i] && dist[u] != INT_MAX
                && dist[u] + graph[u][i] < dist[i])
                dist[i] = dist[u] + graph[u][i];
    }

    printSolution(v, dist);
}
int main()
{
    int v;
    cin>>v;
    int **g = new int *[v];
    for(int i = 0; i <v; i++)
        g[i] = new int[v];
    int i,j;
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
            cin>>g[i][j];
    }
    int s;
    cin>>s;

    dijkstra(v, g, s-1);
    free(g);
    return 0;
}
