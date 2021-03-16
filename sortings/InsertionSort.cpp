#include <bits/stdc++.h>
using namespace std;

// A function to implement insertion sort
void InsertionSort(int a[], int n)
{
    int key, j;
    for (int i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are 
		greater than key, to one position ahead 
		of their current position */
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

// Driver code
int main()
{
    int a[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(a) / sizeof(a[0]);
    InsertionSort(a, n);
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}