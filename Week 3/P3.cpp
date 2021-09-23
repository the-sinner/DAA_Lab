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
        vector<int>v(n);
        for(i=0;i<n;i++)
            cin>>v[i];

        int j,key;
        bool flag = false;

        for(i=1;i<n;i++)
        {
            key = v[i];

            for(j = i-1;(j>0 && v[j] > key);j--)
            {
                v[j+1] = v[j];
            }
            if(v[j] == key)
            {
                flag = true;
                break;
            }
            v[j+1] = key;
        }
        if(flag)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
