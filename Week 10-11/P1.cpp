#include<vector>
#include<iostream>
using namespace std;

struct job
{
    int start,finish,pos_i,pos_f;
};
bool jobCompare(job j1, job j2)
{
    return (j1.finish < j2.finish);
}

void jobSC(int n, job *j)
{
    sort(j,j+n,jobCompare);
    for(int i=0;i<n;i++)
        j[i].pos_f = i;
    bool select[n];
    memset(select,false,sizeof(select));
    int x=0,c=0;
    select[0] = true;
    c++;
    for(int i=1;i<n;i++)
    {
        if(j[i].start >= j[x].finish)
        {
            select[i] = true;
            x = i;
            c++;
        }
    }

    cout<<"No. of non-conflicting activities : "<<c<<endl;
    cout<<"List of selected activities : ";
    for(int i=0;i<n;i++)
    {
        if(select[i])
        {
            cout<<j[i].pos_f + 1<<", ";
        }
    }
}

int main()
{
    int n,i;
    cin>>n;
    job j[n];
    for(i=0;i<n;i++)
        cin>>j[i].start;
    for(i=0;i<n;i++)
        cin>>j[i].finish;
    for(i=0;i<n;i++)
        j[i].pos_i = i;
    jobSC(n,j);
    return 0;
}
