#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MAXN = 3e5 + 5;
int dp[MAXN][2], vis[MAXN][2], n;
vector <int> value, type;

int solve(int pos, bool healthy){
    if(pos == n) return 0;

    int &ans = dp[pos][healthy];
    if(vis[pos][healthy]) return ans;

    vis[pos][healthy] = true;

    ans = solve(pos+1, healthy); //Não comi
    if(!type[pos])
        ans = max(ans, value[pos] + solve(pos+1, 1));
    else if(healthy)
        ans = max(ans, value[pos] + solve(pos+1, 0));

    return ans;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    value.resize(n);
    type.resize(n);

    for(int i = 0; i < n; i++){
        cin >> type[i] >> value[i];
    }

    cout << solve(0, 1) << "\n";

    return 0;
}