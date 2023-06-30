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
    vector <int> ans(n+1, 0);
    for(int i = 0; i < ans.size() - 1; i++){
        n = s.size();
        hashing(s);
        vector <int> dp(n + 1, 0);
        for(int j = 1; j <= n; j++){
            if(rh[j] == h[j]){
                dp[j] = dp[j/2] + 1;
            }
            ans[dp[j]]++;
        }
        if(s.size() > 1)
            s = s.substr(1, s.size() - 1);
    }

    for(int i = ans.size() - 2; i >= 1; i--)
        ans[i] += ans[i+1];
    
    for(int i = 1; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}