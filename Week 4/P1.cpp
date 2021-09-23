#include<vector>
#include<iostream>
using namespace std;
void merge(int arr[], int l, int mid, int r)
{
    int s1 = mid - l + 1;
    int s2 = r - mid;

    int arr1[s1], arr2[s2];

    int i,j,k = l;

    for(i=0;i<s1;i++)
        arr1[i] = arr[l+i];
    for(j=0;j<s2;j++)
        arr2[j] = arr[mid+1+j];

    while(i<s1 && j<s2)
    {
        if(arr1[i]<arr2[j])
        {
            arr[k] = arr1[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            k++;
            j++;
        }
    }
    if(i==s1)
    {
        while(j<s2)
        {
            arr[k] = arr2[j];
            k++;
            j++;
        }
    }
    else
    {
        while(i<s1)
        {
            arr[k] = arr1[i];
            k++;
            i++;
        }
    }
}
void mergeSort(int arr[], int begin, int end)
{
     if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int i,n;
        cin>>n;
        int arr[n];
        for(i=0;i<n;i++)
            cin>>v[i];

        mergeSort(arr, 0, n-1);

        for(i=0;i<n;i++)
            cout<<arr[i]<<" ";

    }
    return 0;
}
