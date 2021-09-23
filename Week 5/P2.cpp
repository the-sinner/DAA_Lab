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
            int temp = x - v[i];
            if(mp.find(temp) != mp.end())
            {
                cout<<x<<mp[temp]<<endl;
                flag=1;
            }
        }
        if(flag==0)
            cout<<"No such pair exists\n";
    }
    return 0;
}
