#include <bits/stdc++.h>

using namespace std;

vector <int> par, sz;
vector <vector <int>> tree;
vector <vector <pair <int, int>>> g;
int n;
double ans;

void build(){
    par.resize(n);
    sz.assign(n, 1);

    for(int i = 0; i < n; i++) par[i] = i;
}

int find(int x){
    if(par[x] != x) par[x] = find(par[x]);

    return par[x];
}

void merge(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return;

    if(sz[b] > sz[a]) swap(a, b);

    sz[a] += sz[b];
    par[b] = a;
}

void kruskal(){
    priority_queue <tuple <int, int, int>> pq;

    for(int u = 0; u < n; u++){
        for(auto [v, w]: g[u]){
            // cout << w << " " << u << " " << v << "\n";
            pq.emplace(w, u, v);
        }
    }

    while(!pq.empty()){
        int u, v, w;
        u = get<1>(pq.top());
        v = get<2>(pq.top());
        w = get<0>(pq.top());

        pq.pop();

        if(find(u) == find(v)) continue;

        ans += sz[find(u)]* sz[find(v)] * w *1.0;
        merge(u, v);
    }
}



int main(){
    int m;
    cin >> n >> m;

    cout << setprecision(6) << fixed;

    vector <int> a(n);
    g.resize(n);
    build();
    ans = 0;

    for(int i = 0; i < n; i++) cin >> a[i];
    while(m--){
        int u, v;
        cin >> u >> v;

        u--;
        v--;

        int w = min(a[u], a[v]);
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    kruskal();

    cout << 2 * ans/(n * (n-1)) << "\n";


    return 0;
}