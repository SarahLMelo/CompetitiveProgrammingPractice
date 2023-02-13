#include <bits/stdc++.h>

using namespace std;
#define int long long

const int mx = 2e5 + 5;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector <int> v(n), pref(n+1, 0);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++){
        pref[i+1] = v[i] + pref[i];
    }

    for(int i = 0; i < m; i++){
        int q;
        cin >> q;

        int pos = lower_bound(v.begin(), v.end(), q) - v.begin();
        cout << pref[pos] + (n - pos) * q << "\n";
    }

    return 0;
}