
#include <bits/stdc++.h>
using namespace std;

void merge(int a[], int left_low, int left_high, int right_low, int right_high)
{
    int length = right_high - left_low + 1;
    int temp[length];
    int left = left_low;
    int right = right_low;
    for (int i = 0; i < length; ++i)
    {
        if (left > left_high)
            temp[i] = a[right++];
        else if (right > right_high)
            temp[i] = a[left++];
        else if (a[left] <= a[right])
            temp[i] = a[left++];
        else
            temp[i] = a[right++];
    }

    for (int i = 0; i < length; ++i)
        a[left_low++] = temp[i];
}
void MergeSort(int a[], int low, int high)
{
    if (low >= high) //Base case: 1 value to sort->sorted
        return;      //(0 possible only on initial call)
    else
    {
        int mid = (low + high) / 2;        //Approximate midpoint*
        MergeSort(a, low, mid);            //Sort low to mid part of array
        MergeSort(a, mid + 1, high);       //Sort mid+1 to high part of array
        merge(a, low, mid, mid + 1, high); //Merge sorted subparts of array
    }
}

// Driver code
int main()
{
    int a[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(a) / sizeof(a[0]);
    MergeSort(a, 0, n - 1);
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}