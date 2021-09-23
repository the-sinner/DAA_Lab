#include<vector>
#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int i,n;
        cin>>n;
        vector<char> v(n);
        for(i=0;i<n;i++)
            cin>>v[i];

        int arr[n] = {0};

        for(i=0;i<n;i++)
        {
            arr[v[i]%97]++;
        }
        int max = 0;
        char ans = 'a';

        for(i=0;i<n;i++)
        {
            if(arr[i]>max)
            {
                max = arr[i];
                ans = v[i];
            }
        }

        if(max==1)
            cout<<"No Duplicates\n";
        else
            cout<<ans<<" - "<<max<<endl;
    }
    return 0;
}
