#include<vector>
#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int i,n,x,cnt=0;
        cin>>n;
        vector<int> v(n);
        for(i=0;i<n;i++)
            cin>>v[i];
        cin>>x;
        bool flag=false;
        for(i=0;i<n;i++)
        {
            if(++cnt && x==v[i])
            {
                cout<<"Present "<<cnt<<endl;
                flag=true;
                break;
            }
        }
        if(!flag)
        {
            cout<<"Not Present\n";
        }
    }

    return 0;
}
