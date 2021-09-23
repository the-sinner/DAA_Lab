#include<vector>
#include<math>
#include<iostream>
using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
} 

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

quickSort(int arr[], int low, int high)
{
    if (low < high)
        {
            int p = partition(arr, low, high);

            quickSort(arr, low, p - 1);
            quickSort(arr, p + 1, high);
        }
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
            cin>>arr[i];


        quickSort(arr,0,n-1);

        for(i=0;i<n;i++)
            cout<<arr[i]<<" ";
    }
    return 0;
}
