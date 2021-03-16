
#include <bits/stdc++.h>
using namespace std;

// A function to implement count sort
void CountSort(int a[], int n)
{
    int max = *max_element(a, a + n);
    int min = *min_element(a, a + n);
    int range = max - min + 1;

    vector<int> count(range, 0), output(n);
    for (int i = 0; i < n; i++)
        count[a[i] - min]++;

    for (int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[a[i] - min] - 1] = a[i];
        count[a[i] - min]--;
    }

    for (int i = 0; i < n; i++)
        a[i] = output[i];
}

// Driver code
int main()
{
    int a[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(a) / sizeof(a[0]);
    CountSort(a, n);
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}