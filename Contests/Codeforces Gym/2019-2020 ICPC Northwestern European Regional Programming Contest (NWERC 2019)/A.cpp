#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << setprecision(9) << fixed;

    int n, w;
    cin >> n >> w;

    vector <int> rank(w+5, 1), scores(n+5, 0), sum(w+5, 0), lastUpdate(w+5, 0), ans(n+5, 0);

    for(int i = 0; i < w; i++){
        int x;
        cin >> x;

        for(int j = 0; j < x; j++){
            int p;
            cin >> p;

            int u = scores[p];
            scores[p]++;
            sum[u] += rank[u] * (i - lastUpdate[u]);
            lastUpdate[u] = i;

            sum[u+1] += rank[u+1] * (i - lastUpdate[u+1]);
            lastUpdate[u+1] = i;

            ans[p] += sum[u] - sum[u+1];
            rank[u]++;
        }
    }

    for(int i = 1; i <= n; i++){
        int u = scores[i];

        // cout << rank[u] << " " << u << " " << lastUpdate[u] << "\n";
        // cout << ans[i] << "\n";
        sum[u] += rank[u] * (w - lastUpdate[u]);
        // cout << sum[u] << "\n";
        lastUpdate[u] = w;
        
        ans[i] += sum[u];
        cout << (long double)ans[i] / (w) << "\n";
    }

    return 0;
}