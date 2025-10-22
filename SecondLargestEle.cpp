#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Fenwick Tree (BIT)
struct BIT {
    vector<int> tree;
    int n;
    BIT(int n) : n(n) { tree.assign(n + 1, 0); }
    void update(int i, int val) {
        for (++i; i <= n; i += i & -i) tree[i] += val;
    }
    int query(int i) {
        int s = 0;
        for (++i; i > 0; i -= i & -i) s += tree[i];
        return s;
    }
    int query_range(int l, int r) {
        if (l > r) return 0;
        return query(r) - (l == 0 ? 0 : query(l - 1));
    }
};

// Count subarrays with sum >= target
long long count_subarrays(vector<ll> &pref, ll target) {
    vector<ll> vals = pref;
    for (ll x : pref) vals.push_back(x - target);
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    BIT bit(vals.size());
    long long cnt = 0;
    for (ll p : pref) {
        ll want = p - target;
        int idx = upper_bound(vals.begin(), vals.end(), want) - vals.begin() - 1;
        if (idx >= 0) cnt += bit.query(idx);
        int cur = lower_bound(vals.begin(), vals.end(), p) - vals.begin();
        bit.update(cur, 1);
    }
    return cnt;
}

long long kthLargestSubarraySum(vector<int> &nums, long long k) {
    int n = nums.size();
    vector<ll> pref(n + 1, 0);
    for (int i = 0; i < n; ++i)
        pref[i + 1] = pref[i] + nums[i];

    ll lo = *min_element(nums.begin(), nums.end()) * 1ll * n;
    ll hi = *max_element(nums.begin(), nums.end()) * 1ll * n;
    ll ans = LLONG_MIN;

    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        long long count = count_subarrays(pref, mid);
        if (count >= k) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];

    cout << kthLargestSubarraySum(nums, k) << "\n";
    return 0;
}
