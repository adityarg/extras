// https://cp-algorithms.com/sequences/longest_increasing_subsequence.html

// This time d[i] will be the element at which a subsequence of length i
// terminates. If there are multiple such sequences, then we take the one
// that ends in the smallest element.

// The array d will always be sorted: d[i−1]<=d[i] for all i=1...n.
// And also the element a[i] will only update at most one value d[j].
int Solution::lis(const vector<int> &a)
{
    int n = a.size();
    const int INF = 1e9;
    vector<int> d(n+1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        int j = lower_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (a[i] < d[j]) d[j] = a[i];
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (d[i] < INF)
            ans = i;
    }
    return ans;
}