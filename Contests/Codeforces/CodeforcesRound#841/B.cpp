#include <bits/stdc++.h>

using namespace std;
#define int long long

const int mod = 1e9+7;

int fExp(int a, int b){
    int ans = 1;

    while(b){
        if(b&1) ans = (ans * a) % mod;

        a = a*a %mod;
        b >>= 1;
    }

    return ans;
}

int32_t main(){
    int t;
    cin >> t;

    while(t--){
        int x;
        cin >> x;

        int ans = ((((((x * (x+1))%mod) * (2*x + 1)%mod)*fExp(6, mod - 2))%mod)*2022) % mod;
        ans = (ans + (2022*(((((x*(x-1)) % mod) * (x+1)%mod) * fExp(3, mod - 2))%mod) % mod)%mod) % mod;

        cout << ans << "\n";
    }


    return 0;
}