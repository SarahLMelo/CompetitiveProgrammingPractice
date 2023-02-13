#include <bits/stdc++.h>

using namespace std;

#define int long long

vector <vector <int>> g, dp;
int n, m, st, en;

bool dp_solve(int pos, int mask){
    if(mask == (1<<n) - 1){
        if(pos == en) return dp[pos][mask] = 1;
        else return dp[pos][mask] = 0;
    }
    if(dp[pos][mask] != -1) return dp[pos][mask];
    
    int ans = 0;
    for(auto i:g[pos]){
        if(mask & (1<<i)) continue;

        ans |= dp_solve(i, mask | (1<<i));
    }

    return dp[pos][mask] = ans;
}

string solve(){
    cin >> n >> m;

    dp.assign(n, vector <int>((1<<n), -1));
    g.assign(n, {});

    vector <char> letters(n);
    for(int i = 0; i < n; i++) cin >> letters[i];

    st = letters[0] - 'A';
    en = letters[n-1] - 'A';
    map <char, int> leg;

    sort(letters.begin(), letters.end());
    for(int i = 0; i < n; i++){
        leg[letters[i]] = i;
    }
    
    st = leg[(char)(st + 'A')];
    en = leg[(char)(en + 'A')];

    for(int i = 0; i < m; i++){
        char a, b;
        cin >> a >> b;

        g[leg[a]].push_back(leg[b]);
        g[leg[b]].push_back(leg[a]);
    }

    for(int i = 0; i < n; i++){
        sort(g[i].begin(), g[i].end());
    }

    dp_solve(st, (1 << st));

    if(dp[en][(1<<n) - 1] != 1){
        return "impossible\n";
    }

    string ans;
    ans.push_back(letters[st]);
    int mask = 1 << st, pos = st;

    while(pos != en){
        for(auto i:g[pos]){
            if(mask & (1 << i)){
                continue;
            }
            if(dp[i][mask | (1<<i)] != 1){
                continue;
            }

            mask |= (1 << i);
            pos = i;
            ans.push_back(letters[i]);
            break;
        }
    }

    return (ans+"\n");
}

int32_t main(){

    int t;
    cin >> t;

    for(int i = 1; i <= t; i++){
        cout << "Case " << i << ": " << solve();
    }


    return 0;
}