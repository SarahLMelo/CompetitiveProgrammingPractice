#include <bits/stdc++.h>

using namespace std;
#define int long long

struct node{
    int par = -1;
    vector <int> children;
    bool inPath = false, parEnd = false;
};

vector <node> tree;
vector <vector <int>> graph;
int x, ans = 0;

void initTree(int pos, int par = -1){
    tree[pos].par = par;
    if(pos == x){
        tree[par].parEnd = true;
        tree[pos].inPath = true;
    }

    for(auto i:graph[pos]){
        if(i == par) continue;

        tree[pos].children.emplace_back(i);
        initTree(i, pos);
    }
}

void dfs(int pos, int par){
    ans++;

    if(tree[pos].parEnd){
        ans++;
        return;
    }

    for(auto i:tree[pos].children){
        if(i == par) continue;
        dfs(i, pos);
        if(!tree[i].inPath) ans++;
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n >> x;
    x--;

    graph.resize(n);
    tree.resize(n);

    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;

        a--;
        b--;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    initTree(0);

    int aux = x;
    while(x){
        tree[x].inPath = true;
        x = tree[x].par;
    }

    dfs(0, -1);

    cout << ans-1 << "\n";

    return 0;
}