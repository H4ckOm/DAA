#include <bits/stdc++.h>
using namespace std;

// A function to implement bubble sort
void bubbleSort(int a[], int n)
{
    bool is_swap = 0;
    for (int i = 0; i < n - 1; i++)
    {
        is_swap = 0;
        // Last i elements are already in place
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                is_swap = 1;
            }
        if (is_swap == 0)
            break;
    }
}

// Driver code
int main()
{
    int a[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(a) / sizeof(a[0]);
    bubbleSort(a, n);
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}