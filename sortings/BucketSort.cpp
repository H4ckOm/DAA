#include <bits/stdc++.h>
using namespace std;

// to sort the array using bucket sort
void bucketSort(float arr[], int n)
{

    vector<float> b[n];
    // Put array elements in different buckets
    for (int i = 0; i < n; i++)
    {
        int bi = n * arr[i]; // Index in bucket
        b[bi].push_back(arr[i]);
    }
    // sorting the buckets
    for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());
    // add all the buckets into arr.
    int idx = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr[idx++] = b[i][j];
}
int main()
{
    float arr[] = {0.878, 0.463, 0.616, 0.1234, 0.665, 0.3154};
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);
    cout << "here is the sorted array: \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}