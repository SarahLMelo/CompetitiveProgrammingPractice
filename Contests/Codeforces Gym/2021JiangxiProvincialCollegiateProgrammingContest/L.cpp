#include <bits/stdc++.h>

using namespace std;
#define int long long
// #define cin input
// #define cout output

void solve(){
    int n;
    cin >> n;

    int ans = 0;
    vector <pair <int, int>> ev;
    int mx = 0;

    for(int i = 0; i < n; i++){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        ev.emplace_back(x1, 0);
        ev.emplace_back(x2, 1);

        mx = max(mx, x2);
    }

    sort(ev.begin(), ev.end());

    int st = -1, act = 0;
    for(int i = 0; i < ev.size(); i++){
        if(ev[i].second){
            act--;

            if(act) continue;
            for(int j = st; j < ev[i].first; j++){
                ans++;
                // cout << "i: " << j << "\n";
            }
            st = -1;
        }

        else{
            if(st == -1) st = ev[i].first;
            act++;
        }
    }

    if(st != -1){
        for(int i = st; i < mx; i++){
            // cout << "i: " << i << "\n";
            ans++;
        }
    }

    cout << ans << "\n";
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ofstream output;
    ifstream input;
    // output.open ("out");
    // input.open("in");
        solve();

    // output.close();
    // input.close();


    return 0;
}