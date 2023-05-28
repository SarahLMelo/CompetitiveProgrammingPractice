#include <bits/stdc++.h>

using namespace std;
#define int long long
const int mx = 2005;

double dp[mx][mx];
int vis[mx][mx];

int n, c, r;
long double p;

long double solve(int pos, int lastSave){
    if(pos == n) return 0;
    if(vis[pos][lastSave]) return dp[pos][lastSave];

    long double ans = c + solve(pos+1, pos);
    ans = min(ans, p*(r + pos - lastSave) + (1/p) * solve(pos+1, lastSave));

    return dp[pos][lastSave] = ans;
}

int32_t main(){
    cin >> n >> c >> r >> p;

    cout << solve(0, 0) + c<< "\n";
}