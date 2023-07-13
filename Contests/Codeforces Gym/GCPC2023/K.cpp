#include <bits/stdc++.h>

using namespace std;
#define int long long

const int mod = 1e9+7, MAXH = 5005, MAXN = 1e6 + 5;
int dp[MAXH], h, fact[MAXN];
vector <int> knights;

int solve(int n, int h_rem){
    if(!h_rem) return fact[n];
    if(~dp[h_rem]) return dp[h_rem];

    dp[h_rem] = fact[n];
    int sum = 0;
    for(int i = h_rem; i > 0; i--){
        sum += knights[h - i];
        dp[h_rem] = ((dp[h_rem] - (fact[sum] * solve(n - sum, i-1)) % mod) + mod) % mod;
    }

    return dp[h_rem];
}

int32_t main(){
    fact[0] = 1;
    for(int i = 1; i < MAXN; i++){
        fact[i] = (i*fact[i-1]) % mod;
    }

    int n;
    cin >> n >> h;

    memset(dp, -1, sizeof dp);
    knights.resize(h);

    for(int i = 0; i < h; i++)
        cin >> knights[i];
    
    cout << solve(n, h) << "\n";

    return 0;
}