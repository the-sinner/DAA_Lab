#include<vector>
#include<iostream>
using namespace std;

bool dfs(int v, int **g, bool vis[v], int s, int d)
{
    if(s==d)
        return true;
    vis[s] = true;
    int i;
    for(i=0;i<v;i++)
    {
        if(g[s][i] && !vis[i])
        {
            return dfs(v,g,vis,i,d);
        }
    }
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
    int s,d;
    cin>>s>>d;

    bool vis[v];

    if(dfs(v,g,vis,s-1,d-1))
        cout<<"Yes Path Exists"<<endl;
    else
        cout<<"No Such Path Exists"<<endl;
    free(g);
    return 0;
}
