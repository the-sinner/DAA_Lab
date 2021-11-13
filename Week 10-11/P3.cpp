#include<unordered_map>
#include<iostream>
using namespace std;
int main()
{
    int n,i;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    unordered_map<int,int> mp;

    for(i=0;i<n;i++)
    {
        mp[arr[i]]++;
    }
    bool flag = false;
    int temp;
    for(auto x : mp)
    {
        if(x.second > n/2)
        {
            flag = true;
            temp = x.first;
        }
    }
    cout<<(flag?"Yes\n":"No\n");
    if(!flag)
    {
        sort(arr,arr+n);
        if (n % 2 != 0)
            cout<<arr[n/2];
        else
            cout<<(arr[(n-1)/2] + arr[n/2])/2;
    }
    else
    {
        cout<<temp;
    }

    return 0;
}
