#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve(){
    int n, k;
    cin >> n >> k;

    vector <int> ans(n);
    int aux = 0;

    for(int i = 0; i < n; i+=k){
        for(int j = 0; j < k - 1 && i+j < n; j++){
            ans[i+j] = n - (i+j);
            ans[i+j]+=aux;
        }
        if(i + k - 1 < n) ans[i+k-1] = 1 + aux;
        aux++;
    }

    for(int i = 0; i < n; i++){
        if(i) cout << " ";
        cout << ans[i];
    }
    cout << "\n";
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    
    while(t--){
        solve();
    }

    return 0;
}