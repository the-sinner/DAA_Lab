#include<vector>
#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int i,n;
        cin>>n;
        vector<int>v(n);
        for(i=0;i<n;i++)
            cin>>v[i];
        int min = v[0],temp;
        int flag=0,l = 0;
        int comp=0,swap = 0;
        for(j=0;j<n-1;j++)
        {
            for(i=j+1;i<n;i++)
            {
                if(++comp && v[i]<min)
                {
                    min = v[i];
                    l = i;
                    flag=1;
                }
            }
            if(flag)
            {
                swap+=3;
                temp = v[l];
                v[l] = v[j];
                v[j] = min;
                flag=0;
            }
        }

        for(i=0;i<n;i++)
            cout<<v[i]<<" ";
        cout<<endl<<"Comparisons = "<<comp<<"\nSwaps = "<<swap<<endl;
    }
    return 0;
}
