#include <bits/stdc++.h>

using namespace std;
#define int long long

const int mx = 5e3 + 5;
int dp[mx][mx], n;
vector <tuple <int, int, int, int>> v;

int solve(int pos, int last){
    if(pos > n) return 0;
    if(dp[pos][last] != -1) return dp[pos][last];

    int ans = solve(pos+1, last);
    int xl, yl, tl, vl, xp, yp, tp, vp;
    tie(tl, xl, yl, vl) = v[last];
    tie(tp, xp, yp, vp) = v[pos];

    // cout << pos << " " << last << "\n";
    // cout << (xp - xl) * (xp - xl) + (yp - yl) * (yp - yl) << " " << (tl - tp) * (tl - tp) << "\n";

    if((xp - xl) * (xp - xl) + (yp - yl) * (yp - yl) <= (tl - tp) * (tl - tp)){
        ans = max(ans, solve(pos+1, pos) + vp);
    }

    return dp[pos][last] = ans;
}

int32_t main(){
    cin >> n;

    memset(dp, -1, sizeof dp);
    
    v.emplace_back(0, 0, 0, 0);
    for(int i = 0; i < n; i++){
        int x, y, t, val;
        cin >> x >> y >> t >> val;

        v.emplace_back(t, x, y, val);
    }

    sort(v.begin(), v.end());

    cout << solve(0, 0) << "\n";

    return 0;
}