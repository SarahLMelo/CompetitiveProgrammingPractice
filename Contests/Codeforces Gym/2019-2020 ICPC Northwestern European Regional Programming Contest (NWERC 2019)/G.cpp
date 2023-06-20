#include <bits/stdc++.h>

using namespace std;

#define double long double
vector <double> fact;

double choose(int n, int k){
    assert(n >= k);
    return fact[n]/fact[k]/fact[n-k];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(11) << fixed;

    int n, k;
    cin >> n >> k;

    fact.assign(501, 1.0);
    for(int i = 1; i <= 500; i++){
        fact[i] = fact[i-1] * i;
    }

    // cout << choose(213, 24) << endl;

    vector <double> spawn(n);
    for(int i = 0; i < n; i++)
        cin >> spawn[i];

    for(int i = 0; i < n; i++){
        double ans = 0;
        if(i) cout << " ";
        for(int d = 0; d < n; d++){
            int idx = (i - d + n) % n;
            if(n - d - 1 < k - 1) continue;
            // cout << i << " " << d << " " << idx << "\n";
            ans += spawn[idx] * choose(n - d - 1, k - 1) / choose(n, k);
        }

        cout << ans;
    }

    return 0;
}