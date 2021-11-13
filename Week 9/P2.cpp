#include<iostream>
using namespace std;

int max_p(int n, float *pr)
{
    int i,a;
    float x=pr[0];
    for(i=1;i<n;i++)
    {
        if(pr[i]>x)
        {
            x = pr[i];
            a = i;
        }
    }
    return a;
}

void printSol(int n, float *val, float profit)
{
    cout<<"Maximum Value : "<<profit<<endl;
    cout<<"Item - Taken"<<endl;

    int i;
    for(i=0;i<n;i++)
    {
        cout<<i+1<<" - "<<1 - val[i]<<endl;
    }

}

void f_knapsack(int n,float *w,float *val,int cap)
{
    float profit_ratio[n];
    float profit=0.0;
    for(int i=0;i<n;i++)
    {
        profit_ratio[i] = val[i]/w[i];
    }
    float max_w = cap;
    while(max_w>0)
    {
        int j = max_p(n, profit_ratio);
        if(w[j]>max_w)
        {
            profit+=(val[j]*(max_w/w[j]));
            val[j] -= (max_w/w[j]);
            max_w = 0;
        }
        else
        {
            profit+=val[j];
            max_w-=w[j];
            profit_ratio[j] = -1;
            val[j] = 0;
        }
    }
    printSol(n,val,profit);
}

int main()
{
    int n;
    cin>>n;
    float w[n],val[n];
    int i,cap;
    for(i=0;i<n;i++)
        cin>>w[i];
    for(i=0;i<n;i++)
        cin>>val[i];
    cin>>cap;

    f_knapsack(n,w,val,cap);
    return 0;
}
