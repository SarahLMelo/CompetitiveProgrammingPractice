#include <bits/stdc++.h>

using namespace std;
#define int long long

const int mx = 101, ms = (1<<10);
bool dp[mx][mx][ms];
int tab[mx][mx], n, m;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

void solve(int x, int y, int mask){
    if(dp[x][y][mask]) return;

    if(mask & (1 << (tab[x][y] - 1))){
        dp[x][y][mask] = true;

        for(int i = 0; i < 4; i++){
            if(x + dx[i] < n && x + dx[i] >= 0 && y + dy[i] < m && y + dy[i] >= 0){
                solve(x + dx[i], y + dy[i], mask|(1 << (tab[x + dx[i]][y + dy[i]] - 1)));
            }
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    a--;
    b--;
    c--;
    d--;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> tab[i][j];
        }
    }

    for(int i = 0; i < 10; i++){
        solve(a, b, (1<<i));
    }

    int minx = 15;
    for(int i = 0; i < (1<<10); i++){
        if(dp[c][d][i]){
            int aux = __builtin_popcountll(i);
            minx = min(aux, minx);
        }
    }

    cout << minx << "\n";

    return 0;
}