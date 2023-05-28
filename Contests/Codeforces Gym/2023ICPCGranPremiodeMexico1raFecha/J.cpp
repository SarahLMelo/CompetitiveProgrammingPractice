#include <bits/stdc++.h>

using namespace std;
// #define int long long

const int mod = 1e9 + 7;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector <int> v(n), ps(n+1, 0), ql(n+1, 0), qr(n+1, 0);

    for(int i = 0; i < n; i++){
        cin >> v[i];

        ps[i+1] = (ps[i] + v[i]) % mod;
        qr[i+1] = (qr[i] + (ps[i] * v[i]) % mod) % mod;
    }

    for(int i = 0; i < n; i++){
        ql[i+1] = (ql[i] + (v[i] * ((ps[n] - ps[i+1] + mod) % mod)) % mod) % mod;
    }

    while(q--){
        int l, r;
        cin >> l >> r;

        int ans = qr[r];
        ans = (mod + ans - (mod + ql[l-1] - ((ps[l - 1] * (ps[n] - ps[r] + mod) % mod))) % mod) % mod;
        if(l == r) ans += v[l-1];
        cout << ans << "\n";
    }

    return 0;
}