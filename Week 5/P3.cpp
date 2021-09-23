#include<vector>
#include<iostream>
using namespace std;
int main()
{
    int m,n,i,j;

    cin>>m;
    vector<int> v(m);
    for(i=0;i<m;i++)
        cin>>v[i];

    cin>>n;
    vector<int> w(n);
    for(i=0;i<n;i++)
        cin>>w[i];

    i=0;
    j=0;
    for(;(i<m && j<n);)
    {
        if(v[i]==w[j])
        {
            cout<<v[i];
            i++;
            j++;
        }
        else if(v[i]>w[j])
            j++
        else
            i++
    }

    return 0;
}
