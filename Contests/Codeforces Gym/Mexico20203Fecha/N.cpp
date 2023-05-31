#include <bits/stdc++.h>

using namespace std;


#define int long long

const int mxd = 5005, mxa = 105, inf = 1e15;
int dp[mxa][mxd];
int d, m;
vector <int> antenna, tree;

void build(int i, int n, int l, int r){
    if(l == r){
        tree[n] = dp[i][l];
        return;
    }

    int mid = (l+r)/2;
    build(i, 2*n, l, mid); build(i, 2*n + 1, mid + 1, r);

    tree[n] = min(tree[2*n], tree[2*n + 1]);
}

void update(int n, int l, int r, int p, int val){
    if(l == r){
        tree[n] = val;
        return;
    }

    int mid = (l+r)/2;
    if(mid <= p) update(2*n, l, mid, p, val);
    else update(2*n + 1, mid + 1, r, p, val);

    tree[n] = min(tree[2*n], tree[2*n + 1]);
}

int query(int n, int l, int r, int L, int R){
    if(l > R || r < L) return 1e18;
    if(L <= l && r <= R) return tree[n];

    int mid = (l+r)/2;
    return min(query(2*n, l, mid, L, R), query(2*n + 1, mid + 1, r, L, R));
}

int check(int f){
    for(int i = 0; i < mxa; i++)
        for(int j = 0; j < mxd; j++)
            dp[i][j] = 1e18;

    for(int i = 0; i <= d; i++){
        if(i <= f) dp[0][i] = abs(antenna[0] - i);
        else dp[0][i] = 1e18;
    }

    tree.assign(4*d + 5, 1e18);
    build(0, 1, 0, d);

    for(int i = 1; i < m; i++){
        for(int j = 0; j <= d; j++){
            dp[i][j] = query(1, 0, d, max(j - f, 0LL), j) + abs(j - antenna[i]);
        }
        tree.assign(4*d + 5, 1e18);
        build(i, 1, 0, d);
    }

    // if(f == 10){
    //     cout << dp[0][0] << " " << dp[1][10] << "\n";
    // }

    return query(1, 0, d, d - f, d);
}

int32_t main(){
    int b; cin >> d >> b >> m;
    antenna.resize(m);
    for(int i = 0; i < m; i++) cin >> antenna[i];

    sort(antenna.begin(), antenna.end());

    int l = 0, r = d+1;
    // cout << check(9) << " " << check(10) << "\n";
    while(l < r){
        int mid = (l+r)/2;

        if(check(mid) <= b) r = mid;
        else l = mid + 1;
    }

    cout << l << "\n";

    return 0;
}