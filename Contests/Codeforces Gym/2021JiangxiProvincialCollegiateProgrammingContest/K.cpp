#include <bits/stdc++.h>

using namespace std;
#define int long long
// #define cin input
// #define cout output

void solve(){
    int n, m;
    cin >> n >> m;

    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans += m * i * i;
    }
    
    cout << ans << "\n";
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ofstream output;
    ifstream input;
    // output.open ("out");
    // input.open("in");
    int t;
    cin >> t;

    while(t--)
        solve();

    // output.close();
    // input.close();


    return 0;
}