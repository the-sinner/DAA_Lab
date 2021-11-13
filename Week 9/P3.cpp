#include<iostream>
#include <vector>
#include <queue>
using namespace std;

int minComp(int n, int *arr)
{
    priority_queue <int, vector<int>, greater<int> > pq;
    int cost=0,a,b,sum;

    for(int i=0;i<n;i++)
    {
        pq.push(arr[i]);
    }
    while (pq.empty() == false)
    {
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        sum = a+b;
        cost+=sum;
        pq.push(sum);
    }
    return cost;
}

int main()
{
    int i,n;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<minComp(n,arr)<<endl;
    return 0;
}
