#include <bits/stdc++.h>

using namespace std;
vector <vector <int>> g;
vector <tuple <int, int, int>> ans;
vector <int> t, vis;

bool dfs(int u, int par){
    vector <int> candidates;

    for(auto i:g[u]){
        if(i == par) continue;
        if(vis[i]){
            if(t[i] > t[u]) continue;
            candidates.push_back(i);
        }
        else{
            vis[i] = 1;
            t[i] = t[u] + 1;
            if(dfs(i, u)) candidates.push_back(i);
        }
    }

    candidates.push_back(par);

    for(int i = 0; i+1 < candidates.size(); i+=2){
        ans.emplace_back(candidates[i], u, candidates[i+1]);
    }

    return (candidates.size() & 1);
}

int main(){
    int n, m;
    cin >> n >> m;

    g.resize(n);
    t.assign(n, 0);
    vis.assign(n, 0);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        a--;
        b--;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    vis[0] = 1;
    t[0] = 1;

    dfs(0, -1);

    cout << ans.size() << "\n";
    for(auto [u, v, w] : ans){
        cout << u+1 << " " << v+1 << " " << w+1 << "\n";
    }

    return 0;
}