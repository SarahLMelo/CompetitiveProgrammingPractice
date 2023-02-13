#include <bits/stdc++.h>

using namespace std;
#define int long long

const int mx = 16, inf = 1e9;
int dp[mx][(1<<15)], n;
vector <char> v;
vector <vector <int>> g;
int st, en;

int solve(int pos, int mask){
    if(dp[pos][mask] != -1) return dp[pos][mask];

    if(pos == en && !mask){
        cout << pos << " " << 0 << " " << 1 << endl;
        return dp[pos][mask] = 1;
    }

    dp[pos][mask] = inf;
    for(auto i:g[pos]){
        int aux = mask & (((1<<n) - 1) ^ (1 << i));
        dp[pos][mask] = min(dp[pos][mask], solve(i, aux));
    }

    dp[pos][mask]++;
    bitset<15> x(mask);
    cout << pos << " " << x << " " << dp[pos][mask] << endl;

    return dp[pos][mask];
}

int32_t main(){
    int t, cnt = 1;
    cin >> t;

    while(t--){
        int m;
        cin >> n >> m;
        memset(dp, -1, sizeof dp);
        v.resize(n);
        g.assign(n, {});

        for(int i = 0; i < n; i++){
            cin >> v[i];
            cout << v[i] << endl;
        }
        
        char in, e;
        in = v[0];
        e = v[n-1];

        sort(v.begin(), v.end());

        for(int j = 0; j < n; j++){
            if(v[j] == in){
                st = j;
                break;
            } 
        }

        for(int j = 0; j < n; j++){
            if(v[j] == e){
                en = j;
                break;
            }
        }


        for(int i = 0; i < m; i++){
            char a, b;
            cin >> a >> b;

            int u1, u2;
            for(int j = 0; j < n; j++){
                if(v[j] == a){
                    u1 = j;
                    break;
                } 
            }

            for(int j = 0; j < n; j++){
                if(v[j] == b){
                    u2 = j;
                    break;
                } 
            }

            g[u1].push_back(u2);
            g[u2].push_back(u1);
        }

        solve(en, (1<<n) - 1 & (((1<<n) - 1) ^ (1 << en)));

        string ans;
        ans.push_back(e);
        int state = (1<<en) - 1 & (((1<<n) - 1) ^ (1 << en));
        while(state || en != st){
            // cout << ans << endl;
            // cout << state << " " << en << endl;
            bool found = false;
            for(int i = 0; i < n && !found; i++){
                for(int j = 0; j < g[en].size(); j++){
                    if(g[en][j] == i){
                        // cout << i << " " << en << "\n";
                        int aux = state & (((1<<n) - 1) ^ (1 << en));
                        // cout << dp[i][aux] << " " << dp[en][state] << "\n";
                        if(dp[i][aux]+1 == dp[en][state]){
                            found = true;
                            state = aux;

                            ans.push_back(v[i]);
                            en = i;
                            break;
                        }
                    }
                }
            }
        }

        cout << ans << "\n";

    }

    return 0;
}