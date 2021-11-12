#include<vector>
#include<iostream>
using namespace std;

bool isCyclicUtil(int **g, int v, int i, bool *visited, bool *recStack)
{
    if(visited[v] == false)
    {
        // Mark the current node as visited and part of recursion stack
        visited[v] = true;
        recStack[v] = true;

        // Recur for all the vertices adjacent to this vertex
        int j;
        for(j = 0; j < v; ++j)
        {
            if (g[i][j] && !visited[j] && isCyclicUtil(g, v, j, visited, recStack) )
                return true;
            else if (recStack[j])
                return true;
        }

    }
    recStack[v] = false;  // remove the vertex from recursion stack
    return false;
}
bool cyc(int **g, int v)
{
    bool *visited = new bool[v];
    bool *recStack = new bool[v];
    for(int i = 0; i < v; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }

    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for(int i = 0; i < v; i++)
        if (isCyclicUtil(g, v, i, visited, recStack))
            return true;

    return false;
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

    if(cyc(g,v))
        cout<<"Yes Cycle Exists"<<endl;
    else
        cout<<"No Cycle Exists"<<endl;

    free(g);
    return 0;
}
