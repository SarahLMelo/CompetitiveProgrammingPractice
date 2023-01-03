#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve(){
    int n, m;
    cin >> n >> m;

    priority_queue <int, vector <int>, greater<int>> a;
    vector <int> b(m);
    int sum  = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;

        a.emplace(x);
    }

    for(int i = 0; i < m; i++){
        cin >> b[i];
    }

    for(int i = 0; i < m; i++){
        a.pop();
        a.emplace(b[i]);
    }

    while(!a.empty()){
        sum += a.top();
        a.pop();
    }

    cout << sum << "\n";
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