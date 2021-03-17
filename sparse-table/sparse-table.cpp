#include <bits/stdc++.h>
using namespace std;

struct sparse_table
{
    // 0 indexed everything
    vector<vector<long long>> st;
    int n;
    long long f(long long x, long long y)
    {
        return min(x, y);
    }
    void init(vector<long long> &a)
    {
        n = a.size();
        int K = log2(n) + 1;
        st.resize(n + 1);
        for (int i = 0; i <= n; i++)
            st[i].resize(K + 1);
        for (int i = 0; i < n; i++)
            st[i][0] = a[i];
        for (int j = 1; j <= K; j++)
            for (int i = 0; i + (1 << j) <= n; i++)
                st[i][j] = f(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
    long long getSum(int l, int r)
    {
        long long sum = 0;
        for (int j = log(n) + 1; j >= 0; j--)
        {
            while ((1 << j) <= (r - l + 1))
            {
                sum += st[l][j];
                l += (1 << j);
            }
        }
        return sum;
    }
    long long getMin(int l, int r)
    {
        int p = log2(r - l + 1);
        return min(st[l][p], st[r - (1 << p) + 1][p]);
    }
    long long getMax(int l, int r)
    {
        int p = log2(r - l + 1);
        return max(st[l][p], st[r - (1 << p) + 1][p]);
    }
};
int main()
{
}