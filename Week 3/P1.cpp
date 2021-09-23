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

        int j,key,shif=0,comp=0;

        for(i=1;i<n;i++)
        {
            key = v[i];

            for(j = i-1;(j>0 && ++comp && v[j] > key);j--)
            {
                shif++;
                v[j+1] = v[j];
            }
            v[j+1] = key;
        }

        for(i=0;i<n;i++)
            cout<<v[i]<<" ";
        cout<<endl<<"Comparisons = "<<comp<<"\nShifts = "<<shif<<endl;
    }
    return 0;
}
