#include <bits/stdc++.h>

using namespace std;
#define int long long

uint64_t n, p = 83, mod = 1610612741;
vector <int> h, rh;

void hashing(string &s){
    h.resize(n + 1);
    rh.resize(n + 1);

    h[0] = 0;
    rh[0] = 0;
    int p_pow = 1;

    for(int i = 1; i <= n; i++){
        h[i] = ((h[i-1] * p) % mod + s[i - 1]) % mod;
        rh[i] = (rh[i-1] + (p_pow * s[i - 1]) % mod) % mod;

        p_pow = (p_pow*p) % mod;
    } 
}

int32_t main(){
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    n = s.size();
    hashing(s);

    vector <int> dp(n + 1, 0);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(rh[i] == h[i]) dp[i] = dp[i/2] + 1;
        ans += dp[i];
    }

    cout << ans << "\n";

    return 0;
}