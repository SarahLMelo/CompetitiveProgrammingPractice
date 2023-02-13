#include <bits/stdc++.h>

using namespace std;

struct edge{
    int u, v, cost, id;
    bool query;
    bool operator <(edge b){
        return cost < b.cost;
    }
};

int n, m, q;
vector <edge> edges;
vector <bool> ans;
const int nMax = 2e5+5;
int par[nMax], sz[nMax];

void init(){
    for(int i = 0; i < n; i++){
        par[i] = i;
        sz[i] = 1;
    }
}

int find(int x){
    if(par[x] != x) return par[x] = find(par[x]);
    return par[x];
}

void union_set(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return;
    if(sz[a] < sz[b]) swap(a, b);

    sz[a] += sz[b];
    par[b] = a;
}

void kruskal(){
    for(auto i:edges){
        if(find(i.u) != find(i.v)){
            if(i.query)
                ans[i.id] = true;
            
            else union_set(i.u, i.v);
        }
    }
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> q;

    init();
    ans.assign(q, false);

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;

        a--;
        b--;

        edge aux;
        aux.u = a;
        aux.v = b;
        aux.cost = c;
        aux.query = false;

        edges.push_back(aux);
    }

    for(int i = 0; i < q; i++){
        int a, b, c;
        cin >> a >> b >> c;

        a--;
        b--;

        edge aux;
        aux.u = a;
        aux.v = b;
        aux.cost = c;
        aux.query = true;
        aux.id = i;

        edges.push_back(aux);
    }

    sort(edges.begin(), edges.end());
    kruskal();

    for(int i = 0; i < q; i++)
        cout << (ans[i] ? "Yes":"No") << "\n";
    
    return 0;
}