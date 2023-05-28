#include <bits/stdc++.h>

using namespace std;
#define int long long
// #define cin input
// #define cout output

void solve(){
    vector <int> ans;
    int x, y;
    cin >> x >> y;

    while(y){
        ans.push_back(x/y);

        // if(x % y == x){
        //     ans.push_back(x % y);
        //     break;
        // }
        int aux = x;
        x = y;
        y = aux % y;

        // cout << x << " " << y << endl;
    }

    cout << ans.size() - 1 <A< " ";
    for(int i = 0; i < ans.size(); i++){
        if(i) cout << " ";
        cout << ans[i];
    }

    cout << "\n";
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ofstream output;
    ifstream input;
    // output.open ("out");
    // input.open("in");
    int t;
    cin >> t;

    while(t--)
        solve();

    // output.close();
    // input.close();


    return 0;
}