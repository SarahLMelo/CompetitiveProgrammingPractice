#include <bits/stdc++.h>

using namespace std;
#define int long long

const int mx = 1e5 + 5;
int tree[4*mx];

void update(int n, int l, int r, int v, int pos){
    if(l == r){
        tree[n] += v;
        return;
    }

    int m = (l+r)/2;
    if(pos <= m) update(2*n, l, m, v, pos);
    else update(2*n + 1, m+1, r, v, pos);

    tree[n] = tree[2*n] + tree[2*n + 1];
}

int query(int n, int l, int r, int ql, int qr){
    if(l > qr || r < ql) return 0;
    if(l >= ql && qr >= r) return tree[n];

    int m = (l+r)/2;
    int left, right;
    left = query(2*n, l, m, ql, qr);
    right = query(2*n + 1, m + 1, r, ql, qr);

    return left + right;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector <int> numbers;
    int n;
    cin >> n;
    vector <tuple <int, int, int>> op(n);

    for(int i = 0; i < n; i++){
        int cmd, v;
        cin >> cmd >> v;

        op[i] = {cmd, v, 0};

        if(cmd == 1){
            numbers.push_back(v);
        }

        if(cmd == 3){
            int x;
            cin >> x;
            get<2>(op[i]) = x;
            get<2>(op[v - 1]) += x;
            numbers.push_back(get<2>(op[v - 1]) + get<1>(op[v - 1]));
        }
    }

    sort(numbers.begin(), numbers.end());
    numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());

    map <int, int> pc;
    for(int i = 0; i < numbers.size(); i++){
        pc[numbers[i]] = i;
    }

    for(int i = 0; i < n; i++){
        if(get<0>(op[i]) == 1){
            update(1, 0, numbers.size() - 1, 1, pc[get<1>(op[i])]);
            get<2>(op[i]) = 0;
            // cout << tree[1] << " " << tree[2] << " " << tree[3] << '\n';
        }

        else if(get<0>(op[i]) == 2){
            int idx = get<1>(op[i]) - 1;
            int toErase = get<1>(op[idx]) + get<2>(op[idx]);
            update(1, 0, numbers.size() - 1, -1, pc[toErase]);
        }

        else if(get<0>(op[i]) == 3){
            int idx = get<1>(op[i]) - 1, amount = get<2>(op[i]);
            int toErase = get<1>(op[idx]) + get<2>(op[idx]);
            int toAdd = get<1>(op[idx]) + get<2>(op[idx]) + amount;

            get<2>(op[idx]) += amount;
            update(1, 0, numbers.size() - 1, -1, pc[toErase]);
            update(1, 0, numbers.size() - 1, 1, pc[toAdd]);
        }

        else{
            int idx = get<1>(op[i]) - 1;
            int search = pc[get<1>(op[idx]) + get<2>(op[idx])];
            search--;

            // cout << search << "\n";

            if(search < 0) cout << "0\n";
            else cout << query(1, 0, numbers.size() - 1, 0, search) << "\n";
        }
    }
    
    return 0;
}