#include <bits/stdc++.h>

using namespace std;
#define int long long

vector <int> par, depth, heavy, head, pos, bit;
vector <vector <int>> tree;
int cur_pos;

void bit_update(int pos, int val){
    // tree[pos] += val

    for(int x = pos; x < bit.size(); x += x & -x){
        bit[x] += val;
    }
}

int bit_query(int pos){
    // soma de bit[i <= pos]

    int ans = 0;
    for(int x = pos; x > 0; x -= x & -x){
        ans += bit[x];
    }

    return ans;
}

int dfs(int u){
    int sz = 1;
    int max_v_sz = 0;

    for(int v:tree[u]){
        if(par[u] == v) continue;
        par[v] = u;
        depth[v] = depth[u] + 1;

        int v_sz = dfs(v);
        sz += v_sz;

        if(v_sz > max_v_sz){
            max_v_sz = v_sz;
            heavy[u] = v; //Heavy representa qual meu filho mais pesado
        }
    }

    return sz;
}

void decompose(int u, int h){
    head[u] = h, pos[u] = cur_pos++;
    if(heavy[u] != -1){ //Continuando a chain atual
        decompose(heavy[u], h);
    }

    for(auto v:tree[u]){
        if(v != par[u] && v != heavy[u]){ //Iniciando uma nova chain
            decompose(v, v);
        }
    }
}

void init(){
    int n = tree.size();
    par.assign(n, -1);
    depth.assign(n, 0);
    heavy.assign(n, -1);
    head.assign(n, -1);
    pos.assign(n, -1);
    cur_pos = 1;

    dfs(0);
    bit = vector <int> (n + 5, 0);
    decompose(0, 0);
}

void update(int p, int val){
    int remove = bit_query(pos[p]) - bit_query(pos[p] - 1);
    bit_update(pos[p], -remove);
    bit_update(pos[p], val);
}

int query(int a, int b){
    int ans = 0;
    for(; head[a] != head[b]; b = par[head[b]]){
        if(depth[head[a]] > depth[head[b]])
            swap(a, b);
        
        int sum = bit_query(pos[b]) - bit_query(pos[head[b]] - 1);
        ans += sum;
    }

    if(depth[a] > depth[b])
        swap(a, b);

    ans += bit_query(pos[b]);
    ans -= bit_query(pos[a] - 1);

    return ans;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int cnt = 1; cnt <= t; cnt++){
        int n;
        cin >> n;

        vector <int> init_val(n);
        for(int i = 0; i < n; i++){
            cin >> init_val[i];
        }

        tree = vector <vector <int>>(n);
        for(int i = 0; i < n-1; i++){
            int a, b;
            cin >> a >> b;

            tree[a].push_back(b);
            tree[b].push_back(a);
        }

        init();

        for(int i = 0; i < n; i++)
            update(i, init_val[i]);
        
        int q;
        cin >> q;
        
        cout << "Case " << cnt << ":\n";

        while(q--){
            int cmd;
            cin >> cmd;

            if(cmd){
                int i, v;
                cin >> i >> v;

                update(i, v);
            }

            else{
                int i, j;
                cin >> i >> j;

                cout << query(i, j) << "\n";
            }
        }
    }

    return 0;
}