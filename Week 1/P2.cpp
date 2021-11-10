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
        vector<int> v(n);
        for(i=0;i<n;i++)
            cin>>v[i];
        int x;
        cin>>x;

        int l,r,mid,cnt=0,flag=0;
        l=0;
        r= n-1;

        while(l<=r)
        {
            mid = (l+r)/2;
            if(++cnt && v[mid] == x)
            {
                cout<<"Present "<<cnt<<endl;
                break;
            }
            else if(++cnt && v[mid] > x)
                r = mid-1;
            else
                l = mid+1;
        }
        if(!flag)
            cout<<"Not Present "<<cnt<<endl;
    }
    return 0;
}
