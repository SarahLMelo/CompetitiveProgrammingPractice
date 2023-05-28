#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve(){
    int n;
    cin >> n;

    vector <int> v(n), v2(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    for(int i = 0; i < n; i++){
        cin >> v2[i];
    }

    bool eq = true;
    for(int i = 0; i < n; i++){
        if(v[i] != v2[i]){
            eq = false;
            break;
        }
    }

    int fdif = n-1, edif = 0;

    for(int i = 0; i < n; i++){
        if(v[i] != v2[i]){
            fdif = i;
            break;
        }
    }

    for(int i = fdif; i < n; i++){
        if(v[i] != v2[i]){
            edif = i;
        }
    }

    while(fdif && v2[fdif] >= v2[fdif-1]) fdif--;
    while(edif < n - 1 && v2[edif] <= v2[edif+1]) edif++;

    cout << fdif + 1 << " " << edif + 1 << "\n";


}

int32_t main(){
    int t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}