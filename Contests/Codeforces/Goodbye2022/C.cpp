#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve(){
    int n;
    cin >> n;

    vector <int> v(n);
    int even = 0, odd = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(v[i] & 1) odd++;
        else even++;
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    
    if(v.size() != n || even > 1 && odd > 1) cout << "NO\n";
    else{
        bool found = false;
        for(auto x:primes){
            found = true;

            for(int i = 0; i < n && found; i++){
                for(int j = i+1; j < n && found; j++){
                    if(x == 2) cout << x + v[i] << " " << x + v[j] << "\n";
                    if(__gcd(x + v[i], x + v[j]) != 1){
                        found = false;
                        break;
                    }
                }
            }

            if(found) break;
        }

        cout << (found ? "YES\n":"NO\n");

    }
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