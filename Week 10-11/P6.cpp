#include<vector>
#include<iostream>
using namespace std;

bool partition(int n, int *arr, int sum)
{
    if(sum<0)
        return false;
    if(sum==0)
        return true;
    if(n==0)
        return false;


    return partition(n-1,arr,sum) + partition(n,arr,sum - arr[n-1]);
}

int main()
{
    int n,i;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];

    int sum = 0;

    for(i=0;i<n;i++)
        sum+=arr[i];

    if(sum%2!=0)
        cout<<"no\n";
    else
    {
        if(partition(n,arr,sum/2))
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}
