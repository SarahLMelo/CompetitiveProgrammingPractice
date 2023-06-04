#include <bits/stdc++.h>

using namespace std;

const int mx = 105;
int dp[mx][mx][2][2];
bool vis[mx][mx][2][2];

int solve(int x, int y, bool player, bool blackCorner){
    // cout << x << " " << y << " " << (player ? "Irma" : "Eu") << " " << (blackCorner ? "Preto" : "Branco") << "\n";
    int &ans = dp[x][y][player][blackCorner];
    if(y == 1 && !player) return ans = (x & 1 ? (blackCorner ? 1:-1) : 0);
    if(x == 1 && player){
        ans = (y & 1 ? (blackCorner ? -1:1) : 0);
        return ans;
    }
    if(vis[x][y][player][blackCorner]) return ans;

    vis[x][y][player][blackCorner] = 1;


    if(!player){
        ans = (x*y & 1 ? (blackCorner ? 1:-1): 0);
        for(int i = 1; i < y; i++){
            ans = max(ans, solve(x, y - i, !player, i&1 ? !blackCorner:blackCorner) + ((x*i & 1) ? (blackCorner ? 1:-1) : 0));
        }
    }
    else{
        ans = (x*y & 1 ? (blackCorner ? -1:1): 0);
        for(int i = 1; i < x; i++){
            ans = min(ans, ((i*y & 1) ? (blackCorner ? (x & 1 ? -1 : 1) : (x & 1 ? 1 : -1)) : 0) + solve(x - i, y, !player, blackCorner));
            // cout << x << " " << y << " " << (player ? "Irma" : "Eu") << " " << (blackCorner ? "Preto" : "Branco") << "\n";
            // cout << i << " " << ((i*y & 1) ? (blackCorner ? (x & 1 ? -1 : 1) : (x & 1 ? 1 : -1)) : 0) + solve(x - i, y, !player, blackCorner) << "\n";
        }
        // cout << ans << "\n";
    }   
        return ans;
}

int main(){
    int p, q;
    cin >> p >> q;

    cout << solve(p, q, 0, 1) << "\n";
}