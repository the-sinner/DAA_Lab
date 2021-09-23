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
        int i,j,x,n,cnt=0;
        cin>>n;
        vector<int>v(n);
        for(i=0;i<n;i++)
            cin>>v[i];
        cin>>x;
        unordered_map<int,int>mp;
        for(i=0;i<n;i++)
        {
            //mp.insert({ v[i],i });
            mp[v[i]] = i;
        }

        int flag=0;
        for(i=0;i<n;i++)
        {
            int temp = v[i]+x;
            if(mp.find(temp) != mp.end())
            {
                cnt++;
            }
        }

        cout<<cnt<<"\n";
    }
    return 0;
}
