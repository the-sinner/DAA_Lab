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
        int cnt=0,flag=0;
        for(i=1;i<=n;i*=2)
        {
            if(++cnt && v[i-1] == x)
            {
                cout<<"Present "<<cnt<<endl;
                flag=1;
                break;
            }
            else if(++cnt && v[i-1] > x)
            {
                int j;
                for(j=i-2;j>=i/2;j--)
                {
                    if(++cnt && v[j]==x)
                    {
                        cout<<"Present "<<cnt<<endl;
                        flag=1;
                        break;
                    }
                }
            }
        }
        if(!flag)
            cout<<"Not Present "<<cnt<<endl;
    }
    return 0;
}
