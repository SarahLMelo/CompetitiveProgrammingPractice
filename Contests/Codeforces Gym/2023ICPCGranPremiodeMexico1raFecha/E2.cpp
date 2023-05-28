#include <bits/stdc++.h>

using namespace std;
#define int long long

struct bbp{
    int l, r, idx;

    int mid() const { return (l+r)/2; }
    bool operator<(bbp &p) const{
        return mid() < p.mid();
    }
};

vector <vector <int>> g;
vector <int> in, out, tree;
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

void euler_tour(int n){
    in[n] = t;
    for(auto i:g[n]){
        t++;
        euler_tour(i);
    }

    out[n] = t;
}

int32_t main(){
    int n, q;
    cin >> n >> q;
    vector <int> success(n);
    vector <pair <int, int>> bonus(q);
    vector <bbp> info(n);

    g.resize(n);
    in.resize(n);
    out.resize(n);
    t = 0;

    for(int i = 0; i < n; i++){
        cin >> success[i];

        info[i].idx = i;
        info[i].l = 0;
        info[i].r = q+1;
    }

    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;

        a--; b--;

        g[a].push_back(b);
    }

    euler_tour(0);

    for(int i = 0; i < q; i++){
        cin >> bonus[i].first >> bonus[i].second;
        bonus[i].first--;
    }

    bool flag = true;

    while(flag){
        // cout << "HERE" << endl;
        flag = false;
        sort(info.begin(), info.end());
        tree.assign(n + 20, 0);
        int upd = 0;

        for(auto &i:info){
            if(i.l >= i.r) continue;
            flag = true;

            while(upd < i.mid()){
                int val = bonus[upd].second, u = bonus[upd].first;
                int everyone = val / (out[u] - in[u] + 1), solo = val % (out[u] - in[u] + 1);


                update(in[u] + 1, everyone);
                update(out[u] + 2, -everyone);

                update(in[u] + 1, solo);
                update(in[u] + 2, -solo);

                // cout << upd << ": " << everyone << " " << solo << "\n";
                // cout << in[u] << " " << out[u] << "\n";

                upd++;
            }

            if(query(in[i.idx] + 1) < success[i.idx]) i.l = i.mid() + 1;
            else i.r = i.mid();
        }
    }

    // cout << "HERE" << endl;

    vector <int> ans(n);
    for(int i = 0; i < n; i++){
        ans[info[i].idx] = info[i].l;

        if(info[i].l > q){
            ans[info[i].idx] = -1;
        }
    }

    for(int i = 0; i < n; i++){
        cout << ans[i] << "\n";
    }

    return 0;
}

/*

10010 -> soma de todas as posições tal que
do bit mais significativo até antes do bit menos significativo que está
setado como 1 é igual e o bit menos significativo é zero.
Ou seja, todas as posições do intervalo [x - (x & -x), x[ (Se zero-based)

1) Os updates passam por todas as posições em que aquele update faz parte do intervalo
2) A query pega a soma de todas as posições que aquela query precisa ter
    Quer pegar todos os valores de [0, x[
    tree[x] = sum(a[i] | i pertence a [x - (x & -x), x[)
    query(x) = tree[x] + query(x - (x & -x))
    query(x) = ([x - (x & -x), x[) + query(x - (x & -x));
    query(x) = ([x - (x & -x), x[) + [0, x - (x & -x)[;
*/

// FFFFFFFFTTTTTT