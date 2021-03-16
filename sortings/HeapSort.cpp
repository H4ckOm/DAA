#include <bits/stdc++.h>
using namespace std;

// To heapify a subtree rooted with node i which is
// an index in a[]. n is size of heap
void heapify(int a[], int n, int i)
{
    int largest = i;   // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && a[l] > a[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && a[r] > a[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(a[i], a[largest]);
        // Recursively heapify the affected sub-tree
        heapify(a, n, largest);
    }
}

// main function to do heap sort
void HeapSort(int a[], int n)
{
    // Build heap (reaange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--)
    {
        // Move current root to end
        swap(a[0], a[i]);
        // call max heapify on the reduced heap
        heapify(a, i, 0);
    }
}

int main()
{
    int a[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(a) / sizeof(a[0]);
    HeapSort(a, n);
    cout << "Sorted array is \n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}
