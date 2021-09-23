#include <climits>
#include <iostream>
using namespace std;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int r)
{
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= x) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

int kthSmallest(int arr[], int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1) {
        int pos = partition(arr, l, r);

        if (pos - l == k - 1)
            return arr[pos];
        if (pos - l > k - 1)
            return kthSmallest(arr, l, pos - 1, k);

        return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
    }
    return INT_MAX;
}



int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int i,n,k;
        cin>>n;
        int arr[n];
        for(i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        cout <<kthSmallest(arr, 0, n - 1, k);
    }

    return 0;
}
