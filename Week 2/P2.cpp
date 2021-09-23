#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int i,j,k,n;
        cin>>n;
        vector<int>v(n);
        for(i=0;i<n;i++)
            cin>>v[i];

        unordered_map<int,int>mp;
        for(i=0;i<n;i++)
        {
            //mp.insert({ v[i],i });
            mp[v[i]] = i;
        }
        int flag=0;
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                int temp = v[i]+v[j];
                if(mp.find(temp) != mp.end())
                {
                    k = mp[temp];
                    cout<<i<<", "<<j<<", "<<k<<endl;
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                break;
        }

        if(flag==0)
            cout<<"No sequence found\n";
    }
    return 0;
}
