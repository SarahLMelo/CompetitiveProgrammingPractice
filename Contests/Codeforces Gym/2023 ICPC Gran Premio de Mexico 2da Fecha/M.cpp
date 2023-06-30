#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MAXN = 5e3 + 5, mod = 998244353;
int dp[MAXN], n;
vector <int> v;

int solve(int pos){
    int &ans = dp[pos];
    if(~ans) return ans;

    int mn = n+1;
    ans = 0;
    for(int i = pos + 1; i <= n; i++){
        if(mn > v[pos] || mn > v[i]){
            ans = (ans + solve(i)) % mod;
        }

        mn = min(v[i], mn);
    }
    if(v[pos] < mn) ans = (ans + 1) % mod;

    return ans;
}

int32_t main(){
    cin >> n;
    memset(dp, -1, sizeof dp);

    v.resize(n+1);
    v[0] = n+2;
    for(int i = 1; i <= n; i++)
        cin >> v[i];

    cout << solve(0) << "\n";

}