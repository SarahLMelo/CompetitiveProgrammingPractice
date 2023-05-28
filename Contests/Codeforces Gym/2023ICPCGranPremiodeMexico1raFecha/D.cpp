#include <bits/stdc++.h>

using namespace std;
#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    vector <int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    while(q--){
        int cmd;
        cin >> cmd;
        cmd--;

        if(cmd){
            int l, r;
            cin >> l >> r;
            cout << upper_bound(v.begin(), v.end(), r) - upper_bound(v.begin(), v.end(), l-1) << "\n";
        }

        else{
            int x;
            cin >> x;

            auto it = lower_bound(v.begin(), v.end(), x);
            if(it == v.end()) v.push_back(x);
            else (*it) = x;
            
        }
    }


    return 0;
}