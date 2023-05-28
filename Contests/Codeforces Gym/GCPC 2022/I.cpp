#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    int n, m;
    cin >> n >> m;

    vector <vector <int>> prices(n+1, vector <int>(m+1, 0));
    for(int i = 0; i < n; i++){
        cin >> prices[i][0];
        for(int j = 1; j < min(m+1, n - i + 1); j++){
            cin >> prices[i][j];
        }
    }

    // for(auto i:prices){
    //     for(auto j:i) cout << j << " ";
    //     cout << "\n";
    // }

    vector <int> agoravai(n+1, 1e15);
    agoravai[0] = prices[0][0];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i && j <= m; j++){
            // cout << i << " " << j << ": ";
            // cout << prices[i][0] - prices[i-j][j] + agoravai[i-j] << "\n";
            agoravai[i] = min(agoravai[i], prices[i][0] - prices[i-j][j] + agoravai[i-j]);
        }
        //prices[2][0] - prices[1][1] + dp[1]
        //300 - 300 + 300 = 300
    }

    // for(auto i:agoravai) cout << i << " ";
    // cout << "\n";

    cout << agoravai[n] << "\n";

    return 0;
} 