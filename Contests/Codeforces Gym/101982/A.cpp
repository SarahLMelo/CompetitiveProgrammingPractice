#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, w;
    cin >> n >> w;
    w++;

    int maxx = 0, minx = 0, acc = 0;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;

        acc += x;
        maxx = max(acc, maxx);
        minx = min(minx, acc);
    }

    w -= maxx;
    w += minx;

    cout << max(0LL, w) << "\n";

    return 0;
}