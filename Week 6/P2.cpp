#include<queue>
#include<iostream>
using namespace std;

bool bfs(int v, int **g, int s)
{
    int colorArr[v];
    memset(colorArr,-1,sizeof(colorArr));

    colorArr[s] = 1;

    queue <int> q;
    q.push(s);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        if (g[u][u] == 1)
        return false;

        for (int i = 0; i < v; i++)
        {
            if (g[u][i] && colorArr[i] == -1)
            {
                colorArr[i] = 1 - colorArr[u];
                q.push(i);
            }

            else if (g[u][i] && colorArr[i] == colorArr[u])
                return false;
        }
    }

    return true;
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
    
    bool vis[v];

    if(bfs(v,g,0))
        cout<<"Bipartite"<<endl;
    else
        cout<<"Not Bipartite"<<endl;

    free(g);
    return 0;
}
