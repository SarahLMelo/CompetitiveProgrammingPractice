#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    int p, n;
    cin >> p >> n;

    vector <bool> plates(p);
    for(int i = 0; i < p; i++){
        char c;
        cin >> c;

        if(c == 'L') plates[i] = false;
        else plates[i] = true;
    }

    int ans = 0, cur = 0, dir = 0;
    for(int i = 0; i < n; i++){
        if(i) dir = plates[cur];
        // cout << plates[cur] << " " << dir << endl;
        while(cur < p && plates[cur] == dir){
            cur++;
            dir = !dir;
            // cout << plates[cur] << " " << dir << endl;
        }

        // cout << cur << "\n";

        if(cur == p){
            ans = n - i;
            break;
        }
    }

    cout << ans << "\n";

    return 0;
}