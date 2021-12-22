#include <bits/stdc++.h>
using namespace std;

int fastMaxSum(const vector<int> &A, int lo, int hi)
{
    if (lo == hi)
        return A[lo];

    int mid = (hi + lo) / 2;

    int left = MIN, right = MIN, sum = 0;

    for (int i = mid; i >= lo; --i)
    {
        sum += A[i];
        left = max(left, sum);
    }

    sum = 0;

    for (int i = mid + 1; i <= hi; ++i)
    {
        sum += A[i];
        right = max(right, sum);
    }

    int single = max(fastMaxSum(A, lo, mid), fastMaxSum(A, mid + 1, hi));
    return max(left + right, single);
}