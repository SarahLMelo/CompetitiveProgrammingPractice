#include <bits/stdc++.h>

using namespace std;
#define int long long

vector <int> tree;
int sz;

void build(int sz){
    tree.assign(4*sz, 0);
}

void update(int v, int pos, int n = 1, int l = 1, int r = sz){
    if(l == r){
        tree[n] = v;
        return;
    }

    int mid = (l+r)/2;
    if(pos <= mid) update(v, pos, 2*n, l, mid);
    else update(v, pos, 2*n + 1, mid + 1, r);

    tree[n] = tree[2*n + 1] + tree[2*n];
}

int qAux(int lq, int rq, int n = 1, int l = 1, int r = sz){
    if(lq > r || rq < l) return 0;
    if(lq <= l && r <= rq) return tree[n];

    int mid = (l+r)/2;
    return qAux(lq, rq, 2*n, l, mid) + qAux(lq, rq, 2*n + 1, mid+1, r);
}

bool query(int l, int r){
    if(l > r) swap(l, r);

    int ans = qAux(l, r);
    // cout << ans << "\n";
    if((qAux(0, l) + qAux(r, sz)) == 0) ans = 0;
    // cout << qAux(0, l) << " " << qAux(r, sz) << "\n\n";

    return ans;
}

int32_t main(){
    int n, q;
    cin >> n >> q;

    sz = n;
    build(n);

    while(q--){
        char cmd;
        cin >> cmd;

        if(cmd == '?'){
            int l, r;
            cin >> l >> r;

            if(query(l, r)) cout << "im";
            cout << "possible\n";
        }

        else if(cmd == '-'){
            int pos;
            cin >> pos;

            update(1, pos);
        }

        else{
            int pos;
            cin >> pos;

            update(0, pos);
        }
    }

    return 0;
}