#include <iostream>
using namespace std;

// Matrix Ai has dimension p[i-1] x p[i]
// for i = 1..n
int m[5][5];

int MatrixChainOrder(int p[], int i, int j)
{
    if (i == j)
    {
        return 0;
    }
    if(m[i][j]!=-1)
        return m[i][j];

    int k;
    int min = INT_MAX;
    int count = 0;


    for (k = i; k < j; k++)
    {
        count = MatrixChainOrder(p, i, k)
                + MatrixChainOrder(p, k + 1, j)
                + p[i - 1] * p[k] * p[j];

        if (count < min)
            min = count;
    }

    // Return minimum count
    m[i][j] = min;
    return min;
}

// Driver Code
int main()
{
    memset(m,-1,sizeof(m));
    int n,i;
    cin>>n;
    int arr[n+1];

    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        cin>>arr[i+1];
    }
    n++;
    /*
    int n = 4;
    int arr[4] = {10,30,5,60};
    */
    cout<< MatrixChainOrder(arr, 1, n-1);
}
