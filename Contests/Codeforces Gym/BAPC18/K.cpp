#include <bits/stdc++.h>

using namespace std;

vector <vector <int>> g;
vector <int> vis, leafs;

void dfs(int u){
    for(auto v:g[u]){
        if(vis[v]) continue;
        vis[v] = true;
        dfs(v);
    }
    if(g[u].size() == 1) leafs.push_back(u);
}

int main(){
    int n, root;
    cin >> n >> root;

    g.resize(n);
    vis.assign(n, 0);
    vis[root] = 1;

    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(root);


    vector <pair <int, int>> ans;
    for(int i = 0; i + leafs.size()/2 < leafs.size(); i++){
        ans.emplace_back(leafs[i], leafs[(i+leafs.size()/2)]);
    }

    cout << ans.size() << "\n";
    for(auto i:ans) cout << i.first << " " << i.second << "\n";

    return 0;
}