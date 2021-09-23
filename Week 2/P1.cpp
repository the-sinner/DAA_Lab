#include<vector>
#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,x,cnt=0;
        cin>>n;
        vector<int> v(n);
        for(i=0;i<n;i++)
            cin>>v[i];
        cin>>x;

        int first=-1,last=-1;
        int l,r,mid;
        l=0;
        r= n-1;

        while(l<=r)
        {
            mid = (l+r)/2;

            if(v[m] == x)
            {
                first = m;
                l = m-1;
            }
            else if(v[m]<x)
                r= m-1;
            else
                l = m+1;
        }
        while(l<=r)
        {
            mid = (l+r)/2;

            if(v[m] == x)
            {
                last = m;
                r = m+1;
            }
            else if(v[m]<x)
                r= m-1;
            else
                l = m+1;
        }

        if(last == -1 && first == -1)
        {
            cout<<"Key not present\n";
        }
        else
            cout<<x<<" - "<<last-first+1<<endl;
    }

    return 0;
}
