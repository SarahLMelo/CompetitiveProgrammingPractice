#include <bits/stdc++.h>

using namespace std;
#define int long long

priority_queue <pair <int, int>> candidates;
priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> inSum;
set <int> idxInSum;
vector <int> A;
int n, k, q, sum;

void balance(){
    while(idxInSum.size() < k){
        int v, idx;
        tie(v, idx) = candidates.top();
        candidates.pop();

        if(A[idx] != v) continue;
        sum += v;
        idxInSum.insert(idx);
        inSum.emplace(v, idx);
    }

    while(!candidates.empty() && candidates.top().first > inSum.top().first){
        int idx1, idx2, v1, v2;
        tie(v1, idx1) = candidates.top();
        tie(v2, idx2) = inSum.top();

        if(A[idx2] != v2){
            inSum.pop();
            continue;
        }

        if(A[idx1] != v1){
            candidates.pop();
            continue;
        }

        inSum.pop();
        candidates.pop();

        idxInSum.erase(idx2);
        idxInSum.insert(idx1);

        sum -= v2;
        sum += v1;

        candidates.emplace(v2, idx2);
        inSum.emplace(v1, idx1);
    }
}

int32_t main(){
    cin >> n >> k >> q;

    A.assign(n, 0);

    for(int i = 0; i < n; i++){
        candidates.emplace(0, i);
    }

    balance();

    for(int i = 0; i < q; i++){
        int x, y;
        cin >> x >> y;
        x--;

        if(idxInSum.find(x) != idxInSum.end()){
            idxInSum.erase(x);
            sum -= A[x];
        }

        A[x] = y;
        candidates.emplace(y, x);
        balance();

        cout << sum << "\n";
    }

}