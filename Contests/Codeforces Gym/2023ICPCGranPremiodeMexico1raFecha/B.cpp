#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    int n, k, l;
    cin >> n >> k >> l;

    int ans = (n*k) / l;
    if(ans * l != n*k) ans++;

    cout << ans << "\n";

    return 0;
}