#include <bits/stdc++.h>

using namespace std;
// #define int long long
// #define cin input
// #define cout output

const int mod = 998244353;
int dp[500][500*500+5][2];

void solve(){
    int n, m, p, q;
    cin >> n >> m >> p >> q;

    int g[n][m];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cin >> g[i][j];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!i && !j){
                if(g[i][j]) dp[i][0][1] = 1;
                else dp[i][1][1] = 1;
                continue;
            }

            for(int k = 0; k < n+m; k++){
                if(g[i][j]){ //se a posição que eu tô é 1
                    if(!k) dp[j][0][0] = 0;
                    else{
                        
                    }
                }
                else{

                }
            }
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    // ofstream output;
    // ifstream input;
    // output.open ("out");
    // input.open("in");

    solve();

    // output.close();
    // input.close();


    return 0;
}