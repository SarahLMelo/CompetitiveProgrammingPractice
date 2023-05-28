#include <bits/stdc++.h>

#define int long long
using namespace std;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector <int> sp(n), pos(n);

    for(int i = 0; i < n; i++){
        cin >> sp[i];
        pos[i] = i;
    }

    bool ans = false;
    for(int t = 0; t < 1001; t++){
        ans = true;
        for(int i = 0; i < n-1 && ans; i++){
            if(pos[i] != pos[i+1]) ans = false;
        }

        if(ans){
            cout << t << " " << pos[0] << "\n";
            break;
        }
        else{
            for(int i = 0; i < n; i++){
                pos[i] += sp[i];
                pos[i] %= n;
            }
        }
    }

    if(!ans) cout << "-1\n";

    return 0;
}