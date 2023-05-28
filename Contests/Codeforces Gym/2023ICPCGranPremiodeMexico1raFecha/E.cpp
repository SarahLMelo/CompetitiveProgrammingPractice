#include <bits/stdc++.h>

using namespace std;
#define int long long

struct bb{
    public:
    int l, r, idx;
    bb(int l, int r, int idx){
        this->l = l;
        this->r = r;
        this->idx = idx;
    }

    int mid() const { return (l+r)/2; }

    bool operator < (bb x) const { return mid() < x.mid(); }
};

int n;
vector <vector <int>> g;
vector <int> in, out, success, tree;
int t;

void update(int pos, int val){
    // tree[pos] += val

    for(int x = pos; x < tree.size(); x += x & -x){
        tree[x] += val;
    }
}

int query(int pos){
    // soma de tree[i <= pos]

    int ans = 0;
    for(int x = pos; x > 0; x -= x & -x){
        ans += tree[x];
    }

    return ans;
}

void euler(int pos, int par){
    in[pos] = t;
    for(auto i:g[pos]){
        if(i == par) continue;
        t++;
        euler(i, pos);
    }
    out[pos] = t;
}

int32_t main(){
    cin >> n;
    int q; cin >> q;

    g.resize(n);
    success.resize(n);
    in.resize(n);
    out.resize(n);
    for(int i = 0; i < n; i++) cin >> success[i];

    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;

        a--;
        b--;

        g[a].push_back(b);
    }

    euler(0, -1);
    vector <bb> searches(n, {0, 0, 0});
    vector <pair <int, int>> bonus(n);
    for(int i = 0; i < q; i++){
        searches[i] = {0, q+1, i};
        cin >> bonus[i].first >> bonus[i].second;
        bonus[i].first--;
    }

    bool flag = true;

    while(flag){
        flag = false;
        sort(searches.begin(), searches.end());
        tree.assign(n + 1, 0);

        int upd = 0;
        for(auto &search:searches){
            if(search.l == search.r) continue;
            flag = true;

            while(upd < q && upd < search.mid()){
                int u = in[bonus[upd].first], last_child = out[bonus[upd].first], child_amount = last_child - u + 1;
                
                upd++;
            }

            // if(search.idx == 0) query(1, 0, n-1, in[search.idx]);
            // if(query(1, 0, n-1, in[search.idx]) < success[search.idx]) search.l = search.mid() + 1;
            // else search.r = search.mid();
        }
    }

    vector <int> ans(n);
    for(int i = 0; i < n; i++){
        ans[searches[i].idx] = searches[i].l;
        // if(searches[i].l > q){
        //     cout << "-1\n";
        //     return 0;
        // }
    }

    for(int i = 0; i < n; i++) cout << ans[i] << "\n";

    return 0;
}

/* 0 0 0 0 0 0  0 0 : tree
   0 0 0 0 1 0  0 0 : tree
   0 0 0 0 1 1  1 1
   0 0 0 0 1 0 -1 0 : tree
   0 0 0 0 1 1  0 0

*/