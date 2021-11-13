#include<iostream>
using namespace std;

int numChange(int n, int *arr, int sum)
{
    if(sum==0)
        return 1;

    if(sum<0)
        return 0;

    if(n==0 && sum>0)
        return 0;

    return numChange(n-1,arr,sum)+numChange(n,arr,sum-arr[n-1]);
}

int main()
{
    int n,i;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    int sum;
    cin>>sum;
    int check[n];
    memset(check,0,sizeof(check));
    cout<<numChange(n,arr,sum)<<endl;
    return 0;
}
