#include <bits/stdc++.h>

using namespace std;

class seg{
    vector <int> tree;
    int sz;

    void build(int n, int l, int r, vector <int> &v){
        if(l == r){
            tree[n] = v[l];
            return;
        }

        int mid = (l+r)/2;
        build(2*n, l, mid, v);
        build(2*n + 1, mid + 1, r, v);

        tree[n] = max(tree[2*n], tree[2*n + 1]);
    }

    void update(int n, int l, int r, int p, int val){
        if(l == r){
            tree[n] = val;
            return;
        }

        int mid = (l+r)/2;
        if(p <= mid) update(2*n, l, mid, p, val);
        else update(2*n + 1, mid + 1, r, p, val);

        tree[n] = max(tree[2*n], tree[2*n + 1]);
    }

    int query(int n, int l, int r, int L, int R){
        if(L <= l && r <= R) return tree[n];
        if(r < L || l > R) return 0;

        int mid = (l+r)/2;

        return max(query(2*n, l, mid, L, R), query(2*n + 1, mid + 1, r, L, R));
    }

    public:
    seg(){}

    seg(int n){
        tree.assign(4*n, 0);
        sz = n;
    }

    void update(int p, int val){
        update(1, 0, sz -1 , p, val);
    }

    int query(int l, int r){
        return query(1, 0, sz-1, l, r);
    }
};

template <class T>
class HLD{
    vector <int> par, depth, heavy, head, pos;
    T helper;
    int cur_pos;

    int dfs(int u, vector <vector <pair <int, int>>> &tree, vector <int> &vals){
        int sz = 1;
        int max_sz = 0;

        for(auto v:tree[u]){
            if(par[u] == v.first) continue;
            
            par[v.first] = u;
            depth[v.first] = depth[u] + 1;
            vals[v.first] = v.second;

            int v_sz = dfs(v.first, tree, vals);
            sz += v_sz;

            if(v_sz > max_sz){
                max_sz = v_sz;
                heavy[u] = v.first; // Esse é o filho mais pesado
            }
        }

        return sz;
    }

    void decompose(int u, int h, vector <vector <pair <int, int>>> &g){
        head[u] = h, pos[u] = cur_pos++;

        if(heavy[u] != -1){
            decompose(heavy[u], h, g);
        }

        for(auto v:g[u]){
            if(v.first != par[u] && v.first != heavy[u]){
                decompose(v.first, v.first, g);
            }
        }
    }

    public:
    HLD(vector <vector <pair <int, int>>> &g){
        int n = g.size();
        par.assign(n, -1);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, -1);
        pos.assign(n, -1);
        cur_pos = 1;
        vector <int> v(n);

        dfs(0, g, v);
        decompose(0, 0, g);
        
        helper = seg(n + 5);
        for(int i = 0; i < n; i++){
            helper.update(pos[i], v[i]);
        }
    }

    void update(int a, int b, int v){
        if(par[a] == b)
            helper.update(pos[a], v);
        else helper.update(pos[b], v);
    }

    int query(int a, int b){
        if(a == b) return 0;
        //Não esquecer de alterar de acordo com a necessidade
        int ans = 0;
        while(head[a] != head[b]){
            if(depth[a] > depth[b])
                swap(a, b);

            ans = max(ans, helper.query(pos[head[b]], pos[b]));
            b = par[head[b]];
        }

        if(depth[a] > depth[b])
            swap(a, b);

        ans = max(ans, helper.query(pos[a] + 1, pos[b]));

        return ans;
    }
    
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector <vector <pair <int, int>>> g(n);
        vector <pair <int, int>> code(n-1);
        for(int i = 0; i < n-1; i++){
            int a, b, w;
            cin >> a >> b >> w;

            a--;
            b--;

            code[i] = {a, b};

            g[a].emplace_back(b, w);
            g[b].emplace_back(a, w);
        }

        HLD <seg> hld(g);

        string cmd;
        cin >> cmd;
        while(cmd != "DONE"){
            if(cmd == "QUERY"){
                int a, b;
                cin >> a >> b;

                a--;
                b--;


                cout << hld.query(a, b) << "\n";
            }

            else{
                int i, v;
                cin >> i >> v;

                i--;

                hld.update(code[i].first, code[i].second, v);
            }

            cin >> cmd;
        }
    }

    return 0;
}